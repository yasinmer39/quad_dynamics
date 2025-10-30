//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_Controller.cpp
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
#include "Quadcopter_Controller_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "Quadcopter_Controller_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_assert.h"
#include "rt_defines.h"

// Block signals (default storage)
B_Quadcopter_Controller_T Quadcopter_Controller_B;

// Block states (default storage)
DW_Quadcopter_Controller_T Quadcopter_Controller_DW;

// Real-time model
RT_MODEL_Quadcopter_Controlle_T Quadcopter_Controller_M_ =
  RT_MODEL_Quadcopter_Controlle_T();
RT_MODEL_Quadcopter_Controlle_T *const Quadcopter_Controller_M =
  &Quadcopter_Controller_M_;

// Forward declaration for local functions
static void Quadcopter_Contro_PWM_setupImpl(px4_internal_block_PWM_Quadco_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe);
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void Quadcopter_Contro_PWM_setupImpl(px4_internal_block_PWM_Quadco_T *obj,
  boolean_T armPWM, boolean_T forceFailsafe)
{
  obj->isMain = true;
  pwm_open(&obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->servoCount = 8;
  if (armPWM) {
    pwm_arm(&obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    pwm_disarm(&obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->channelMask = 15;
  if (obj->isMain) {
    if (forceFailsafe) {
      pwm_disarm(&obj->armAdvertiseObj);
    } else {
      pwm_arm(&obj->armAdvertiseObj);
    }
  }
}

// Model step function
void Quadcopter_Controller_step(void)
{
  real_T rtb_MatrixMultiply_idx_0;
  real_T rtb_MatrixMultiply_idx_1;
  real_T rtb_Merge_idx_0;
  real_T rtb_Merge_idx_2;
  int32_T i;
  int32_T i_0;
  int32_T rtb_VectorConcatenate_tmp;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;
  boolean_T tmp;

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC_o);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfActionSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfActionSubsystem1_SubsysRanB_j);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfActionSubsystem2_SubsysRanB_g);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.AxisRotZeroR3_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.AxisRotDefault_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.Warning_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.Error_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.None_SubsysRanBC_a);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfNotProper_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.Warning_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.Error_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.None_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.ElseIfNotOrthogonal_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.ElseNoAction_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_Controller_DW.IfWarningError_SubsysRanBC);

  // MATLABSystem: '<S3>/SourceBlock'
  tmp = uORB_read_step(Quadcopter_Controller_DW.obj_m.orbMetadataObj,
                       &Quadcopter_Controller_DW.obj_m.eventStructObj,
                       &Quadcopter_Controller_B.r1, false, 1.0);

  // Logic: '<S3>/NOT' incorporates:
  //   MATLABSystem: '<S3>/SourceBlock'
  //
  Quadcopter_Controller_B.NOT = !tmp;

  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = uORB_read_step(Quadcopter_Controller_DW.obj.orbMetadataObj,
    &Quadcopter_Controller_DW.obj.eventStructObj, &Quadcopter_Controller_B.r,
    false, 1.0);

  // Logic: '<S4>/NOT' incorporates:
  //   MATLABSystem: '<S4>/SourceBlock'
  //
  Quadcopter_Controller_B.NOT_n = !b_varargout_1;

  // MATLABSystem: '<S2>/SourceBlock'
  b_varargout_1_0 = uORB_read_step(Quadcopter_Controller_DW.obj_c.orbMetadataObj,
    &Quadcopter_Controller_DW.obj_c.eventStructObj, &Quadcopter_Controller_B.r2,
    false, 1.0);

  // Logic: '<S2>/NOT' incorporates:
  //   MATLABSystem: '<S2>/SourceBlock'
  //
  Quadcopter_Controller_B.NOT_h = !b_varargout_1_0;

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  // Start for MATLABSystem: '<S4>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S8>/In1'
    Quadcopter_Controller_B.In1 = Quadcopter_Controller_B.r;
    srUpdateBC(Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // Constant: '<S1>/des_alt'
  Quadcopter_Controller_B.des_alt = Quadcopter_Controller_P.des_alt_Value;

  // DataTypeConversion: '<S506>/Data Type Conversion'
  Quadcopter_Controller_B.DataTypeConversion[0] = Quadcopter_Controller_B.In1.x;
  Quadcopter_Controller_B.DataTypeConversion[1] = Quadcopter_Controller_B.In1.y;
  Quadcopter_Controller_B.DataTypeConversion[2] = Quadcopter_Controller_B.In1.z;

  // Sum: '<S13>/Add' incorporates:
  //   Gain: '<S1>/Gain'

  Quadcopter_Controller_B.DeadZone_n = Quadcopter_Controller_P.Gain_Gain *
    Quadcopter_Controller_B.des_alt -
    Quadcopter_Controller_B.DataTypeConversion[2];

  // Gain: '<S228>/Proportional Gain'
  Quadcopter_Controller_B.Saturation_g = Quadcopter_Controller_P.PID_Altitude_P *
    Quadcopter_Controller_B.DeadZone_n;

  // Gain: '<S226>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S218>/Filter'
  //   Gain: '<S216>/Derivative Gain'
  //   Sum: '<S218>/SumD'

  Quadcopter_Controller_B.FilterCoefficient =
    (Quadcopter_Controller_P.PID_Altitude_D * Quadcopter_Controller_B.DeadZone_n
     - Quadcopter_Controller_DW.Filter_DSTATE) *
    Quadcopter_Controller_P.PID_Altitude_N;

  // Sum: '<S233>/Sum Fdbk'
  Quadcopter_Controller_B.Filter_f = (Quadcopter_Controller_B.Saturation_g +
    Quadcopter_Controller_DW.Integrator_DSTATE) +
    Quadcopter_Controller_B.FilterCoefficient;

  // DeadZone: '<S215>/DeadZone'
  if (Quadcopter_Controller_B.Filter_f >
      Quadcopter_Controller_P.PID_Altitude_UpperSaturationLim) {
    Quadcopter_Controller_B.Filter_f -=
      Quadcopter_Controller_P.PID_Altitude_UpperSaturationLim;
  } else if (Quadcopter_Controller_B.Filter_f >=
             Quadcopter_Controller_P.PID_Altitude_LowerSaturationLim) {
    Quadcopter_Controller_B.Filter_f = 0.0;
  } else {
    Quadcopter_Controller_B.Filter_f -=
      Quadcopter_Controller_P.PID_Altitude_LowerSaturationLim;
  }

  // End of DeadZone: '<S215>/DeadZone'

  // Gain: '<S220>/Integral Gain'
  Quadcopter_Controller_B.DeadZone_n *= Quadcopter_Controller_P.PID_Altitude_I;

  // Switch: '<S213>/Switch1' incorporates:
  //   Constant: '<S213>/Clamping_zero'
  //   Constant: '<S213>/Constant'
  //   Constant: '<S213>/Constant2'
  //   RelationalOperator: '<S213>/fix for DT propagation issue'

  if (Quadcopter_Controller_B.Filter_f >
      Quadcopter_Controller_P.Clamping_zero_Value) {
    tmp_0 = Quadcopter_Controller_P.Constant_Value_m;
  } else {
    tmp_0 = Quadcopter_Controller_P.Constant2_Value_c;
  }

  // Switch: '<S213>/Switch2' incorporates:
  //   Constant: '<S213>/Clamping_zero'
  //   Constant: '<S213>/Constant3'
  //   Constant: '<S213>/Constant4'
  //   RelationalOperator: '<S213>/fix for DT propagation issue1'

  if (Quadcopter_Controller_B.DeadZone_n >
      Quadcopter_Controller_P.Clamping_zero_Value) {
    tmp_1 = Quadcopter_Controller_P.Constant3_Value_e;
  } else {
    tmp_1 = Quadcopter_Controller_P.Constant4_Value_o;
  }

  // Switch: '<S213>/Switch' incorporates:
  //   Constant: '<S213>/Clamping_zero'
  //   Constant: '<S213>/Constant1'
  //   Logic: '<S213>/AND3'
  //   RelationalOperator: '<S213>/Equal1'
  //   RelationalOperator: '<S213>/Relational Operator'
  //   Switch: '<S213>/Switch1'
  //   Switch: '<S213>/Switch2'

  if ((Quadcopter_Controller_P.Clamping_zero_Value !=
       Quadcopter_Controller_B.Filter_f) && (tmp_0 == tmp_1)) {
    Quadcopter_Controller_B.DeadZone_n =
      Quadcopter_Controller_P.Constant1_Value_p;
  }

  // DiscreteIntegrator: '<S223>/Integrator' incorporates:
  //   Switch: '<S213>/Switch'

  Quadcopter_Controller_DW.Integrator_DSTATE +=
    Quadcopter_Controller_P.Integrator_gainval *
    Quadcopter_Controller_B.DeadZone_n;

  // Sum: '<S232>/Sum'
  Quadcopter_Controller_B.IntegralGain_o = (Quadcopter_Controller_B.Saturation_g
    + Quadcopter_Controller_DW.Integrator_DSTATE) +
    Quadcopter_Controller_B.FilterCoefficient;

  // Saturate: '<S230>/Saturation'
  if (Quadcopter_Controller_B.IntegralGain_o >
      Quadcopter_Controller_P.PID_Altitude_UpperSaturationLim) {
    Quadcopter_Controller_B.IntegralGain_o =
      Quadcopter_Controller_P.PID_Altitude_UpperSaturationLim;
  } else if (Quadcopter_Controller_B.IntegralGain_o <
             Quadcopter_Controller_P.PID_Altitude_LowerSaturationLim) {
    Quadcopter_Controller_B.IntegralGain_o =
      Quadcopter_Controller_P.PID_Altitude_LowerSaturationLim;
  }

  // Sum: '<S13>/Add1' incorporates:
  //   DataTypeConversion: '<S508>/Data Type Conversion'
  //   Saturate: '<S230>/Saturation'

  Quadcopter_Controller_B.Saturation_g = Quadcopter_Controller_B.In1.vz -
    Quadcopter_Controller_B.IntegralGain_o;

  // DiscreteIntegrator: '<S379>/Integrator' incorporates:
  //   Gain: '<S376>/Integral Gain'

  Quadcopter_Controller_DW.Integrator_DSTATE_k +=
    Quadcopter_Controller_P.PID_vz_I * Quadcopter_Controller_B.Saturation_g *
    Quadcopter_Controller_P.Integrator_gainval_l;

  // Gain: '<S382>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S374>/Filter'
  //   Gain: '<S372>/Derivative Gain'
  //   Sum: '<S374>/SumD'

  Quadcopter_Controller_B.Filter_f = (Quadcopter_Controller_P.PID_vz_D *
    Quadcopter_Controller_B.Saturation_g -
    Quadcopter_Controller_DW.Filter_DSTATE_b) * Quadcopter_Controller_P.PID_vz_N;

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S7>/Enable'

  // Start for MATLABSystem: '<S3>/SourceBlock'
  if (tmp) {
    // SignalConversion generated from: '<S7>/In1'
    Quadcopter_Controller_B.In1_b = Quadcopter_Controller_B.r1;
    srUpdateBC(Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC_n);
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'

  // Sqrt: '<S550>/sqrt' incorporates:
  //   DataTypeConversion: '<S507>/Data Type Conversion1'
  //   Product: '<S551>/Product'
  //   Product: '<S551>/Product1'
  //   Product: '<S551>/Product2'
  //   Product: '<S551>/Product3'
  //   Sum: '<S551>/Sum'

  Quadcopter_Controller_B.DeadZone_n = sqrt(((static_cast<real_T>
    (Quadcopter_Controller_B.In1_b.q[0]) * Quadcopter_Controller_B.In1_b.q[0] +
    static_cast<real_T>(Quadcopter_Controller_B.In1_b.q[1]) *
    Quadcopter_Controller_B.In1_b.q[1]) + static_cast<real_T>
    (Quadcopter_Controller_B.In1_b.q[2]) * Quadcopter_Controller_B.In1_b.q[2]) +
    static_cast<real_T>(Quadcopter_Controller_B.In1_b.q[3]) *
    Quadcopter_Controller_B.In1_b.q[3]);

  // Product: '<S549>/Product' incorporates:
  //   DataTypeConversion: '<S507>/Data Type Conversion1'

  Quadcopter_Controller_B.IntegralGain_j = Quadcopter_Controller_B.In1_b.q[0] /
    Quadcopter_Controller_B.DeadZone_n;

  // Product: '<S549>/Product1' incorporates:
  //   DataTypeConversion: '<S507>/Data Type Conversion1'

  Quadcopter_Controller_B.Integrator_l = Quadcopter_Controller_B.In1_b.q[1] /
    Quadcopter_Controller_B.DeadZone_n;

  // Product: '<S549>/Product2' incorporates:
  //   DataTypeConversion: '<S507>/Data Type Conversion1'

  Quadcopter_Controller_B.Filter_l = Quadcopter_Controller_B.In1_b.q[2] /
    Quadcopter_Controller_B.DeadZone_n;

  // Product: '<S549>/Product3' incorporates:
  //   DataTypeConversion: '<S507>/Data Type Conversion1'

  Quadcopter_Controller_B.DeadZone_n = Quadcopter_Controller_B.In1_b.q[3] /
    Quadcopter_Controller_B.DeadZone_n;

  // Product: '<S539>/Product3' incorporates:
  //   Product: '<S543>/Product3'

  Quadcopter_Controller_B.FilterCoefficient_p =
    Quadcopter_Controller_B.IntegralGain_j *
    Quadcopter_Controller_B.IntegralGain_j;

  // Product: '<S539>/Product2' incorporates:
  //   Product: '<S543>/Product2'

  Quadcopter_Controller_B.DeadZone = Quadcopter_Controller_B.Integrator_l *
    Quadcopter_Controller_B.Integrator_l;

  // Product: '<S539>/Product1' incorporates:
  //   Product: '<S543>/Product1'
  //   Product: '<S547>/Product1'

  rtb_MatrixMultiply_idx_0 = Quadcopter_Controller_B.Filter_l *
    Quadcopter_Controller_B.Filter_l;

  // Product: '<S539>/Product' incorporates:
  //   Product: '<S543>/Product'
  //   Product: '<S547>/Product'

  rtb_MatrixMultiply_idx_1 = Quadcopter_Controller_B.DeadZone_n *
    Quadcopter_Controller_B.DeadZone_n;

  // Sum: '<S539>/Sum' incorporates:
  //   Product: '<S539>/Product'
  //   Product: '<S539>/Product1'
  //   Product: '<S539>/Product2'
  //   Product: '<S539>/Product3'

  Quadcopter_Controller_B.VectorConcatenate[0] =
    ((Quadcopter_Controller_B.FilterCoefficient_p +
      Quadcopter_Controller_B.DeadZone) - rtb_MatrixMultiply_idx_0) -
    rtb_MatrixMultiply_idx_1;

  // Product: '<S542>/Product3' incorporates:
  //   Product: '<S540>/Product3'

  Quadcopter_Controller_B.FilterCoefficient_db =
    Quadcopter_Controller_B.DeadZone_n * Quadcopter_Controller_B.IntegralGain_j;

  // Product: '<S542>/Product2' incorporates:
  //   Product: '<S540>/Product2'

  Quadcopter_Controller_B.rtb_Merge_idx_1 = Quadcopter_Controller_B.Integrator_l
    * Quadcopter_Controller_B.Filter_l;

  // Gain: '<S542>/Gain' incorporates:
  //   Product: '<S542>/Product2'
  //   Product: '<S542>/Product3'
  //   Sum: '<S542>/Sum'

  Quadcopter_Controller_B.VectorConcatenate[1] =
    (Quadcopter_Controller_B.rtb_Merge_idx_1 -
     Quadcopter_Controller_B.FilterCoefficient_db) *
    Quadcopter_Controller_P.Gain_Gain_f;

  // Product: '<S545>/Product2' incorporates:
  //   Product: '<S541>/Product2'

  Quadcopter_Controller_B.Saturation = Quadcopter_Controller_B.Integrator_l *
    Quadcopter_Controller_B.DeadZone_n;

  // Product: '<S545>/Product1' incorporates:
  //   Product: '<S541>/Product1'

  Quadcopter_Controller_B.TSamp = Quadcopter_Controller_B.IntegralGain_j *
    Quadcopter_Controller_B.Filter_l;

  // Gain: '<S545>/Gain' incorporates:
  //   Product: '<S545>/Product1'
  //   Product: '<S545>/Product2'
  //   Sum: '<S545>/Sum'

  Quadcopter_Controller_B.VectorConcatenate[2] = (Quadcopter_Controller_B.TSamp
    + Quadcopter_Controller_B.Saturation) * Quadcopter_Controller_P.Gain_Gain_o;

  // Gain: '<S540>/Gain' incorporates:
  //   Sum: '<S540>/Sum'

  Quadcopter_Controller_B.VectorConcatenate[3] =
    (Quadcopter_Controller_B.FilterCoefficient_db +
     Quadcopter_Controller_B.rtb_Merge_idx_1) *
    Quadcopter_Controller_P.Gain_Gain_a;

  // Sum: '<S543>/Sum' incorporates:
  //   Sum: '<S547>/Sum'

  Quadcopter_Controller_B.FilterCoefficient_p -=
    Quadcopter_Controller_B.DeadZone;
  Quadcopter_Controller_B.VectorConcatenate[4] =
    (Quadcopter_Controller_B.FilterCoefficient_p + rtb_MatrixMultiply_idx_0) -
    rtb_MatrixMultiply_idx_1;

  // Product: '<S546>/Product1' incorporates:
  //   Product: '<S544>/Product1'

  Quadcopter_Controller_B.DeadZone = Quadcopter_Controller_B.IntegralGain_j *
    Quadcopter_Controller_B.Integrator_l;

  // Product: '<S546>/Product2' incorporates:
  //   Product: '<S544>/Product2'

  Quadcopter_Controller_B.FilterCoefficient_db =
    Quadcopter_Controller_B.Filter_l * Quadcopter_Controller_B.DeadZone_n;

  // Gain: '<S546>/Gain' incorporates:
  //   Product: '<S546>/Product1'
  //   Product: '<S546>/Product2'
  //   Sum: '<S546>/Sum'

  Quadcopter_Controller_B.VectorConcatenate[5] =
    (Quadcopter_Controller_B.FilterCoefficient_db -
     Quadcopter_Controller_B.DeadZone) * Quadcopter_Controller_P.Gain_Gain_ff;

  // Gain: '<S541>/Gain' incorporates:
  //   Sum: '<S541>/Sum'

  Quadcopter_Controller_B.VectorConcatenate[6] =
    (Quadcopter_Controller_B.Saturation - Quadcopter_Controller_B.TSamp) *
    Quadcopter_Controller_P.Gain_Gain_n;

  // Gain: '<S544>/Gain' incorporates:
  //   Sum: '<S544>/Sum'

  Quadcopter_Controller_B.VectorConcatenate[7] =
    (Quadcopter_Controller_B.DeadZone +
     Quadcopter_Controller_B.FilterCoefficient_db) *
    Quadcopter_Controller_P.Gain_Gain_l;

  // Sum: '<S547>/Sum'
  Quadcopter_Controller_B.VectorConcatenate[8] =
    (Quadcopter_Controller_B.FilterCoefficient_p - rtb_MatrixMultiply_idx_0) +
    rtb_MatrixMultiply_idx_1;

  // Gain: '<S514>/Gain1' incorporates:
  //   Concatenate: '<S548>/Vector Concatenate'
  //   Selector: '<S514>/Selector1'

  Quadcopter_Controller_B.DeadZone_n = Quadcopter_Controller_P.Gain1_Gain[2] *
    Quadcopter_Controller_B.VectorConcatenate[6];

  // If: '<S510>/If'
  if ((Quadcopter_Controller_B.DeadZone_n >= 1.0) ||
      (Quadcopter_Controller_B.DeadZone_n <= -1.0)) {
    // Outputs for IfAction SubSystem: '<S510>/AxisRotZeroR3' incorporates:
    //   ActionPort: '<S513>/Action Port'

    // Fcn: '<S513>/Fcn1' incorporates:
    //   Concatenate: '<S548>/Vector Concatenate'
    //   Gain: '<S514>/Gain3'
    //   Selector: '<S514>/Selector3'

    rtb_Merge_idx_0 = rt_atan2d_snf(Quadcopter_Controller_P.Gain3_Gain[0] *
      Quadcopter_Controller_B.VectorConcatenate[1],
      Quadcopter_Controller_P.Gain3_Gain[1] *
      Quadcopter_Controller_B.VectorConcatenate[4]);

    // If: '<S520>/If' incorporates:
    //   Constant: '<S521>/Constant'
    //   Constant: '<S522>/Constant'

    if (Quadcopter_Controller_B.DeadZone_n > 1.0) {
      // Outputs for IfAction SubSystem: '<S520>/If Action Subsystem' incorporates:
      //   ActionPort: '<S521>/Action Port'

      Quadcopter_Controller_B.DeadZone_n =
        Quadcopter_Controller_P.Constant_Value_g;

      // End of Outputs for SubSystem: '<S520>/If Action Subsystem'

      // Update for IfAction SubSystem: '<S520>/If Action Subsystem' incorporates:
      //   ActionPort: '<S521>/Action Port'

      // Update for If: '<S520>/If' incorporates:
      //   Constant: '<S521>/Constant'

      srUpdateBC(Quadcopter_Controller_DW.IfActionSubsystem_SubsysRanBC_g);

      // End of Update for SubSystem: '<S520>/If Action Subsystem'
    } else if (Quadcopter_Controller_B.DeadZone_n < -1.0) {
      // Outputs for IfAction SubSystem: '<S520>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S522>/Action Port'

      Quadcopter_Controller_B.DeadZone_n =
        Quadcopter_Controller_P.Constant_Value_p;

      // End of Outputs for SubSystem: '<S520>/If Action Subsystem1'

      // Update for IfAction SubSystem: '<S520>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S522>/Action Port'

      // Update for If: '<S520>/If' incorporates:
      //   Constant: '<S522>/Constant'

      srUpdateBC(Quadcopter_Controller_DW.IfActionSubsystem1_SubsysRanB_j);

      // End of Update for SubSystem: '<S520>/If Action Subsystem1'
    } else {
      // Update for IfAction SubSystem: '<S520>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S523>/Action Port'

      // Update for If: '<S520>/If'
      srUpdateBC(Quadcopter_Controller_DW.IfActionSubsystem2_SubsysRanB_g);

      // End of Update for SubSystem: '<S520>/If Action Subsystem2'
    }

    // End of If: '<S520>/If'

    // Fcn: '<S513>/Fcn2'
    if (Quadcopter_Controller_B.DeadZone_n > 1.0) {
      Quadcopter_Controller_B.DeadZone_n = 1.0;
    } else if (Quadcopter_Controller_B.DeadZone_n < -1.0) {
      Quadcopter_Controller_B.DeadZone_n = -1.0;
    }

    Quadcopter_Controller_B.rtb_Merge_idx_1 = asin
      (Quadcopter_Controller_B.DeadZone_n);

    // End of Fcn: '<S513>/Fcn2'

    // Fcn: '<S513>/Fcn3'
    rtb_Merge_idx_2 = 0.0;

    // End of Outputs for SubSystem: '<S510>/AxisRotZeroR3'

    // Update for IfAction SubSystem: '<S510>/AxisRotZeroR3' incorporates:
    //   ActionPort: '<S513>/Action Port'

    // Update for If: '<S510>/If'
    srUpdateBC(Quadcopter_Controller_DW.AxisRotZeroR3_SubsysRanBC);

    // End of Update for SubSystem: '<S510>/AxisRotZeroR3'
  } else {
    // Outputs for IfAction SubSystem: '<S510>/AxisRotDefault' incorporates:
    //   ActionPort: '<S512>/Action Port'

    // Fcn: '<S512>/Fcn1' incorporates:
    //   Concatenate: '<S548>/Vector Concatenate'
    //   Gain: '<S514>/Gain1'
    //   Selector: '<S514>/Selector1'

    rtb_Merge_idx_0 = rt_atan2d_snf(Quadcopter_Controller_P.Gain1_Gain[0] *
      Quadcopter_Controller_B.VectorConcatenate[3],
      Quadcopter_Controller_B.VectorConcatenate[0] *
      Quadcopter_Controller_P.Gain1_Gain[1]);

    // Update for IfAction SubSystem: '<S516>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S519>/Action Port'

    // Update for If: '<S516>/If'
    srUpdateBC(Quadcopter_Controller_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S516>/If Action Subsystem2'

    // Outputs for IfAction SubSystem: '<S516>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S519>/Action Port'

    // If: '<S516>/If' incorporates:
    //   Fcn: '<S512>/Fcn2'
    //   SignalConversion generated from: '<S519>/In'

    Quadcopter_Controller_B.rtb_Merge_idx_1 = asin
      (Quadcopter_Controller_B.DeadZone_n);

    // End of Outputs for SubSystem: '<S516>/If Action Subsystem2'

    // Fcn: '<S512>/Fcn3' incorporates:
    //   Concatenate: '<S548>/Vector Concatenate'
    //   Gain: '<S514>/Gain2'
    //   Selector: '<S514>/Selector2'

    rtb_Merge_idx_2 = rt_atan2d_snf(Quadcopter_Controller_P.Gain2_Gain[0] *
      Quadcopter_Controller_B.VectorConcatenate[7],
      Quadcopter_Controller_P.Gain2_Gain[1] *
      Quadcopter_Controller_B.VectorConcatenate[8]);

    // End of Outputs for SubSystem: '<S510>/AxisRotDefault'

    // Update for IfAction SubSystem: '<S510>/AxisRotDefault' incorporates:
    //   ActionPort: '<S512>/Action Port'

    // Update for If: '<S510>/If'
    srUpdateBC(Quadcopter_Controller_DW.AxisRotDefault_SubsysRanBC);

    // End of Update for SubSystem: '<S510>/AxisRotDefault'
  }

  // End of If: '<S510>/If'

  // Sin: '<S1>/x+'
  if (Quadcopter_Controller_DW.systemEnable != 0) {
    Quadcopter_Controller_B.DeadZone_n = Quadcopter_Controller_P.x_Freq *
      Quadcopter_Controller_M->Timing.taskTime0;
    Quadcopter_Controller_DW.lastSin = sin(Quadcopter_Controller_B.DeadZone_n);
    Quadcopter_Controller_DW.lastCos = cos(Quadcopter_Controller_B.DeadZone_n);
    Quadcopter_Controller_DW.systemEnable = 0;
  }

  // Sin: '<S1>/x+'
  Quadcopter_Controller_B.x = ((Quadcopter_Controller_DW.lastSin *
    Quadcopter_Controller_P.x_PCos + Quadcopter_Controller_DW.lastCos *
    Quadcopter_Controller_P.x_PSin) * Quadcopter_Controller_P.x_HCos +
    (Quadcopter_Controller_DW.lastCos * Quadcopter_Controller_P.x_PCos -
     Quadcopter_Controller_DW.lastSin * Quadcopter_Controller_P.x_PSin) *
    Quadcopter_Controller_P.x_Hsin) * Quadcopter_Controller_P.x_Amp +
    Quadcopter_Controller_P.x_Bias;

  // Switch: '<S1>/Switch' incorporates:
  //   Constant: '<S1>/X_SwitchOn_Sine Wave'
  //   Constant: '<S1>/des_x'

  if (Quadcopter_Controller_P.X_SwitchOn_SineWave_Value >
      Quadcopter_Controller_P.Switch_Threshold) {
    Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_B.x;
  } else {
    Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_P.des_x_Value;
  }

  // Sum: '<S13>/Subtract1' incorporates:
  //   Switch: '<S1>/Switch'

  Quadcopter_Controller_B.IntegralGain_j = Quadcopter_Controller_B.Filter_hc -
    Quadcopter_Controller_B.DataTypeConversion[0];

  // Gain: '<S436>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S428>/Filter'
  //   Gain: '<S426>/Derivative Gain'
  //   Sum: '<S428>/SumD'

  Quadcopter_Controller_B.Integrator_l = (Quadcopter_Controller_P.PID_x_D *
    Quadcopter_Controller_B.IntegralGain_j -
    Quadcopter_Controller_DW.Filter_DSTATE_f) * Quadcopter_Controller_P.PID_x_N;

  // Sum: '<S442>/Sum' incorporates:
  //   DiscreteIntegrator: '<S433>/Integrator'
  //   Gain: '<S438>/Proportional Gain'

  Quadcopter_Controller_B.DeadZone_n = (Quadcopter_Controller_P.PID_x_P *
    Quadcopter_Controller_B.IntegralGain_j +
    Quadcopter_Controller_DW.Integrator_DSTATE_b) +
    Quadcopter_Controller_B.Integrator_l;

  // Sin: '<S1>/y+'
  if (Quadcopter_Controller_DW.systemEnable_e != 0) {
    Quadcopter_Controller_B.Filter_l = Quadcopter_Controller_P.y_Freq *
      Quadcopter_Controller_M->Timing.taskTime0;
    Quadcopter_Controller_DW.lastSin_k = sin(Quadcopter_Controller_B.Filter_l);
    Quadcopter_Controller_DW.lastCos_e = cos(Quadcopter_Controller_B.Filter_l);
    Quadcopter_Controller_DW.systemEnable_e = 0;
  }

  // Sin: '<S1>/y+'
  Quadcopter_Controller_B.y = ((Quadcopter_Controller_DW.lastSin_k *
    Quadcopter_Controller_P.y_PCos + Quadcopter_Controller_DW.lastCos_e *
    Quadcopter_Controller_P.y_PSin) * Quadcopter_Controller_P.y_HCos +
    (Quadcopter_Controller_DW.lastCos_e * Quadcopter_Controller_P.y_PCos -
     Quadcopter_Controller_DW.lastSin_k * Quadcopter_Controller_P.y_PSin) *
    Quadcopter_Controller_P.y_Hsin) * Quadcopter_Controller_P.y_Amp +
    Quadcopter_Controller_P.y_Bias;

  // Switch: '<S1>/Switch1' incorporates:
  //   Constant: '<S1>/X_SwitchOn_Sine Wave'
  //   Constant: '<S1>/des_y'

  if (Quadcopter_Controller_P.X_SwitchOn_SineWave_Value >
      Quadcopter_Controller_P.Switch1_Threshold) {
    Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_B.y;
  } else {
    Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_P.des_y_Value;
  }

  // Sum: '<S13>/Subtract2' incorporates:
  //   Switch: '<S1>/Switch1'

  Quadcopter_Controller_B.Filter_l = Quadcopter_Controller_B.Filter_hc -
    Quadcopter_Controller_B.DataTypeConversion[1];

  // Gain: '<S490>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S482>/Filter'
  //   Gain: '<S480>/Derivative Gain'
  //   Sum: '<S482>/SumD'

  Quadcopter_Controller_B.FilterCoefficient_p = (Quadcopter_Controller_P.PID_y_D
    * Quadcopter_Controller_B.Filter_l -
    Quadcopter_Controller_DW.Filter_DSTATE_j) * Quadcopter_Controller_P.PID_y_N;

  // Sum: '<S496>/Sum' incorporates:
  //   DiscreteIntegrator: '<S487>/Integrator'
  //   Gain: '<S492>/Proportional Gain'

  Quadcopter_Controller_B.DeadZone = (Quadcopter_Controller_P.PID_y_P *
    Quadcopter_Controller_B.Filter_l +
    Quadcopter_Controller_DW.Integrator_DSTATE_j) +
    Quadcopter_Controller_B.FilterCoefficient_p;

  // MATLAB Function: '<S13>/Rotation mat '
  rtb_MatrixMultiply_idx_1 = sin(rtb_Merge_idx_0);
  Quadcopter_Controller_B.FilterCoefficient_db = cos(rtb_Merge_idx_0);

  // Saturate: '<S440>/Saturation'
  if (Quadcopter_Controller_B.DeadZone_n >
      Quadcopter_Controller_P.PID_x_UpperSaturationLimit) {
    Quadcopter_Controller_B.Filter_hc =
      Quadcopter_Controller_P.PID_x_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.DeadZone_n <
             Quadcopter_Controller_P.PID_x_LowerSaturationLimit) {
    Quadcopter_Controller_B.Filter_hc =
      Quadcopter_Controller_P.PID_x_LowerSaturationLimit;
  } else {
    Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_B.DeadZone_n;
  }

  // Sum: '<S13>/Subtract' incorporates:
  //   DataTypeConversion: '<S508>/Data Type Conversion'
  //   Saturate: '<S440>/Saturation'

  Quadcopter_Controller_B.Saturation = Quadcopter_Controller_B.In1.vx -
    Quadcopter_Controller_B.Filter_hc;

  // Saturate: '<S494>/Saturation'
  if (Quadcopter_Controller_B.DeadZone >
      Quadcopter_Controller_P.PID_y_UpperSaturationLimit) {
    Quadcopter_Controller_B.Filter_hc =
      Quadcopter_Controller_P.PID_y_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.DeadZone <
             Quadcopter_Controller_P.PID_y_LowerSaturationLimit) {
    Quadcopter_Controller_B.Filter_hc =
      Quadcopter_Controller_P.PID_y_LowerSaturationLimit;
  } else {
    Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_B.DeadZone;
  }

  // Sum: '<S13>/Subtract' incorporates:
  //   DataTypeConversion: '<S508>/Data Type Conversion'
  //   Saturate: '<S494>/Saturation'

  Quadcopter_Controller_B.TSamp = Quadcopter_Controller_B.In1.vy -
    Quadcopter_Controller_B.Filter_hc;

  // Product: '<S13>/MatrixMultiply' incorporates:
  //   MATLAB Function: '<S13>/Rotation mat '

  rtb_MatrixMultiply_idx_0 = Quadcopter_Controller_B.FilterCoefficient_db *
    Quadcopter_Controller_B.Saturation + rtb_MatrixMultiply_idx_1 *
    Quadcopter_Controller_B.TSamp;
  rtb_MatrixMultiply_idx_1 = -rtb_MatrixMultiply_idx_1 *
    Quadcopter_Controller_B.Saturation +
    Quadcopter_Controller_B.FilterCoefficient_db * Quadcopter_Controller_B.TSamp;

  // Gain: '<S278>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S270>/Filter'
  //   Gain: '<S268>/Derivative Gain'
  //   Sum: '<S270>/SumD'

  Quadcopter_Controller_B.FilterCoefficient_db =
    (Quadcopter_Controller_P.PID_vx_D * rtb_MatrixMultiply_idx_0 -
     Quadcopter_Controller_DW.Filter_DSTATE_o) *
    Quadcopter_Controller_P.PID_vx_N;

  // Sum: '<S284>/Sum' incorporates:
  //   DiscreteIntegrator: '<S275>/Integrator'
  //   Gain: '<S280>/Proportional Gain'

  Quadcopter_Controller_B.Saturation = (Quadcopter_Controller_P.PID_vx_P *
    rtb_MatrixMultiply_idx_0 + Quadcopter_Controller_DW.Integrator_DSTATE_f) +
    Quadcopter_Controller_B.FilterCoefficient_db;

  // Saturate: '<S282>/Saturation'
  if (Quadcopter_Controller_B.Saturation >
      Quadcopter_Controller_P.PID_vx_UpperSaturationLimit) {
    Quadcopter_Controller_B.Saturation =
      Quadcopter_Controller_P.PID_vx_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.Saturation <
             Quadcopter_Controller_P.PID_vx_LowerSaturationLimit) {
    Quadcopter_Controller_B.Saturation =
      Quadcopter_Controller_P.PID_vx_LowerSaturationLimit;
  }

  // End of Saturate: '<S282>/Saturation'

  // Sum: '<S12>/Add2' incorporates:
  //   Gain: '<S16>/Gain1'

  Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_B.rtb_Merge_idx_1 -
    Quadcopter_Controller_P.Gain1_Gain_c * Quadcopter_Controller_B.Saturation;

  // DiscreteIntegrator: '<S56>/Integrator' incorporates:
  //   Gain: '<S53>/Integral Gain'

  Quadcopter_Controller_DW.Integrator_DSTATE_o +=
    Quadcopter_Controller_P.PID_pitch_I * Quadcopter_Controller_B.Filter_hc *
    Quadcopter_Controller_P.Integrator_gainval_ld;

  // Gain: '<S59>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S51>/Filter'
  //   Gain: '<S49>/Derivative Gain'
  //   Sum: '<S51>/SumD'

  Quadcopter_Controller_B.rtb_Merge_idx_1 = (Quadcopter_Controller_P.PID_pitch_D
    * Quadcopter_Controller_B.Filter_hc -
    Quadcopter_Controller_DW.Filter_DSTATE_ox) *
    Quadcopter_Controller_P.PID_pitch_N;

  // Sin: '<S12>/Sine Wave Function'
  if (Quadcopter_Controller_DW.systemEnable_f != 0) {
    Quadcopter_Controller_B.TSamp =
      Quadcopter_Controller_P.SineWaveFunction_Freq *
      Quadcopter_Controller_M->Timing.taskTime0;
    Quadcopter_Controller_DW.lastSin_l = sin(Quadcopter_Controller_B.TSamp);
    Quadcopter_Controller_DW.lastCos_b = cos(Quadcopter_Controller_B.TSamp);
    Quadcopter_Controller_DW.systemEnable_f = 0;
  }

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  // Start for MATLABSystem: '<S2>/SourceBlock'
  if (b_varargout_1_0) {
    // SignalConversion generated from: '<S6>/In1'
    Quadcopter_Controller_B.In1_k = Quadcopter_Controller_B.r2;
    srUpdateBC(Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC_o);
  }

  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'

  // DiscreteFilter: '<S12>/Discrete Filter'
  Quadcopter_Controller_B.Saturation = ((Quadcopter_Controller_B.Saturation -
    Quadcopter_Controller_DW.DiscreteFilter_states[0] *
    Quadcopter_Controller_P.DiscreteFilter_DenCoef[1]) -
    Quadcopter_Controller_DW.DiscreteFilter_states[1] *
    Quadcopter_Controller_P.DiscreteFilter_DenCoef[2]) /
    Quadcopter_Controller_P.DiscreteFilter_DenCoef[0];

  // SampleTimeMath: '<S18>/TSamp' incorporates:
  //   DiscreteFilter: '<S12>/Discrete Filter'
  //
  //  About '<S18>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  Quadcopter_Controller_B.TSamp =
    (Quadcopter_Controller_P.DiscreteFilter_NumCoef[0] *
     Quadcopter_Controller_B.Saturation +
     Quadcopter_Controller_DW.DiscreteFilter_states[0] *
     Quadcopter_Controller_P.DiscreteFilter_NumCoef[1]) *
    Quadcopter_Controller_P.TSamp_WtEt;

  // DigitalClock: '<S12>/Digital Clock'
  Quadcopter_Controller_B.DigitalClock =
    Quadcopter_Controller_M->Timing.taskTime0;

  // Sum: '<S12>/Add' incorporates:
  //   DataTypeConversion: '<S505>/Data Type Conversion1'
  //   Delay: '<S12>/Delay'
  //   Delay: '<S12>/Delay1'
  //   Gain: '<S12>/Gain'
  //   Product: '<S12>/Product'
  //   Product: '<S12>/Product1'
  //   Sum: '<S12>/Subtract'
  //   Sum: '<S12>/Subtract1'
  //   Sum: '<S18>/Diff'
  //   UnitDelay: '<S18>/UD'
  //
  //  Block description for '<S18>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S18>/UD':
  //
  //   Store in Global RAM

  Quadcopter_Controller_DW.Delay_DSTATE += (Quadcopter_Controller_B.In1_k.xyz[1]
    - (Quadcopter_Controller_B.TSamp - Quadcopter_Controller_DW.UD_DSTATE)) *
    Quadcopter_Controller_B.In1_k.xyz[1] * Quadcopter_Controller_P.Gain_Gain_fr *
    (Quadcopter_Controller_B.DigitalClock -
     Quadcopter_Controller_DW.Delay1_DSTATE);

  // Product: '<S12>/Product2' incorporates:
  //   DataTypeConversion: '<S505>/Data Type Conversion1'
  //   Delay: '<S12>/Delay'

  Quadcopter_Controller_B.Product2 = Quadcopter_Controller_B.In1_k.xyz[1] *
    Quadcopter_Controller_DW.Delay_DSTATE;

  // Gain: '<S330>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S322>/Filter'
  //   Gain: '<S320>/Derivative Gain'
  //   Sum: '<S322>/SumD'

  Quadcopter_Controller_B.FilterCoefficient_f =
    (Quadcopter_Controller_P.PID_vy_D * rtb_MatrixMultiply_idx_1 -
     Quadcopter_Controller_DW.Filter_DSTATE_oxe) *
    Quadcopter_Controller_P.PID_vy_N;

  // Sum: '<S336>/Sum' incorporates:
  //   DiscreteIntegrator: '<S327>/Integrator'
  //   Gain: '<S332>/Proportional Gain'

  Quadcopter_Controller_B.IntegralGain_o = (Quadcopter_Controller_P.PID_vy_P *
    rtb_MatrixMultiply_idx_1 + Quadcopter_Controller_DW.Integrator_DSTATE_jo) +
    Quadcopter_Controller_B.FilterCoefficient_f;

  // Saturate: '<S334>/Saturation'
  if (Quadcopter_Controller_B.IntegralGain_o >
      Quadcopter_Controller_P.PID_vy_UpperSaturationLimit) {
    Quadcopter_Controller_B.IntegralGain_o =
      Quadcopter_Controller_P.PID_vy_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.IntegralGain_o <
             Quadcopter_Controller_P.PID_vy_LowerSaturationLimit) {
    Quadcopter_Controller_B.IntegralGain_o =
      Quadcopter_Controller_P.PID_vy_LowerSaturationLimit;
  }

  // Sum: '<S12>/Add3' incorporates:
  //   Gain: '<S13>/Gain'
  //   Gain: '<S17>/Gain1'
  //   Saturate: '<S334>/Saturation'

  Quadcopter_Controller_B.Filter_o = rtb_Merge_idx_2 -
    Quadcopter_Controller_P.Gain_Gain_p * Quadcopter_Controller_B.IntegralGain_o
    * Quadcopter_Controller_P.Gain1_Gain_d;

  // DiscreteIntegrator: '<S108>/Integrator' incorporates:
  //   Gain: '<S105>/Integral Gain'

  Quadcopter_Controller_DW.Integrator_DSTATE_m +=
    Quadcopter_Controller_P.PID_roll_I * Quadcopter_Controller_B.Filter_o *
    Quadcopter_Controller_P.Integrator_gainval_e1;

  // Gain: '<S111>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S103>/Filter'
  //   Gain: '<S101>/Derivative Gain'
  //   Sum: '<S103>/SumD'

  rtb_Merge_idx_2 = (Quadcopter_Controller_P.PID_roll_D *
                     Quadcopter_Controller_B.Filter_o -
                     Quadcopter_Controller_DW.Filter_DSTATE_d) *
    Quadcopter_Controller_P.PID_roll_N;

  // Sum: '<S12>/Add1' incorporates:
  //   Constant: '<S1>/des_yaw'
  //   Gain: '<S15>/Gain1'

  Quadcopter_Controller_B.IntegralGain_o = Quadcopter_Controller_P.Gain1_Gain_n *
    Quadcopter_Controller_P.des_yaw_Value - rtb_Merge_idx_0;

  // Gain: '<S167>/Proportional Gain'
  Quadcopter_Controller_B.Saturation_l = Quadcopter_Controller_P.PID_yaw_P *
    Quadcopter_Controller_B.IntegralGain_o;

  // Gain: '<S165>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S157>/Filter'
  //   Gain: '<S155>/Derivative Gain'
  //   Sum: '<S157>/SumD'

  rtb_Merge_idx_0 = (Quadcopter_Controller_P.PID_yaw_D *
                     Quadcopter_Controller_B.IntegralGain_o -
                     Quadcopter_Controller_DW.Filter_DSTATE_k) *
    Quadcopter_Controller_P.PID_yaw_N;

  // Sum: '<S172>/Sum Fdbk'
  Quadcopter_Controller_B.DeadZone_l = (Quadcopter_Controller_B.Saturation_l +
    Quadcopter_Controller_DW.Integrator_DSTATE_i) + rtb_Merge_idx_0;

  // DeadZone: '<S154>/DeadZone'
  if (Quadcopter_Controller_B.DeadZone_l >
      Quadcopter_Controller_P.PID_yaw_UpperSaturationLimit) {
    Quadcopter_Controller_B.DeadZone_l -=
      Quadcopter_Controller_P.PID_yaw_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.DeadZone_l >=
             Quadcopter_Controller_P.PID_yaw_LowerSaturationLimit) {
    Quadcopter_Controller_B.DeadZone_l = 0.0;
  } else {
    Quadcopter_Controller_B.DeadZone_l -=
      Quadcopter_Controller_P.PID_yaw_LowerSaturationLimit;
  }

  // End of DeadZone: '<S154>/DeadZone'

  // Gain: '<S159>/Integral Gain'
  Quadcopter_Controller_B.IntegralGain_o *= Quadcopter_Controller_P.PID_yaw_I;

  // Switch: '<S152>/Switch1' incorporates:
  //   Constant: '<S152>/Clamping_zero'
  //   Constant: '<S152>/Constant'
  //   Constant: '<S152>/Constant2'
  //   RelationalOperator: '<S152>/fix for DT propagation issue'

  if (Quadcopter_Controller_B.DeadZone_l >
      Quadcopter_Controller_P.Clamping_zero_Value_m) {
    tmp_0 = Quadcopter_Controller_P.Constant_Value_nq;
  } else {
    tmp_0 = Quadcopter_Controller_P.Constant2_Value;
  }

  // Switch: '<S152>/Switch2' incorporates:
  //   Constant: '<S152>/Clamping_zero'
  //   Constant: '<S152>/Constant3'
  //   Constant: '<S152>/Constant4'
  //   RelationalOperator: '<S152>/fix for DT propagation issue1'

  if (Quadcopter_Controller_B.IntegralGain_o >
      Quadcopter_Controller_P.Clamping_zero_Value_m) {
    tmp_1 = Quadcopter_Controller_P.Constant3_Value;
  } else {
    tmp_1 = Quadcopter_Controller_P.Constant4_Value;
  }

  // Switch: '<S152>/Switch' incorporates:
  //   Constant: '<S152>/Clamping_zero'
  //   Constant: '<S152>/Constant1'
  //   Logic: '<S152>/AND3'
  //   RelationalOperator: '<S152>/Equal1'
  //   RelationalOperator: '<S152>/Relational Operator'
  //   Switch: '<S152>/Switch1'
  //   Switch: '<S152>/Switch2'

  if ((Quadcopter_Controller_P.Clamping_zero_Value_m !=
       Quadcopter_Controller_B.DeadZone_l) && (tmp_0 == tmp_1)) {
    Quadcopter_Controller_B.IntegralGain_o =
      Quadcopter_Controller_P.Constant1_Value_c;
  }

  // DiscreteIntegrator: '<S162>/Integrator' incorporates:
  //   Switch: '<S152>/Switch'

  Quadcopter_Controller_DW.Integrator_DSTATE_i +=
    Quadcopter_Controller_P.Integrator_gainval_b *
    Quadcopter_Controller_B.IntegralGain_o;

  // Sum: '<S388>/Sum' incorporates:
  //   Gain: '<S384>/Proportional Gain'

  Quadcopter_Controller_B.IntegralGain_o = (Quadcopter_Controller_P.PID_vz_P *
    Quadcopter_Controller_B.Saturation_g +
    Quadcopter_Controller_DW.Integrator_DSTATE_k) +
    Quadcopter_Controller_B.Filter_f;

  // Sum: '<S65>/Sum' incorporates:
  //   Gain: '<S61>/Proportional Gain'

  Quadcopter_Controller_B.Saturation_g = (Quadcopter_Controller_P.PID_pitch_P *
    Quadcopter_Controller_B.Filter_hc +
    Quadcopter_Controller_DW.Integrator_DSTATE_o) +
    Quadcopter_Controller_B.rtb_Merge_idx_1;

  // Sum: '<S117>/Sum' incorporates:
  //   Gain: '<S113>/Proportional Gain'

  Quadcopter_Controller_B.Filter_hc = (Quadcopter_Controller_P.PID_roll_P *
    Quadcopter_Controller_B.Filter_o +
    Quadcopter_Controller_DW.Integrator_DSTATE_m) + rtb_Merge_idx_2;

  // Sum: '<S171>/Sum'
  Quadcopter_Controller_B.Filter_o = (Quadcopter_Controller_B.Saturation_l +
    Quadcopter_Controller_DW.Integrator_DSTATE_i) + rtb_Merge_idx_0;

  // Saturate: '<S386>/Saturation'
  if (Quadcopter_Controller_B.IntegralGain_o >
      Quadcopter_Controller_P.PID_vz_UpperSaturationLimit) {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[0] =
      Quadcopter_Controller_P.PID_vz_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.IntegralGain_o <
             Quadcopter_Controller_P.PID_vz_LowerSaturationLimit) {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[0] =
      Quadcopter_Controller_P.PID_vz_LowerSaturationLimit;
  } else {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[0] = Quadcopter_Controller_B.IntegralGain_o;
  }

  // End of Saturate: '<S386>/Saturation'

  // Saturate: '<S63>/Saturation'
  if (Quadcopter_Controller_B.Saturation_g >
      Quadcopter_Controller_P.PID_pitch_UpperSaturationLimit) {
    Quadcopter_Controller_B.Saturation_g =
      Quadcopter_Controller_P.PID_pitch_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.Saturation_g <
             Quadcopter_Controller_P.PID_pitch_LowerSaturationLimit) {
    Quadcopter_Controller_B.Saturation_g =
      Quadcopter_Controller_P.PID_pitch_LowerSaturationLimit;
  }

  // SignalConversion generated from: '<S14>/Product1' incorporates:
  //   Saturate: '<S63>/Saturation'
  //   Sin: '<S12>/Sine Wave Function'
  //   Sum: '<S12>/Add4'

  Quadcopter_Controller_B.dv[1] = ((((Quadcopter_Controller_DW.lastSin_l *
    Quadcopter_Controller_P.SineWaveFunction_PCos +
    Quadcopter_Controller_DW.lastCos_b *
    Quadcopter_Controller_P.SineWaveFunction_PSin) *
    Quadcopter_Controller_P.SineWaveFunction_HCos +
    (Quadcopter_Controller_DW.lastCos_b *
     Quadcopter_Controller_P.SineWaveFunction_PCos -
     Quadcopter_Controller_DW.lastSin_l *
     Quadcopter_Controller_P.SineWaveFunction_PSin) *
    Quadcopter_Controller_P.SineWaveFunction_Hsin) *
    Quadcopter_Controller_P.SineWaveFunction_Amp +
    Quadcopter_Controller_P.SineWaveFunction_Bias) +
    Quadcopter_Controller_B.Saturation_g) - Quadcopter_Controller_B.Product2;

  // Saturate: '<S115>/Saturation'
  if (Quadcopter_Controller_B.Filter_hc >
      Quadcopter_Controller_P.PID_roll_UpperSaturationLimit) {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[2] =
      Quadcopter_Controller_P.PID_roll_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.Filter_hc <
             Quadcopter_Controller_P.PID_roll_LowerSaturationLimit) {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[2] =
      Quadcopter_Controller_P.PID_roll_LowerSaturationLimit;
  } else {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[2] = Quadcopter_Controller_B.Filter_hc;
  }

  // End of Saturate: '<S115>/Saturation'

  // Saturate: '<S169>/Saturation'
  if (Quadcopter_Controller_B.Filter_o >
      Quadcopter_Controller_P.PID_yaw_UpperSaturationLimit) {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[3] =
      Quadcopter_Controller_P.PID_yaw_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.Filter_o <
             Quadcopter_Controller_P.PID_yaw_LowerSaturationLimit) {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[3] =
      Quadcopter_Controller_P.PID_yaw_LowerSaturationLimit;
  } else {
    // SignalConversion generated from: '<S14>/Product1'
    Quadcopter_Controller_B.dv[3] = Quadcopter_Controller_B.Filter_o;
  }

  // End of Saturate: '<S169>/Saturation'

  // Product: '<S14>/Product1' incorporates:
  //   Constant: '<S14>/Mixer matrix'

  Quadcopter_Controller_B.Filter_o = 0.0;
  Quadcopter_Controller_B.Saturation_l = 0.0;
  Quadcopter_Controller_B.IntegralGain_o = 0.0;
  Quadcopter_Controller_B.Saturation_g = 0.0;
  for (i = 0; i < 4; i++) {
    Quadcopter_Controller_B.Filter_hc = Quadcopter_Controller_B.dv[i];
    i_0 = i << 2;
    Quadcopter_Controller_B.Filter_o +=
      Quadcopter_Controller_P.Mixermatrix_Value[i_0] *
      Quadcopter_Controller_B.Filter_hc;
    Quadcopter_Controller_B.Saturation_l +=
      Quadcopter_Controller_P.Mixermatrix_Value[i_0 + 1] *
      Quadcopter_Controller_B.Filter_hc;
    Quadcopter_Controller_B.IntegralGain_o +=
      Quadcopter_Controller_P.Mixermatrix_Value[i_0 + 2] *
      Quadcopter_Controller_B.Filter_hc;
    Quadcopter_Controller_B.Saturation_g +=
      Quadcopter_Controller_P.Mixermatrix_Value[i_0 + 3] *
      Quadcopter_Controller_B.Filter_hc;
  }

  // End of Product: '<S14>/Product1'

  // Saturate: '<S14>/Saturation'
  if (Quadcopter_Controller_B.Filter_o >
      Quadcopter_Controller_P.Saturation_UpperSat) {
    Quadcopter_Controller_B.Filter_o =
      Quadcopter_Controller_P.Saturation_UpperSat;
  } else if (Quadcopter_Controller_B.Filter_o <
             Quadcopter_Controller_P.Saturation_LowerSat) {
    Quadcopter_Controller_B.Filter_o =
      Quadcopter_Controller_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
  //   Constant: '<S10>/Constant'
  //   Gain: '<S10>/Gain'
  //   Saturate: '<S14>/Saturation'
  //   Sum: '<S10>/Sum'

  Quadcopter_Controller_B.Filter_hc = floor(Quadcopter_Controller_P.Gain_Gain_j *
    Quadcopter_Controller_B.Filter_o + Quadcopter_Controller_P.Constant_Value_o);
  if (rtIsNaN(Quadcopter_Controller_B.Filter_hc) || rtIsInf
      (Quadcopter_Controller_B.Filter_hc)) {
    Quadcopter_Controller_B.Filter_hc = 0.0;
  } else {
    Quadcopter_Controller_B.Filter_hc = fmod(Quadcopter_Controller_B.Filter_hc,
      65536.0);
  }

  // Saturate: '<S14>/Saturation'
  if (Quadcopter_Controller_B.Saturation_l >
      Quadcopter_Controller_P.Saturation_UpperSat) {
    Quadcopter_Controller_B.Saturation_l =
      Quadcopter_Controller_P.Saturation_UpperSat;
  } else if (Quadcopter_Controller_B.Saturation_l <
             Quadcopter_Controller_P.Saturation_LowerSat) {
    Quadcopter_Controller_B.Saturation_l =
      Quadcopter_Controller_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
  //   Constant: '<S10>/Constant'
  //   Gain: '<S10>/Gain'
  //   Saturate: '<S14>/Saturation'
  //   Sum: '<S10>/Sum'

  Quadcopter_Controller_B.Filter_o = floor(Quadcopter_Controller_P.Gain_Gain_j *
    Quadcopter_Controller_B.Saturation_l +
    Quadcopter_Controller_P.Constant_Value_o);
  if (rtIsNaN(Quadcopter_Controller_B.Filter_o) || rtIsInf
      (Quadcopter_Controller_B.Filter_o)) {
    Quadcopter_Controller_B.Filter_o = 0.0;
  } else {
    Quadcopter_Controller_B.Filter_o = fmod(Quadcopter_Controller_B.Filter_o,
      65536.0);
  }

  // Saturate: '<S14>/Saturation'
  if (Quadcopter_Controller_B.IntegralGain_o >
      Quadcopter_Controller_P.Saturation_UpperSat) {
    Quadcopter_Controller_B.IntegralGain_o =
      Quadcopter_Controller_P.Saturation_UpperSat;
  } else if (Quadcopter_Controller_B.IntegralGain_o <
             Quadcopter_Controller_P.Saturation_LowerSat) {
    Quadcopter_Controller_B.IntegralGain_o =
      Quadcopter_Controller_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
  //   Constant: '<S10>/Constant'
  //   Gain: '<S10>/Gain'
  //   Saturate: '<S14>/Saturation'
  //   Sum: '<S10>/Sum'

  Quadcopter_Controller_B.IntegralGain_o = floor
    (Quadcopter_Controller_P.Gain_Gain_j *
     Quadcopter_Controller_B.IntegralGain_o +
     Quadcopter_Controller_P.Constant_Value_o);
  if (rtIsNaN(Quadcopter_Controller_B.IntegralGain_o) || rtIsInf
      (Quadcopter_Controller_B.IntegralGain_o)) {
    Quadcopter_Controller_B.IntegralGain_o = 0.0;
  } else {
    Quadcopter_Controller_B.IntegralGain_o = fmod
      (Quadcopter_Controller_B.IntegralGain_o, 65536.0);
  }

  // Saturate: '<S14>/Saturation'
  if (Quadcopter_Controller_B.Saturation_g >
      Quadcopter_Controller_P.Saturation_UpperSat) {
    Quadcopter_Controller_B.Saturation_g =
      Quadcopter_Controller_P.Saturation_UpperSat;
  } else if (Quadcopter_Controller_B.Saturation_g <
             Quadcopter_Controller_P.Saturation_LowerSat) {
    Quadcopter_Controller_B.Saturation_g =
      Quadcopter_Controller_P.Saturation_LowerSat;
  }

  // DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
  //   Constant: '<S10>/Constant'
  //   Gain: '<S10>/Gain'
  //   Saturate: '<S14>/Saturation'
  //   Sum: '<S10>/Sum'

  Quadcopter_Controller_B.Saturation_g = floor
    (Quadcopter_Controller_P.Gain_Gain_j * Quadcopter_Controller_B.Saturation_g
     + Quadcopter_Controller_P.Constant_Value_o);
  if (rtIsNaN(Quadcopter_Controller_B.Saturation_g) || rtIsInf
      (Quadcopter_Controller_B.Saturation_g)) {
    Quadcopter_Controller_B.Saturation_g = 0.0;
  } else {
    Quadcopter_Controller_B.Saturation_g = fmod
      (Quadcopter_Controller_B.Saturation_g, 65536.0);
  }

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/Constant'
  //   DataTypeConversion: '<S10>/Data Type Conversion'
  //   Logic: '<Root>/NOT'
  //
  for (i = 0; i < 8; i++) {
    Quadcopter_Controller_B.pwmValue[i] = 0U;
  }

  Quadcopter_Controller_B.pwmValue[0] = static_cast<uint16_T>
    (Quadcopter_Controller_B.Filter_hc < 0.0 ? static_cast<int32_T>(static_cast<
      uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Quadcopter_Controller_B.Filter_hc)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Quadcopter_Controller_B.Filter_hc)));
  Quadcopter_Controller_B.pwmValue[1] = static_cast<uint16_T>
    (Quadcopter_Controller_B.Filter_o < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Quadcopter_Controller_B.Filter_o)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Quadcopter_Controller_B.Filter_o)));
  Quadcopter_Controller_B.pwmValue[2] = static_cast<uint16_T>
    (Quadcopter_Controller_B.IntegralGain_o < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Quadcopter_Controller_B.IntegralGain_o)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Quadcopter_Controller_B.IntegralGain_o)));
  Quadcopter_Controller_B.pwmValue[3] = static_cast<uint16_T>
    (Quadcopter_Controller_B.Saturation_g < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Quadcopter_Controller_B.Saturation_g)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Quadcopter_Controller_B.Saturation_g)));
  if (Quadcopter_Controller_P.Constant_Value_a) {
    if (!Quadcopter_Controller_DW.obj_n.isArmed) {
      Quadcopter_Controller_DW.obj_n.isArmed = true;
      pwm_arm(&Quadcopter_Controller_DW.obj_n.armAdvertiseObj);
    }

    pwm_setServo(Quadcopter_Controller_DW.obj_n.servoCount,
                 Quadcopter_Controller_DW.obj_n.channelMask,
                 &Quadcopter_Controller_B.pwmValue[0],
                 Quadcopter_Controller_DW.obj_n.isMain,
                 &Quadcopter_Controller_DW.obj_n.actuatorAdvertiseObj);
  } else {
    pwm_disarm(&Quadcopter_Controller_DW.obj_n.armAdvertiseObj);
    Quadcopter_Controller_DW.obj_n.isArmed = false;
    pwm_resetServo(Quadcopter_Controller_DW.obj_n.servoCount,
                   Quadcopter_Controller_DW.obj_n.isMain,
                   &Quadcopter_Controller_DW.obj_n.actuatorAdvertiseObj);
  }

  if (Quadcopter_Controller_DW.obj_n.isMain) {
    if (!Quadcopter_Controller_P.Constant_Value_a) {
      pwm_disarm(&Quadcopter_Controller_DW.obj_n.armAdvertiseObj);
    } else {
      pwm_arm(&Quadcopter_Controller_DW.obj_n.armAdvertiseObj);
    }
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'
  // DeadZone: '<S425>/DeadZone'
  if (Quadcopter_Controller_B.DeadZone_n >
      Quadcopter_Controller_P.PID_x_UpperSaturationLimit) {
    Quadcopter_Controller_B.DeadZone_n -=
      Quadcopter_Controller_P.PID_x_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.DeadZone_n >=
             Quadcopter_Controller_P.PID_x_LowerSaturationLimit) {
    Quadcopter_Controller_B.DeadZone_n = 0.0;
  } else {
    Quadcopter_Controller_B.DeadZone_n -=
      Quadcopter_Controller_P.PID_x_LowerSaturationLimit;
  }

  // End of DeadZone: '<S425>/DeadZone'

  // Gain: '<S430>/Integral Gain'
  Quadcopter_Controller_B.IntegralGain_j *= Quadcopter_Controller_P.PID_x_I;

  // DeadZone: '<S479>/DeadZone'
  if (Quadcopter_Controller_B.DeadZone >
      Quadcopter_Controller_P.PID_y_UpperSaturationLimit) {
    Quadcopter_Controller_B.DeadZone -=
      Quadcopter_Controller_P.PID_y_UpperSaturationLimit;
  } else if (Quadcopter_Controller_B.DeadZone >=
             Quadcopter_Controller_P.PID_y_LowerSaturationLimit) {
    Quadcopter_Controller_B.DeadZone = 0.0;
  } else {
    Quadcopter_Controller_B.DeadZone -=
      Quadcopter_Controller_P.PID_y_LowerSaturationLimit;
  }

  // End of DeadZone: '<S479>/DeadZone'

  // Gain: '<S484>/Integral Gain'
  Quadcopter_Controller_B.Filter_l *= Quadcopter_Controller_P.PID_y_I;

  // If: '<S515>/If1' incorporates:
  //   Constant: '<S515>/Constant'

  if (Quadcopter_Controller_P.DCM2Ang_action > 1) {
    // Outputs for IfAction SubSystem: '<S515>/If Warning//Error' incorporates:
    //   ActionPort: '<S524>/if'

    // Bias: '<S528>/Bias1' incorporates:
    //   Concatenate: '<S548>/Vector Concatenate'
    //   Math: '<S528>/Math Function'
    //   Product: '<S528>/Product'

    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_VectorConcatenate_tmp = 3 * i_0 + i;
        Quadcopter_Controller_B.rtb_VectorConcatenate_m[rtb_VectorConcatenate_tmp]
          = ((Quadcopter_Controller_B.VectorConcatenate[3 * i + 1] *
              Quadcopter_Controller_B.VectorConcatenate[3 * i_0 + 1] +
              Quadcopter_Controller_B.VectorConcatenate[3 * i] *
              Quadcopter_Controller_B.VectorConcatenate[3 * i_0]) +
             Quadcopter_Controller_B.VectorConcatenate[3 * i + 2] *
             Quadcopter_Controller_B.VectorConcatenate[3 * i_0 + 2]) +
          Quadcopter_Controller_P.Bias1_Bias[rtb_VectorConcatenate_tmp];
      }
    }

    // End of Bias: '<S528>/Bias1'

    // RelationalOperator: '<S536>/Compare' incorporates:
    //   Abs: '<S528>/Abs2'
    //   Constant: '<S536>/Constant'

    for (i = 0; i < 9; i++) {
      Quadcopter_Controller_B.Compare[i] = (fabs
        (Quadcopter_Controller_B.rtb_VectorConcatenate_m[i]) >
        Quadcopter_Controller_P.DCM2Ang_tolerance);
    }

    // End of RelationalOperator: '<S536>/Compare'

    // Logic: '<S528>/Logical Operator1' incorporates:
    //   RelationalOperator: '<S536>/Compare'

    tmp = Quadcopter_Controller_B.Compare[0];
    for (i = 0; i < 8; i++) {
      tmp = (tmp || Quadcopter_Controller_B.Compare[i + 1]);
    }

    // If: '<S524>/If' incorporates:
    //   Abs: '<S529>/Abs1'
    //   Bias: '<S529>/Bias'
    //   Constant: '<S538>/Constant'
    //   Logic: '<S528>/Logical Operator1'
    //   Product: '<S537>/Product'
    //   Product: '<S537>/Product1'
    //   Product: '<S537>/Product2'
    //   Product: '<S537>/Product3'
    //   Product: '<S537>/Product4'
    //   Product: '<S537>/Product5'
    //   RelationalOperator: '<S538>/Compare'
    //   Sum: '<S537>/Sum'

    if (fabs((((((Quadcopter_Controller_B.VectorConcatenate[0] *
                  Quadcopter_Controller_B.VectorConcatenate[4] *
                  Quadcopter_Controller_B.VectorConcatenate[8] -
                  Quadcopter_Controller_B.VectorConcatenate[0] *
                  Quadcopter_Controller_B.VectorConcatenate[5] *
                  Quadcopter_Controller_B.VectorConcatenate[7]) -
                 Quadcopter_Controller_B.VectorConcatenate[1] *
                 Quadcopter_Controller_B.VectorConcatenate[3] *
                 Quadcopter_Controller_B.VectorConcatenate[8]) +
                Quadcopter_Controller_B.VectorConcatenate[2] *
                Quadcopter_Controller_B.VectorConcatenate[3] *
                Quadcopter_Controller_B.VectorConcatenate[7]) +
               Quadcopter_Controller_B.VectorConcatenate[1] *
               Quadcopter_Controller_B.VectorConcatenate[5] *
               Quadcopter_Controller_B.VectorConcatenate[6]) -
              Quadcopter_Controller_B.VectorConcatenate[2] *
              Quadcopter_Controller_B.VectorConcatenate[4] *
              Quadcopter_Controller_B.VectorConcatenate[6]) +
             Quadcopter_Controller_P.Bias_Bias) >
        Quadcopter_Controller_P.DCM2Ang_tolerance) {
      // Outputs for IfAction SubSystem: '<S524>/If Not Proper' incorporates:
      //   ActionPort: '<S527>/Action Port'

      // If: '<S527>/If' incorporates:
      //   Constant: '<S527>/Constant'

      if (Quadcopter_Controller_P.DCM2Ang_action == 2) {
        // Outputs for IfAction SubSystem: '<S527>/Warning' incorporates:
        //   ActionPort: '<S535>/Action Port'

        // Assertion: '<S535>/Assertion' incorporates:
        //   Constant: '<S527>/Constant1'

        utAssert(Quadcopter_Controller_P.Constant1_Value != 0.0);

        // End of Outputs for SubSystem: '<S527>/Warning'

        // Update for IfAction SubSystem: '<S527>/Warning' incorporates:
        //   ActionPort: '<S535>/Action Port'

        // Update for If: '<S527>/If'
        srUpdateBC(Quadcopter_Controller_DW.Warning_SubsysRanBC_f);

        // End of Update for SubSystem: '<S527>/Warning'
      } else if (Quadcopter_Controller_P.DCM2Ang_action == 3) {
        // Outputs for IfAction SubSystem: '<S527>/Error' incorporates:
        //   ActionPort: '<S533>/Action Port'

        // Assertion: '<S533>/Assertion' incorporates:
        //   Constant: '<S527>/Constant1'

        utAssert(Quadcopter_Controller_P.Constant1_Value != 0.0);

        // End of Outputs for SubSystem: '<S527>/Error'

        // Update for IfAction SubSystem: '<S527>/Error' incorporates:
        //   ActionPort: '<S533>/Action Port'

        // Update for If: '<S527>/If'
        srUpdateBC(Quadcopter_Controller_DW.Error_SubsysRanBC_f);

        // End of Update for SubSystem: '<S527>/Error'
      } else {
        // Update for IfAction SubSystem: '<S527>/None' incorporates:
        //   ActionPort: '<S534>/Action Port'

        // Update for If: '<S527>/If'
        srUpdateBC(Quadcopter_Controller_DW.None_SubsysRanBC_a);

        // End of Update for SubSystem: '<S527>/None'
      }

      // End of If: '<S527>/If'
      // End of Outputs for SubSystem: '<S524>/If Not Proper'

      // Update for IfAction SubSystem: '<S524>/If Not Proper' incorporates:
      //   ActionPort: '<S527>/Action Port'

      // Update for If: '<S524>/If'
      srUpdateBC(Quadcopter_Controller_DW.IfNotProper_SubsysRanBC);

      // End of Update for SubSystem: '<S524>/If Not Proper'
    } else if (tmp) {
      // Outputs for IfAction SubSystem: '<S524>/Else If Not Orthogonal' incorporates:
      //   ActionPort: '<S525>/Action Port'

      // If: '<S525>/If' incorporates:
      //   Constant: '<S525>/Constant'

      if (Quadcopter_Controller_P.DCM2Ang_action == 2) {
        // Outputs for IfAction SubSystem: '<S525>/Warning' incorporates:
        //   ActionPort: '<S532>/Action Port'

        // Assertion: '<S532>/Assertion' incorporates:
        //   Constant: '<S525>/Constant1'

        utAssert(Quadcopter_Controller_P.Constant1_Value_d != 0.0);

        // End of Outputs for SubSystem: '<S525>/Warning'

        // Update for IfAction SubSystem: '<S525>/Warning' incorporates:
        //   ActionPort: '<S532>/Action Port'

        // Update for If: '<S525>/If'
        srUpdateBC(Quadcopter_Controller_DW.Warning_SubsysRanBC);

        // End of Update for SubSystem: '<S525>/Warning'
      } else if (Quadcopter_Controller_P.DCM2Ang_action == 3) {
        // Outputs for IfAction SubSystem: '<S525>/Error' incorporates:
        //   ActionPort: '<S530>/Action Port'

        // Assertion: '<S530>/Assertion' incorporates:
        //   Constant: '<S525>/Constant1'

        utAssert(Quadcopter_Controller_P.Constant1_Value_d != 0.0);

        // End of Outputs for SubSystem: '<S525>/Error'

        // Update for IfAction SubSystem: '<S525>/Error' incorporates:
        //   ActionPort: '<S530>/Action Port'

        // Update for If: '<S525>/If'
        srUpdateBC(Quadcopter_Controller_DW.Error_SubsysRanBC);

        // End of Update for SubSystem: '<S525>/Error'
      } else {
        // Update for IfAction SubSystem: '<S525>/None' incorporates:
        //   ActionPort: '<S531>/Action Port'

        // Update for If: '<S525>/If'
        srUpdateBC(Quadcopter_Controller_DW.None_SubsysRanBC);

        // End of Update for SubSystem: '<S525>/None'
      }

      // End of If: '<S525>/If'
      // End of Outputs for SubSystem: '<S524>/Else If Not Orthogonal'

      // Update for IfAction SubSystem: '<S524>/Else If Not Orthogonal' incorporates:
      //   ActionPort: '<S525>/Action Port'

      // Update for If: '<S524>/If'
      srUpdateBC(Quadcopter_Controller_DW.ElseIfNotOrthogonal_SubsysRanBC);

      // End of Update for SubSystem: '<S524>/Else If Not Orthogonal'
    } else {
      // Update for IfAction SubSystem: '<S524>/Else No Action' incorporates:
      //   ActionPort: '<S526>/Action Port'

      // Update for If: '<S524>/If'
      srUpdateBC(Quadcopter_Controller_DW.ElseNoAction_SubsysRanBC);

      // End of Update for SubSystem: '<S524>/Else No Action'
    }

    // End of If: '<S524>/If'
    // End of Outputs for SubSystem: '<S515>/If Warning//Error'

    // Update for IfAction SubSystem: '<S515>/If Warning//Error' incorporates:
    //   ActionPort: '<S524>/if'

    // Update for If: '<S515>/If1'
    srUpdateBC(Quadcopter_Controller_DW.IfWarningError_SubsysRanBC);

    // End of Update for SubSystem: '<S515>/If Warning//Error'
  }

  // End of If: '<S515>/If1'

  // Update for DiscreteIntegrator: '<S218>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE +=
    Quadcopter_Controller_P.Filter_gainval *
    Quadcopter_Controller_B.FilterCoefficient;

  // Update for DiscreteIntegrator: '<S374>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_b +=
    Quadcopter_Controller_P.Filter_gainval_d * Quadcopter_Controller_B.Filter_f;

  // Update for Sin: '<S1>/x+'
  Quadcopter_Controller_B.FilterCoefficient = Quadcopter_Controller_DW.lastSin;
  Quadcopter_Controller_DW.lastSin = Quadcopter_Controller_DW.lastSin *
    Quadcopter_Controller_P.x_HCos + Quadcopter_Controller_DW.lastCos *
    Quadcopter_Controller_P.x_Hsin;
  Quadcopter_Controller_DW.lastCos = Quadcopter_Controller_DW.lastCos *
    Quadcopter_Controller_P.x_HCos - Quadcopter_Controller_B.FilterCoefficient *
    Quadcopter_Controller_P.x_Hsin;

  // Switch: '<S423>/Switch1' incorporates:
  //   Constant: '<S423>/Clamping_zero'
  //   Constant: '<S423>/Constant'
  //   Constant: '<S423>/Constant2'
  //   RelationalOperator: '<S423>/fix for DT propagation issue'

  if (Quadcopter_Controller_B.DeadZone_n >
      Quadcopter_Controller_P.Clamping_zero_Value_e) {
    tmp_0 = Quadcopter_Controller_P.Constant_Value_b;
  } else {
    tmp_0 = Quadcopter_Controller_P.Constant2_Value_j;
  }

  // Switch: '<S423>/Switch2' incorporates:
  //   Constant: '<S423>/Clamping_zero'
  //   Constant: '<S423>/Constant3'
  //   Constant: '<S423>/Constant4'
  //   RelationalOperator: '<S423>/fix for DT propagation issue1'

  if (Quadcopter_Controller_B.IntegralGain_j >
      Quadcopter_Controller_P.Clamping_zero_Value_e) {
    tmp_1 = Quadcopter_Controller_P.Constant3_Value_c;
  } else {
    tmp_1 = Quadcopter_Controller_P.Constant4_Value_g;
  }

  // Switch: '<S423>/Switch' incorporates:
  //   Constant: '<S423>/Clamping_zero'
  //   Constant: '<S423>/Constant1'
  //   Logic: '<S423>/AND3'
  //   RelationalOperator: '<S423>/Equal1'
  //   RelationalOperator: '<S423>/Relational Operator'
  //   Switch: '<S423>/Switch1'
  //   Switch: '<S423>/Switch2'

  if ((Quadcopter_Controller_P.Clamping_zero_Value_e !=
       Quadcopter_Controller_B.DeadZone_n) && (tmp_0 == tmp_1)) {
    Quadcopter_Controller_B.IntegralGain_j =
      Quadcopter_Controller_P.Constant1_Value_ck;
  }

  // Update for DiscreteIntegrator: '<S433>/Integrator' incorporates:
  //   Switch: '<S423>/Switch'

  Quadcopter_Controller_DW.Integrator_DSTATE_b +=
    Quadcopter_Controller_P.Integrator_gainval_lq *
    Quadcopter_Controller_B.IntegralGain_j;

  // Update for DiscreteIntegrator: '<S428>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_f +=
    Quadcopter_Controller_P.Filter_gainval_p *
    Quadcopter_Controller_B.Integrator_l;

  // Update for Sin: '<S1>/y+'
  Quadcopter_Controller_B.FilterCoefficient = Quadcopter_Controller_DW.lastSin_k;
  Quadcopter_Controller_DW.lastSin_k = Quadcopter_Controller_DW.lastSin_k *
    Quadcopter_Controller_P.y_HCos + Quadcopter_Controller_DW.lastCos_e *
    Quadcopter_Controller_P.y_Hsin;
  Quadcopter_Controller_DW.lastCos_e = Quadcopter_Controller_DW.lastCos_e *
    Quadcopter_Controller_P.y_HCos - Quadcopter_Controller_B.FilterCoefficient *
    Quadcopter_Controller_P.y_Hsin;

  // Switch: '<S477>/Switch1' incorporates:
  //   Constant: '<S477>/Clamping_zero'
  //   Constant: '<S477>/Constant'
  //   Constant: '<S477>/Constant2'
  //   RelationalOperator: '<S477>/fix for DT propagation issue'

  if (Quadcopter_Controller_B.DeadZone >
      Quadcopter_Controller_P.Clamping_zero_Value_d) {
    tmp_0 = Quadcopter_Controller_P.Constant_Value_b5;
  } else {
    tmp_0 = Quadcopter_Controller_P.Constant2_Value_a;
  }

  // Switch: '<S477>/Switch2' incorporates:
  //   Constant: '<S477>/Clamping_zero'
  //   Constant: '<S477>/Constant3'
  //   Constant: '<S477>/Constant4'
  //   RelationalOperator: '<S477>/fix for DT propagation issue1'

  if (Quadcopter_Controller_B.Filter_l >
      Quadcopter_Controller_P.Clamping_zero_Value_d) {
    tmp_1 = Quadcopter_Controller_P.Constant3_Value_k;
  } else {
    tmp_1 = Quadcopter_Controller_P.Constant4_Value_k;
  }

  // Switch: '<S477>/Switch' incorporates:
  //   Constant: '<S477>/Clamping_zero'
  //   Constant: '<S477>/Constant1'
  //   Logic: '<S477>/AND3'
  //   RelationalOperator: '<S477>/Equal1'
  //   RelationalOperator: '<S477>/Relational Operator'
  //   Switch: '<S477>/Switch1'
  //   Switch: '<S477>/Switch2'

  if ((Quadcopter_Controller_P.Clamping_zero_Value_d !=
       Quadcopter_Controller_B.DeadZone) && (tmp_0 == tmp_1)) {
    Quadcopter_Controller_B.Filter_l =
      Quadcopter_Controller_P.Constant1_Value_cm;
  }

  // Update for DiscreteIntegrator: '<S487>/Integrator' incorporates:
  //   Switch: '<S477>/Switch'

  Quadcopter_Controller_DW.Integrator_DSTATE_j +=
    Quadcopter_Controller_P.Integrator_gainval_d *
    Quadcopter_Controller_B.Filter_l;

  // Update for DiscreteIntegrator: '<S482>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_j +=
    Quadcopter_Controller_P.Filter_gainval_b *
    Quadcopter_Controller_B.FilterCoefficient_p;

  // Update for DiscreteIntegrator: '<S275>/Integrator' incorporates:
  //   Gain: '<S272>/Integral Gain'

  Quadcopter_Controller_DW.Integrator_DSTATE_f +=
    Quadcopter_Controller_P.PID_vx_I * rtb_MatrixMultiply_idx_0 *
    Quadcopter_Controller_P.Integrator_gainval_e;

  // Update for DiscreteIntegrator: '<S270>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_o +=
    Quadcopter_Controller_P.Filter_gainval_n *
    Quadcopter_Controller_B.FilterCoefficient_db;

  // Update for DiscreteIntegrator: '<S51>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_ox +=
    Quadcopter_Controller_P.Filter_gainval_k *
    Quadcopter_Controller_B.rtb_Merge_idx_1;

  // Update for Sin: '<S12>/Sine Wave Function'
  Quadcopter_Controller_B.FilterCoefficient = Quadcopter_Controller_DW.lastSin_l;
  Quadcopter_Controller_DW.lastSin_l = Quadcopter_Controller_DW.lastSin_l *
    Quadcopter_Controller_P.SineWaveFunction_HCos +
    Quadcopter_Controller_DW.lastCos_b *
    Quadcopter_Controller_P.SineWaveFunction_Hsin;
  Quadcopter_Controller_DW.lastCos_b = Quadcopter_Controller_DW.lastCos_b *
    Quadcopter_Controller_P.SineWaveFunction_HCos -
    Quadcopter_Controller_B.FilterCoefficient *
    Quadcopter_Controller_P.SineWaveFunction_Hsin;

  // Update for DiscreteFilter: '<S12>/Discrete Filter'
  Quadcopter_Controller_DW.DiscreteFilter_states[1] =
    Quadcopter_Controller_DW.DiscreteFilter_states[0];
  Quadcopter_Controller_DW.DiscreteFilter_states[0] =
    Quadcopter_Controller_B.Saturation;

  // Update for UnitDelay: '<S18>/UD'
  //
  //  Block description for '<S18>/UD':
  //
  //   Store in Global RAM

  Quadcopter_Controller_DW.UD_DSTATE = Quadcopter_Controller_B.TSamp;

  // Update for Delay: '<S12>/Delay1'
  Quadcopter_Controller_DW.Delay1_DSTATE = Quadcopter_Controller_B.DigitalClock;

  // Update for DiscreteIntegrator: '<S327>/Integrator' incorporates:
  //   Gain: '<S324>/Integral Gain'

  Quadcopter_Controller_DW.Integrator_DSTATE_jo +=
    Quadcopter_Controller_P.PID_vy_I * rtb_MatrixMultiply_idx_1 *
    Quadcopter_Controller_P.Integrator_gainval_o;

  // Update for DiscreteIntegrator: '<S322>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_oxe +=
    Quadcopter_Controller_P.Filter_gainval_l *
    Quadcopter_Controller_B.FilterCoefficient_f;

  // Update for DiscreteIntegrator: '<S103>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_d +=
    Quadcopter_Controller_P.Filter_gainval_j * rtb_Merge_idx_2;

  // Update for DiscreteIntegrator: '<S157>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_k +=
    Quadcopter_Controller_P.Filter_gainval_i * rtb_Merge_idx_0;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  Quadcopter_Controller_M->Timing.taskTime0 =
    ((time_T)(++Quadcopter_Controller_M->Timing.clockTick0)) *
    Quadcopter_Controller_M->Timing.stepSize0;
}

