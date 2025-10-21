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

%topic mesajlarını extract et
ang_vel_meas = vehicle_angular_velocity.TopicMessages{1,1};
rate_sp = vehicle_rates_setpoint.TopicMessages{1,1};
status = vehicle_status.TopicMessages{1,1};

%takeoff zamanını bulana kadar listeyi tara
takeoff_time = status.takeoff_time(find(status.takeoff_time ~= 0, 1, "first"));

if isempty(takeoff_time) || takeoff_time==0
    error('vehicle_status.takeoff_time bulunamadı (hep 0). Uçuş olmayan bir log olabilir.');
end

takeoff_time = seconds(double(takeoff_time) * 1e-6);   % ★ uint64 -> duration

% p,q,r matrisleri ve zamanlar
meas_pqr = [ang_vel_meas.xyz(:,1) ang_vel_meas.xyz(:,2) ang_vel_meas.xyz(:,3)];
sp_pqr   = [rate_sp.roll rate_sp.pitch rate_sp.yaw];
t_meas   = ang_vel_meas.timestamp;
t_sp     = rate_sp.timestamp;

%takeoffdan sonraki timestampleri al
idx_meas = t_meas >= takeoff_time;
idx_sp = t_sp >= takeoff_time;

meas_pqr = meas_pqr(idx_meas,:);
sp_pqr = sp_pqr(idx_sp,:);
t_meas = t_meas(idx_meas);
t_sp = t_sp(idx_sp);

% ölçüm ve setpoint timetable oluştur
TT_meas = array2timetable(meas_pqr,'RowTimes',t_meas,'VariableNames',{'p_meas','q_meas','r_meas'});
TT_sp   = array2timetable(sp_pqr,  'RowTimes',t_sp,  'VariableNames',{'p_sp','q_sp','r_sp'});

% ölçüm ve setpoint frekanslarını bulma
dt_meas = mean(seconds(diff(TT_meas.Time)));
dt_sp   = mean(seconds(diff(TT_sp.Time)));

freq_meas = 1 / dt_meas;
freq_sp = 1 / dt_sp;
freq_resamp = 285.0;

%resample et verileri ve zamanı
resamp_p_meas = double(resample(TT_meas.p_meas, freq_resamp, round(freq_meas, 0)));
resamp_p_sp = double(resample(TT_sp.p_sp, freq_resamp, round(freq_sp, 0)));
resamp_p_sp(end) = [];
resamp_p_sp(end-1) = [];
resamp_p_sp(end-2) = [];
resamp_p_sp(end-3) = [];
resamp_p_sp(end-4) = [];
resamp_p_sp(end-5) = [];

resamp_q_meas = double(resample(TT_meas.q_meas, freq_resamp, round(freq_meas, 0)));
resamp_q_sp = double(resample(TT_sp.q_sp, freq_resamp, round(freq_sp, 0)));
resamp_q_sp(end) = [];
resamp_q_sp(end-1) = [];
resamp_q_sp(end-2) = [];
resamp_q_sp(end-3) = [];
resamp_q_sp(end-4) = [];
resamp_q_sp(end-5) = [];

resamp_r_meas = double(resample(TT_meas.r_meas, freq_resamp, round(freq_meas, 0)));
resamp_r_sp = double(resample(TT_sp.r_sp, freq_resamp, round(freq_sp, 0)));
resamp_r_sp(end) = [];
resamp_r_sp(end-1) = [];
resamp_r_sp(end-2) = [];
resamp_r_sp(end-3) = [];
resamp_r_sp(end-4) = [];
resamp_r_sp(end-5) = [];

resamp_t = duration([zeros(length(resamp_q_sp),1) zeros(length(resamp_q_sp),1) (0:1/freq_resamp:(length(resamp_q_meas)-1)/freq_resamp)'], 'Format', 'hh:mm:ss.SSS');

%lowpass at
lpass_resamp_meas = lowpass(resamp_q_meas, 0.150);
lpass_resamp_sp = lowpass(resamp_q_sp, 0.150);

% verileri timetable yap
TT_resamp = timetable(resamp_t, resamp_p_meas, resamp_p_sp, resamp_q_meas, resamp_q_sp, resamp_r_meas, resamp_r_sp, 'VariableNames', {'p_meas', 'p_sp', 'q_meas', 'q_sp', 'r_meas', 'r_sp'});

data = iddata(TT_resamp);

%çeşitli yöntemlerle estimate et
%sys_n4 = n4sid(TT_resamp, 10); %25Hz'de 7th order yüzde 62.61 fit to estimation data
%sys_tf = tfest(TT_resamp, 2); %25Hz'de 2nd order yüzde 24.23 fit to estimation data
sys_ss = ssest(TT_resamp, 8) %285Hz'de 8th order yüzde 91.1 fit to estimation data continuous time state-space
%sys_ss_discrete = ssest(resamp_q_sp, resamp_q_meas, 1, "Ts", freq_resamp)
%sys_te = tfestimate(resamp_q_sp, resamp_q_meas);

compare(TT_resamp,sys_ss)

% ölçüm ve setpoint plotla
figure;
plot(TT_resamp.resamp_t, TT_resamp.q_meas, 'b', 'DisplayName', 'Measured q');
hold on;
plot(TT_resamp.resamp_t, TT_resamp.q_sp, 'r--', 'DisplayName', 'Setpoint q');
xlabel('Time (s)');
ylabel('Angular Velocity (q)');
title('Resampled Angular Velocity Measurements and Setpoints');
legend show;
grid on;