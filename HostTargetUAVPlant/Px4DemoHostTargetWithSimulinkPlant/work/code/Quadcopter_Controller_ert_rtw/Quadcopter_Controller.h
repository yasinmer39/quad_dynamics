//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_Controller.h
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
#ifndef Quadcopter_Controller_h_
#define Quadcopter_Controller_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "Quadcopter_Controller_types.h"
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_angular_velocity.h>

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
struct B_Quadcopter_Controller_T {
  px4_Bus_vehicle_local_position In1;  // '<S8>/In1'
  px4_Bus_vehicle_local_position r;
  real_T VectorConcatenate[9];         // '<S548>/Vector Concatenate'
  real_T rtb_VectorConcatenate_m[9];
  px4_Bus_vehicle_attitude In1_b;      // '<S7>/In1'
  px4_Bus_vehicle_attitude r1;
  px4_Bus_vehicle_angular_velocity In1_k;// '<S6>/In1'
  px4_Bus_vehicle_angular_velocity r2;
  real_T dv[4];
  real_T DataTypeConversion[3];        // '<S506>/Data Type Conversion'
  uint16_T pwmValue[8];
  boolean_T Compare[9];                // '<S536>/Compare'
  real_T des_alt;                      // '<S1>/des_alt'
  real_T x;                            // '<S1>/x+'
  real_T y;                            // '<S1>/y+'
  real_T Product2;                     // '<S12>/Product2'
  real_T DeadZone_n;                   // '<S425>/DeadZone'
  real_T Saturation_g;                 // '<S386>/Saturation'
  real_T FilterCoefficient;            // '<S226>/Filter Coefficient'
  real_T Filter_f;                     // '<S374>/Filter'
  real_T Filter_l;                     // '<S428>/Filter'
  real_T Integrator_l;                 // '<S433>/Integrator'
  real_T IntegralGain_j;               // '<S430>/Integral Gain'
  real_T FilterCoefficient_p;          // '<S490>/Filter Coefficient'
  real_T DeadZone;                     // '<S479>/DeadZone'
  real_T Filter_hc;                    // '<S51>/Filter'
  real_T FilterCoefficient_db;         // '<S278>/Filter Coefficient'
  real_T Saturation;                   // '<S282>/Saturation'
  real_T TSamp;                        // '<S18>/TSamp'
  real_T Filter_o;                     // '<S103>/Filter'
  real_T DigitalClock;                 // '<S12>/Digital Clock'
  real_T FilterCoefficient_f;          // '<S330>/Filter Coefficient'
  real_T IntegralGain_o;               // '<S159>/Integral Gain'
  real_T Saturation_l;                 // '<S169>/Saturation'
  real_T DeadZone_l;                   // '<S154>/DeadZone'
  real_T rtb_Merge_idx_1;
  boolean_T NOT;                       // '<S3>/NOT'
  boolean_T NOT_n;                     // '<S4>/NOT'
  boolean_T NOT_h;                     // '<S2>/NOT'
};

// Block states (default storage) for system '<Root>'
struct DW_Quadcopter_Controller_T {
  px4_internal_block_Subscriber_T obj; // '<S4>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S3>/SourceBlock'
  px4_internal_block_Subscriber_T obj_c;// '<S2>/SourceBlock'
  px4_internal_block_PWM_Quadco_T obj_n;// '<Root>/PX4 PWM Output'
  real_T Filter_DSTATE;                // '<S218>/Filter'
  real_T Integrator_DSTATE;            // '<S223>/Integrator'
  real_T Integrator_DSTATE_k;          // '<S379>/Integrator'
  real_T Filter_DSTATE_b;              // '<S374>/Filter'
  real_T Integrator_DSTATE_b;          // '<S433>/Integrator'
  real_T Filter_DSTATE_f;              // '<S428>/Filter'
  real_T Integrator_DSTATE_j;          // '<S487>/Integrator'
  real_T Filter_DSTATE_j;              // '<S482>/Filter'
  real_T Integrator_DSTATE_f;          // '<S275>/Integrator'
  real_T Filter_DSTATE_o;              // '<S270>/Filter'
  real_T Integrator_DSTATE_o;          // '<S56>/Integrator'
  real_T Filter_DSTATE_ox;             // '<S51>/Filter'
  real_T DiscreteFilter_states[2];     // '<S12>/Discrete Filter'
  real_T UD_DSTATE;                    // '<S18>/UD'
  real_T Delay1_DSTATE;                // '<S12>/Delay1'
  real_T Delay_DSTATE;                 // '<S12>/Delay'
  real_T Integrator_DSTATE_jo;         // '<S327>/Integrator'
  real_T Filter_DSTATE_oxe;            // '<S322>/Filter'
  real_T Integrator_DSTATE_m;          // '<S108>/Integrator'
  real_T Filter_DSTATE_d;              // '<S103>/Filter'
  real_T Filter_DSTATE_k;              // '<S157>/Filter'
  real_T Integrator_DSTATE_i;          // '<S162>/Integrator'
  real_T lastSin;                      // '<S1>/x+'
  real_T lastCos;                      // '<S1>/x+'
  real_T lastSin_k;                    // '<S1>/y+'
  real_T lastCos_e;                    // '<S1>/y+'
  real_T lastSin_l;                    // '<S12>/Sine Wave Function'
  real_T lastCos_b;                    // '<S12>/Sine Wave Function'
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S12>/Scope'

  int32_T systemEnable;                // '<S1>/x+'
  int32_T systemEnable_e;              // '<S1>/y+'
  int32_T systemEnable_f;              // '<S12>/Sine Wave Function'
  int8_T IfWarningError_SubsysRanBC;   // '<S515>/If Warning//Error'
  int8_T ElseNoAction_SubsysRanBC;     // '<S524>/Else No Action'
  int8_T ElseIfNotOrthogonal_SubsysRanBC;// '<S524>/Else If Not Orthogonal'
  int8_T None_SubsysRanBC;             // '<S525>/None'
  int8_T Error_SubsysRanBC;            // '<S525>/Error'
  int8_T Warning_SubsysRanBC;          // '<S525>/Warning'
  int8_T IfNotProper_SubsysRanBC;      // '<S524>/If Not Proper'
  int8_T None_SubsysRanBC_a;           // '<S527>/None'
  int8_T Error_SubsysRanBC_f;          // '<S527>/Error'
  int8_T Warning_SubsysRanBC_f;        // '<S527>/Warning'
  int8_T AxisRotDefault_SubsysRanBC;   // '<S510>/AxisRotDefault'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S516>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S516>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S516>/If Action Subsystem'
  int8_T AxisRotZeroR3_SubsysRanBC;    // '<S510>/AxisRotZeroR3'
  int8_T IfActionSubsystem2_SubsysRanB_g;// '<S520>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_j;// '<S520>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_g;// '<S520>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S4>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S3>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_o;// '<S2>/Enabled Subsystem'
  boolean_T doneDoubleBufferReInit;    // '<S13>/Rotation mat '
};

// Parameters (default storage)
struct P_Quadcopter_Controller_T_ {
  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S216>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S372>/Derivative Gain'

