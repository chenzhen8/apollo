//
// File: ACC_core2015b.cpp
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
#include "ACC_core2015b.h"
#include "ACC_core2015b_private.h"

// Model step function
void ACC_core2015bModelClass::step()
{
  real_T rtb_desiredorNOTSET;
  real_T rtb_Divide_g;
  ZCEventType zcEvent;
  boolean_T rtb_targetdetected;
  real_T u0;
  int32_T rtb_targetdetected_0;

  // Switch: '<S2>/Switch Brake  ACC on//off' incorporates:
  //   Constant: '<S2>/ACC Off'
  //   Inport: '<Root>/Acc_Enable'
  //   Inport: '<Root>/DM Brake'
  //   Inport: '<Root>/Initial brake threshold_1'
  //   RelationalOperator: '<S2>/Relational Operator'

  if (ACC_core2015b_U.DMBrake > ACC_core2015b_U.Initialbrakethreshold_1) {
    rtb_desiredorNOTSET = 0.0;
  } else {
    rtb_desiredorNOTSET = ACC_core2015b_U.Acc_Enable;
  }

  // End of Switch: '<S2>/Switch Brake  ACC on//off'

  // Outport: '<Root>/Write_ACC_IsActive'
  ACC_core2015b_Y.Write_ACC_IsActive = rtb_desiredorNOTSET;

  // Switch: '<S5>/ACC Active ACC//Actual Speed' incorporates:
  //   Inport: '<Root>/Acc_Enable'
  //   Inport: '<Root>/Read Car.v[m//s]_1'
  //   Inport: '<Root>/Read User desired speed_1'

  if (ACC_core2015b_U.Acc_Enable >= 1.0) {
    rtb_Divide_g = ACC_core2015b_U.ReadUserdesiredspeed_1;
  } else {
    rtb_Divide_g = ACC_core2015b_U.ReadCarvms_1;
  }

  // End of Switch: '<S5>/ACC Active ACC//Actual Speed'

  // Outport: '<Root>/Write_desired_speed'
  ACC_core2015b_Y.Write_desired_speed = rtb_Divide_g;

  // Outputs for Triggered SubSystem: '<S5>/Init Desired time gap quantity' incorporates:
  //   TriggerPort: '<S12>/Trigger'

  // Memory: '<S5>/Memory'
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &ACC_core2015b_PrevZCX.InitDesiredtimegapquantity_Trig,
                     (ACC_core2015b_DW.Memory_PreviousInput));
  if (zcEvent != NO_ZCEVENT) {
    // Outport: '<Root>/Write_init_time_gap' incorporates:
    //   Inport: '<Root>/Read init desired time gap from Inf_1'
    //   Inport: '<S12>/Init desired time gap '

    ACC_core2015b_Y.Write_init_time_gap =
      ACC_core2015b_U.ReadinitdesiredtimegapfromInf_1;
  }

  // End of Outputs for SubSystem: '<S5>/Init Desired time gap quantity'

  // Logic: '<S3>/Logical Operator' incorporates:
  //   Inport: '<Root>/Acc_Enable'

  rtb_targetdetected = ((ACC_core2015b_U.Acc_Enable != 0.0) &&
                        (ACC_core2015b_ConstB.TargetDetected != 0.0));

  // Outputs for Enabled SubSystem: '<S4>/Desired Distance Calculation with time gap' incorporates:
  //   EnablePort: '<S6>/Enable'

  // Logic: '<S4>/Logical Operator' incorporates:
  //   RelationalOperator: '<S9>/Compare'

  if ((rtb_desiredorNOTSET != 0.0) && rtb_targetdetected) {
    // Switch: '<S3>/Switch1' incorporates:
    //   Constant: '<S3>/Target dv'

    if (rtb_targetdetected) {
      rtb_targetdetected_0 = ACC_core2015b_ConstB.NearPntdv_p;
    } else {
      rtb_targetdetected_0 = -1;
    }

    // End of Switch: '<S3>/Switch1'

    // Product: '<S6>/Product' incorporates:
    //   Inport: '<Root>/Read Car.v[m//s]_1'
    //   Inport: '<Root>/Read User desired time gap_1'
    //   Sum: '<S6>/Add'

    u0 = ((real_T)rtb_targetdetected_0 + ACC_core2015b_U.ReadCarvms_1) *
      ACC_core2015b_U.ReadUserdesiredtimegap_1;

    // MinMax: '<S6>/MinMax'
    if (u0 >= 10.0) {
      // Outport: '<Root>/Write_desired_distance'
      ACC_core2015b_Y.Write_desired_distance = u0;
    } else {
      // Outport: '<Root>/Write_desired_distance'
      ACC_core2015b_Y.Write_desired_distance = 10.0;
    }

    // End of MinMax: '<S6>/MinMax'

    // SignalConversion: '<S6>/OutportBufferFordesired distance'
    ACC_core2015b_B.OutportBufferFordesireddistance =
      ACC_core2015b_Y.Write_desired_distance;
  }

  // End of Logic: '<S4>/Logical Operator'
  // End of Outputs for SubSystem: '<S4>/Desired Distance Calculation with time gap' 

  // Product: '<S11>/Divide' incorporates:
  //   Constant: '<S11>/Initial spdctrl.kv_1'
  //   Inport: '<Root>/Read Car.v[m//s]_1'
  //   Sum: '<S11>/Sum'

  u0 = (rtb_Divide_g - ACC_core2015b_U.ReadCarvms_1) / 3.0;

  // Switch: '<S4>/desired or NOTSET'
  if (rtb_desiredorNOTSET >= 1.0) {
    // Saturate: '<S8>/-0.35<=ax<=1'
    if (u0 > 1.0) {
      // Outport: '<Root>/Write desired Ax_1' incorporates:
      //   Switch: '<S4>/desired Ax'

      ACC_core2015b_Y.WritedesiredAx_1 = 1.0;
    } else if (u0 < -0.35) {
      // Outport: '<Root>/Write desired Ax_1' incorporates:
      //   Switch: '<S4>/desired Ax'

      ACC_core2015b_Y.WritedesiredAx_1 = -0.35;
    } else {
      // Outport: '<Root>/Write desired Ax_1' incorporates:
      //   Switch: '<S4>/desired Ax'

      ACC_core2015b_Y.WritedesiredAx_1 = u0;
    }

    // End of Saturate: '<S8>/-0.35<=ax<=1'
  } else {
    // Outport: '<Root>/Write desired Ax_1' incorporates:
    //   Constant: '<S4>/Ax is NOTSET (=-99999)'
    //   Switch: '<S4>/desired Ax'

    ACC_core2015b_Y.WritedesiredAx_1 = -99999.0;
  }

  // End of Switch: '<S4>/desired or NOTSET'

  // Update for Memory: '<S5>/Memory' incorporates:
  //   Constant: '<S5>/Constant'

  ACC_core2015b_DW.Memory_PreviousInput = 1.0;
}

// Model initialize function
void ACC_core2015bModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize error status
  rtmSetErrorStatus((&ACC_core2015b_M), (NULL));

  // block I/O
  (void) memset(((void *) &ACC_core2015b_B), 0,
                sizeof(B_ACC_core2015b_T));

  // states (dwork)
  (void) memset((void *)&ACC_core2015b_DW, 0,
                sizeof(DW_ACC_core2015b_T));

  // external inputs
  (void) memset((void *)&ACC_core2015b_U, 0,
                sizeof(ExtU_ACC_core2015b_T));

  // external outputs
  (void) memset((void *)&ACC_core2015b_Y, 0,
                sizeof(ExtY_ACC_core2015b_T));
  ACC_core2015b_PrevZCX.InitDesiredtimegapquantity_Trig = UNINITIALIZED_ZCSIG;
}

// Model terminate function
void ACC_core2015bModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
ACC_core2015bModelClass::ACC_core2015bModelClass()
{
}

// Destructor
ACC_core2015bModelClass::~ACC_core2015bModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_ACC_core2015b_T * ACC_core2015bModelClass::getRTM()
{
  return (&ACC_core2015b_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
