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

takeoff_time = seconds(double(takeoff_time) * 1e-6);   %duration yap

% takeoff sonrası kes
t_meas_all   = ang_vel_meas.timestamp;
t_thrust_all = motors.timestamp;
idx_meas   = (t_meas_all   >= takeoff_time);
idx_thrust = (t_thrust_all >= takeoff_time);

TT_meas = timetable(t_meas_all(idx_meas), ...
    ang_vel_meas.xyz(idx_meas,1), ang_vel_meas.xyz(idx_meas,2), ang_vel_meas.xyz(idx_meas,3), ...
    'VariableNames',{'p_meas','q_meas','r_meas'});

TT_thrust = timetable(t_thrust_all(idx_thrust), ...
    motors.control(idx_thrust,1), motors.control(idx_thrust,2), ...
    motors.control(idx_thrust,3), motors.control(idx_thrust,4), ...
    'VariableNames',{'m1','m2','m3','m4'});

% (i) zamanları sıralayıp (ii) tekrar edenleri at
TT_meas   = sortrows(TT_meas);
TT_thrust = sortrows(TT_thrust);

[TT_meas.Time,   ia] = unique(TT_meas.Time,'stable');   TT_meas   = TT_meas(ia,:);
[TT_thrust.Time, ia] = unique(TT_thrust.Time,'stable'); TT_thrust = TT_thrust(ia,:);

% 2) Ortak pencere
t0 = max(TT_meas.Time(1), TT_thrust.Time(1));
t1 = min(TT_meas.Time(end), TT_thrust.Time(end));
if t1 <= t0
    error('Ortak zaman aralığı yok (intersection boş).');
end

% 3) Ortak ızgara zaman vektörü (duration)
Ts = 0.0035;
gridT = (t0 : seconds(Ts) : t1).';   % sütun vektör

% Her tabloyu aynı ızgaraya yeniden örnekle
TT_meas_g   = retime(TT_meas,   gridT, 'pchip');
TT_thrust_g = retime(TT_thrust, gridT, 'pchip');

% 4) DC çıkar + miks (motorlar)
m1 = TT_thrust_g.m1 - mean(TT_thrust_g.m1,'omitnan');
m2 = TT_thrust_g.m2 - mean(TT_thrust_g.m2,'omitnan');
m3 = TT_thrust_g.m3 - mean(TT_thrust_g.m3,'omitnan');
m4 = TT_thrust_g.m4 - mean(TT_thrust_g.m4,'omitnan');

u_roll  = +m3 - m1 + m2 - m4;
u_pitch = +m3 + m1 - m2 - m4;
u_yaw   = +m3 - m1 + m4 - m2;   % işaret/sıra sonra teyit

% === Mix işaret test taraması (roll/pitch/yaw) ===
cands = [-1 1];
best = struct('sr',1,'sp',1,'sy',1,'score',-Inf);

for sr = cands, for sp = cands, for sy = cands
    ur = sr*u_roll;  up = sp*u_pitch;  uy = sy*u_yaw;
    s = 0;
    s = s + abs(corr(ur, TT_meas_g.p_meas, 'rows','complete'));
    s = s + abs(corr(up, TT_meas_g.q_meas, 'rows','complete'));
    s = s + abs(corr(uy, TT_meas_g.r_meas, 'rows','complete'));
    if s > best.score
        best = struct('sr',sr,'sp',sp,'sy',sy,'score',s);
    end
end, end, end

% Seçilen işaretleri uygula
u_roll  = best.sr * u_roll;
u_pitch = best.sp * u_pitch;
u_yaw   = best.sy * u_yaw;
fprintf('Mix signs -> roll:%+d pitch:%+d yaw:%+d (corr=%.3f)\n', best.sr,best.sp,best.sy,best.score);

% 6) (Opsiyonel ama çok faydalı) Giriş→çıktı gecikmelerini ölç
maxLag = 60; % ≈ 210 ms
[~,i]=max(abs(xcorr(u_roll,  TT_meas_g.p_meas, maxLag,'coeff'))); nd_r = (i-1)-maxLag; nd_r = max(nd_r,0);
[~,i]=max(abs(xcorr(u_pitch, TT_meas_g.q_meas, maxLag,'coeff'))); nd_p = (i-1)-maxLag; nd_p = max(nd_p,0);
[~,i]=max(abs(xcorr(u_yaw,   TT_meas_g.r_meas, maxLag,'coeff'))); nd_y = (i-1)-maxLag; nd_y = max(nd_y,0);

