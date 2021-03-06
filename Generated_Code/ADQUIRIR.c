/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ADQUIRIR.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : TimerInt
**     Version     : Component 02.160, Driver 01.23, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-26, 14:04, # CodeGen: 65
**     Abstract    :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings    :
**         Timer name                  : RTC (8-bit)
**         Compare name                : RTCmod
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 32768 Hz
**           Initial period/frequency
**             Xtal ticks              : 66
**             microseconds            : 2014
**             milliseconds            : 2
**             seconds (real)          : 0.002014160156
**             Hz                      : 496
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : RTCCNT    [$1831]
**              Mode                   : RTCSC     [$1830]
**              Run                    : RTCSC     [$1830]
**              Prescaler              : RTCSC     [$1830]
**
**         Compare registers
**              Compare                : RTCMOD    [$1832]
**
**         Flip-flop registers
**     Contents    :
**         Enable       - byte ADQUIRIR_Enable(void);
**         Disable      - byte ADQUIRIR_Disable(void);
**         EnableEvent  - byte ADQUIRIR_EnableEvent(void);
**         DisableEvent - byte ADQUIRIR_DisableEvent(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ADQUIRIR. */

#include "Events.h"
#include "PE_Error.h"
#include "ADQUIRIR.h"
#pragma MESSAGE DISABLE C2705          /* WARNING C2705: Possible loss of data */
#pragma MESSAGE DISABLE C5919          /* WARNING C5919: Conversion of floating to unsigned integral */
#pragma MESSAGE DISABLE C5703          /* WARNING C5703: Parameter X declared in function F but not referenced */

static bool EnUser;                    /* Enable device by user */
/*** Internal macros and method prototypes ***/

/*
** ===================================================================
**     Method      :  SetCV (component TimerInt)
**
**     Description :
**         The method computes and sets compare eventually modulo value 
**         for time measuring.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ADQUIRIR_SetCV(_Val) \
  (RTCMOD = (byte)(_Val))

/*
** ===================================================================
**     Method      :  HWEnDi (component TimerInt)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void);


/*** End of internal method prototypes ***/

/*
** ===================================================================
**     Method      :  HWEnDi (component TimerInt)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  if (EnUser) {
    /* RTCSC: RTIF=1,RTCLKS=2,RTIE=1,RTCPS=8 */
    setReg8(RTCSC, 0xD8U);             /* Run RTC (select clock source; set frequency and enable interrupt) */ 
  } else {
    /* RTCSC: RTCPS=0 */
    clrReg8Bits(RTCSC, 0x0FU);         /* Stop counter */ 
  }
}

/*
** ===================================================================
**     Method      :  ADQUIRIR_Enable (component TimerInt)
**
**     Description :
**         This method enables the component - it starts the timer.
**         Events may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte ADQUIRIR_Enable(void)
{
  if (!EnUser) {                       /* Is the device disabled by user? */
    EnUser = TRUE;                     /* If yes then set the flag "device enabled" */
    HWEnDi();                          /* Enable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  ADQUIRIR_Disable (component TimerInt)
**
**     Description :
**         This method disables the component - it stops the timer. No
**         events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte ADQUIRIR_Disable(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    EnUser = FALSE;                    /* If yes then set the flag "device disabled" */
    HWEnDi();                          /* Disable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  ADQUIRIR_EnableEvent (component TimerInt)
**
**     Description :
**         This method enables the events.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte ADQUIRIR_EnableEvent(void)
{
  if (RTCSC_RTIE == 0x00U) {
    /* RTCSC: RTIF=1 */
    setReg8Bits(RTCSC, 0x80U);         /* Reset real-time counter request flag */ 
  }
  /* RTCSC: RTIE=1 */
  setReg8Bits(RTCSC, 0x10U);           /* Enable interrupt */ 
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  ADQUIRIR_DisableEvent (component TimerInt)
**
**     Description :
**         This method disables the events.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte ADQUIRIR_DisableEvent(void)

**      This method is implemented as a macro. See header module. **
*/

/*
** ===================================================================
**     Method      :  ADQUIRIR_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void ADQUIRIR_Init(void)
{
  /* RTCSC: RTIF=0,RTCLKS=0,RTIE=0,RTCPS=0 */
  setReg8(RTCSC, 0x00U);               /* Stop HW */ 
  EnUser = TRUE;                       /* Enable device */
  ADQUIRIR_SetCV(0x41U);               /* Initialize appropriate value to the compare/modulo/reload register */
  RTCMOD = RTCMOD;                     /* Reset HW counter */
  HWEnDi();
}


/*
** ===================================================================
**     Method      :  ADQUIRIR_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the component event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(ADQUIRIR_Interrupt)
{
  /* RTCSC: RTIF=1 */
  setReg8Bits(RTCSC, 0x80U);           /* Reset real-time counter request flag */ 
  ADQUIRIR_OnInterrupt();              /* Invoke user event */
}



/* END ADQUIRIR. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
