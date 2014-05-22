/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CMP2.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.216, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-22, 18:46, # CodeGen: 62
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
**             Timer                   : TPM2
**             Counter shared          : Yes
**
**         High speed mode
**             Prescaler               : divide-by-4
**           Maximal time for capture register
**             Xtal ticks              : 341
**             microseconds            : 10417
**             milliseconds            : 10
**             seconds (real)          : 0.010416666667
**             Hz                      : 96
**           One tick of timer is
**             nanoseconds             : 166.666666666667
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TPM2C2V   [$005C]
**              Counter                : TPM2CNT   [$0051]
**              Mode                   : TPM2SC    [$0050]
**              Run                    : TPM2SC    [$0050]
**              Prescaler              : TPM2SC    [$0050]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       47            |  PTA7_TPM2CH2_ADP9
**             ----------------------------------------------------
**
**         Port name                   : PTA
**         Bit number (in port)        : 7
**         Bit mask of the port        : $0080
**
**         Signal edge/level           : falling
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         GetPinValue - bool CMP2_GetPinValue(void);
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
#define CMP2_PRESCALER_VALUE           0x04U /* Prescaler value of the timer in high speed mode */
#define CMP2_COUNTER_INPUT_CLOCK_HZ    0x00600000LU /* Initial counter input clock frequency [Hz] */
#define CMP2_TIMER_INPUT_CLOCK         0x01800000LU /* Deprecated, Initial timer input clock frequency [Hz] */
#define CMP2_PRESCALER_VALUE_HIGH      0x04U /* Prescaler value of the timer in high speed mode */
#define CMP2_COUNTER_INPUT_CLOCK_HZ_HIGH 0x00600000LU /* Counter input clock frequency in high speed mode [Hz] */
#define CMP2_TIMER_INPUT_CLOCK_HIGH    0x01800000LU /* Deprecated, Timer input clock frequency in high speed mode[Hz] */

#ifndef __BWUserType_CMP2_TCapturedValue
#define __BWUserType_CMP2_TCapturedValue
  #define CMP2_TCapturedValue word     /*  Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif



#define CMP2_GetPinValue() ((PTAD & 0x80U) ? TRUE : FALSE)
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