// Model initialize function
void Quadcopter_Controller_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Quadcopter_Controller_M, -1);
  Quadcopter_Controller_M->Timing.stepSize0 = 0.01;

  // External mode info
  Quadcopter_Controller_M->Sizes.checksums[0] = (3701034561U);
  Quadcopter_Controller_M->Sizes.checksums[1] = (3164872920U);
  Quadcopter_Controller_M->Sizes.checksums[2] = (655389059U);
  Quadcopter_Controller_M->Sizes.checksums[3] = (1919189762U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[43];
    Quadcopter_Controller_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC_o;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Quadcopter_Controller_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &Quadcopter_Controller_DW.AxisRotDefault_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[30] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfActionSubsystem1_SubsysRanB_j;
    systemRan[31] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfActionSubsystem2_SubsysRanB_g;
    systemRan[32] = (sysRanDType *)
      &Quadcopter_Controller_DW.AxisRotZeroR3_SubsysRanBC;
    systemRan[33] = (sysRanDType *)&Quadcopter_Controller_DW.Error_SubsysRanBC;
    systemRan[34] = (sysRanDType *)&Quadcopter_Controller_DW.None_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&Quadcopter_Controller_DW.Warning_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &Quadcopter_Controller_DW.ElseIfNotOrthogonal_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &Quadcopter_Controller_DW.ElseNoAction_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&Quadcopter_Controller_DW.Error_SubsysRanBC_f;
    systemRan[39] = (sysRanDType *)&Quadcopter_Controller_DW.None_SubsysRanBC_a;
    systemRan[40] = (sysRanDType *)
      &Quadcopter_Controller_DW.Warning_SubsysRanBC_f;
    systemRan[41] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfNotProper_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &Quadcopter_Controller_DW.IfWarningError_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Quadcopter_Controller_M->extModeInfo,
      &Quadcopter_Controller_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Quadcopter_Controller_M->extModeInfo,
                        Quadcopter_Controller_M->Sizes.checksums);
    rteiSetTPtr(Quadcopter_Controller_M->extModeInfo, rtmGetTPtr
                (Quadcopter_Controller_M));
  }

  // InitializeConditions for DiscreteIntegrator: '<S218>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE =
    Quadcopter_Controller_P.PID_Altitude_InitialConditionFo;

  // InitializeConditions for DiscreteIntegrator: '<S223>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE =
    Quadcopter_Controller_P.PID_Altitude_InitialCondition_j;

  // InitializeConditions for DiscreteIntegrator: '<S379>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_k =
    Quadcopter_Controller_P.PID_vz_InitialConditionForInteg;

  // InitializeConditions for DiscreteIntegrator: '<S374>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_b =
    Quadcopter_Controller_P.PID_vz_InitialConditionForFilte;

  // InitializeConditions for DiscreteIntegrator: '<S433>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_b =
    Quadcopter_Controller_P.PID_x_InitialConditionForIntegr;

  // InitializeConditions for DiscreteIntegrator: '<S428>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_f =
    Quadcopter_Controller_P.PID_x_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S487>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_j =
    Quadcopter_Controller_P.PID_y_InitialConditionForIntegr;

  // InitializeConditions for DiscreteIntegrator: '<S482>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_j =
    Quadcopter_Controller_P.PID_y_InitialConditionForFilter;

  // InitializeConditions for DiscreteIntegrator: '<S275>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_f =
    Quadcopter_Controller_P.PID_vx_InitialConditionForInteg;

  // InitializeConditions for DiscreteIntegrator: '<S270>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_o =
    Quadcopter_Controller_P.PID_vx_InitialConditionForFilte;

  // InitializeConditions for DiscreteIntegrator: '<S56>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_o =
    Quadcopter_Controller_P.PID_pitch_InitialConditionForIn;

  // InitializeConditions for DiscreteIntegrator: '<S51>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_ox =
    Quadcopter_Controller_P.PID_pitch_InitialConditionForFi;

  // InitializeConditions for DiscreteFilter: '<S12>/Discrete Filter'
  Quadcopter_Controller_DW.DiscreteFilter_states[0] =
    Quadcopter_Controller_P.DiscreteFilter_InitialStates;
  Quadcopter_Controller_DW.DiscreteFilter_states[1] =
    Quadcopter_Controller_P.DiscreteFilter_InitialStates;

  // InitializeConditions for UnitDelay: '<S18>/UD'
  //
  //  Block description for '<S18>/UD':
  //
  //   Store in Global RAM

  Quadcopter_Controller_DW.UD_DSTATE =
    Quadcopter_Controller_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for Delay: '<S12>/Delay1'
  Quadcopter_Controller_DW.Delay1_DSTATE =
    Quadcopter_Controller_P.Delay1_InitialCondition;

  // InitializeConditions for Delay: '<S12>/Delay'
  Quadcopter_Controller_DW.Delay_DSTATE =
    Quadcopter_Controller_P.Delay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S327>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_jo =
    Quadcopter_Controller_P.PID_vy_InitialConditionForInteg;

  // InitializeConditions for DiscreteIntegrator: '<S322>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_oxe =
    Quadcopter_Controller_P.PID_vy_InitialConditionForFilte;

  // InitializeConditions for DiscreteIntegrator: '<S108>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_m =
    Quadcopter_Controller_P.PID_roll_InitialConditionForInt;

  // InitializeConditions for DiscreteIntegrator: '<S103>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_d =
    Quadcopter_Controller_P.PID_roll_InitialConditionForFil;

  // InitializeConditions for DiscreteIntegrator: '<S157>/Filter'
  Quadcopter_Controller_DW.Filter_DSTATE_k =
    Quadcopter_Controller_P.PID_yaw_InitialConditionForFilt;

  // InitializeConditions for DiscreteIntegrator: '<S162>/Integrator'
  Quadcopter_Controller_DW.Integrator_DSTATE_i =
    Quadcopter_Controller_P.PID_yaw_InitialConditionForInte;

  // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
  //   Outport: '<S8>/Out1'

  Quadcopter_Controller_B.In1 = Quadcopter_Controller_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
  //   Outport: '<S7>/Out1'

  Quadcopter_Controller_B.In1_b = Quadcopter_Controller_P.Out1_Y0_o;

  // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S2>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
  //   Outport: '<S6>/Out1'

  Quadcopter_Controller_B.In1_k = Quadcopter_Controller_P.Out1_Y0_k;

  // End of SystemInitialize for SubSystem: '<S2>/Enabled Subsystem'

  // Start for MATLABSystem: '<S3>/SourceBlock'
  Quadcopter_Controller_DW.obj_m.matlabCodegenIsDeleted = false;
  Quadcopter_Controller_DW.obj_m.isSetupComplete = false;
  Quadcopter_Controller_DW.obj_m.isInitialized = 1;
  Quadcopter_Controller_DW.obj_m.orbMetadataObj = ORB_ID
    (vehicle_attitude_groundtruth);
  uORB_read_initialize(Quadcopter_Controller_DW.obj_m.orbMetadataObj,
                       &Quadcopter_Controller_DW.obj_m.eventStructObj);
  Quadcopter_Controller_DW.obj_m.isSetupComplete = true;

  // Start for MATLABSystem: '<S4>/SourceBlock'
  Quadcopter_Controller_DW.obj.matlabCodegenIsDeleted = false;
  Quadcopter_Controller_DW.obj.isSetupComplete = false;
  Quadcopter_Controller_DW.obj.isInitialized = 1;
  Quadcopter_Controller_DW.obj.orbMetadataObj = ORB_ID
    (vehicle_local_position_groundtruth);
  uORB_read_initialize(Quadcopter_Controller_DW.obj.orbMetadataObj,
                       &Quadcopter_Controller_DW.obj.eventStructObj);
  Quadcopter_Controller_DW.obj.isSetupComplete = true;

  // Start for MATLABSystem: '<S2>/SourceBlock'
  Quadcopter_Controller_DW.obj_c.matlabCodegenIsDeleted = false;
  Quadcopter_Controller_DW.obj_c.isSetupComplete = false;
  Quadcopter_Controller_DW.obj_c.isInitialized = 1;
  Quadcopter_Controller_DW.obj_c.orbMetadataObj = ORB_ID
    (vehicle_angular_velocity_groundtruth);
  uORB_read_initialize(Quadcopter_Controller_DW.obj_c.orbMetadataObj,
                       &Quadcopter_Controller_DW.obj_c.eventStructObj);
  Quadcopter_Controller_DW.obj_c.isSetupComplete = true;

  // Start for MATLABSystem: '<Root>/PX4 PWM Output'
  Quadcopter_Controller_DW.obj_n.matlabCodegenIsDeleted = false;
  Quadcopter_Controller_DW.obj_n.isSetupComplete = false;
  Quadcopter_Controller_DW.obj_n.isInitialized = 1;
  Quadcopter_Contro_PWM_setupImpl(&Quadcopter_Controller_DW.obj_n, false, false);
  Quadcopter_Controller_DW.obj_n.isSetupComplete = true;

  // Enable for Sin: '<S1>/x+'
  Quadcopter_Controller_DW.systemEnable = 1;

  // Enable for Sin: '<S1>/y+'
  Quadcopter_Controller_DW.systemEnable_e = 1;

  // Enable for Sin: '<S12>/Sine Wave Function'
  Quadcopter_Controller_DW.systemEnable_f = 1;
}

