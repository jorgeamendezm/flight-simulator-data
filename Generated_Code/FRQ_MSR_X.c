/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FRQ_MSR_X.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : Capture
**     Version     : Component 02.216, Driver 01.30, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-03-26, 17:10, # CodeGen: 19
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
**             Xtal ticks              : 85
**             microseconds            : 2604
**             milliseconds            : 3
**             seconds (real)          : 0.002604166667
**             Hz                      : 384
**           One tick of timer is
**             nanoseconds             : 40
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TPM1C1V   [$0049]
**              Counter                : TPM1CNT   [$0041]
**              Mode                   : TPM1SC    [$0040]
**              Run                    : TPM1SC    [$0040]
**              Prescaler              : TPM1SC    [$0040]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       22            |  PTB5_TPM1CH1_SS1
**             ----------------------------------------------------
**
**         Port name                   : PTB
**         Bit number (in port)        : 5
**         Bit mask of the port        : $0020
**
**         Signal edge/level           : rising
**         Priority                    : 
**         Pull option                 : off
**
**     Contents    :
**         Reset           - byte FRQ_MSR_X_Reset(void);
**         GetCaptureValue - byte FRQ_MSR_X_GetCaptureValue(FRQ_MSR_X_TCapturedValue *Value);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE FRQ_MSR_X. */

#include "Events.h"
#include "FRQ_MSR_X.h"


volatile word FRQ_MSR_X_CntrState;     /* Content of counter */


/*
** ===================================================================
**     Method      :  FRQ_MSR_X_Reset (component Capture)
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
/*
byte FRQ_MSR_X_Reset(word *Value)

**  This method is implemented as a macro. See FRQ_MSR_X.h file.  **
*/

/*
** ===================================================================
**     Method      :  FRQ_MSR_X_GetCaptureValue (component Capture)
**
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               40 ns in high speed mode
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
/*
byte FRQ_MSR_X_GetCaptureValue(FRQ_MSR_X_TCapturedValue *Value)

**  This method is implemented as a macro. See FRQ_MSR_X.h file.  **
*/

/*
** ===================================================================
**     Method      :  FRQ_MSR_X_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void FRQ_MSR_X_Init(void)
{
  /* TPM1SC: TOF=0,TOIE=0,CPWMS=0,CLKSB=0,CLKSA=0,PS2=0,PS1=0,PS0=0 */
  setReg8(TPM1SC, 0x00U);              /* Stop HW */ 
  /* TPM1MOD: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM1MOD, 0x00U);            /* Disable modulo register */ 
  /* TPM1CNTH: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0 */
  setReg8(TPM1CNTH, 0x00U);            /* Reset counter */ 
  /* TPM1C1V: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM1C1V, 0x00U);            /* Clear capture register */ 
  FRQ_MSR_X_CntrState = 0x00U;         /* Clear variable */
  /* TPM1SC: PS2=0,PS1=0,PS0=0 */
  clrReg8Bits(TPM1SC, 0x07U);          /* Set prescaler register */ 
  /* TPM1C1SC: CH1F=0,CH1IE=1,MS1B=0,MS1A=0,ELS1B=0,ELS1A=1,??=0,??=0 */
  setReg8(TPM1C1SC, 0x44U);            /* Enable both interrupt and capture function */ 
}


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
ISR(FRQ_MSR_X_Interrupt)
{
  (void)TPM1C1SC;                      /* Dummy read to reset interrupt request flag */
  /* TPM1C1SC: CH1F=0 */
  clrReg8Bits(TPM1C1SC, 0x80U);        /* Reset interrupt request flag */ 
  FRQ_MSR_X_OnCapture();               /* Invoke user event */
}



/* END FRQ_MSR_X. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
