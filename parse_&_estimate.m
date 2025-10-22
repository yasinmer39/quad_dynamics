%ulog dosyasını yükle, tüm topicleri oku
ulog = ulogreader("log_12_2025-9-24-09-11-08.ulg");

%hangi zaman aralığını incelemek istiyorsan onu gir, formatı yazıyor 
start_time = ulog.StartTime;
end_time = ulog.EndTime;
%interval = start_time + duration([0 0 55],'Format','hh:mm:ss.SSSSSS');

%açısal hızı setpointinin ve ölçümünün olduğu topici oku
vehicle_angular_velocity = readTopicMsgs(ulog,'TopicNames',{'vehicle_angular_velocity'},'InstanceID',{0},'Time',[start_time end_time]);
vehicle_rates_setpoint = readTopicMsgs(ulog,'TopicNames',{'vehicle_rates_setpoint'},'InstanceID',{0},'Time',[start_time end_time]);
vehicle_status = readTopicMsgs(ulog,'TopicNames',{'vehicle_status'},'InstanceID',{0},'Time',[start_time end_time]);
actuator_motors = readTopicMsgs(ulog,'TopicNames',{'actuator_motors'},'InstanceID',{0},'Time',[start_time end_time]);

%topic mesajlarını extract et
ang_vel_meas = vehicle_angular_velocity.TopicMessages{1,1};
rate_sp = vehicle_rates_setpoint.TopicMessages{1,1};
status = vehicle_status.TopicMessages{1,1};
motors = actuator_motors.TopicMessages{1,1};

%takeoff zamanını bulana kadar listeyi tara
takeoff_time = status.takeoff_time(find(status.takeoff_time ~= 0, 1, "first"));

if isempty(takeoff_time) || takeoff_time==0
    error('vehicle_status.takeoff_time bulunamadı (hep 0). Uçuş olmayan bir log olabilir.');
end

takeoff_time = seconds(double(takeoff_time) * 1e-6);   % ★ uint64 -> duration

% p,q,r matrisleri, motor itkisi ve zamanlar
meas_pqr = [ang_vel_meas.xyz(:,1) ang_vel_meas.xyz(:,2) ang_vel_meas.xyz(:,3)];
sp_pqr   = [rate_sp.roll rate_sp.pitch rate_sp.yaw];
thrust_sp = [motors.control(:,1) motors.control(:,2) motors.control(:,3) motors.control(:,4)];
t_meas   = ang_vel_meas.timestamp;
t_sp     = rate_sp.timestamp;
t_thrust = motors.timestamp;

%takeoffdan sonraki timestampleri al
idx_meas = t_meas >= takeoff_time;
idx_sp = t_sp >= takeoff_time;
idx_thrust = t_thrust >= takeoff_time;

meas_pqr = meas_pqr(idx_meas,:);
sp_pqr = sp_pqr(idx_sp,:);
thrust_sp = thrust_sp(idx_thrust,:);
t_meas = t_meas(idx_meas);
t_sp = t_sp(idx_sp);
t_thrust = t_thrust(idx_thrust,:);

% ölçüm, setpoint ve thrust timetable oluştur
TT_meas = array2timetable(meas_pqr,'RowTimes',t_meas,'VariableNames',{'p_meas','q_meas','r_meas'});
TT_sp   = array2timetable(sp_pqr,'RowTimes',t_sp,'VariableNames',{'p_sp','q_sp','r_sp'});
TT_thrust = array2timetable(thrust_sp,'RowTimes',t_thrust,'VariableNames',{'motor1','motor2','motor3','motor4'});

%Giriş (roll/pitch/yaw mix) sinyallerini oluştur
% Kararlı uçuş çevresinde DC bileşenini azaltmak için ortalamayı çıkar.
m1 = TT_thrust.motor1 - mean(TT_thrust.motor1,'omitnan');
m2 = TT_thrust.motor2 - mean(TT_thrust.motor2,'omitnan');
m3 = TT_thrust.motor3 - mean(TT_thrust.motor3,'omitnan');
m4 = TT_thrust.motor4 - mean(TT_thrust.motor4,'omitnan');

%motor kontrol inputları olan u matrisini oluştur
u1 = TT_thrust.motor3 + TT_thrust.motor1 + TT_thrust.motor2 + TT_thrust.motor4; %total itki 
u2 = TT_thrust.motor3 - TT_thrust.motor1 + TT_thrust.motor2 - TT_thrust.motor4; %roll hareketi
u3 = TT_thrust.motor3 + TT_thrust.motor1 - TT_thrust.motor2 - TT_thrust.motor4; %pitch hareketi
u4 = TT_thrust.motor3 - TT_thrust.motor1 - TT_thrust.motor2 + TT_thrust.motor4; %yaw hareketi

TT_u = timetable(TT_thrust.Time, u2, u3, u4, 'VariableNames',{'u_roll','u_pitch','u_yaw'});

%zamanı duartion yap
%dt_meas = mean(seconds(diff(TT_meas.Time)));
%freq_meas = 1 / dt_meas;
%t = duration([zeros(length(TT_meas.Time),1) zeros(length(TT_thrust.Time),1) (0:1/freq_meas:(length(TT_meas.Time)-1)/freq_meas)'], 'Format', 'hh:mm:ss.SSS');

%timetabelları birleştir
%TT_unified = timetable(t, u1, u2, u3, u4, TT_meas.p_meas, TT_meas.q_meas, TT_meas.r_meas, TT_meas.pdot_meas, TT_meas.qdot_meas, TT_meas.rdot_meas, 'VariableNames', {'u1','u2','u3','u4','p_meas','q_meas','r_meas','pdot_meas','qdot_meas','rdot_meas'});

%senkronizasyon
Ts = 0.0035;
TT = synchronize(TT_meas, TT_u, 'intersection');
TT = retime(TT,'regular','pchip','TimeStep',seconds(Ts));

y = [TT.p_meas, TT.q_meas, TT.r_meas];
u = [TT.u_roll, TT.u_pitch, TT.u_yaw];

data = iddata(y,u,Ts,'InputName',{'tau_r','tau_p','tau_y'},'OutputName',{'p','q','r'});
