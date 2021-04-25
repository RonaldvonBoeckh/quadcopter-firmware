/*
 * droneControl_data.cpp
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

#include "droneControl.h"
#include "droneControl_private.h"

/* Block parameters (default storage) */
P_droneControl_T droneControlModelClass::droneControl_P = {
  /* Mask Parameter: altitude_pid_D
   * Referenced by: '<S31>/Derivative Gain'
   */
  0.0308636218336235,

  /* Mask Parameter: roll_pid_D
   * Referenced by: '<S129>/Derivative Gain'
   */
  0.175416640693547,

  /* Mask Parameter: pitch_pid_D
   * Referenced by: '<S81>/Derivative Gain'
   */
  0.175416640693547,

  /* Mask Parameter: yaw_pid_D
   * Referenced by: '<S177>/Derivative Gain'
   */
  0.296483303369859,

  /* Mask Parameter: altitude_pid_DifferentiatorICPr
   * Referenced by: '<S32>/UD'
   */
  0.0,

  /* Mask Parameter: altitude_pid_I
   * Referenced by: '<S36>/Integral Gain'
   */
  6.54005393668801E-6,

  /* Mask Parameter: pitch_pid_I
   * Referenced by: '<S84>/Integral Gain'
   */
  2.51315170709284,

  /* Mask Parameter: roll_pid_I
   * Referenced by: '<S132>/Integral Gain'
   */
  2.51315170709284,

  /* Mask Parameter: yaw_pid_I
   * Referenced by: '<S180>/Integral Gain'
   */
  0.00115623045145131,

  /* Mask Parameter: roll_pid_InitialConditionForFil
   * Referenced by: '<S130>/Filter'
   */
  0.0,

  /* Mask Parameter: pitch_pid_InitialConditionForFi
   * Referenced by: '<S82>/Filter'
   */
  0.0,

  /* Mask Parameter: yaw_pid_InitialConditionForFilt
   * Referenced by: '<S178>/Filter'
   */
  0.0,

  /* Mask Parameter: altitude_pid_InitialConditionFo
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Mask Parameter: roll_pid_InitialConditionForInt
   * Referenced by: '<S135>/Integrator'
   */
  0.0,

  /* Mask Parameter: pitch_pid_InitialConditionForIn
   * Referenced by: '<S87>/Integrator'
   */
  0.0,

  /* Mask Parameter: yaw_pid_InitialConditionForInte
   * Referenced by: '<S183>/Integrator'
   */
  0.0,

  /* Mask Parameter: roll_pid_N
   * Referenced by: '<S138>/Filter Coefficient'
   */
  379.058251007336,

  /* Mask Parameter: pitch_pid_N
   * Referenced by: '<S90>/Filter Coefficient'
   */
  379.058251007336,

  /* Mask Parameter: yaw_pid_N
   * Referenced by: '<S186>/Filter Coefficient'
   */
  167.126798653034,

  /* Mask Parameter: altitude_pid_P
   * Referenced by: '<S44>/Proportional Gain'
   */
  0.00089855381315478,

  /* Mask Parameter: roll_pid_P
   * Referenced by: '<S140>/Proportional Gain'
   */
  2.26356117826522,

  /* Mask Parameter: pitch_pid_P
   * Referenced by: '<S92>/Proportional Gain'
   */
  2.26356117826522,

  /* Mask Parameter: yaw_pid_P
   * Referenced by: '<S188>/Proportional Gain'
   */
  0.0591241455018976,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S39>/Integrator'
   */
  0.005,

  /* Computed Parameter: Tsamp_WtEt
   * Referenced by: '<S34>/Tsamp'
   */
  200.0,

  /* Computed Parameter: Integrator_gainval_j
   * Referenced by: '<S135>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S130>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_jn
   * Referenced by: '<S87>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_l
   * Referenced by: '<S82>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_o
   * Referenced by: '<S183>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_j
   * Referenced by: '<S178>/Filter'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S2>/m1_sat'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/m1_sat'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/m2_sat'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/m2_sat'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/m3_sat'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/m3_sat'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/m4_sat'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/m4_sat'
   */
  0.0
};
