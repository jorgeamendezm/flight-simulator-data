/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FRQ_MSR_Y.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.216, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-03-26, 18:13, # CodeGen: 17
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings    :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TPM1
**             Counter shared          : Yes
**
**         High speed mode
**             Prescaler               : divide-by-2
**           Maximal time for capture register
**             Xtal ticks              : 171
**             microseconds            : 5208
**             milliseconds            : 5
**             seconds (real)          : 0.005208333333
**             Hz                      : 192
**           One tick of timer is
**             nanoseconds             : 76.923076923077
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TPM1C2V   [$004C]
**              Counter                : TPM1CNT   [$0041]
**              Mode                   : TPM1SC    [$0040]
**              Run                    : TPM1SC    [$0040]
**              Prescaler              : TPM1SC    [$0040]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       48            |  PTA6_TPM1CH2_ADP8
**             ----------------------------------------------------
**
**         Port name                   : PTA
**         Bit number (in port)        : 6
**         Bit mask of the port        : $0040
**
**         Signal edge/level           : rising
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         Reset           - byte FRQ_MSR_Y_Reset(void);
**         GetCaptureValue - byte FRQ_MSR_Y_GetCaptureValue(FRQ_MSR_Y_TCapturedValue *Value);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __FRQ_MSR_Y
#define __FRQ_MSR_Y

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE FRQ_MSR_Y. */

#include "Cpu.h"

/* PUBLISHED CONSTANTS */
#define FRQ_MSR_Y_PRESCALER_VALUE           0x02U /* Prescaler value of the timer in high speed mode */
#define FRQ_MSR_Y_COUNTER_INPUT_CLOCK_HZ    0x00C00000LU /* Initial counter input clock frequency [Hz] */
#define FRQ_MSR_Y_TIMER_INPUT_CLOCK         0x01800000LU /* Deprecated, Initial timer input clock frequency [Hz] */
#define FRQ_MSR_Y_PRESCALER_VALUE_HIGH      0x02U /* Prescaler value of the timer in high speed mode */
#define FRQ_MSR_Y_COUNTER_INPUT_CLOCK_HZ_HIGH 0x00C00000LU /* Counter input clock frequency in high speed mode [Hz] */
#define FRQ_MSR_Y_TIMER_INPUT_CLOCK_HIGH    0x01800000LU /* Deprecated, Timer input clock frequency in high speed mode[Hz] */

#ifndef __BWUserType_FRQ_MSR_Y_TCapturedValue
#define __BWUserType_FRQ_MSR_Y_TCapturedValue
  #define FRQ_MSR_Y_TCapturedValue word /*  Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif


extern volatile word FRQ_MSR_Y_CntrState; /* Content of counter */


#define FRQ_MSR_Y_Reset() \
  (FRQ_MSR_Y_CntrState = TPM1CNT , (byte)ERR_OK)
/*
** ===================================================================
**     Method      :  FRQ_MSR_Y_Reset (component Capture)
**
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define FRQ_MSR_Y_GetCaptureValue(Value) \
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. */\
  (((*(FRQ_MSR_Y_TCapturedValue*)(Value) = TPM1C2V), \
  (*(FRQ_MSR_Y_TCapturedValue*)(Value) -= FRQ_MSR_Y_CntrState)), \
  ERR_OK) \
  /*lint -restore Enable MISRA rule (11.4) checking. */
/*
** ===================================================================
**     Method      :  FRQ_MSR_Y_GetCaptureValue (component Capture)
**
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               76.923076923077 ns in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void FRQ_MSR_Y_Init(void);
/*
** ===================================================================
**     Method      :  FRQ_MSR_Y_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void FRQ_MSR_Y_Interrupt(void);
/*
** ===================================================================
**     Method      :  Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END FRQ_MSR_Y. */

#endif /* ifndef __FRQ_MSR_Y */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
