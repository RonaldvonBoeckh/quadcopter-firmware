/*
 * LPF.cpp
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

#include "LPF_capi.h"
#include "LPF.h"
#include "LPF_private.h"

/* Model step function */
void LPFModelClass::step()
{
  real_T denAccum;
  real_T rtb_Hlp;

  /* S-Function (sdspbiquad): '<Root>/Hlp' incorporates:
   *  Inport: '<Root>/LPF_in'
   */
  denAccum = (0.025278552670006178 * LPF_U.LPF_in - -1.7763683334263993 *
              LPF_DW.Hlp_FILT_STATES[0]) - 0.80193343281258178 *
    LPF_DW.Hlp_FILT_STATES[1];
  rtb_Hlp = (0.0061790608673443657 * denAccum + 0.012358121734688731 *
             LPF_DW.Hlp_FILT_STATES[0]) + 0.0061790608673443657 *
    LPF_DW.Hlp_FILT_STATES[1];
  LPF_DW.Hlp_FILT_STATES[1] = LPF_DW.Hlp_FILT_STATES[0];
  LPF_DW.Hlp_FILT_STATES[0] = denAccum;
  denAccum = (rtb_Hlp - -1.6981369855479791 * LPF_DW.Hlp_FILT_STATES[2]) -
    0.72257619671267515 * LPF_DW.Hlp_FILT_STATES[3];
  rtb_Hlp = (0.0044874467297692866 * denAccum + 0.0089748934595385733 *
             LPF_DW.Hlp_FILT_STATES[2]) + 0.0044874467297692866 *
    LPF_DW.Hlp_FILT_STATES[3];
  LPF_DW.Hlp_FILT_STATES[3] = LPF_DW.Hlp_FILT_STATES[2];
  LPF_DW.Hlp_FILT_STATES[2] = denAccum;
  denAccum = (rtb_Hlp - -1.9256261050698087 * LPF_DW.Hlp_FILT_STATES[4]) -
    0.95333928922783762 * LPF_DW.Hlp_FILT_STATES[5];
  rtb_Hlp = (0.00959714757712422 * denAccum + 0.019194295154248441 *
             LPF_DW.Hlp_FILT_STATES[4]) + 0.00959714757712422 *
    LPF_DW.Hlp_FILT_STATES[5];
  LPF_DW.Hlp_FILT_STATES[5] = LPF_DW.Hlp_FILT_STATES[4];
  LPF_DW.Hlp_FILT_STATES[4] = denAccum;
  denAccum = (rtb_Hlp - -1.7276691219236349 * LPF_DW.Hlp_FILT_STATES[6]) -
    0.75253335305030744 * LPF_DW.Hlp_FILT_STATES[7];
  rtb_Hlp = (0.03896867969467227 * denAccum + 0.07793735938934454 *
             LPF_DW.Hlp_FILT_STATES[6]) + 0.03896867969467227 *
    LPF_DW.Hlp_FILT_STATES[7];
  LPF_DW.Hlp_FILT_STATES[7] = LPF_DW.Hlp_FILT_STATES[6];
  LPF_DW.Hlp_FILT_STATES[6] = denAccum;
  denAccum = (rtb_Hlp - -0.84412528122131092 * LPF_DW.Hlp_FILT_STATES[8]) - 0.0 *
    LPF_DW.Hlp_FILT_STATES[9];
  rtb_Hlp = (0.013218652674995977 * denAccum + 0.013218652674995977 *
             LPF_DW.Hlp_FILT_STATES[8]) + 0.0 * LPF_DW.Hlp_FILT_STATES[9];
  LPF_DW.Hlp_FILT_STATES[9] = LPF_DW.Hlp_FILT_STATES[8];
  LPF_DW.Hlp_FILT_STATES[8] = denAccum;
  denAccum = (rtb_Hlp - -1.8431089663090192 * LPF_DW.Hlp_FILT_STATES[10]) -
    0.86963458209297462 * LPF_DW.Hlp_FILT_STATES[11];

  /* Outport: '<Root>/LPF_out' incorporates:
   *  S-Function (sdspbiquad): '<Root>/Hlp'
   */
  LPF_Y.LPF_out = (0.25083509299448614 * denAccum + 0.50167018598897228 *
                   LPF_DW.Hlp_FILT_STATES[10]) + 0.25083509299448614 *
    LPF_DW.Hlp_FILT_STATES[11];

  /* S-Function (sdspbiquad): '<Root>/Hlp' */
  LPF_DW.Hlp_FILT_STATES[11] = LPF_DW.Hlp_FILT_STATES[10];
  LPF_DW.Hlp_FILT_STATES[10] = denAccum;
}

/* Model initialize function */
void LPFModelClass::initialize()
{
  /* Registration code */

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  LPF_InitializeDataMapInfo((&LPF_M));
}

/* Model terminate function */
void LPFModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
LPFModelClass::LPFModelClass() :
  LPF_DW(),
  LPF_U(),
  LPF_Y(),
  LPF_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
LPFModelClass::~LPFModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_LPF_T * LPFModelClass::getRTM()
{
  return (&LPF_M);
}
