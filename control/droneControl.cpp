/*
 * droneControl.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "droneControl".
 *
 * Model version              : 1.12
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C++ source code generated on : Sun Apr 18 18:43:22 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "droneControl_capi.h"
#include "droneControl.h"
#include "droneControl_private.h"

/* Model step function */
void droneControlModelClass::step()
{
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_g;
  real_T rtb_FilterCoefficient_h;
  real_T rtb_Sum;
  real_T rtb_Sum_d;
  real_T rtb_Sum_g;
  real_T rtb_Tsamp;
  real_T rtb_altitude_sum;
  real_T rtb_m4_sat;
  real_T rtb_pitch_sum;
  real_T rtb_roll_sum;
  real_T rtb_yaw_sum;
  real_T u0;
  real_T u0_tmp;

  /* Sum: '<Root>/altitude_sum' incorporates:
   *  Inport: '<Root>/altitude_setpoint'
   *  Inport: '<Root>/altitude_value'
   */
  rtb_altitude_sum = droneControl_U.altitude_setpoint
    - droneControl_U.altitude_value;

  /* SampleTimeMath: '<S34>/Tsamp' incorporates:
   *  Gain: '<S31>/Derivative Gain'
   *
   * About '<S34>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Tsamp = droneControl_P.altitude_pid_D * rtb_altitude_sum *
    droneControl_P.Tsamp_WtEt;

  /* Sum: '<S48>/Sum' incorporates:
   *  Delay: '<S32>/UD'
   *  DiscreteIntegrator: '<S39>/Integrator'
   *  Gain: '<S44>/Proportional Gain'
   *  Sum: '<S32>/Diff'
   */
  rtb_m4_sat = (droneControl_P.altitude_pid_P * rtb_altitude_sum +
                droneControl_DW.Integrator_DSTATE) + (rtb_Tsamp -
    droneControl_DW.UD_DSTATE);

  /* Sum: '<Root>/roll_sum' incorporates:
   *  Inport: '<Root>/roll_setpoint'
   *  Inport: '<Root>/roll_value'
   */
  rtb_roll_sum = droneControl_U.roll_setpoint - droneControl_U.roll_value;

  /* Gain: '<S138>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S130>/Filter'
   *  Gain: '<S129>/Derivative Gain'
   *  Sum: '<S130>/SumD'
   */
  rtb_FilterCoefficient = (droneControl_P.roll_pid_D * rtb_roll_sum -
    droneControl_DW.Filter_DSTATE) * droneControl_P.roll_pid_N;

  /* Sum: '<S144>/Sum' incorporates:
   *  DiscreteIntegrator: '<S135>/Integrator'
   *  Gain: '<S140>/Proportional Gain'
   */
  rtb_Sum = (droneControl_P.roll_pid_P * rtb_roll_sum +
             droneControl_DW.Integrator_DSTATE_i) + rtb_FilterCoefficient;

  /* Sum: '<Root>/pitch_sum' incorporates:
   *  Inport: '<Root>/pitch_setpoint'
   *  Inport: '<Root>/pitch_value'
   */
  rtb_pitch_sum = droneControl_U.pitch_setpoint - droneControl_U.pitch_value;

  /* Gain: '<S90>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S82>/Filter'
   *  Gain: '<S81>/Derivative Gain'
   *  Sum: '<S82>/SumD'
   */
  rtb_FilterCoefficient_h = (droneControl_P.pitch_pid_D * rtb_pitch_sum -
    droneControl_DW.Filter_DSTATE_a) * droneControl_P.pitch_pid_N;

  /* Sum: '<S96>/Sum' incorporates:
   *  DiscreteIntegrator: '<S87>/Integrator'
   *  Gain: '<S92>/Proportional Gain'
   */
  rtb_Sum_g = (droneControl_P.pitch_pid_P * rtb_pitch_sum +
               droneControl_DW.Integrator_DSTATE_b) + rtb_FilterCoefficient_h;

  /* Sum: '<Root>/yaw_sum' incorporates:
   *  Inport: '<Root>/yaw_setpoint'
   *  Inport: '<Root>/yaw_value'
   */
  rtb_yaw_sum = droneControl_U.yaw_setpoint - droneControl_U.yaw_value;

  /* Gain: '<S186>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S178>/Filter'
   *  Gain: '<S177>/Derivative Gain'
   *  Sum: '<S178>/SumD'
   */
  rtb_FilterCoefficient_g = (droneControl_P.yaw_pid_D * rtb_yaw_sum -
    droneControl_DW.Filter_DSTATE_l) * droneControl_P.yaw_pid_N;

  /* Sum: '<S192>/Sum' incorporates:
   *  DiscreteIntegrator: '<S183>/Integrator'
   *  Gain: '<S188>/Proportional Gain'
   */
  rtb_Sum_d = (droneControl_P.yaw_pid_P * rtb_yaw_sum +
               droneControl_DW.Integrator_DSTATE_p) + rtb_FilterCoefficient_g;

  /* Sum: '<S2>/m1_sum' incorporates:
   *  Sum: '<S2>/m2_sum'
   */
  u0_tmp = rtb_m4_sat - rtb_Sum;
  u0 = (u0_tmp - rtb_Sum_g) + rtb_Sum_d;

  /* Saturate: '<S2>/m1_sat' */
  if (u0 > droneControl_P.m1_sat_UpperSat) {
    /* Outport: '<Root>/motor_rf_throttle' */
    droneControl_Y.motor_rf_throttle = droneControl_P.m1_sat_UpperSat;
  } else if (u0 < droneControl_P.m1_sat_LowerSat) {
    /* Outport: '<Root>/motor_rf_throttle' */
    droneControl_Y.motor_rf_throttle = droneControl_P.m1_sat_LowerSat;
  } else {
    /* Outport: '<Root>/motor_rf_throttle' */
    droneControl_Y.motor_rf_throttle = u0;
  }

  /* End of Saturate: '<S2>/m1_sat' */

  /* Sum: '<S2>/m2_sum' */
  u0 = (u0_tmp + rtb_Sum_g) - rtb_Sum_d;

  /* Saturate: '<S2>/m2_sat' */
  if (u0 > droneControl_P.m2_sat_UpperSat) {
    /* Outport: '<Root>/motor_rb_throttle' */
    droneControl_Y.motor_rb_throttle = droneControl_P.m2_sat_UpperSat;
  } else if (u0 < droneControl_P.m2_sat_LowerSat) {
    /* Outport: '<Root>/motor_rb_throttle' */
    droneControl_Y.motor_rb_throttle = droneControl_P.m2_sat_LowerSat;
  } else {
    /* Outport: '<Root>/motor_rb_throttle' */
    droneControl_Y.motor_rb_throttle = u0;
  }

  /* End of Saturate: '<S2>/m2_sat' */

  /* Sum: '<S2>/m3_sum' incorporates:
   *  Sum: '<S2>/m4_sum'
   */
  u0_tmp = rtb_m4_sat + rtb_Sum;
  u0 = (u0_tmp + rtb_Sum_g) + rtb_Sum_d;

  /* Saturate: '<S2>/m3_sat' */
  if (u0 > droneControl_P.m3_sat_UpperSat) {
    /* Outport: '<Root>/motor_lb_throttle' */
    droneControl_Y.motor_lb_throttle = droneControl_P.m3_sat_UpperSat;
  } else if (u0 < droneControl_P.m3_sat_LowerSat) {
    /* Outport: '<Root>/motor_lb_throttle' */
    droneControl_Y.motor_lb_throttle = droneControl_P.m3_sat_LowerSat;
  } else {
    /* Outport: '<Root>/motor_lb_throttle' */
    droneControl_Y.motor_lb_throttle = u0;
  }

  /* End of Saturate: '<S2>/m3_sat' */

  /* Sum: '<S2>/m4_sum' */
  rtb_m4_sat = (u0_tmp - rtb_Sum_g) - rtb_Sum_d;

  /* Saturate: '<S2>/m4_sat' */
  if (rtb_m4_sat > droneControl_P.m4_sat_UpperSat) {
    /* Outport: '<Root>/motor_lf_throttle' */
    droneControl_Y.motor_lf_throttle = droneControl_P.m4_sat_UpperSat;
  } else if (rtb_m4_sat < droneControl_P.m4_sat_LowerSat) {
    /* Outport: '<Root>/motor_lf_throttle' */
    droneControl_Y.motor_lf_throttle = droneControl_P.m4_sat_LowerSat;
  } else {
    /* Outport: '<Root>/motor_lf_throttle' */
    droneControl_Y.motor_lf_throttle = rtb_m4_sat;
  }

  /* End of Saturate: '<S2>/m4_sat' */

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Gain: '<S36>/Integral Gain'
   */
  droneControl_DW.Integrator_DSTATE += droneControl_P.altitude_pid_I *
    rtb_altitude_sum * droneControl_P.Integrator_gainval;

  /* Update for Delay: '<S32>/UD' */
  droneControl_DW.UD_DSTATE = rtb_Tsamp;

  /* Update for DiscreteIntegrator: '<S135>/Integrator' incorporates:
   *  Gain: '<S132>/Integral Gain'
   */
  droneControl_DW.Integrator_DSTATE_i += droneControl_P.roll_pid_I *
    rtb_roll_sum * droneControl_P.Integrator_gainval_j;

  /* Update for DiscreteIntegrator: '<S130>/Filter' */
  droneControl_DW.Filter_DSTATE += droneControl_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S87>/Integrator' incorporates:
   *  Gain: '<S84>/Integral Gain'
   */
  droneControl_DW.Integrator_DSTATE_b += droneControl_P.pitch_pid_I *
    rtb_pitch_sum * droneControl_P.Integrator_gainval_jn;

  /* Update for DiscreteIntegrator: '<S82>/Filter' */
  droneControl_DW.Filter_DSTATE_a += droneControl_P.Filter_gainval_l *
    rtb_FilterCoefficient_h;

  /* Update for DiscreteIntegrator: '<S183>/Integrator' incorporates:
   *  Gain: '<S180>/Integral Gain'
   */
  droneControl_DW.Integrator_DSTATE_p += droneControl_P.yaw_pid_I * rtb_yaw_sum *
    droneControl_P.Integrator_gainval_o;

  /* Update for DiscreteIntegrator: '<S178>/Filter' */
  droneControl_DW.Filter_DSTATE_l += droneControl_P.Filter_gainval_j *
    rtb_FilterCoefficient_g;
}