  real_T PID_x_D;                      // Mask Parameter: PID_x_D
                                          //  Referenced by: '<S426>/Derivative Gain'

  real_T PID_y_D;                      // Mask Parameter: PID_y_D
                                          //  Referenced by: '<S480>/Derivative Gain'

  real_T PID_vx_D;                     // Mask Parameter: PID_vx_D
                                          //  Referenced by: '<S268>/Derivative Gain'

  real_T PID_pitch_D;                  // Mask Parameter: PID_pitch_D
                                          //  Referenced by: '<S49>/Derivative Gain'

  real_T PID_vy_D;                     // Mask Parameter: PID_vy_D
                                          //  Referenced by: '<S320>/Derivative Gain'

  real_T PID_roll_D;                   // Mask Parameter: PID_roll_D
                                          //  Referenced by: '<S101>/Derivative Gain'

  real_T PID_yaw_D;                    // Mask Parameter: PID_yaw_D
                                          //  Referenced by: '<S155>/Derivative Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S220>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S376>/Integral Gain'

  real_T PID_pitch_I;                  // Mask Parameter: PID_pitch_I
                                          //  Referenced by: '<S53>/Integral Gain'

  real_T PID_roll_I;                   // Mask Parameter: PID_roll_I
                                          //  Referenced by: '<S105>/Integral Gain'

  real_T PID_yaw_I;                    // Mask Parameter: PID_yaw_I
                                          //  Referenced by: '<S159>/Integral Gain'

  real_T PID_vx_I;                     // Mask Parameter: PID_vx_I
                                          //  Referenced by: '<S272>/Integral Gain'

  real_T PID_vy_I;                     // Mask Parameter: PID_vy_I
                                          //  Referenced by: '<S324>/Integral Gain'

  real_T PID_x_I;                      // Mask Parameter: PID_x_I
                                          //  Referenced by: '<S430>/Integral Gain'

  real_T PID_y_I;                      // Mask Parameter: PID_y_I
                                          //  Referenced by: '<S484>/Integral Gain'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S18>/UD'

  real_T PID_Altitude_InitialConditionFo;
                              // Mask Parameter: PID_Altitude_InitialConditionFo
                                 //  Referenced by: '<S218>/Filter'

  real_T PID_vz_InitialConditionForFilte;
                              // Mask Parameter: PID_vz_InitialConditionForFilte
                                 //  Referenced by: '<S374>/Filter'

  real_T PID_x_InitialConditionForFilter;
                              // Mask Parameter: PID_x_InitialConditionForFilter
                                 //  Referenced by: '<S428>/Filter'

  real_T PID_y_InitialConditionForFilter;
                              // Mask Parameter: PID_y_InitialConditionForFilter
                                 //  Referenced by: '<S482>/Filter'

  real_T PID_vx_InitialConditionForFilte;
                              // Mask Parameter: PID_vx_InitialConditionForFilte
                                 //  Referenced by: '<S270>/Filter'

  real_T PID_pitch_InitialConditionForFi;
                              // Mask Parameter: PID_pitch_InitialConditionForFi
                                 //  Referenced by: '<S51>/Filter'

  real_T PID_vy_InitialConditionForFilte;
                              // Mask Parameter: PID_vy_InitialConditionForFilte
                                 //  Referenced by: '<S322>/Filter'

  real_T PID_roll_InitialConditionForFil;
                              // Mask Parameter: PID_roll_InitialConditionForFil
                                 //  Referenced by: '<S103>/Filter'

  real_T PID_yaw_InitialConditionForFilt;
                              // Mask Parameter: PID_yaw_InitialConditionForFilt
                                 //  Referenced by: '<S157>/Filter'

  real_T PID_Altitude_InitialCondition_j;
                              // Mask Parameter: PID_Altitude_InitialCondition_j
                                 //  Referenced by: '<S223>/Integrator'

  real_T PID_vz_InitialConditionForInteg;
                              // Mask Parameter: PID_vz_InitialConditionForInteg
                                 //  Referenced by: '<S379>/Integrator'

  real_T PID_x_InitialConditionForIntegr;
                              // Mask Parameter: PID_x_InitialConditionForIntegr
                                 //  Referenced by: '<S433>/Integrator'

  real_T PID_y_InitialConditionForIntegr;
                              // Mask Parameter: PID_y_InitialConditionForIntegr
                                 //  Referenced by: '<S487>/Integrator'

  real_T PID_vx_InitialConditionForInteg;
                              // Mask Parameter: PID_vx_InitialConditionForInteg
                                 //  Referenced by: '<S275>/Integrator'

  real_T PID_pitch_InitialConditionForIn;
                              // Mask Parameter: PID_pitch_InitialConditionForIn
                                 //  Referenced by: '<S56>/Integrator'

  real_T PID_vy_InitialConditionForInteg;
                              // Mask Parameter: PID_vy_InitialConditionForInteg
                                 //  Referenced by: '<S327>/Integrator'

  real_T PID_roll_InitialConditionForInt;
                              // Mask Parameter: PID_roll_InitialConditionForInt
                                 //  Referenced by: '<S108>/Integrator'

  real_T PID_yaw_InitialConditionForInte;
                              // Mask Parameter: PID_yaw_InitialConditionForInte
                                 //  Referenced by: '<S162>/Integrator'

  real_T PID_Altitude_LowerSaturationLim;
                              // Mask Parameter: PID_Altitude_LowerSaturationLim
                                 //  Referenced by:
                                 //    '<S230>/Saturation'
                                 //    '<S215>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by: '<S386>/Saturation'

  real_T PID_x_LowerSaturationLimit;
                                   // Mask Parameter: PID_x_LowerSaturationLimit
                                      //  Referenced by:
                                      //    '<S440>/Saturation'
                                      //    '<S425>/DeadZone'

  real_T PID_y_LowerSaturationLimit;
                                   // Mask Parameter: PID_y_LowerSaturationLimit
                                      //  Referenced by:
                                      //    '<S494>/Saturation'
                                      //    '<S479>/DeadZone'

  real_T PID_vx_LowerSaturationLimit;
                                  // Mask Parameter: PID_vx_LowerSaturationLimit
                                     //  Referenced by: '<S282>/Saturation'

  real_T PID_pitch_LowerSaturationLimit;
                               // Mask Parameter: PID_pitch_LowerSaturationLimit
                                  //  Referenced by: '<S63>/Saturation'

  real_T PID_vy_LowerSaturationLimit;
                                  // Mask Parameter: PID_vy_LowerSaturationLimit
                                     //  Referenced by: '<S334>/Saturation'

  real_T PID_roll_LowerSaturationLimit;
                                // Mask Parameter: PID_roll_LowerSaturationLimit
                                   //  Referenced by: '<S115>/Saturation'

  real_T PID_yaw_LowerSaturationLimit;
                                 // Mask Parameter: PID_yaw_LowerSaturationLimit
                                    //  Referenced by:
                                    //    '<S169>/Saturation'
                                    //    '<S154>/DeadZone'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S226>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S382>/Filter Coefficient'

  real_T PID_x_N;                      // Mask Parameter: PID_x_N
                                          //  Referenced by: '<S436>/Filter Coefficient'

