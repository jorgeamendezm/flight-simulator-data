/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Control.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : BitIO
**     Version     : Component 02.086, Driver 03.27, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-21, 14:15, # CodeGen: 58
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       62            |  PTA0_KBI1P0_TPM1CH0_ADP0_ACMP1PLUS
**             ----------------------------------------------------
**
**         Port name                   : PTA
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : $0001
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTAD      [$0000]
**         Port control register       : PTADD     [$0001]
**
**         Optimization for            : speed
**     Contents    :
**         SetDir - void Control_SetDir(bool Dir);
**         GetVal - bool Control_GetVal(void);
**         PutVal - void Control_PutVal(bool Val);
**         ClrVal - void Control_ClrVal(void);
**         SetVal - void Control_SetVal(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef Control_H_
#define Control_H_

/* MODULE Control. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  Control_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Control_GetVal() ( \
    (bool)((getReg8(PTAD) & 0x01U))    /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  Control_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void Control_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  Control_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**           a) direction = Input  : sets the output value to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Control_ClrVal() ( \
    (void)clrReg8Bits(PTAD, 0x01U)     /* PTAD0=0x00U */, \
    (Shadow_PTA &= 0xFEU)              /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  Control_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**           a) direction = Input  : sets the output value to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Control_SetVal() ( \
    (void)setReg8Bits(PTAD, 0x01U)     /* PTAD0=0x01U */, \
    (Shadow_PTA |= 0x01U)              /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  Control_SetDir (component BitIO)
**
**     Description :
**         This method sets direction of the component.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void Control_SetDir(bool Dir);



/* END Control. */
#endif /* #ifndef __Control_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
