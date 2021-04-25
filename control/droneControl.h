/*
 * droneControl.h
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

#ifndef RTW_HEADER_droneControl_h_
#define RTW_HEADER_droneControl_h_
#include <stddef.h>
#include "rtw_modelmap.h"
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "droneControl_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S39>/Integrator' */
  real_T UD_DSTATE;                    /* '<S32>/UD' */
  real_T Integrator_DSTATE_i;          /* '<S135>/Integrator' */
  real_T Filter_DSTATE;                /* '<S130>/Filter' */
  real_T Integrator_DSTATE_b;          /* '<S87>/Integrator' */
  real_T Filter_DSTATE_a;              /* '<S82>/Filter' */
  real_T Integrator_DSTATE_p;          /* '<S183>/Integrator' */
  real_T Filter_DSTATE_l;              /* '<S178>/Filter' */
} DW_droneControl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T altitude_setpoint;            /* '<Root>/altitude_setpoint' */
  real_T roll_setpoint;                /* '<Root>/roll_setpoint' */
  real_T pitch_setpoint;               /* '<Root>/pitch_setpoint' */
  real_T yaw_setpoint;                 /* '<Root>/yaw_setpoint' */
  real_T altitude_value;               /* '<Root>/altitude_value' */
  real_T roll_value;                   /* '<Root>/roll_value' */
  real_T pitch_value;                  /* '<Root>/pitch_value' */
  real_T yaw_value;                    /* '<Root>/yaw_value' */
} ExtU_droneControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T motor_rf_throttle;            /* '<Root>/motor_rf_throttle' */
  real_T motor_rb_throttle;            /* '<Root>/motor_rb_throttle' */
  real_T motor_lb_throttle;            /* '<Root>/motor_lb_throttle' */
  real_T motor_lf_throttle;            /* '<Root>/motor_lf_throttle' */
} ExtY_droneControl_T;

