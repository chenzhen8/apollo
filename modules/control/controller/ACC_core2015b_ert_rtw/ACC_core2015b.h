//
// File: ACC_core2015b.h
//
// Code generated for Simulink model 'ACC_core2015b'.
//
// Model version                  : 1.55
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Mon Nov 29 15:43:13 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ACC_core2015b_h_
#define RTW_HEADER_ACC_core2015b_h_
#include <cstddef>
#include <string>
#include <cstring>
#ifndef ACC_core2015b_COMMON_INCLUDES_
# define ACC_core2015b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 // ACC_core2015b_COMMON_INCLUDES_

#include "ACC_core2015b_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (auto storage)
typedef struct {
  real_T OutportBufferFordesireddistance;// '<S6>/MinMax'
} B_ACC_core2015b_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T Memory_PreviousInput;         // '<S5>/Memory'
} DW_ACC_core2015b_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState InitDesiredtimegapquantity_Trig;// '<S5>/Init Desired time gap quantity' 
} PrevZCX_ACC_core2015b_T;

// Invariant block signals (auto storage)
typedef const struct tag_ConstB_ACC_core2015b_T {
  real_T relvTargetIndex;              // '<S14>/Product'
  real_T TargetDetected;               // '<S14>/Switch'
  real_T NearPntds_p;                  // '<S13>/Product'
  boolean_T NearPntdv_p;               // '<S13>/Logical Operator'
} ConstB_ACC_core2015b_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T DMBrake;                      // '<Root>/DM Brake'
  real_T ReadUserdesiredspeed_1;       // '<Root>/Read User desired speed_1'
  real_T ReadCarvms_1;                 // '<Root>/Read Car.v[m//s]_1'
  real_T ReadUserdesiredtimegap_1;     // '<Root>/Read User desired time gap_1'
  real_T ReadinitdesiredtimegapfromInf_1;// '<Root>/Read init desired time gap from Inf_1' 
  real_T Initialbrakethreshold_1;      // '<Root>/Initial brake threshold_1'
  real_T Acc_Enable;                   // '<Root>/Acc_Enable'
} ExtU_ACC_core2015b_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T Write_ACC_IsActive;           // '<Root>/Write_ACC_IsActive'
  real_T Write_desired_speed;          // '<Root>/Write_desired_speed'
  real_T Write_init_time_gap;          // '<Root>/Write_init_time_gap'
  real_T Write_desired_distance;       // '<Root>/Write_desired_distance'
  real_T WritedesiredAx_1;             // '<Root>/Write desired Ax_1'
} ExtY_ACC_core2015b_T;

// Real-time Model Data Structure
struct tag_RTM_ACC_core2015b_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

extern const ConstB_ACC_core2015b_T ACC_core2015b_ConstB;// constant block i/o

// Class declaration for model ACC_core2015b
class ACC_core2015bModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_ACC_core2015b_T ACC_core2015b_U;

  // External outputs
  ExtY_ACC_core2015b_T ACC_core2015b_Y;

  // Model entry point functions

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  ACC_core2015bModelClass();

  // Destructor
  ~ACC_core2015bModelClass();

  // Real-Time Model get method
  RT_MODEL_ACC_core2015b_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_ACC_core2015b_T ACC_core2015b_B;

  // Block states
  DW_ACC_core2015b_T ACC_core2015b_DW;
  PrevZCX_ACC_core2015b_T ACC_core2015b_PrevZCX;// Triggered events

  // Real-Time Model
  RT_MODEL_ACC_core2015b_T ACC_core2015b_M;
};

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
//  '<Root>' : 'ACC_core2015b'
//  '<S1>'   : 'ACC_core2015b/ACC'
//  '<S2>'   : 'ACC_core2015b/ACC/ACC ECU'
//  '<S3>'   : 'ACC_core2015b/ACC/Sensor'
//  '<S4>'   : 'ACC_core2015b/ACC/ACC ECU/ACC Control'
//  '<S5>'   : 'ACC_core2015b/ACC/ACC ECU/ACC User Input'
//  '<S6>'   : 'ACC_core2015b/ACC/ACC ECU/ACC Control/Desired Distance Calculation with time gap'
//  '<S7>'   : 'ACC_core2015b/ACC/ACC ECU/ACC Control/Distance Control Algorithm'
//  '<S8>'   : 'ACC_core2015b/ACC/ACC ECU/ACC Control/Speed Control Algorithm'
//  '<S9>'   : 'ACC_core2015b/ACC/ACC ECU/ACC Control/Target detected'
//  '<S10>'  : 'ACC_core2015b/ACC/ACC ECU/ACC Control/Distance Control Algorithm/desired ax'
//  '<S11>'  : 'ACC_core2015b/ACC/ACC ECU/ACC Control/Speed Control Algorithm/desired ax'
//  '<S12>'  : 'ACC_core2015b/ACC/ACC ECU/ACC User Input/Init Desired time gap quantity'
//  '<S13>'  : 'ACC_core2015b/ACC/Sensor/Car ObjectSensor Object_1'
//  '<S14>'  : 'ACC_core2015b/ACC/Sensor/Car ObjectSensor_1'

#endif                                 // RTW_HEADER_ACC_core2015b_h_

//
// File trailer for generated code.
//
// [EOF]
//
