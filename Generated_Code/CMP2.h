/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CMP2.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.216, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-26, 14:49, # CodeGen: 67
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
**             Prescaler               : divide-by-1
**           Maximal time for capture register
**             Xtal ticks              : 131072
**             microseconds            : 4000000
**             milliseconds            : 4000
**             seconds                 : 4
**             seconds (real)          : 4.0
**           One tick of timer is
**             microseconds            : 61.035156
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
**         Signal edge/level           : falling
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         GetCaptureValue - byte CMP2_GetCaptureValue(CMP2_TCapturedValue *Value);
**         GetPinValue     - bool CMP2_GetPinValue(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __CMP2
#define __CMP2

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE CMP2. */

#include "Cpu.h"

/* PUBLISHED CONSTANTS */
#define CMP2_PRESCALER_VALUE           0x01U /* Prescaler value of the timer in high speed mode */
#define CMP2_COUNTER_INPUT_CLOCK_HZ    0x4000LU /* Initial counter input clock frequency [Hz] */
#define CMP2_TIMER_INPUT_CLOCK         0x01800000LU /* Deprecated, Initial timer input clock frequency [Hz] */
#define CMP2_PRESCALER_VALUE_HIGH      0x01U /* Prescaler value of the timer in high speed mode */
#define CMP2_COUNTER_INPUT_CLOCK_HZ_HIGH 0x4000LU /* Counter input clock frequency in high speed mode [Hz] */
#define CMP2_TIMER_INPUT_CLOCK_HIGH    0x01800000LU /* Deprecated, Timer input clock frequency in high speed mode[Hz] */

#ifndef __BWUserType_CMP2_TCapturedValue
#define __BWUserType_CMP2_TCapturedValue
  #define CMP2_TCapturedValue word     /*  Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif



#define CMP2_GetCaptureValue(Value) \
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. */\
  (*(CMP2_TCapturedValue*)(Value) = TPM1C2V , (byte)ERR_OK) \
  /*lint -restore Enable MISRA rule (11.4) checking. */
/*
** ===================================================================
**     Method      :  CMP2_GetCaptureValue (component Capture)
**
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               61.035156 us in high speed mode
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

#define CMP2_GetPinValue() ((PTAD & 0x40U) ? TRUE : FALSE)
/*
** ===================================================================
**     Method      :  CMP2_GetPinValue (component Capture)
**
**     Description :
**         The method reads the Capture pin value. The method is
**         available only if it is possible to read the pin value
**         (usually not available for internal signals).
**     Parameters  : None
**     Returns     :
**         ---             - Capture pin value.
**                           <true> - high level
**                           <false> - low level.
** ===================================================================
*/

void CMP2_Init(void);
/*
** ===================================================================
**     Method      :  CMP2_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void CMP2_Interrupt(void);
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


/* END CMP2. */

#endif /* ifndef __CMP2 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