% 7) Giriş sinyallerine manuel gecikme uygula (InputDelay alternatifi)
delay_shift = @(x,nd) (nd>0) * [zeros(nd,1); x(1:end-nd)] + (nd==0)*x;

u_roll_d  = delay_shift(u_roll,  nd_r);
u_pitch_d = delay_shift(u_pitch, nd_p);
u_yaw_d   = delay_shift(u_yaw,   nd_y);

% --- girişleri birim RMS'e ölçekle ---
su = rms([u_roll_d u_pitch_d u_yaw_d], 1);
su(su==0) = 1;  % bölünme güvenliği
u_roll_d  = u_roll_d  ./ su(1);
u_pitch_d = u_pitch_d ./ su(2);
u_yaw_d   = u_yaw_d   ./ su(3);

% Tüm vektörleri aynı uzunluğa getir
N = min([length(TT_meas_g.p_meas), length(u_roll_d), length(u_pitch_d), length(u_yaw_d)]);
y = TT_meas_g{1:N, {'p_meas','q_meas','r_meas'}};
u = [u_roll_d(1:N) u_pitch_d(1:N) u_yaw_d(1:N)];

% --- 0.2 Hz üstü içeriği bırak (2. mertebe butter HP) ---
wc = 0.2;                    % Hz
[b,a] = butter(2, wc/(0.5/Ts), 'high');

% y ve u matrislerini zero-phase high-pass filtreden geçir
y_f = filtfilt(b, a, y);     % y: Nx3
u_f = filtfilt(b, a, u);     % u: Nx3

% iddata oluştur (filtrelenmiş veriden)
data = iddata(y_f, u_f, Ts, ...
    'InputName',{'tau_r','tau_p','tau_y'}, ...
    'OutputName',{'p','q','r'});

% DC bileşenlerini yine de sıfırla (küçük ofsetler kalabilir)
data = detrend(data, 0);

% 8) Grey-box (3 durum, aktüatör lag yok — önce bunu oturt)
function [A,B,C,D] = bodyrate_model(par,~,Ts)
    Ixx=par(1); Iyy=par(2); Izz=par(3);
    dph=par(4); dth=par(5); dps=par(6);
    kph=par(7); kth=par(8); kps=par(9);

    Ac = diag([-dph/Ixx, -dth/Iyy, -dps/Izz]);
    Bc = diag([ kph/Ixx,  kth/Iyy,  kps/Izz]);

    A = eye(3) + Ts*Ac;
    B = Ts*Bc;
    C = eye(3);
    D = zeros(3,3);
end

% Başlangıç parametreleri (seninkilerle uyumlu)
Msphere=25.0; Mrotor=2.8; r=1.02; lr=1.02;
I0   = (2/5)*Msphere*r^2 + 2*(lr^2)*Mrotor;  % Ixx≈Iyy
Ixx0 = I0; Iyy0 = I0; Izz0 = (2/5)*Msphere*r^2 + 4*(lr^2)*Mrotor;

par0 = [Ixx0, Iyy0, Izz0,  5, 5, 5,  1, 1, 1];
lb   = [1,1,1,  0,0,0,  0,0,0];
ub   = [400,400,800,  300,300,300,  200,200,200];

sys0 = idgrey(@bodyrate_model, par0, 'd', Ts);
% --- sys0 tanımlandıktan HEMEN SONRA ekle ---
P = sys0.Structure.Parameters;           % parametre yapıları
lbv = [1,1,1,  0,0,0,  0,0,0];           % senin lb vektörün
ubv = [400,400,800,  300,300,300,  200,200,200];  % senin ub vektörün
for k = 1:numel(P)
    P(k).Minimum = lbv(k);
    P(k).Maximum = ubv(k);
    P(k).Free    = true;                 % hepsi ayarlanabilir olsun (istersen bazılarını kilitleyebilirsin)
end
sys0.Structure.Parameters = P;

% --- sonra sadece bu şekilde çağır ---
opt  = greyestOptions( ...
    'EnforceStability', true, ...
    'Display',          'on', ...
    'InitialState',     'estimate', ...
    'Focus',            'prediction', ...
    'DisturbanceModel', 'estimate');   % <<< K ve NoiseVariance'ı tahmin et

sys  = greyest(data, sys0, opt)