/* Parameters (default storage) */
struct P_droneControl_T_ {
  real_T altitude_pid_D;               /* Mask Parameter: altitude_pid_D
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T roll_pid_D;                   /* Mask Parameter: roll_pid_D
                                        * Referenced by: '<S129>/Derivative Gain'
                                        */
  real_T pitch_pid_D;                  /* Mask Parameter: pitch_pid_D
                                        * Referenced by: '<S81>/Derivative Gain'
                                        */
  real_T yaw_pid_D;                    /* Mask Parameter: yaw_pid_D
                                        * Referenced by: '<S177>/Derivative Gain'
                                        */
  real_T altitude_pid_DifferentiatorICPr;
                              /* Mask Parameter: altitude_pid_DifferentiatorICPr
                               * Referenced by: '<S32>/UD'
                               */
  real_T altitude_pid_I;               /* Mask Parameter: altitude_pid_I
                                        * Referenced by: '<S36>/Integral Gain'
                                        */
  real_T pitch_pid_I;                  /* Mask Parameter: pitch_pid_I
                                        * Referenced by: '<S84>/Integral Gain'
                                        */
  real_T roll_pid_I;                   /* Mask Parameter: roll_pid_I
                                        * Referenced by: '<S132>/Integral Gain'
                                        */
  real_T yaw_pid_I;                    /* Mask Parameter: yaw_pid_I
                                        * Referenced by: '<S180>/Integral Gain'
                                        */
  real_T roll_pid_InitialConditionForFil;
                              /* Mask Parameter: roll_pid_InitialConditionForFil
                               * Referenced by: '<S130>/Filter'
                               */
  real_T pitch_pid_InitialConditionForFi;
                              /* Mask Parameter: pitch_pid_InitialConditionForFi
                               * Referenced by: '<S82>/Filter'
                               */
  real_T yaw_pid_InitialConditionForFilt;
                              /* Mask Parameter: yaw_pid_InitialConditionForFilt
                               * Referenced by: '<S178>/Filter'
                               */
  real_T altitude_pid_InitialConditionFo;
                              /* Mask Parameter: altitude_pid_InitialConditionFo
                               * Referenced by: '<S39>/Integrator'
                               */
  real_T roll_pid_InitialConditionForInt;
                              /* Mask Parameter: roll_pid_InitialConditionForInt
                               * Referenced by: '<S135>/Integrator'
                               */
  real_T pitch_pid_InitialConditionForIn;
                              /* Mask Parameter: pitch_pid_InitialConditionForIn
                               * Referenced by: '<S87>/Integrator'
                               */
  real_T yaw_pid_InitialConditionForInte;
                              /* Mask Parameter: yaw_pid_InitialConditionForInte
                               * Referenced by: '<S183>/Integrator'
                               */
  real_T roll_pid_N;                   /* Mask Parameter: roll_pid_N
                                        * Referenced by: '<S138>/Filter Coefficient'
                                        */
  real_T pitch_pid_N;                  /* Mask Parameter: pitch_pid_N
                                        * Referenced by: '<S90>/Filter Coefficient'
                                        */
  real_T yaw_pid_N;                    /* Mask Parameter: yaw_pid_N
                                        * Referenced by: '<S186>/Filter Coefficient'
                                        */
  real_T altitude_pid_P;               /* Mask Parameter: altitude_pid_P
                                        * Referenced by: '<S44>/Proportional Gain'
                                        */
  real_T roll_pid_P;                   /* Mask Parameter: roll_pid_P
                                        * Referenced by: '<S140>/Proportional Gain'
                                        */
  real_T pitch_pid_P;                  /* Mask Parameter: pitch_pid_P
                                        * Referenced by: '<S92>/Proportional Gain'
                                        */
  real_T yaw_pid_P;                    /* Mask Parameter: yaw_pid_P
                                        * Referenced by: '<S188>/Proportional Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S34>/Tsamp'
                                        */
  real_T Integrator_gainval_j;       /* Computed Parameter: Integrator_gainval_j
                                      * Referenced by: '<S135>/Integrator'
                                      */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S130>/Filter'
                                        */
  real_T Integrator_gainval_jn;     /* Computed Parameter: Integrator_gainval_jn
                                     * Referenced by: '<S87>/Integrator'
                                     */
  real_T Filter_gainval_l;             /* Computed Parameter: Filter_gainval_l
                                        * Referenced by: '<S82>/Filter'
                                        */
  real_T Integrator_gainval_o;       /* Computed Parameter: Integrator_gainval_o
                                      * Referenced by: '<S183>/Integrator'
                                      */
  real_T Filter_gainval_j;             /* Computed Parameter: Filter_gainval_j
                                        * Referenced by: '<S178>/Filter'
                                        */
  real_T m1_sat_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S2>/m1_sat'
                                        */
  real_T m1_sat_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S2>/m1_sat'
                                        */
  real_T m2_sat_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S2>/m2_sat'
                                        */
  real_T m2_sat_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S2>/m2_sat'
                                        */
  real_T m3_sat_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S2>/m3_sat'
                                        */
  real_T m3_sat_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S2>/m3_sat'
                                        */
  real_T m4_sat_UpperSat;              /* Expression: 1
                                        * Referenced by: '<S2>/m4_sat'
                                        */
  real_T m4_sat_LowerSat;              /* Expression: 0
                                        * Referenced by: '<S2>/m4_sat'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_droneControl_T {
  const char_T *errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[39];
    int32_T* vardimsAddress[39];
    RTWLoggingFcnPtr loggingPtrs[39];
  } DataMapInfo;
};

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  droneControl_GetCAPIStaticMap(void);

/* Class declaration for model droneControl */
class droneControlModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  droneControlModelClass();

