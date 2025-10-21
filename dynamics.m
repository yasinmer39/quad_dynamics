function [A, B, C, D] = drone(I,T)

    A = [0 1 0 0 0 0;
         0 0 0 0 0 0;
         0 0 0 1 0 0;
         0 0 0 0 0 0;
         0 0 0 0 0 1;
         0 0 0 0 0 0];

    B = [0 0 0 0;
         0 1/I(1) 0 0;
         0 0 0 0;
         0 0 1/I(2) 0;
         0 0 0 0;
         0 0 0 1/I(3)];

    C = eye(6); % Define the output matrix C as an identity matrix (y = C x) (xdot = A x + B u) (x [phi phidot theta thetadot psi psidot])
    D = zeros(6,4);

end

lr=0.7;
Ixx=1.1*(4*3*lr^2);
Iyy=1.1*(4*3*lr^2);
Izz=2*Ixx;
I = [Ixx; Iyy; Izz]; % Atalet matrisi
aux = {};
T = 0.0035;

sys_dy = idgrey(@drone, I, 'd', aux, T)

sys = greyest(data, sys_dy)