/* Model initialize function */
void droneControlModelClass::initialize()
{
  /* Registration code */

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  droneControl_InitializeDataMapInfo((&droneControl_M), &droneControl_P);

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
  droneControl_DW.Integrator_DSTATE =
    droneControl_P.altitude_pid_InitialConditionFo;

  /* InitializeConditions for Delay: '<S32>/UD' */
  droneControl_DW.UD_DSTATE = droneControl_P.altitude_pid_DifferentiatorICPr;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator' */
  droneControl_DW.Integrator_DSTATE_i =
    droneControl_P.roll_pid_InitialConditionForInt;

  /* InitializeConditions for DiscreteIntegrator: '<S130>/Filter' */
  droneControl_DW.Filter_DSTATE = droneControl_P.roll_pid_InitialConditionForFil;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator' */
  droneControl_DW.Integrator_DSTATE_b =
    droneControl_P.pitch_pid_InitialConditionForIn;

  /* InitializeConditions for DiscreteIntegrator: '<S82>/Filter' */
  droneControl_DW.Filter_DSTATE_a =
    droneControl_P.pitch_pid_InitialConditionForFi;

  /* InitializeConditions for DiscreteIntegrator: '<S183>/Integrator' */
  droneControl_DW.Integrator_DSTATE_p =
    droneControl_P.yaw_pid_InitialConditionForInte;

  /* InitializeConditions for DiscreteIntegrator: '<S178>/Filter' */
  droneControl_DW.Filter_DSTATE_l =
    droneControl_P.yaw_pid_InitialConditionForFilt;
}

/* Model terminate function */
void droneControlModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
droneControlModelClass::droneControlModelClass() :
  droneControl_DW(),
  droneControl_U(),
  droneControl_Y(),
  droneControl_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
droneControlModelClass::~droneControlModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_droneControl_T * droneControlModelClass::getRTM()
{
  return (&droneControl_M);
}