  real_T PID_y_N;                      // Mask Parameter: PID_y_N
                                          //  Referenced by: '<S490>/Filter Coefficient'

  real_T PID_vx_N;                     // Mask Parameter: PID_vx_N
                                          //  Referenced by: '<S278>/Filter Coefficient'

  real_T PID_pitch_N;                  // Mask Parameter: PID_pitch_N
                                          //  Referenced by: '<S59>/Filter Coefficient'

  real_T PID_vy_N;                     // Mask Parameter: PID_vy_N
                                          //  Referenced by: '<S330>/Filter Coefficient'

  real_T PID_roll_N;                   // Mask Parameter: PID_roll_N
                                          //  Referenced by: '<S111>/Filter Coefficient'

  real_T PID_yaw_N;                    // Mask Parameter: PID_yaw_N
                                          //  Referenced by: '<S165>/Filter Coefficient'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S228>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S384>/Proportional Gain'

  real_T PID_x_P;                      // Mask Parameter: PID_x_P
                                          //  Referenced by: '<S438>/Proportional Gain'

  real_T PID_y_P;                      // Mask Parameter: PID_y_P
                                          //  Referenced by: '<S492>/Proportional Gain'

  real_T PID_vx_P;                     // Mask Parameter: PID_vx_P
                                          //  Referenced by: '<S280>/Proportional Gain'

  real_T PID_pitch_P;                  // Mask Parameter: PID_pitch_P
                                          //  Referenced by: '<S61>/Proportional Gain'

  real_T PID_vy_P;                     // Mask Parameter: PID_vy_P
                                          //  Referenced by: '<S332>/Proportional Gain'

  real_T PID_roll_P;                   // Mask Parameter: PID_roll_P
                                          //  Referenced by: '<S113>/Proportional Gain'

  real_T PID_yaw_P;                    // Mask Parameter: PID_yaw_P
                                          //  Referenced by: '<S167>/Proportional Gain'

  real_T PID_Altitude_UpperSaturationLim;
                              // Mask Parameter: PID_Altitude_UpperSaturationLim
                                 //  Referenced by:
                                 //    '<S230>/Saturation'
                                 //    '<S215>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by: '<S386>/Saturation'

  real_T PID_x_UpperSaturationLimit;
                                   // Mask Parameter: PID_x_UpperSaturationLimit
                                      //  Referenced by:
                                      //    '<S440>/Saturation'
                                      //    '<S425>/DeadZone'

  real_T PID_y_UpperSaturationLimit;
                                   // Mask Parameter: PID_y_UpperSaturationLimit
                                      //  Referenced by:
                                      //    '<S494>/Saturation'
                                      //    '<S479>/DeadZone'

  real_T PID_vx_UpperSaturationLimit;
                                  // Mask Parameter: PID_vx_UpperSaturationLimit
                                     //  Referenced by: '<S282>/Saturation'

  real_T PID_pitch_UpperSaturationLimit;
                               // Mask Parameter: PID_pitch_UpperSaturationLimit
                                  //  Referenced by: '<S63>/Saturation'

  real_T PID_vy_UpperSaturationLimit;
                                  // Mask Parameter: PID_vy_UpperSaturationLimit
                                     //  Referenced by: '<S334>/Saturation'

  real_T PID_roll_UpperSaturationLimit;
                                // Mask Parameter: PID_roll_UpperSaturationLimit
                                   //  Referenced by: '<S115>/Saturation'

  real_T PID_yaw_UpperSaturationLimit;
                                 // Mask Parameter: PID_yaw_UpperSaturationLimit
                                    //  Referenced by:
                                    //    '<S169>/Saturation'
                                    //    '<S154>/DeadZone'

  real_T DCM2Ang_tolerance;            // Mask Parameter: DCM2Ang_tolerance
                                          //  Referenced by:
                                          //    '<S536>/Constant'
                                          //    '<S538>/Constant'

  uint8_T DCM2Ang_action;              // Mask Parameter: DCM2Ang_action
                                          //  Referenced by:
                                          //    '<S515>/Constant'
                                          //    '<S525>/Constant'
                                          //    '<S527>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S8>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S4>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_o;  // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S7>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S3>/Constant'

  px4_Bus_vehicle_angular_velocity Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                                //  Referenced by: '<S6>/Out1'

  px4_Bus_vehicle_angular_velocity Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                       //  Referenced by: '<S2>/Constant'

  real_T Constant_Value_g;             // Expression: 1
                                          //  Referenced by: '<S521>/Constant'

  real_T Constant_Value_p;             // Expression: 1
                                          //  Referenced by: '<S522>/Constant'

  real_T Constant_Value_j;             // Expression: 1
                                          //  Referenced by: '<S517>/Constant'

  real_T Constant_Value_hj;            // Expression: 1
                                          //  Referenced by: '<S518>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S527>/Constant1'

  real_T Constant1_Value_d;            // Expression: 0
                                          //  Referenced by: '<S525>/Constant1'

  real_T Bias1_Bias[9];                // Expression: -eye(3)
                                          //  Referenced by: '<S528>/Bias1'

  real_T Bias_Bias;                    // Expression: -1
                                          //  Referenced by: '<S529>/Bias'

  real_T Constant1_Value_c;            // Expression: 0
                                          //  Referenced by: '<S152>/Constant1'

  real_T Constant1_Value_p;            // Expression: 0
                                          //  Referenced by: '<S213>/Constant1'

  real_T Constant1_Value_ck;           // Expression: 0
                                          //  Referenced by: '<S423>/Constant1'

  real_T Constant1_Value_cm;           // Expression: 0
                                          //  Referenced by: '<S477>/Constant1'

  real_T Mixermatrix_Value[16];
                          // Expression: [1 -1 1 1;1 1 -1 1;1 -1 -1 -1;1 1 1 -1]
                             //  Referenced by: '<S14>/Mixer matrix'

  real_T des_alt_Value;                // Expression: 8.973447131341869
                                          //  Referenced by: '<S1>/des_alt'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S1>/Gain'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S213>/Clamping_zero'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S218>/Filter'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S223>/Integrator'

  real_T Integrator_gainval_l;       // Computed Parameter: Integrator_gainval_l
                                        //  Referenced by: '<S379>/Integrator'

  real_T Filter_gainval_d;             // Computed Parameter: Filter_gainval_d
                                          //  Referenced by: '<S374>/Filter'

  real_T Gain_Gain_f;                  // Expression: 2
                                          //  Referenced by: '<S542>/Gain'

  real_T Gain_Gain_o;                  // Expression: 2
                                          //  Referenced by: '<S545>/Gain'

  real_T Gain_Gain_a;                  // Expression: 2
                                          //  Referenced by: '<S540>/Gain'

  real_T Gain_Gain_ff;                 // Expression: 2
                                          //  Referenced by: '<S546>/Gain'

  real_T Gain_Gain_n;                  // Expression: 2
                                          //  Referenced by: '<S541>/Gain'

  real_T Gain_Gain_l;                  // Expression: 2
                                          //  Referenced by: '<S544>/Gain'

  real_T Gain1_Gain[3];                // Expression: [1 1 -1]
                                          //  Referenced by: '<S514>/Gain1'

