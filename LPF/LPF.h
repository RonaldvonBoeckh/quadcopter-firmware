/*
 * LPF.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "LPF".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C++ source code generated on : Tue Mar 23 15:32:11 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LPF_h_
#define RTW_HEADER_LPF_h_
#include <stddef.h>
#include "rtw_modelmap.h"
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "LPF_types.h"

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
  real_T Hlp_FILT_STATES[12];          /* '<Root>/Hlp' */
} DW_LPF_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T LPF_in;                       /* '<Root>/LPF_in' */
} ExtU_LPF_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T LPF_out;                      /* '<Root>/LPF_out' */
} ExtY_LPF_T;

/* Real-time Model Data Structure */
struct tag_RTM_LPF_T {
  const char_T *errorStatus;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;
};

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  LPF_GetCAPIStaticMap(void);

/* Class declaration for model LPF */
class LPFModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  LPFModelClass();

  /* Destructor */
  ~LPFModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_LPF_T* pExtU_LPF_T)
  {
    LPF_U = *pExtU_LPF_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_LPF_T & getExternalOutputs() const
  {
    return LPF_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_LPF_T * getRTM();

  /* private data and function members */
 private:
  /* Block states */
  DW_LPF_T LPF_DW;

  /* External inputs */
  ExtU_LPF_T LPF_U;

  /* External outputs */
  ExtY_LPF_T LPF_Y;

  /* Real-Time Model */
  RT_MODEL_LPF_T LPF_M;
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
 * '<Root>' : 'LPF'
 */
#endif                                 /* RTW_HEADER_LPF_h_ */
