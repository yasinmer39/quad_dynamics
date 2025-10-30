%% Monitor and Tune PX4 Host Target Flight Controller with Simulink-Based Plant Model
% This example shows how to use the UAV Toolbox Support Package for PX4
% Autopilots to verify the controller design using PX4 Host Target versus the simulator designed in Simulink(R).
%
% The UAV Toolbox Support Package for PX4 Autopilots enables you to use Simulink to design a flight controller algorithm to stabilize the vehicle based on the 
% current vehicle attitude, position, and velocity and also track the desired attitude using Simulink. The MAVlink blocks in the UAV Toolbox enable you to read and write the 
% MAVLink HIL_* messages and design the plant dynamics. 
%
% This example shows how to validate a position controller design on a medium-sized quadrotor plant using a single Simulink model, and then take the same controller 
% and plant model and simulate it with the PX4 source code in, what the PX4 community calls it, Software In The Loop (SITL) simulation.

% Copyright 2022 -2024 The MathWorks, Inc.

%% Prerequisites
%
% * If you are new to Simulink, watch the   
% <https://www.mathworks.com/videos/simulink-quick-start-78774.html Simulink Quick Start> video.
%
% * Perform the initial <docid:uav_doccenter#mw_536a8bb9-a780-45b4-9ed5-5d4aa47126d8 setup and configuration tasks> of the 
% support package using Hardware Setup screens. In the *Select a PX4 Autopilot and Build Target* screen, select |PX4 Host Target| as the PX4 Autopilot board from the drop-down list.
%
% <<../px_sitl_hwsetup.png>>
% 
% * For more information on how to verify the controller design using the jMAVSim simulator, 
% see <docid:px4_ug#mw_e3a8839f-ac1c-401c-8e25-fb70f0636df8 Deployment and Verification Using PX4 Host Target and jMAVSim> and <docid:px4_ref#mw_81df3540-d3b2-4e98-b574-af303a7fd41e>. 
%
% * For more information on designing the controller model and verifying it using the simulator plant model designed in Simulink, 
% see <docid:px4_ug#mw_19d9a55f-a164-4ed1-813f-3c5169a4dc6e>.
%  
%% Model
% To get started, launch the Simulink
% <matlab:openExample('px4/MonitorTunePX4HostTargetFlightPlantModelExample') Px4DemoHostTargetWithSimulinkPlant> project.
%
%% Model Architecture and Conventions
% This project consists of the following models:
%
% * The |Quadcopter_controller| is the harness model that contains the flight controller. The model is set up to run with the PX4 source code by creating a PX4 Host Target executable.
%
% * The |Quad_UAV_dynamics| harness model contains the UAV plant dynamics. This harness model is set up to run in normal simulation pacing mode in lockstep with the |Quadcopter_controller| harness model.
%
% The Project shortcuts guide you through the three tasks as you progress
% through the example.
% 
% <<../px_sitl_project_shortcuts.png>>
%
%% Task 1: Deploy Controller as Host Target and Run Plant Model in Simulink
% In this task, we use the controller designed in Task 1 and run it with
% PX4 source code using the PX4 Host Target feature (for more information,
% see <docid:px4_ug#mw_19d9a55f-a164-4ed1-813f-3c5169a4dc6e>). Use two separate instances of MATLAB to run controller and plant model. 
%
% *Step 1: Deploy Quad controller on Host Target*
%
% *1.* Click *Step 1: Deploy Quad controller on Host Target*  in the Project Shortcuts tab to open the |Quadcopter_controller | model.
%
% <<../px4_open_prj_step1.png>>
%
% <<../px_sitl_flightcontroller_top.png>>
%        
%
% The uORB Read blocks are used to subscribe to the |vehicle_local_position| and |vehicle_attitude| topics. 
% These topics contain data sent by the simulator plant model using HIL_STATE_QUATERNION and HIL_GPS messages.
%
% The Controller subsystem designs the Rate controller and the Position and Attitude controller as explained in <docid:px4_ref#mw_81df3540-d3b2-4e98-b574-af303a7fd41e>.
% 
% The |FlightController| model outputs the actuator values that are then fed to the PX4 PWM Output block.
%
% *2.* Copy the MATLAB Project Path to clipboard. 
%
% <<../px4_project_path.png>>
% 
% *Step 2: Launch Simulink Plant model in second MATLAB*
%
% *1.* Open the second instance of the same MATLAB version. 
%
% *2.* Navigate to the project path previously copied in current MATLAB. 
%
% <<../px4_path_copied.png>>
% 
% *3.* Click on the |.prj| file to launch the same Project in current MATLAB.
%
% <<../px4_open_prj.png>>
% 
% *4.* Click *Step 2: Run Quad dynamics simulation* in the Project
% Shortcuts tab to open the |Quad_UAV_dynamics| model.
%
% <<../px4_open_prj_step2.png>>
%
% <<../px4_quadmodel.png>>
%
%
% Ensure that the *Simulation Pacing* option for this model is enabled, as described in <docid:px4_ug#mw_19d9a55f-a164-4ed1-813f-3c5169a4dc6e>.
%
% The |TCP read from PX4 Host Target| MATLAB System block is used to read the MAVLink data sent from the |px4Demo_FlightController_top| model. 
%
% The Enabled subsystem has the MAVLink Deserializer block that extracts the HIL_ACTUATOR_CONTROLS message.
%
% <<../px_sitl_enabled_ss.png>>
% 
% The |TCP write to PX4 Host Target| MATLAB System block sends the HIL_SENSOR, HIL_GPS, and HIL_STATE_QUATERNION MAVLink messages to the |px4Demo_FlightController_top| model.
%
% *Step 3: Deploy controller model over Monitor & Tune and run Plant
% Simulation*
%
% *1.* In Configuration parameters > Hardware Implementation, set the *Hardware board* parameter to |PX4 Host Target|.
%
% *2.* Under *Target hardware resources* > *Build Options*, set *Simulator* to |Simulink|.
%
% *3.* In the *Simulation* tab, set the Simulation *Stop time* to _inf_.
%
% *4.* On the *Hardware* tab, in the *Mode* section, select *Run on board* and then click *Monitor & Tune* to start signal monitoring and parameter tuning.
%
% *5.* Wait for Simulink to complete the code generation. The following dialog box appears. *Do not click OK yet*.   
%
% <<../px_sitl_startplant.png>>
% 
% In the plant model launched in second MATLAB, follow the below steps.
%
% *1.* In the *Simulation* tab, set the Simulation *Stop Time* to _inf_.
%
% *2.* Click *Run* on the *Simulation* Tab.
%
% <<../px_sitl_run.png>>
%  
% After the simulation starts in the plant model, click *OK* in the dialog box of the first model. 
%