  real_T Gain2_Gain[2];                // Expression: [1 1]
                                          //  Referenced by: '<S514>/Gain2'

  real_T Gain3_Gain[2];                // Expression: [-1 1]
                                          //  Referenced by: '<S514>/Gain3'

  real_T x_Amp;                        // Expression: 1
                                          //  Referenced by: '<S1>/x+'

  real_T x_Bias;                       // Expression: 0
                                          //  Referenced by: '<S1>/x+'

  real_T x_Freq;                       // Expression: 2*pi*.125
                                          //  Referenced by: '<S1>/x+'

  real_T x_Phase;                      // Expression: -pi/2
                                          //  Referenced by: '<S1>/x+'

  real_T x_Hsin;                       // Computed Parameter: x_Hsin
                                          //  Referenced by: '<S1>/x+'

  real_T x_HCos;                       // Computed Parameter: x_HCos
                                          //  Referenced by: '<S1>/x+'

  real_T x_PSin;                       // Computed Parameter: x_PSin
                                          //  Referenced by: '<S1>/x+'

  real_T x_PCos;                       // Computed Parameter: x_PCos
                                          //  Referenced by: '<S1>/x+'

  real_T X_SwitchOn_SineWave_Value;    // Expression: 1
                                          //  Referenced by: '<S1>/X_SwitchOn_Sine Wave'

  real_T des_x_Value;                  // Expression: 0
                                          //  Referenced by: '<S1>/des_x'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S1>/Switch'

  real_T Integrator_gainval_lq;     // Computed Parameter: Integrator_gainval_lq
                                       //  Referenced by: '<S433>/Integrator'

  real_T Filter_gainval_p;             // Computed Parameter: Filter_gainval_p
                                          //  Referenced by: '<S428>/Filter'

  real_T y_Amp;                        // Expression: 1
                                          //  Referenced by: '<S1>/y+'

  real_T y_Bias;                       // Expression: 0
                                          //  Referenced by: '<S1>/y+'

  real_T y_Freq;                       // Expression: 2*pi*.125
                                          //  Referenced by: '<S1>/y+'

  real_T y_Phase;                      // Expression: 0
                                          //  Referenced by: '<S1>/y+'

  real_T y_Hsin;                       // Computed Parameter: y_Hsin
                                          //  Referenced by: '<S1>/y+'

  real_T y_HCos;                       // Computed Parameter: y_HCos
                                          //  Referenced by: '<S1>/y+'

  real_T y_PSin;                       // Computed Parameter: y_PSin
                                          //  Referenced by: '<S1>/y+'

  real_T y_PCos;                       // Computed Parameter: y_PCos
                                          //  Referenced by: '<S1>/y+'

  real_T des_y_Value;                  // Expression: 0
                                          //  Referenced by: '<S1>/des_y'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S1>/Switch1'

  real_T Integrator_gainval_d;       // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S487>/Integrator'

  real_T Filter_gainval_b;             // Computed Parameter: Filter_gainval_b
                                          //  Referenced by: '<S482>/Filter'

  real_T Integrator_gainval_e;       // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S275>/Integrator'

  real_T Filter_gainval_n;             // Computed Parameter: Filter_gainval_n
                                          //  Referenced by: '<S270>/Filter'

  real_T Gain1_Gain_c;                 // Expression: pi/180
                                          //  Referenced by: '<S16>/Gain1'

  real_T Integrator_gainval_ld;     // Computed Parameter: Integrator_gainval_ld
                                       //  Referenced by: '<S56>/Integrator'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                          //  Referenced by: '<S51>/Filter'

  real_T SineWaveFunction_Amp;         // Expression: 0.02
                                          //  Referenced by: '<S12>/Sine Wave Function'

  real_T SineWaveFunction_Bias;        // Expression: 0
                                          //  Referenced by: '<S12>/Sine Wave Function'

  real_T SineWaveFunction_Freq;        // Expression: 0.0628
                                          //  Referenced by: '<S12>/Sine Wave Function'

  real_T SineWaveFunction_Phase;       // Expression: 0
                                          //  Referenced by: '<S12>/Sine Wave Function'

  real_T SineWaveFunction_Hsin;     // Computed Parameter: SineWaveFunction_Hsin
                                       //  Referenced by: '<S12>/Sine Wave Function'

  real_T SineWaveFunction_HCos;     // Computed Parameter: SineWaveFunction_HCos
                                       //  Referenced by: '<S12>/Sine Wave Function'

  real_T SineWaveFunction_PSin;     // Computed Parameter: SineWaveFunction_PSin
                                       //  Referenced by: '<S12>/Sine Wave Function'

  real_T SineWaveFunction_PCos;     // Computed Parameter: SineWaveFunction_PCos
                                       //  Referenced by: '<S12>/Sine Wave Function'

  real_T DiscreteFilter_NumCoef[2];    // Expression: [46.6 -46.6]
                                          //  Referenced by: '<S12>/Discrete Filter'

  real_T DiscreteFilter_DenCoef[3];    // Expression: [1 -0.534 0]
                                          //  Referenced by: '<S12>/Discrete Filter'

  real_T DiscreteFilter_InitialStates; // Expression: 0
                                          //  Referenced by: '<S12>/Discrete Filter'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S18>/TSamp'

  real_T Gain_Gain_fr;                 // Expression: 0.0003
                                          //  Referenced by: '<S12>/Gain'

  real_T Delay1_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S12>/Delay1'

  real_T Delay_InitialCondition;       // Expression: 0
                                          //  Referenced by: '<S12>/Delay'

  real_T Integrator_gainval_o;       // Computed Parameter: Integrator_gainval_o
                                        //  Referenced by: '<S327>/Integrator'

  real_T Filter_gainval_l;             // Computed Parameter: Filter_gainval_l
                                          //  Referenced by: '<S322>/Filter'

  real_T Gain_Gain_p;                  // Expression: -1
                                          //  Referenced by: '<S13>/Gain'

  real_T Gain1_Gain_d;                 // Expression: pi/180
                                          //  Referenced by: '<S17>/Gain1'

  real_T Integrator_gainval_e1;     // Computed Parameter: Integrator_gainval_e1
                                       //  Referenced by: '<S108>/Integrator'

  real_T Filter_gainval_j;             // Computed Parameter: Filter_gainval_j
                                          //  Referenced by: '<S103>/Filter'

  real_T des_yaw_Value;                // Expression: 0
                                          //  Referenced by: '<S1>/des_yaw'

  real_T Gain1_Gain_n;                 // Expression: pi/180
                                          //  Referenced by: '<S15>/Gain1'

  real_T Clamping_zero_Value_m;        // Expression: 0
                                          //  Referenced by: '<S152>/Clamping_zero'

  real_T Filter_gainval_i;             // Computed Parameter: Filter_gainval_i
                                          //  Referenced by: '<S157>/Filter'

  real_T Integrator_gainval_b;       // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S162>/Integrator'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S14>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                          //  Referenced by: '<S14>/Saturation'

  real_T Gain_Gain_j;                  // Expression: 1000
                                          //  Referenced by: '<S10>/Gain'

