//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_Controller_data.cpp
//
// Code generated for Simulink model 'Quadcopter_Controller'.
//
// Model version                  : 4.28
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Mon Oct 27 14:33:13 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Quadcopter_Controller.h"

// Block parameters (default storage)
P_Quadcopter_Controller_T Quadcopter_Controller_P = {
  // Mask Parameter: PID_Altitude_D
  //  Referenced by: '<S216>/Derivative Gain'

  0.01,

  // Mask Parameter: PID_vz_D
  //  Referenced by: '<S372>/Derivative Gain'

  0.05,

  // Mask Parameter: PID_x_D
  //  Referenced by: '<S426>/Derivative Gain'

  0.0,

  // Mask Parameter: PID_y_D
  //  Referenced by: '<S480>/Derivative Gain'

  0.0,

  // Mask Parameter: PID_vx_D
  //  Referenced by: '<S268>/Derivative Gain'

  0.0,

  // Mask Parameter: PID_pitch_D
  //  Referenced by: '<S49>/Derivative Gain'

  0.0145948093220339,

  // Mask Parameter: PID_vy_D
  //  Referenced by: '<S320>/Derivative Gain'

  0.0,

  // Mask Parameter: PID_roll_D
  //  Referenced by: '<S101>/Derivative Gain'

  0.015,

  // Mask Parameter: PID_yaw_D
  //  Referenced by: '<S155>/Derivative Gain'

  0.075,

  // Mask Parameter: PID_Altitude_I
  //  Referenced by: '<S220>/Integral Gain'

  0.01,

  // Mask Parameter: PID_vz_I
  //  Referenced by: '<S376>/Integral Gain'

  0.1,

  // Mask Parameter: PID_pitch_I
  //  Referenced by: '<S53>/Integral Gain'

  0.005,

  // Mask Parameter: PID_roll_I
  //  Referenced by: '<S105>/Integral Gain'

  0.005,

  // Mask Parameter: PID_yaw_I
  //  Referenced by: '<S159>/Integral Gain'

  0.0001,

  // Mask Parameter: PID_vx_I
  //  Referenced by: '<S272>/Integral Gain'

  0.01,

  // Mask Parameter: PID_vy_I
  //  Referenced by: '<S324>/Integral Gain'

  0.01,

  // Mask Parameter: PID_x_I
  //  Referenced by: '<S430>/Integral Gain'

  0.0,

  // Mask Parameter: PID_y_I
  //  Referenced by: '<S484>/Integral Gain'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S18>/UD'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionFo
  //  Referenced by: '<S218>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForFilte
  //  Referenced by: '<S374>/Filter'

  0.0,

  // Mask Parameter: PID_x_InitialConditionForFilter
  //  Referenced by: '<S428>/Filter'

  0.0,

  // Mask Parameter: PID_y_InitialConditionForFilter
  //  Referenced by: '<S482>/Filter'

  0.0,

  // Mask Parameter: PID_vx_InitialConditionForFilte
  //  Referenced by: '<S270>/Filter'

  0.0,

  // Mask Parameter: PID_pitch_InitialConditionForFi
  //  Referenced by: '<S51>/Filter'

  0.0,

  // Mask Parameter: PID_vy_InitialConditionForFilte
  //  Referenced by: '<S322>/Filter'

  0.0,

  // Mask Parameter: PID_roll_InitialConditionForFil
  //  Referenced by: '<S103>/Filter'

  0.0,

  // Mask Parameter: PID_yaw_InitialConditionForFilt
  //  Referenced by: '<S157>/Filter'

  0.0,

  // Mask Parameter: PID_Altitude_InitialCondition_j
  //  Referenced by: '<S223>/Integrator'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForInteg
  //  Referenced by: '<S379>/Integrator'

  0.0,

  // Mask Parameter: PID_x_InitialConditionForIntegr
  //  Referenced by: '<S433>/Integrator'

  0.0,

  // Mask Parameter: PID_y_InitialConditionForIntegr
  //  Referenced by: '<S487>/Integrator'

  0.0,

  // Mask Parameter: PID_vx_InitialConditionForInteg
  //  Referenced by: '<S275>/Integrator'

  0.0,

  // Mask Parameter: PID_pitch_InitialConditionForIn
  //  Referenced by: '<S56>/Integrator'

  0.0,

  // Mask Parameter: PID_vy_InitialConditionForInteg
  //  Referenced by: '<S327>/Integrator'

  0.0,

  // Mask Parameter: PID_roll_InitialConditionForInt
  //  Referenced by: '<S108>/Integrator'

  0.0,

  // Mask Parameter: PID_yaw_InitialConditionForInte
  //  Referenced by: '<S162>/Integrator'

  0.0,

  // Mask Parameter: PID_Altitude_LowerSaturationLim
  //  Referenced by:
  //    '<S230>/Saturation'
  //    '<S215>/DeadZone'

  -10.0,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by: '<S386>/Saturation'

  0.0,

  // Mask Parameter: PID_x_LowerSaturationLimit
  //  Referenced by:
  //    '<S440>/Saturation'
  //    '<S425>/DeadZone'

  -20.0,

  // Mask Parameter: PID_y_LowerSaturationLimit
  //  Referenced by:
  //    '<S494>/Saturation'
  //    '<S479>/DeadZone'

  -20.0,

  // Mask Parameter: PID_vx_LowerSaturationLimit
  //  Referenced by: '<S282>/Saturation'

  -50.0,

  // Mask Parameter: PID_pitch_LowerSaturationLimit
  //  Referenced by: '<S63>/Saturation'

  -0.05,

  // Mask Parameter: PID_vy_LowerSaturationLimit
  //  Referenced by: '<S334>/Saturation'

  -50.0,

  // Mask Parameter: PID_roll_LowerSaturationLimit
  //  Referenced by: '<S115>/Saturation'

  -0.05,

  // Mask Parameter: PID_yaw_LowerSaturationLimit
  //  Referenced by:
  //    '<S169>/Saturation'
  //    '<S154>/DeadZone'

  -0.01,

  // Mask Parameter: PID_Altitude_N
  //  Referenced by: '<S226>/Filter Coefficient'

  10.0,

  // Mask Parameter: PID_vz_N
  //  Referenced by: '<S382>/Filter Coefficient'

  10.0,

  // Mask Parameter: PID_x_N
  //  Referenced by: '<S436>/Filter Coefficient'

  1.0,

  // Mask Parameter: PID_y_N
  //  Referenced by: '<S490>/Filter Coefficient'

  1.0,

  // Mask Parameter: PID_vx_N
  //  Referenced by: '<S278>/Filter Coefficient'

  1.0,

  // Mask Parameter: PID_pitch_N
  //  Referenced by: '<S59>/Filter Coefficient'

  50.0,

  // Mask Parameter: PID_vy_N
  //  Referenced by: '<S330>/Filter Coefficient'

  1.0,

  // Mask Parameter: PID_roll_N
  //  Referenced by: '<S111>/Filter Coefficient'

  100.0,

  // Mask Parameter: PID_yaw_N
  //  Referenced by: '<S165>/Filter Coefficient'

  10.0,

  // Mask Parameter: PID_Altitude_P
  //  Referenced by: '<S228>/Proportional Gain'

  2.3,

  // Mask Parameter: PID_vz_P
  //  Referenced by: '<S384>/Proportional Gain'

  0.5,

  // Mask Parameter: PID_x_P
  //  Referenced by: '<S438>/Proportional Gain'

  0.85800438596491224,

  // Mask Parameter: PID_y_P
  //  Referenced by: '<S492>/Proportional Gain'

  0.85,

  // Mask Parameter: PID_vx_P
  //  Referenced by: '<S280>/Proportional Gain'

  4.0,

  // Mask Parameter: PID_pitch_P
  //  Referenced by: '<S61>/Proportional Gain'

  0.027,

  // Mask Parameter: PID_vy_P
  //  Referenced by: '<S332>/Proportional Gain'

  4.0,

  // Mask Parameter: PID_roll_P
  //  Referenced by: '<S113>/Proportional Gain'

  0.03,

  // Mask Parameter: PID_yaw_P
  //  Referenced by: '<S167>/Proportional Gain'

  0.005,

  // Mask Parameter: PID_Altitude_UpperSaturationLim
  //  Referenced by:
  //    '<S230>/Saturation'
  //    '<S215>/DeadZone'

  10.0,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by: '<S386>/Saturation'

  1.0,

  // Mask Parameter: PID_x_UpperSaturationLimit
  //  Referenced by:
  //    '<S440>/Saturation'
  //    '<S425>/DeadZone'

  20.0,

  // Mask Parameter: PID_y_UpperSaturationLimit
  //  Referenced by:
  //    '<S494>/Saturation'
  //    '<S479>/DeadZone'

  20.0,

  // Mask Parameter: PID_vx_UpperSaturationLimit
  //  Referenced by: '<S282>/Saturation'

  50.0,

  // Mask Parameter: PID_pitch_UpperSaturationLimit
  //  Referenced by: '<S63>/Saturation'

  0.05,

  // Mask Parameter: PID_vy_UpperSaturationLimit
  //  Referenced by: '<S334>/Saturation'

  50.0,

  // Mask Parameter: PID_roll_UpperSaturationLimit
  //  Referenced by: '<S115>/Saturation'

  0.05,

  // Mask Parameter: PID_yaw_UpperSaturationLimit
  //  Referenced by:
  //    '<S169>/Saturation'
  //    '<S154>/DeadZone'

  0.01,

  // Mask Parameter: DCM2Ang_tolerance
  //  Referenced by:
  //    '<S536>/Constant'
  //    '<S538>/Constant'

  4.4408920985006262E-16,

  // Mask Parameter: DCM2Ang_action
  //  Referenced by:
  //    '<S515>/Constant'
  //    '<S525>/Constant'
  //    '<S527>/Constant'

  1U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S8>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S4>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S7>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S3>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S6>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S2>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // xyz

    {
      0.0F, 0.0F, 0.0F }
    // xyz_derivative
  },

  // Expression: 1
  //  Referenced by: '<S521>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S522>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S517>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S518>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S527>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S525>/Constant1'

  0.0,

  // Expression: -eye(3)
  //  Referenced by: '<S528>/Bias1'

  { -1.0, -0.0, -0.0, -0.0, -1.0, -0.0, -0.0, -0.0, -1.0 },

  // Expression: -1
  //  Referenced by: '<S529>/Bias'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S152>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S213>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S423>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S477>/Constant1'

  0.0,

  // Expression: [1 -1 1 1;1 1 -1 1;1 -1 -1 -1;1 1 1 -1]
  //  Referenced by: '<S14>/Mixer matrix'

  { 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, -1.0 },

  // Expression: 8.973447131341869
  //  Referenced by: '<S1>/des_alt'

  8.9734471313418691,

  // Expression: -1
  //  Referenced by: '<S1>/Gain'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S213>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S218>/Filter'

  0.01,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S223>/Integrator'

  0.01,

  // Computed Parameter: Integrator_gainval_l
  //  Referenced by: '<S379>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S374>/Filter'

  0.01,

  // Expression: 2
  //  Referenced by: '<S542>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S545>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S540>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S546>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S541>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S544>/Gain'

  2.0,

  // Expression: [1 1 -1]
  //  Referenced by: '<S514>/Gain1'

  { 1.0, 1.0, -1.0 },

  // Expression: [1 1]
  //  Referenced by: '<S514>/Gain2'

  { 1.0, 1.0 },

  // Expression: [-1 1]
  //  Referenced by: '<S514>/Gain3'

  { -1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S1>/x+'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1>/x+'

  0.0,

  // Expression: 2*pi*.125
  //  Referenced by: '<S1>/x+'

  0.78539816339744828,

  // Expression: -pi/2
  //  Referenced by: '<S1>/x+'

  -1.5707963267948966,

  // Computed Parameter: x_Hsin
  //  Referenced by: '<S1>/x+'

  0.0078539008887113342,

  // Computed Parameter: x_HCos
  //  Referenced by: '<S1>/x+'

  0.99996915764478966,

  // Computed Parameter: x_PSin
  //  Referenced by: '<S1>/x+'

  -0.99996915764478966,

  // Computed Parameter: x_PCos
  //  Referenced by: '<S1>/x+'

  -0.0078539008887112283,

  // Expression: 1
  //  Referenced by: '<S1>/X_SwitchOn_Sine Wave'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1>/des_x'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/Switch'

  0.0,

  // Computed Parameter: Integrator_gainval_lq
  //  Referenced by: '<S433>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S428>/Filter'

  0.01,

  // Expression: 1
  //  Referenced by: '<S1>/y+'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1>/y+'

  0.0,

  // Expression: 2*pi*.125
  //  Referenced by: '<S1>/y+'

  0.78539816339744828,

  // Expression: 0
  //  Referenced by: '<S1>/y+'

  0.0,

  // Computed Parameter: y_Hsin
  //  Referenced by: '<S1>/y+'

  0.0078539008887113342,

  // Computed Parameter: y_HCos
  //  Referenced by: '<S1>/y+'

  0.99996915764478966,

  // Computed Parameter: y_PSin
  //  Referenced by: '<S1>/y+'

  -0.0078539008887113342,

  // Computed Parameter: y_PCos
  //  Referenced by: '<S1>/y+'

  0.99996915764478966,

  // Expression: 0
  //  Referenced by: '<S1>/des_y'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/Switch1'

  0.0,

  // Computed Parameter: Integrator_gainval_d
  //  Referenced by: '<S487>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_b
  //  Referenced by: '<S482>/Filter'

  0.01,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S275>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_n
  //  Referenced by: '<S270>/Filter'

  0.01,

  // Expression: pi/180
  //  Referenced by: '<S16>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Integrator_gainval_ld
  //  Referenced by: '<S56>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_k
  //  Referenced by: '<S51>/Filter'

  0.01,

  // Expression: 0.02
  //  Referenced by: '<S12>/Sine Wave Function'

  0.02,

  // Expression: 0
  //  Referenced by: '<S12>/Sine Wave Function'

  0.0,

  // Expression: 0.0628
  //  Referenced by: '<S12>/Sine Wave Function'

  0.0628,

  // Expression: 0
  //  Referenced by: '<S12>/Sine Wave Function'

  0.0,

  // Computed Parameter: SineWaveFunction_Hsin
  //  Referenced by: '<S12>/Sine Wave Function'

  0.00062799995872114215,

  // Computed Parameter: SineWaveFunction_HCos
  //  Referenced by: '<S12>/Sine Wave Function'

  0.99999980280800649,

  // Computed Parameter: SineWaveFunction_PSin
  //  Referenced by: '<S12>/Sine Wave Function'

  -0.00062799995872114215,

  // Computed Parameter: SineWaveFunction_PCos
  //  Referenced by: '<S12>/Sine Wave Function'

  0.99999980280800649,

  // Expression: [46.6 -46.6]
  //  Referenced by: '<S12>/Discrete Filter'

  { 46.6, -46.6 },

  // Expression: [1 -0.534 0]
  //  Referenced by: '<S12>/Discrete Filter'

  { 1.0, -0.534, 0.0 },

  // Expression: 0
  //  Referenced by: '<S12>/Discrete Filter'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S18>/TSamp'

  100.0,

  // Expression: 0.0003
  //  Referenced by: '<S12>/Gain'

  0.0003,

  // Expression: 0
  //  Referenced by: '<S12>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/Delay'

  0.0,

  // Computed Parameter: Integrator_gainval_o
  //  Referenced by: '<S327>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S322>/Filter'

  0.01,

  // Expression: -1
  //  Referenced by: '<S13>/Gain'

  -1.0,

  // Expression: pi/180
  //  Referenced by: '<S17>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Integrator_gainval_e1
  //  Referenced by: '<S108>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_j
  //  Referenced by: '<S103>/Filter'

  0.01,

  // Expression: 0
  //  Referenced by: '<S1>/des_yaw'

  0.0,

  // Expression: pi/180
  //  Referenced by: '<S15>/Gain1'

  0.017453292519943295,

  // Expression: 0
  //  Referenced by: '<S152>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S157>/Filter'

  0.01,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S162>/Integrator'

  0.01,

  // Expression: 1
  //  Referenced by: '<S14>/Saturation'

  1.0,

  // Expression: 0
  //  Referenced by: '<S14>/Saturation'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S10>/Gain'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S10>/Constant'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S423>/Clamping_zero'

  0.0,

  // Expression: 0
  //  Referenced by: '<S477>/Clamping_zero'

  0.0,

  // Computed Parameter: Assertion_Enabled
  //  Referenced by: '<S535>/Assertion'

  true,

  // Computed Parameter: Assertion_Enabled_e
  //  Referenced by: '<S533>/Assertion'

  true,

  // Computed Parameter: Assertion_Enabled_l
  //  Referenced by: '<S532>/Assertion'

  true,

  // Computed Parameter: Assertion_Enabled_c
  //  Referenced by: '<S530>/Assertion'

  true,

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S5>/Constant'

  true,

  // Computed Parameter: Constant_Value_nq
  //  Referenced by: '<S152>/Constant'

  1,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<S152>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value
  //  Referenced by: '<S152>/Constant3'

  1,

  // Computed Parameter: Constant4_Value
  //  Referenced by: '<S152>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S213>/Constant'

  1,

  // Computed Parameter: Constant2_Value_c
  //  Referenced by: '<S213>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_e
  //  Referenced by: '<S213>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_o
  //  Referenced by: '<S213>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S423>/Constant'

  1,

  // Computed Parameter: Constant2_Value_j
  //  Referenced by: '<S423>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_c
  //  Referenced by: '<S423>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_g
  //  Referenced by: '<S423>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_b5
  //  Referenced by: '<S477>/Constant'

  1,

  // Computed Parameter: Constant2_Value_a
  //  Referenced by: '<S477>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_k
  //  Referenced by: '<S477>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_k
  //  Referenced by: '<S477>/Constant4'

  -1
};

//
// File trailer for generated code.
//
// [EOF]
//
