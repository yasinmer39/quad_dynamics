%Grey-box modeli (p,q,r domain)
% States: x = [p q r]^T
% xdot = A x + B u
% A = diag(-dphi/Ixx, -dtheta/Iyy, -dyaw/Izz)
% B = diag(kphi/Ixx, ktheta/Iyy, kpsi/Izz)
function [A,B,C,D] = bodyrate_model(par,~,Ts)
    Ixx = par(1); Iyy = par(2); Izz = par(3);
    dph = par(4); dth = par(5); dps = par(6);
    kph = par(7); kth = par(8); kps = par(9);

    Ac = diag([-dph/Ixx, -dth/Iyy, -dps/Izz]);
    Bc = diag([ kph/Ixx,  kth/Iyy,  kps/Izz]);

    % Discrete eşdeğer (Euler forward yeterli, küçük Ts)
    A = eye(3) + Ts*Ac;
    B = Ts*Bc;
    C = eye(3);
    D = zeros(3,3);
end

Msphere = 25.0; %atalet, bir küresel kütle yoğunluğunun merkezinden yaklaşık olarak tahmin edilebilir (Dynamic Modelling of a Quadrotor Aerial Vehicle with Nonlinear Inputs Article)
Mrotor = 2.8; %rotorun point mass 
r = 1.02; %dronun yarıçapı 
lr = 1.02; %motorun ağırlık merkezine uzaklığı

I0 = (2/5)*Msphere*r^2 + 2*(lr^2)*Mrotor;  % Ixx≈Iyy
Ixx0 = I0;
Iyy0 = I0;
Izz0 = (2/5)*Msphere*r^2 + 4*(lr^2)*Mrotor;

par0 = [Ixx0, Iyy0, Izz0,  % inertialar
        5.0,  5.0,  5.0,   % sönüm (tune edilmek üzere)
        1.0,  1.0,  1.0];  % PWM→tork ölçekleri

sys0 = idgrey(@bodyrate_model, par0, 'd', Ts)

opt = greyestOptions('EnforceStability',true, 'Display','on');
sys  = greyest(data, sys0, opt, 'InitialState','zero')

compare(data, sys);