// Model terminate function
void Quadcopter_Controller_terminate(void)
{
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!Quadcopter_Controller_DW.obj_m.matlabCodegenIsDeleted) {
    Quadcopter_Controller_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Quadcopter_Controller_DW.obj_m.isInitialized == 1) &&
        Quadcopter_Controller_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&Quadcopter_Controller_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!Quadcopter_Controller_DW.obj.matlabCodegenIsDeleted) {
    Quadcopter_Controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((Quadcopter_Controller_DW.obj.isInitialized == 1) &&
        Quadcopter_Controller_DW.obj.isSetupComplete) {
      uORB_read_terminate(&Quadcopter_Controller_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!Quadcopter_Controller_DW.obj_c.matlabCodegenIsDeleted) {
    Quadcopter_Controller_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Quadcopter_Controller_DW.obj_c.isInitialized == 1) &&
        Quadcopter_Controller_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&Quadcopter_Controller_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  if (!Quadcopter_Controller_DW.obj_n.matlabCodegenIsDeleted) {
    Quadcopter_Controller_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Quadcopter_Controller_DW.obj_n.isInitialized == 1) &&
        Quadcopter_Controller_DW.obj_n.isSetupComplete) {
      pwm_disarm(&Quadcopter_Controller_DW.obj_n.armAdvertiseObj);
      pwm_resetServo(Quadcopter_Controller_DW.obj_n.servoCount,
                     Quadcopter_Controller_DW.obj_n.isMain,
                     &Quadcopter_Controller_DW.obj_n.actuatorAdvertiseObj);
      pwm_close(Quadcopter_Controller_DW.obj_n.servoCount,
                &Quadcopter_Controller_DW.obj_n.actuatorAdvertiseObj,
                &Quadcopter_Controller_DW.obj_n.armAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
}

//
// File trailer for generated code.
//
// [EOF]
//
