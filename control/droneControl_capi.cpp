/*
 * droneControl_capi.cpp
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "droneControl_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "droneControl.h"
#include "droneControl_capi.h"
#include "droneControl_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 0, TARGET_STRING("droneControl/altitude_pid"),
    TARGET_STRING("P"), 0, 0, 0 },

  { 1, TARGET_STRING("droneControl/altitude_pid"),
    TARGET_STRING("I"), 0, 0, 0 },

  { 2, TARGET_STRING("droneControl/altitude_pid"),
    TARGET_STRING("D"), 0, 0, 0 },

  { 3, TARGET_STRING("droneControl/altitude_pid"),
    TARGET_STRING("InitialConditionForIntegrator"), 0, 0, 0 },

  { 4, TARGET_STRING("droneControl/altitude_pid"),
    TARGET_STRING("DifferentiatorICPrevScaledInput"), 0, 0, 0 },

  { 5, TARGET_STRING("droneControl/pitch_pid"),
    TARGET_STRING("P"), 0, 0, 0 },

  { 6, TARGET_STRING("droneControl/pitch_pid"),
    TARGET_STRING("I"), 0, 0, 0 },

  { 7, TARGET_STRING("droneControl/pitch_pid"),
    TARGET_STRING("D"), 0, 0, 0 },

  { 8, TARGET_STRING("droneControl/pitch_pid"),
    TARGET_STRING("N"), 0, 0, 0 },

  { 9, TARGET_STRING("droneControl/pitch_pid"),
    TARGET_STRING("InitialConditionForIntegrator"), 0, 0, 0 },

  { 10, TARGET_STRING("droneControl/pitch_pid"),
    TARGET_STRING("InitialConditionForFilter"), 0, 0, 0 },

  { 11, TARGET_STRING("droneControl/roll_pid"),
    TARGET_STRING("P"), 0, 0, 0 },

  { 12, TARGET_STRING("droneControl/roll_pid"),
    TARGET_STRING("I"), 0, 0, 0 },

  { 13, TARGET_STRING("droneControl/roll_pid"),
    TARGET_STRING("D"), 0, 0, 0 },

  { 14, TARGET_STRING("droneControl/roll_pid"),
    TARGET_STRING("N"), 0, 0, 0 },

  { 15, TARGET_STRING("droneControl/roll_pid"),
    TARGET_STRING("InitialConditionForIntegrator"), 0, 0, 0 },

  { 16, TARGET_STRING("droneControl/roll_pid"),
    TARGET_STRING("InitialConditionForFilter"), 0, 0, 0 },

  { 17, TARGET_STRING("droneControl/yaw_pid"),
    TARGET_STRING("P"), 0, 0, 0 },

  { 18, TARGET_STRING("droneControl/yaw_pid"),
    TARGET_STRING("I"), 0, 0, 0 },

  { 19, TARGET_STRING("droneControl/yaw_pid"),
    TARGET_STRING("D"), 0, 0, 0 },

  { 20, TARGET_STRING("droneControl/yaw_pid"),
    TARGET_STRING("N"), 0, 0, 0 },

  { 21, TARGET_STRING("droneControl/yaw_pid"),
    TARGET_STRING("InitialConditionForIntegrator"), 0, 0, 0 },

  { 22, TARGET_STRING("droneControl/yaw_pid"),
    TARGET_STRING("InitialConditionForFilter"), 0, 0, 0 },

  { 23, TARGET_STRING("droneControl/motor_mixing/m1_sat"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 24, TARGET_STRING("droneControl/motor_mixing/m1_sat"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 25, TARGET_STRING("droneControl/motor_mixing/m2_sat"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 26, TARGET_STRING("droneControl/motor_mixing/m2_sat"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 27, TARGET_STRING("droneControl/motor_mixing/m3_sat"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 28, TARGET_STRING("droneControl/motor_mixing/m3_sat"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 29, TARGET_STRING("droneControl/motor_mixing/m4_sat"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 30, TARGET_STRING("droneControl/motor_mixing/m4_sat"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 31, TARGET_STRING("droneControl/altitude_pid/Integrator/Discrete/Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 32, TARGET_STRING("droneControl/pitch_pid/Filter/Disc. Forward Euler Filter/Filter"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 33, TARGET_STRING("droneControl/pitch_pid/Integrator/Discrete/Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 34, TARGET_STRING("droneControl/roll_pid/Filter/Disc. Forward Euler Filter/Filter"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 35, TARGET_STRING("droneControl/roll_pid/Integrator/Discrete/Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 36, TARGET_STRING("droneControl/yaw_pid/Filter/Disc. Forward Euler Filter/Filter"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 37, TARGET_STRING("droneControl/yaw_pid/Integrator/Discrete/Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 38, TARGET_STRING("droneControl/altitude_pid/Filter/Differentiator/Tsamp/Internal Ts/Tsamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Initialize Data Address */