  real_T Constant_Value_o;             // Expression: 1000
                                          //  Referenced by: '<S10>/Constant'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S423>/Clamping_zero'

  real_T Clamping_zero_Value_d;        // Expression: 0
                                          //  Referenced by: '<S477>/Clamping_zero'

  boolean_T Assertion_Enabled;         // Computed Parameter: Assertion_Enabled
                                          //  Referenced by: '<S535>/Assertion'

  boolean_T Assertion_Enabled_e;      // Computed Parameter: Assertion_Enabled_e
                                         //  Referenced by: '<S533>/Assertion'

  boolean_T Assertion_Enabled_l;      // Computed Parameter: Assertion_Enabled_l
                                         //  Referenced by: '<S532>/Assertion'

  boolean_T Assertion_Enabled_c;      // Computed Parameter: Assertion_Enabled_c
                                         //  Referenced by: '<S530>/Assertion'

  boolean_T Constant_Value_a;          // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<S5>/Constant'

  int8_T Constant_Value_nq;            // Computed Parameter: Constant_Value_nq
                                          //  Referenced by: '<S152>/Constant'

  int8_T Constant2_Value;              // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<S152>/Constant2'

  int8_T Constant3_Value;              // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<S152>/Constant3'

  int8_T Constant4_Value;              // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<S152>/Constant4'

  int8_T Constant_Value_m;             // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S213>/Constant'

  int8_T Constant2_Value_c;            // Computed Parameter: Constant2_Value_c
                                          //  Referenced by: '<S213>/Constant2'

  int8_T Constant3_Value_e;            // Computed Parameter: Constant3_Value_e
                                          //  Referenced by: '<S213>/Constant3'

  int8_T Constant4_Value_o;            // Computed Parameter: Constant4_Value_o
                                          //  Referenced by: '<S213>/Constant4'

  int8_T Constant_Value_b;             // Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S423>/Constant'

  int8_T Constant2_Value_j;            // Computed Parameter: Constant2_Value_j
                                          //  Referenced by: '<S423>/Constant2'

  int8_T Constant3_Value_c;            // Computed Parameter: Constant3_Value_c
                                          //  Referenced by: '<S423>/Constant3'

  int8_T Constant4_Value_g;            // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S423>/Constant4'

  int8_T Constant_Value_b5;            // Computed Parameter: Constant_Value_b5
                                          //  Referenced by: '<S477>/Constant'

  int8_T Constant2_Value_a;            // Computed Parameter: Constant2_Value_a
                                          //  Referenced by: '<S477>/Constant2'

  int8_T Constant3_Value_k;            // Computed Parameter: Constant3_Value_k
                                          //  Referenced by: '<S477>/Constant3'

  int8_T Constant4_Value_k;            // Computed Parameter: Constant4_Value_k
                                          //  Referenced by: '<S477>/Constant4'

};

// Real-time Model Data Structure
struct tag_RTM_Quadcopter_Controller_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Quadcopter_Controller_T Quadcopter_Controller_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Quadcopter_Controller_T Quadcopter_Controller_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_Quadcopter_Controller_T Quadcopter_Controller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Quadcopter_Controller_initialize(void);
  extern void Quadcopter_Controller_step(void);
  extern void Quadcopter_Controller_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Quadcopter_Controlle_T *const Quadcopter_Controller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S12>/Constant' : Unused code path elimination