  /* Destructor */
  ~droneControlModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_droneControl_T* pExtU_droneControl_T)
  {
    droneControl_U = *pExtU_droneControl_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_droneControl_T & getExternalOutputs() const
  {
    return droneControl_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_droneControl_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_droneControl_T droneControl_P;

  /* Block states */
  DW_droneControl_T droneControl_DW;

  /* External inputs */
  ExtU_droneControl_T droneControl_U;

  /* External outputs */
  ExtY_droneControl_T droneControl_Y;

  /* Real-Time Model */
  RT_MODEL_droneControl_T droneControl_M;
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'droneControl'
 * '<S1>'   : 'droneControl/altitude_pid'
 * '<S2>'   : 'droneControl/motor_mixing'
 * '<S3>'   : 'droneControl/pitch_pid'
 * '<S4>'   : 'droneControl/roll_pid'
 * '<S5>'   : 'droneControl/yaw_pid'
 * '<S6>'   : 'droneControl/altitude_pid/Anti-windup'
 * '<S7>'   : 'droneControl/altitude_pid/D Gain'
 * '<S8>'   : 'droneControl/altitude_pid/Filter'
 * '<S9>'   : 'droneControl/altitude_pid/Filter ICs'
 * '<S10>'  : 'droneControl/altitude_pid/I Gain'
 * '<S11>'  : 'droneControl/altitude_pid/Ideal P Gain'
 * '<S12>'  : 'droneControl/altitude_pid/Ideal P Gain Fdbk'
 * '<S13>'  : 'droneControl/altitude_pid/Integrator'
 * '<S14>'  : 'droneControl/altitude_pid/Integrator ICs'
 * '<S15>'  : 'droneControl/altitude_pid/N Copy'
 * '<S16>'  : 'droneControl/altitude_pid/N Gain'
 * '<S17>'  : 'droneControl/altitude_pid/P Copy'
 * '<S18>'  : 'droneControl/altitude_pid/Parallel P Gain'
 * '<S19>'  : 'droneControl/altitude_pid/Reset Signal'
 * '<S20>'  : 'droneControl/altitude_pid/Saturation'
 * '<S21>'  : 'droneControl/altitude_pid/Saturation Fdbk'
 * '<S22>'  : 'droneControl/altitude_pid/Sum'
 * '<S23>'  : 'droneControl/altitude_pid/Sum Fdbk'
 * '<S24>'  : 'droneControl/altitude_pid/Tracking Mode'
 * '<S25>'  : 'droneControl/altitude_pid/Tracking Mode Sum'
 * '<S26>'  : 'droneControl/altitude_pid/Tsamp - Integral'
 * '<S27>'  : 'droneControl/altitude_pid/Tsamp - Ngain'
 * '<S28>'  : 'droneControl/altitude_pid/postSat Signal'
 * '<S29>'  : 'droneControl/altitude_pid/preSat Signal'
 * '<S30>'  : 'droneControl/altitude_pid/Anti-windup/Passthrough'
 * '<S31>'  : 'droneControl/altitude_pid/D Gain/Internal Parameters'
 * '<S32>'  : 'droneControl/altitude_pid/Filter/Differentiator'
 * '<S33>'  : 'droneControl/altitude_pid/Filter/Differentiator/Tsamp'
 * '<S34>'  : 'droneControl/altitude_pid/Filter/Differentiator/Tsamp/Internal Ts'
 * '<S35>'  : 'droneControl/altitude_pid/Filter ICs/Internal IC - Differentiator'
 * '<S36>'  : 'droneControl/altitude_pid/I Gain/Internal Parameters'
 * '<S37>'  : 'droneControl/altitude_pid/Ideal P Gain/Passthrough'
 * '<S38>'  : 'droneControl/altitude_pid/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'droneControl/altitude_pid/Integrator/Discrete'
 * '<S40>'  : 'droneControl/altitude_pid/Integrator ICs/Internal IC'
 * '<S41>'  : 'droneControl/altitude_pid/N Copy/Disabled wSignal Specification'
 * '<S42>'  : 'droneControl/altitude_pid/N Gain/Passthrough'
 * '<S43>'  : 'droneControl/altitude_pid/P Copy/Disabled'
 * '<S44>'  : 'droneControl/altitude_pid/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'droneControl/altitude_pid/Reset Signal/Disabled'
 * '<S46>'  : 'droneControl/altitude_pid/Saturation/Passthrough'
 * '<S47>'  : 'droneControl/altitude_pid/Saturation Fdbk/Disabled'
 * '<S48>'  : 'droneControl/altitude_pid/Sum/Sum_PID'
 * '<S49>'  : 'droneControl/altitude_pid/Sum Fdbk/Disabled'
 * '<S50>'  : 'droneControl/altitude_pid/Tracking Mode/Disabled'
 * '<S51>'  : 'droneControl/altitude_pid/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'droneControl/altitude_pid/Tsamp - Integral/Passthrough'
 * '<S53>'  : 'droneControl/altitude_pid/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'droneControl/altitude_pid/postSat Signal/Forward_Path'
 * '<S55>'  : 'droneControl/altitude_pid/preSat Signal/Forward_Path'
 * '<S56>'  : 'droneControl/pitch_pid/Anti-windup'
 * '<S57>'  : 'droneControl/pitch_pid/D Gain'
 * '<S58>'  : 'droneControl/pitch_pid/Filter'
 * '<S59>'  : 'droneControl/pitch_pid/Filter ICs'
 * '<S60>'  : 'droneControl/pitch_pid/I Gain'
 * '<S61>'  : 'droneControl/pitch_pid/Ideal P Gain'
 * '<S62>'  : 'droneControl/pitch_pid/Ideal P Gain Fdbk'
 * '<S63>'  : 'droneControl/pitch_pid/Integrator'
 * '<S64>'  : 'droneControl/pitch_pid/Integrator ICs'
 * '<S65>'  : 'droneControl/pitch_pid/N Copy'
 * '<S66>'  : 'droneControl/pitch_pid/N Gain'
 * '<S67>'  : 'droneControl/pitch_pid/P Copy'
 * '<S68>'  : 'droneControl/pitch_pid/Parallel P Gain'
 * '<S69>'  : 'droneControl/pitch_pid/Reset Signal'
 * '<S70>'  : 'droneControl/pitch_pid/Saturation'
 * '<S71>'  : 'droneControl/pitch_pid/Saturation Fdbk'
 * '<S72>'  : 'droneControl/pitch_pid/Sum'
 * '<S73>'  : 'droneControl/pitch_pid/Sum Fdbk'
 * '<S74>'  : 'droneControl/pitch_pid/Tracking Mode'
 * '<S75>'  : 'droneControl/pitch_pid/Tracking Mode Sum'
 * '<S76>'  : 'droneControl/pitch_pid/Tsamp - Integral'
 * '<S77>'  : 'droneControl/pitch_pid/Tsamp - Ngain'
 * '<S78>'  : 'droneControl/pitch_pid/postSat Signal'
 * '<S79>'  : 'droneControl/pitch_pid/preSat Signal'
 * '<S80>'  : 'droneControl/pitch_pid/Anti-windup/Passthrough'
 * '<S81>'  : 'droneControl/pitch_pid/D Gain/Internal Parameters'
 * '<S82>'  : 'droneControl/pitch_pid/Filter/Disc. Forward Euler Filter'
 * '<S83>'  : 'droneControl/pitch_pid/Filter ICs/Internal IC - Filter'
 * '<S84>'  : 'droneControl/pitch_pid/I Gain/Internal Parameters'
 * '<S85>'  : 'droneControl/pitch_pid/Ideal P Gain/Passthrough'
 * '<S86>'  : 'droneControl/pitch_pid/Ideal P Gain Fdbk/Disabled'
 * '<S87>'  : 'droneControl/pitch_pid/Integrator/Discrete'
 * '<S88>'  : 'droneControl/pitch_pid/Integrator ICs/Internal IC'
 * '<S89>'  : 'droneControl/pitch_pid/N Copy/Disabled'
 * '<S90>'  : 'droneControl/pitch_pid/N Gain/Internal Parameters'
 * '<S91>'  : 'droneControl/pitch_pid/P Copy/Disabled'
 * '<S92>'  : 'droneControl/pitch_pid/Parallel P Gain/Internal Parameters'
 * '<S93>'  : 'droneControl/pitch_pid/Reset Signal/Disabled'
 * '<S94>'  : 'droneControl/pitch_pid/Saturation/Passthrough'
 * '<S95>'  : 'droneControl/pitch_pid/Saturation Fdbk/Disabled'
 * '<S96>'  : 'droneControl/pitch_pid/Sum/Sum_PID'
 * '<S97>'  : 'droneControl/pitch_pid/Sum Fdbk/Disabled'
 * '<S98>'  : 'droneControl/pitch_pid/Tracking Mode/Disabled'
 * '<S99>'  : 'droneControl/pitch_pid/Tracking Mode Sum/Passthrough'
 * '<S100>' : 'droneControl/pitch_pid/Tsamp - Integral/Passthrough'
 * '<S101>' : 'droneControl/pitch_pid/Tsamp - Ngain/Passthrough'
 * '<S102>' : 'droneControl/pitch_pid/postSat Signal/Forward_Path'
 * '<S103>' : 'droneControl/pitch_pid/preSat Signal/Forward_Path'
 * '<S104>' : 'droneControl/roll_pid/Anti-windup'
 * '<S105>' : 'droneControl/roll_pid/D Gain'
 * '<S106>' : 'droneControl/roll_pid/Filter'
 * '<S107>' : 'droneControl/roll_pid/Filter ICs'
 * '<S108>' : 'droneControl/roll_pid/I Gain'
 * '<S109>' : 'droneControl/roll_pid/Ideal P Gain'
 * '<S110>' : 'droneControl/roll_pid/Ideal P Gain Fdbk'
 * '<S111>' : 'droneControl/roll_pid/Integrator'
 * '<S112>' : 'droneControl/roll_pid/Integrator ICs'
 * '<S113>' : 'droneControl/roll_pid/N Copy'
 * '<S114>' : 'droneControl/roll_pid/N Gain'
 * '<S115>' : 'droneControl/roll_pid/P Copy'
 * '<S116>' : 'droneControl/roll_pid/Parallel P Gain'
 * '<S117>' : 'droneControl/roll_pid/Reset Signal'
 * '<S118>' : 'droneControl/roll_pid/Saturation'
 * '<S119>' : 'droneControl/roll_pid/Saturation Fdbk'
 * '<S120>' : 'droneControl/roll_pid/Sum'
 * '<S121>' : 'droneControl/roll_pid/Sum Fdbk'
 * '<S122>' : 'droneControl/roll_pid/Tracking Mode'
 * '<S123>' : 'droneControl/roll_pid/Tracking Mode Sum'
 * '<S124>' : 'droneControl/roll_pid/Tsamp - Integral'
 * '<S125>' : 'droneControl/roll_pid/Tsamp - Ngain'
 * '<S126>' : 'droneControl/roll_pid/postSat Signal'
 * '<S127>' : 'droneControl/roll_pid/preSat Signal'
 * '<S128>' : 'droneControl/roll_pid/Anti-windup/Passthrough'
 * '<S129>' : 'droneControl/roll_pid/D Gain/Internal Parameters'
 * '<S130>' : 'droneControl/roll_pid/Filter/Disc. Forward Euler Filter'
 * '<S131>' : 'droneControl/roll_pid/Filter ICs/Internal IC - Filter'
 * '<S132>' : 'droneControl/roll_pid/I Gain/Internal Parameters'
 * '<S133>' : 'droneControl/roll_pid/Ideal P Gain/Passthrough'
 * '<S134>' : 'droneControl/roll_pid/Ideal P Gain Fdbk/Disabled'
 * '<S135>' : 'droneControl/roll_pid/Integrator/Discrete'
 * '<S136>' : 'droneControl/roll_pid/Integrator ICs/Internal IC'
 * '<S137>' : 'droneControl/roll_pid/N Copy/Disabled'
 * '<S138>' : 'droneControl/roll_pid/N Gain/Internal Parameters'
 * '<S139>' : 'droneControl/roll_pid/P Copy/Disabled'
 * '<S140>' : 'droneControl/roll_pid/Parallel P Gain/Internal Parameters'
 * '<S141>' : 'droneControl/roll_pid/Reset Signal/Disabled'
 * '<S142>' : 'droneControl/roll_pid/Saturation/Passthrough'
 * '<S143>' : 'droneControl/roll_pid/Saturation Fdbk/Disabled'
 * '<S144>' : 'droneControl/roll_pid/Sum/Sum_PID'
 * '<S145>' : 'droneControl/roll_pid/Sum Fdbk/Disabled'
 * '<S146>' : 'droneControl/roll_pid/Tracking Mode/Disabled'
 * '<S147>' : 'droneControl/roll_pid/Tracking Mode Sum/Passthrough'
 * '<S148>' : 'droneControl/roll_pid/Tsamp - Integral/Passthrough'
 * '<S149>' : 'droneControl/roll_pid/Tsamp - Ngain/Passthrough'
 * '<S150>' : 'droneControl/roll_pid/postSat Signal/Forward_Path'
 * '<S151>' : 'droneControl/roll_pid/preSat Signal/Forward_Path'
 * '<S152>' : 'droneControl/yaw_pid/Anti-windup'
 * '<S153>' : 'droneControl/yaw_pid/D Gain'
 * '<S154>' : 'droneControl/yaw_pid/Filter'
 * '<S155>' : 'droneControl/yaw_pid/Filter ICs'
 * '<S156>' : 'droneControl/yaw_pid/I Gain'
 * '<S157>' : 'droneControl/yaw_pid/Ideal P Gain'
 * '<S158>' : 'droneControl/yaw_pid/Ideal P Gain Fdbk'
 * '<S159>' : 'droneControl/yaw_pid/Integrator'
 * '<S160>' : 'droneControl/yaw_pid/Integrator ICs'
 * '<S161>' : 'droneControl/yaw_pid/N Copy'
 * '<S162>' : 'droneControl/yaw_pid/N Gain'
 * '<S163>' : 'droneControl/yaw_pid/P Copy'
 * '<S164>' : 'droneControl/yaw_pid/Parallel P Gain'
 * '<S165>' : 'droneControl/yaw_pid/Reset Signal'
 * '<S166>' : 'droneControl/yaw_pid/Saturation'
 * '<S167>' : 'droneControl/yaw_pid/Saturation Fdbk'
 * '<S168>' : 'droneControl/yaw_pid/Sum'
 * '<S169>' : 'droneControl/yaw_pid/Sum Fdbk'
 * '<S170>' : 'droneControl/yaw_pid/Tracking Mode'
 * '<S171>' : 'droneControl/yaw_pid/Tracking Mode Sum'
 * '<S172>' : 'droneControl/yaw_pid/Tsamp - Integral'
 * '<S173>' : 'droneControl/yaw_pid/Tsamp - Ngain'
 * '<S174>' : 'droneControl/yaw_pid/postSat Signal'
 * '<S175>' : 'droneControl/yaw_pid/preSat Signal'
 * '<S176>' : 'droneControl/yaw_pid/Anti-windup/Passthrough'
 * '<S177>' : 'droneControl/yaw_pid/D Gain/Internal Parameters'
 * '<S178>' : 'droneControl/yaw_pid/Filter/Disc. Forward Euler Filter'
 * '<S179>' : 'droneControl/yaw_pid/Filter ICs/Internal IC - Filter'
 * '<S180>' : 'droneControl/yaw_pid/I Gain/Internal Parameters'
 * '<S181>' : 'droneControl/yaw_pid/Ideal P Gain/Passthrough'
 * '<S182>' : 'droneControl/yaw_pid/Ideal P Gain Fdbk/Disabled'
 * '<S183>' : 'droneControl/yaw_pid/Integrator/Discrete'
 * '<S184>' : 'droneControl/yaw_pid/Integrator ICs/Internal IC'
 * '<S185>' : 'droneControl/yaw_pid/N Copy/Disabled'
 * '<S186>' : 'droneControl/yaw_pid/N Gain/Internal Parameters'
 * '<S187>' : 'droneControl/yaw_pid/P Copy/Disabled'
 * '<S188>' : 'droneControl/yaw_pid/Parallel P Gain/Internal Parameters'
 * '<S189>' : 'droneControl/yaw_pid/Reset Signal/Disabled'
 * '<S190>' : 'droneControl/yaw_pid/Saturation/Passthrough'
 * '<S191>' : 'droneControl/yaw_pid/Saturation Fdbk/Disabled'
 * '<S192>' : 'droneControl/yaw_pid/Sum/Sum_PID'
 * '<S193>' : 'droneControl/yaw_pid/Sum Fdbk/Disabled'
 * '<S194>' : 'droneControl/yaw_pid/Tracking Mode/Disabled'
 * '<S195>' : 'droneControl/yaw_pid/Tracking Mode Sum/Passthrough'
 * '<S196>' : 'droneControl/yaw_pid/Tsamp - Integral/Passthrough'
 * '<S197>' : 'droneControl/yaw_pid/Tsamp - Ngain/Passthrough'
 * '<S198>' : 'droneControl/yaw_pid/postSat Signal/Forward_Path'
 * '<S199>' : 'droneControl/yaw_pid/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_droneControl_h_ */