static void droneControl_InitializeDataAddr(void* dataAddr[], P_droneControl_T
  *droneControl_P)
{
  dataAddr[0] = (void*) (&droneControl_P->altitude_pid_P);
  dataAddr[1] = (void*) (&droneControl_P->altitude_pid_I);
  dataAddr[2] = (void*) (&droneControl_P->altitude_pid_D);
  dataAddr[3] = (void*) (&droneControl_P->altitude_pid_InitialConditionFo);
  dataAddr[4] = (void*) (&droneControl_P->altitude_pid_DifferentiatorICPr);
  dataAddr[5] = (void*) (&droneControl_P->pitch_pid_P);
  dataAddr[6] = (void*) (&droneControl_P->pitch_pid_I);
  dataAddr[7] = (void*) (&droneControl_P->pitch_pid_D);
  dataAddr[8] = (void*) (&droneControl_P->pitch_pid_N);
  dataAddr[9] = (void*) (&droneControl_P->pitch_pid_InitialConditionForIn);
  dataAddr[10] = (void*) (&droneControl_P->pitch_pid_InitialConditionForFi);
  dataAddr[11] = (void*) (&droneControl_P->roll_pid_P);
  dataAddr[12] = (void*) (&droneControl_P->roll_pid_I);
  dataAddr[13] = (void*) (&droneControl_P->roll_pid_D);
  dataAddr[14] = (void*) (&droneControl_P->roll_pid_N);
  dataAddr[15] = (void*) (&droneControl_P->roll_pid_InitialConditionForInt);
  dataAddr[16] = (void*) (&droneControl_P->roll_pid_InitialConditionForFil);
  dataAddr[17] = (void*) (&droneControl_P->yaw_pid_P);
  dataAddr[18] = (void*) (&droneControl_P->yaw_pid_I);
  dataAddr[19] = (void*) (&droneControl_P->yaw_pid_D);
  dataAddr[20] = (void*) (&droneControl_P->yaw_pid_N);
  dataAddr[21] = (void*) (&droneControl_P->yaw_pid_InitialConditionForInte);
  dataAddr[22] = (void*) (&droneControl_P->yaw_pid_InitialConditionForFilt);
  dataAddr[23] = (void*) (&droneControl_P->m1_sat_UpperSat);
  dataAddr[24] = (void*) (&droneControl_P->m1_sat_LowerSat);
  dataAddr[25] = (void*) (&droneControl_P->m2_sat_UpperSat);
  dataAddr[26] = (void*) (&droneControl_P->m2_sat_LowerSat);
  dataAddr[27] = (void*) (&droneControl_P->m3_sat_UpperSat);
  dataAddr[28] = (void*) (&droneControl_P->m3_sat_LowerSat);
  dataAddr[29] = (void*) (&droneControl_P->m4_sat_UpperSat);
  dataAddr[30] = (void*) (&droneControl_P->m4_sat_LowerSat);
  dataAddr[31] = (void*) (&droneControl_P->Integrator_gainval);
  dataAddr[32] = (void*) (&droneControl_P->Filter_gainval_l);
  dataAddr[33] = (void*) (&droneControl_P->Integrator_gainval_jn);
  dataAddr[34] = (void*) (&droneControl_P->Filter_gainval);
  dataAddr[35] = (void*) (&droneControl_P->Integrator_gainval_j);
  dataAddr[36] = (void*) (&droneControl_P->Filter_gainval_j);
  dataAddr[37] = (void*) (&droneControl_P->Integrator_gainval_o);
  dataAddr[38] = (void*) (&droneControl_P->Tsamp_WtEt);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void droneControl_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void droneControl_InitializeLoggingFunctions(RTWLoggingFcnPtr
  loggingPtrs[])
{
  loggingPtrs[0] = (NULL);
  loggingPtrs[1] = (NULL);
  loggingPtrs[2] = (NULL);
  loggingPtrs[3] = (NULL);
  loggingPtrs[4] = (NULL);
  loggingPtrs[5] = (NULL);
  loggingPtrs[6] = (NULL);
  loggingPtrs[7] = (NULL);
  loggingPtrs[8] = (NULL);
  loggingPtrs[9] = (NULL);
  loggingPtrs[10] = (NULL);
  loggingPtrs[11] = (NULL);
  loggingPtrs[12] = (NULL);
  loggingPtrs[13] = (NULL);
  loggingPtrs[14] = (NULL);
  loggingPtrs[15] = (NULL);
  loggingPtrs[16] = (NULL);
  loggingPtrs[17] = (NULL);
  loggingPtrs[18] = (NULL);
  loggingPtrs[19] = (NULL);
  loggingPtrs[20] = (NULL);
  loggingPtrs[21] = (NULL);
  loggingPtrs[22] = (NULL);
  loggingPtrs[23] = (NULL);
  loggingPtrs[24] = (NULL);
  loggingPtrs[25] = (NULL);
  loggingPtrs[26] = (NULL);
  loggingPtrs[27] = (NULL);
  loggingPtrs[28] = (NULL);
  loggingPtrs[29] = (NULL);
  loggingPtrs[30] = (NULL);
  loggingPtrs[31] = (NULL);
  loggingPtrs[32] = (NULL);
  loggingPtrs[33] = (NULL);
  loggingPtrs[34] = (NULL);
  loggingPtrs[35] = (NULL);
  loggingPtrs[36] = (NULL);
  loggingPtrs[37] = (NULL);
  loggingPtrs[38] = (NULL);
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  {
    (NULL), (NULL), 0, 0
  }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 0,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 39,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2669569682U,
    506825512U,
    334136208U,
    3718422324U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  droneControl_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void droneControl_InitializeDataMapInfo(RT_MODEL_droneControl_T *const
  droneControl_M, P_droneControl_T *droneControl_P)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(droneControl_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(droneControl_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(droneControl_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  droneControl_InitializeDataAddr(droneControl_M->DataMapInfo.dataAddress,
    droneControl_P);
  rtwCAPI_SetDataAddressMap(droneControl_M->DataMapInfo.mmi,
    droneControl_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  droneControl_InitializeVarDimsAddr(droneControl_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(droneControl_M->DataMapInfo.mmi,
    droneControl_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(droneControl_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(droneControl_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  droneControl_InitializeLoggingFunctions
    (droneControl_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(droneControl_M->DataMapInfo.mmi,
    droneControl_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(droneControl_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(droneControl_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(droneControl_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void droneControl_host_InitializeDataMapInfo(droneControl_host_DataMapInfo_T
    *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: droneControl_capi.cpp */