//  Block '<S18>/Data Type Duplicate' : Unused code path elimination
//  Block '<S1>/Rate Transition3' : Eliminated since input and output rates are identical
//  Block '<S14>/Reshape' : Reshape block reduction
//  Block '<S514>/Reshape' : Reshape block reduction
//  Block '<S514>/Reshape1' : Reshape block reduction
//  Block '<S514>/Reshape2' : Reshape block reduction
//  Block '<S528>/Reshape' : Reshape block reduction
//  Block '<S537>/Reshape' : Reshape block reduction
//  Block '<S548>/Reshape (9) to [3x3] column-major' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Quadcopter_Controller'
//  '<S1>'   : 'Quadcopter_Controller/Commands'
//  '<S2>'   : 'Quadcopter_Controller/PX4 uORB Read1'
//  '<S3>'   : 'Quadcopter_Controller/PX4 uORB Read2'
//  '<S4>'   : 'Quadcopter_Controller/PX4 uORB Read5'
//  '<S5>'   : 'Quadcopter_Controller/Subsystem'
//  '<S6>'   : 'Quadcopter_Controller/PX4 uORB Read1/Enabled Subsystem'
//  '<S7>'   : 'Quadcopter_Controller/PX4 uORB Read2/Enabled Subsystem'
//  '<S8>'   : 'Quadcopter_Controller/PX4 uORB Read5/Enabled Subsystem'
//  '<S9>'   : 'Quadcopter_Controller/Subsystem/Controller'
//  '<S10>'  : 'Quadcopter_Controller/Subsystem/Omega to PX4 PWM'
//  '<S11>'  : 'Quadcopter_Controller/Subsystem/Signal Conditioning'
//  '<S12>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller'
//  '<S13>'  : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller'
//  '<S14>'  : 'Quadcopter_Controller/Subsystem/Controller/To Actuator'
//  '<S15>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/Degrees to Radians'
//  '<S16>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/Degrees to Radians1'
//  '<S17>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/Degrees to Radians2'
//  '<S18>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/Discrete Derivative'
//  '<S19>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch'
//  '<S20>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll'
//  '<S21>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw'
//  '<S22>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Anti-windup'
//  '<S23>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/D Gain'
//  '<S24>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/External Derivative'
//  '<S25>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Filter'
//  '<S26>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Filter ICs'
//  '<S27>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/I Gain'
//  '<S28>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Ideal P Gain'
//  '<S29>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Ideal P Gain Fdbk'
//  '<S30>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Integrator'
//  '<S31>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Integrator ICs'
//  '<S32>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/N Copy'
//  '<S33>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/N Gain'
//  '<S34>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/P Copy'
//  '<S35>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Parallel P Gain'
//  '<S36>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Reset Signal'
//  '<S37>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Saturation'
//  '<S38>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Saturation Fdbk'
//  '<S39>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Sum'
//  '<S40>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Sum Fdbk'
//  '<S41>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tracking Mode'
//  '<S42>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tracking Mode Sum'
//  '<S43>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tsamp - Integral'
//  '<S44>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tsamp - Ngain'
//  '<S45>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/postSat Signal'
//  '<S46>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/preInt Signal'
//  '<S47>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/preSat Signal'
//  '<S48>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Anti-windup/Passthrough'
//  '<S49>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/D Gain/Internal Parameters'
//  '<S50>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/External Derivative/Error'
//  '<S51>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Filter/Disc. Forward Euler Filter'
//  '<S52>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Filter ICs/Internal IC - Filter'
//  '<S53>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/I Gain/Internal Parameters'
//  '<S54>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Ideal P Gain/Passthrough'
//  '<S55>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Ideal P Gain Fdbk/Disabled'
//  '<S56>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Integrator/Discrete'
//  '<S57>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Integrator ICs/Internal IC'
//  '<S58>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/N Copy/Disabled'
//  '<S59>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/N Gain/Internal Parameters'
//  '<S60>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/P Copy/Disabled'
//  '<S61>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Parallel P Gain/Internal Parameters'
//  '<S62>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Reset Signal/Disabled'
//  '<S63>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Saturation/Enabled'
//  '<S64>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Saturation Fdbk/Disabled'
//  '<S65>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Sum/Sum_PID'
//  '<S66>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Sum Fdbk/Disabled'
//  '<S67>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tracking Mode/Disabled'
//  '<S68>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tracking Mode Sum/Passthrough'
//  '<S69>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tsamp - Integral/TsSignalSpecification'
//  '<S70>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/Tsamp - Ngain/Passthrough'
//  '<S71>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/postSat Signal/Forward_Path'
//  '<S72>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/preInt Signal/Internal PreInt'
//  '<S73>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_pitch/preSat Signal/Forward_Path'
//  '<S74>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Anti-windup'
//  '<S75>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/D Gain'
//  '<S76>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/External Derivative'
//  '<S77>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Filter'
//  '<S78>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Filter ICs'
//  '<S79>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/I Gain'
//  '<S80>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Ideal P Gain'
//  '<S81>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Ideal P Gain Fdbk'
//  '<S82>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Integrator'
//  '<S83>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Integrator ICs'
//  '<S84>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/N Copy'
//  '<S85>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/N Gain'
//  '<S86>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/P Copy'
//  '<S87>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Parallel P Gain'
//  '<S88>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Reset Signal'
//  '<S89>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Saturation'
//  '<S90>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Saturation Fdbk'
//  '<S91>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Sum'
//  '<S92>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Sum Fdbk'
//  '<S93>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tracking Mode'
//  '<S94>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tracking Mode Sum'
//  '<S95>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tsamp - Integral'
//  '<S96>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tsamp - Ngain'
//  '<S97>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/postSat Signal'
//  '<S98>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/preInt Signal'
//  '<S99>'  : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/preSat Signal'
//  '<S100>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Anti-windup/Passthrough'
//  '<S101>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/D Gain/Internal Parameters'
//  '<S102>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/External Derivative/Error'
//  '<S103>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Filter/Disc. Forward Euler Filter'
//  '<S104>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Filter ICs/Internal IC - Filter'
//  '<S105>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/I Gain/Internal Parameters'
//  '<S106>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Ideal P Gain/Passthrough'
//  '<S107>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Ideal P Gain Fdbk/Disabled'
//  '<S108>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Integrator/Discrete'
//  '<S109>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Integrator ICs/Internal IC'
//  '<S110>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/N Copy/Disabled'
//  '<S111>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/N Gain/Internal Parameters'
//  '<S112>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/P Copy/Disabled'
//  '<S113>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Parallel P Gain/Internal Parameters'
//  '<S114>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Reset Signal/Disabled'
//  '<S115>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Saturation/Enabled'
//  '<S116>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Saturation Fdbk/Disabled'
//  '<S117>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Sum/Sum_PID'
//  '<S118>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Sum Fdbk/Disabled'
//  '<S119>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tracking Mode/Disabled'
//  '<S120>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tracking Mode Sum/Passthrough'
//  '<S121>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tsamp - Integral/TsSignalSpecification'
//  '<S122>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/Tsamp - Ngain/Passthrough'
//  '<S123>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/postSat Signal/Forward_Path'
//  '<S124>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/preInt Signal/Internal PreInt'
//  '<S125>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_roll/preSat Signal/Forward_Path'
//  '<S126>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Anti-windup'
//  '<S127>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/D Gain'
//  '<S128>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/External Derivative'
//  '<S129>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Filter'
//  '<S130>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Filter ICs'
//  '<S131>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/I Gain'
//  '<S132>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Ideal P Gain'
//  '<S133>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Ideal P Gain Fdbk'
//  '<S134>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Integrator'
//  '<S135>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Integrator ICs'
//  '<S136>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/N Copy'
//  '<S137>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/N Gain'
//  '<S138>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/P Copy'
//  '<S139>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Parallel P Gain'
//  '<S140>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Reset Signal'
//  '<S141>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Saturation'
//  '<S142>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Saturation Fdbk'
//  '<S143>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Sum'
//  '<S144>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Sum Fdbk'
//  '<S145>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tracking Mode'
//  '<S146>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tracking Mode Sum'
//  '<S147>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tsamp - Integral'
//  '<S148>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tsamp - Ngain'
//  '<S149>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/postSat Signal'
//  '<S150>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/preInt Signal'
//  '<S151>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/preSat Signal'
//  '<S152>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Anti-windup/Disc. Clamping Parallel'
//  '<S153>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S154>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S155>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/D Gain/Internal Parameters'
//  '<S156>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/External Derivative/Error'
//  '<S157>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Filter/Disc. Forward Euler Filter'
//  '<S158>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Filter ICs/Internal IC - Filter'
//  '<S159>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/I Gain/Internal Parameters'
//  '<S160>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Ideal P Gain/Passthrough'
//  '<S161>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Ideal P Gain Fdbk/Passthrough'
//  '<S162>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Integrator/Discrete'
//  '<S163>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Integrator ICs/Internal IC'
//  '<S164>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/N Copy/Disabled'
//  '<S165>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/N Gain/Internal Parameters'
//  '<S166>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/P Copy/Disabled'
//  '<S167>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Parallel P Gain/Internal Parameters'
//  '<S168>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Reset Signal/Disabled'
//  '<S169>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Saturation/Enabled'
//  '<S170>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Saturation Fdbk/Passthrough'
//  '<S171>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Sum/Sum_PID'
//  '<S172>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Sum Fdbk/Enabled'
//  '<S173>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tracking Mode/Disabled'
//  '<S174>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tracking Mode Sum/Passthrough'
//  '<S175>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tsamp - Integral/TsSignalSpecification'
//  '<S176>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/Tsamp - Ngain/Passthrough'
//  '<S177>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/postSat Signal/Feedback_Path'
//  '<S178>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/preInt Signal/Internal PreInt'
//  '<S179>' : 'Quadcopter_Controller/Subsystem/Controller/Attitude controller/PID_yaw/preSat Signal/Feedback_Path'
//  '<S180>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude'
//  '<S181>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx'
//  '<S182>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy'
//  '<S183>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz'
//  '<S184>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x'
//  '<S185>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y'
//  '<S186>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/Rotation mat '
//  '<S187>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S188>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S189>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/External Derivative'
//  '<S190>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Filter'
//  '<S191>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S192>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S193>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S194>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S195>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S196>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S197>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S198>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S199>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S200>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S201>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S202>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S203>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S204>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Sum'
//  '<S205>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S206>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S207>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S208>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S209>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S210>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S211>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/preInt Signal'
//  '<S212>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S213>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S214>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S215>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S216>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S217>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/External Derivative/Error'
//  '<S218>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S219>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S220>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S221>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S222>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S223>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S224>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S225>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S226>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S227>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S228>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S229>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S230>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S231>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S232>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S233>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S234>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S235>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S236>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S237>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S238>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S239>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/preInt Signal/Internal PreInt'
//  '<S240>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S241>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Anti-windup'
//  '<S242>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/D Gain'
//  '<S243>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/External Derivative'
//  '<S244>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Filter'
//  '<S245>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Filter ICs'
//  '<S246>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/I Gain'
//  '<S247>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Ideal P Gain'
//  '<S248>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Ideal P Gain Fdbk'
//  '<S249>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Integrator'
//  '<S250>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Integrator ICs'
//  '<S251>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/N Copy'
//  '<S252>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/N Gain'
//  '<S253>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/P Copy'
//  '<S254>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Parallel P Gain'
//  '<S255>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Reset Signal'
//  '<S256>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Saturation'
//  '<S257>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Saturation Fdbk'
//  '<S258>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Sum'
//  '<S259>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Sum Fdbk'
//  '<S260>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tracking Mode'
//  '<S261>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tracking Mode Sum'
//  '<S262>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tsamp - Integral'
//  '<S263>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tsamp - Ngain'
//  '<S264>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/postSat Signal'
//  '<S265>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/preInt Signal'
//  '<S266>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/preSat Signal'
//  '<S267>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Anti-windup/Passthrough'
//  '<S268>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/D Gain/Internal Parameters'
//  '<S269>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/External Derivative/Error'
//  '<S270>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Filter/Disc. Forward Euler Filter'
//  '<S271>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Filter ICs/Internal IC - Filter'
//  '<S272>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/I Gain/Internal Parameters'
//  '<S273>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Ideal P Gain/Passthrough'
//  '<S274>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Ideal P Gain Fdbk/Disabled'
//  '<S275>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Integrator/Discrete'
//  '<S276>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Integrator ICs/Internal IC'
//  '<S277>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/N Copy/Disabled'
//  '<S278>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/N Gain/Internal Parameters'
//  '<S279>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/P Copy/Disabled'
//  '<S280>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Parallel P Gain/Internal Parameters'
//  '<S281>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Reset Signal/Disabled'
//  '<S282>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Saturation/Enabled'
//  '<S283>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Saturation Fdbk/Disabled'
//  '<S284>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Sum/Sum_PID'
//  '<S285>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Sum Fdbk/Disabled'
//  '<S286>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tracking Mode/Disabled'
//  '<S287>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tracking Mode Sum/Passthrough'
//  '<S288>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tsamp - Integral/TsSignalSpecification'
//  '<S289>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/Tsamp - Ngain/Passthrough'
//  '<S290>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/postSat Signal/Forward_Path'
//  '<S291>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/preInt Signal/Internal PreInt'
//  '<S292>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vx/preSat Signal/Forward_Path'
//  '<S293>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Anti-windup'
//  '<S294>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/D Gain'
//  '<S295>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/External Derivative'
//  '<S296>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Filter'
//  '<S297>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Filter ICs'
//  '<S298>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/I Gain'
//  '<S299>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Ideal P Gain'
//  '<S300>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Ideal P Gain Fdbk'
//  '<S301>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Integrator'
//  '<S302>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Integrator ICs'
//  '<S303>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/N Copy'
//  '<S304>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/N Gain'
//  '<S305>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/P Copy'
//  '<S306>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Parallel P Gain'
//  '<S307>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Reset Signal'
//  '<S308>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Saturation'
//  '<S309>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Saturation Fdbk'
//  '<S310>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Sum'
//  '<S311>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Sum Fdbk'
//  '<S312>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tracking Mode'
//  '<S313>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tracking Mode Sum'
//  '<S314>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tsamp - Integral'
//  '<S315>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tsamp - Ngain'
//  '<S316>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/postSat Signal'
//  '<S317>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/preInt Signal'
//  '<S318>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/preSat Signal'
//  '<S319>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Anti-windup/Passthrough'
//  '<S320>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/D Gain/Internal Parameters'
//  '<S321>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/External Derivative/Error'
//  '<S322>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Filter/Disc. Forward Euler Filter'
//  '<S323>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Filter ICs/Internal IC - Filter'
//  '<S324>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/I Gain/Internal Parameters'
//  '<S325>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Ideal P Gain/Passthrough'
//  '<S326>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Ideal P Gain Fdbk/Disabled'
//  '<S327>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Integrator/Discrete'
//  '<S328>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Integrator ICs/Internal IC'
//  '<S329>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/N Copy/Disabled'
//  '<S330>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/N Gain/Internal Parameters'
//  '<S331>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/P Copy/Disabled'
//  '<S332>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Parallel P Gain/Internal Parameters'
//  '<S333>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Reset Signal/Disabled'
//  '<S334>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Saturation/Enabled'
//  '<S335>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Saturation Fdbk/Disabled'
//  '<S336>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Sum/Sum_PID'
//  '<S337>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Sum Fdbk/Disabled'
//  '<S338>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tracking Mode/Disabled'
//  '<S339>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tracking Mode Sum/Passthrough'
//  '<S340>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tsamp - Integral/TsSignalSpecification'
//  '<S341>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/Tsamp - Ngain/Passthrough'
//  '<S342>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/postSat Signal/Forward_Path'
//  '<S343>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/preInt Signal/Internal PreInt'
//  '<S344>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vy/preSat Signal/Forward_Path'
//  '<S345>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S346>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/D Gain'
//  '<S347>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/External Derivative'
//  '<S348>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Filter'
//  '<S349>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S350>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/I Gain'
//  '<S351>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S352>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S353>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Integrator'
//  '<S354>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S355>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/N Copy'
//  '<S356>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/N Gain'
//  '<S357>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/P Copy'
//  '<S358>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S359>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S360>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Saturation'
//  '<S361>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S362>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Sum'
//  '<S363>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S364>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S365>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S366>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S367>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S368>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S369>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/preInt Signal'
//  '<S370>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S371>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Anti-windup/Passthrough'
//  '<S372>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S373>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/External Derivative/Error'
//  '<S374>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S375>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S376>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S377>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S378>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Disabled'
//  '<S379>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S380>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S381>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S382>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S383>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S384>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S385>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S386>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S387>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Saturation Fdbk/Disabled'
//  '<S388>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S389>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Sum Fdbk/Disabled'
//  '<S390>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S391>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S392>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S393>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S394>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/postSat Signal/Forward_Path'
//  '<S395>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/preInt Signal/Internal PreInt'
//  '<S396>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_vz/preSat Signal/Forward_Path'
//  '<S397>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Anti-windup'
//  '<S398>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/D Gain'
//  '<S399>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/External Derivative'
//  '<S400>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Filter'
//  '<S401>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Filter ICs'
//  '<S402>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/I Gain'
//  '<S403>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Ideal P Gain'
//  '<S404>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Ideal P Gain Fdbk'
//  '<S405>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Integrator'
//  '<S406>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Integrator ICs'
//  '<S407>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/N Copy'
//  '<S408>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/N Gain'
//  '<S409>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/P Copy'
//  '<S410>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Parallel P Gain'
//  '<S411>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Reset Signal'
//  '<S412>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Saturation'
//  '<S413>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Saturation Fdbk'
//  '<S414>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Sum'
//  '<S415>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Sum Fdbk'
//  '<S416>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tracking Mode'
//  '<S417>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tracking Mode Sum'
//  '<S418>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tsamp - Integral'
//  '<S419>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tsamp - Ngain'
//  '<S420>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/postSat Signal'
//  '<S421>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/preInt Signal'
//  '<S422>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/preSat Signal'
//  '<S423>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Anti-windup/Disc. Clamping Parallel'
//  '<S424>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S425>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S426>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/D Gain/Internal Parameters'
//  '<S427>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/External Derivative/Error'
//  '<S428>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Filter/Disc. Forward Euler Filter'
//  '<S429>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Filter ICs/Internal IC - Filter'
//  '<S430>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/I Gain/Internal Parameters'
//  '<S431>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Ideal P Gain/Passthrough'
//  '<S432>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Ideal P Gain Fdbk/Disabled'
//  '<S433>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Integrator/Discrete'
//  '<S434>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Integrator ICs/Internal IC'
//  '<S435>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/N Copy/Disabled'
//  '<S436>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/N Gain/Internal Parameters'
//  '<S437>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/P Copy/Disabled'
//  '<S438>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Parallel P Gain/Internal Parameters'
//  '<S439>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Reset Signal/Disabled'
//  '<S440>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Saturation/Enabled'
//  '<S441>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Saturation Fdbk/Disabled'
//  '<S442>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Sum/Sum_PID'
//  '<S443>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Sum Fdbk/Disabled'
//  '<S444>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tracking Mode/Disabled'
//  '<S445>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tracking Mode Sum/Passthrough'
//  '<S446>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tsamp - Integral/TsSignalSpecification'
//  '<S447>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/Tsamp - Ngain/Passthrough'
//  '<S448>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/postSat Signal/Forward_Path'
//  '<S449>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/preInt Signal/Internal PreInt'
//  '<S450>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_x/preSat Signal/Forward_Path'
//  '<S451>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Anti-windup'
//  '<S452>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/D Gain'
//  '<S453>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/External Derivative'
//  '<S454>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Filter'
//  '<S455>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Filter ICs'
//  '<S456>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/I Gain'
//  '<S457>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Ideal P Gain'
//  '<S458>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Ideal P Gain Fdbk'
//  '<S459>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Integrator'
//  '<S460>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Integrator ICs'
//  '<S461>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/N Copy'
//  '<S462>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/N Gain'
//  '<S463>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/P Copy'
//  '<S464>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Parallel P Gain'
//  '<S465>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Reset Signal'
//  '<S466>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Saturation'
//  '<S467>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Saturation Fdbk'
//  '<S468>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Sum'
//  '<S469>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Sum Fdbk'
//  '<S470>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tracking Mode'
//  '<S471>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tracking Mode Sum'
//  '<S472>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tsamp - Integral'
//  '<S473>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tsamp - Ngain'
//  '<S474>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/postSat Signal'
//  '<S475>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/preInt Signal'
//  '<S476>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/preSat Signal'
//  '<S477>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Anti-windup/Disc. Clamping Parallel'
//  '<S478>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S479>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S480>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/D Gain/Internal Parameters'
//  '<S481>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/External Derivative/Error'
//  '<S482>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Filter/Disc. Forward Euler Filter'
//  '<S483>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Filter ICs/Internal IC - Filter'
//  '<S484>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/I Gain/Internal Parameters'
//  '<S485>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Ideal P Gain/Passthrough'
//  '<S486>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Ideal P Gain Fdbk/Disabled'
//  '<S487>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Integrator/Discrete'
//  '<S488>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Integrator ICs/Internal IC'
//  '<S489>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/N Copy/Disabled'
//  '<S490>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/N Gain/Internal Parameters'
//  '<S491>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/P Copy/Disabled'
//  '<S492>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Parallel P Gain/Internal Parameters'
//  '<S493>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Reset Signal/Disabled'
//  '<S494>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Saturation/Enabled'
//  '<S495>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Saturation Fdbk/Disabled'
//  '<S496>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Sum/Sum_PID'
//  '<S497>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Sum Fdbk/Disabled'
//  '<S498>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tracking Mode/Disabled'
//  '<S499>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tracking Mode Sum/Passthrough'
//  '<S500>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tsamp - Integral/TsSignalSpecification'
//  '<S501>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/Tsamp - Ngain/Passthrough'
//  '<S502>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/postSat Signal/Forward_Path'
//  '<S503>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/preInt Signal/Internal PreInt'
//  '<S504>' : 'Quadcopter_Controller/Subsystem/Controller/Position & Altitude controller/PID_y/preSat Signal/Forward_Path'
//  '<S505>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/X,Y,Z from Vehicle Angular Velocity'
//  '<S506>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/XYZ from Vehicle Local Position'
//  '<S507>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude'
//  '<S508>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/dx,dy,dz from vehile_local_position'
//  '<S509>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles'
//  '<S510>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang'
//  '<S511>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM'
//  '<S512>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotDefault'
//  '<S513>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotZeroR3'
//  '<S514>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Get DCM Values'
//  '<S515>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM'
//  '<S516>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotDefault/Protect asincos input'
//  '<S517>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotDefault/Protect asincos input/If Action Subsystem'
//  '<S518>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotDefault/Protect asincos input/If Action Subsystem1'
//  '<S519>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotDefault/Protect asincos input/If Action Subsystem2'
//  '<S520>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotZeroR3/Protect asincos input'
//  '<S521>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotZeroR3/Protect asincos input/If Action Subsystem'
//  '<S522>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotZeroR3/Protect asincos input/If Action Subsystem1'
//  '<S523>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/AxisRotZeroR3/Protect asincos input/If Action Subsystem2'
//  '<S524>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error'
//  '<S525>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/Else If Not Orthogonal'
//  '<S526>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/Else No Action'
//  '<S527>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/If Not Proper'
//  '<S528>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/isNotOrthogonal'
//  '<S529>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/isNotProper'
//  '<S530>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/Else If Not Orthogonal/Error'
//  '<S531>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/Else If Not Orthogonal/None'
//  '<S532>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/Else If Not Orthogonal/Warning'
//  '<S533>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/If Not Proper/Error'
//  '<S534>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/If Not Proper/None'
//  '<S535>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/If Not Proper/Warning'
//  '<S536>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/isNotOrthogonal/transpose*dcm ~= eye(3)'
//  '<S537>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/isNotProper/Determinant of 3x3 Matrix'
//  '<S538>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/DCM2Ang/Validate DCM/If Warning//Error/isNotProper/determinant does not equal 1'
//  '<S539>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A11'
//  '<S540>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A12'
//  '<S541>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A13'
//  '<S542>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A21'
//  '<S543>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A22'
//  '<S544>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A23'
//  '<S545>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A31'
//  '<S546>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A32'
//  '<S547>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/A33'
//  '<S548>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/Create 3x3 Matrix'
//  '<S549>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/Quaternion Normalize'
//  '<S550>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/Quaternion Normalize/Quaternion Modulus'
//  '<S551>' : 'Quadcopter_Controller/Subsystem/Signal Conditioning/Y,P,R from Vehicle Attitude/Quaternions to Rotation Angles/Quat2DCM/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                                 // Quadcopter_Controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
