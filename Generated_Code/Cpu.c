/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : MC9S08QE128_80
**     Version     : Component 01.003, Driver 01.40, CPU db: 3.00.067
**     Datasheet   : MC9S08QE128RM Rev. 2 6/2007
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-05-18, 18:03, # CodeGen: 56
**     Abstract    :
**         This component "MC9S08QE128_80" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
**         Delay100US - void Cpu_Delay100US(word us100);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Cpu. */

#pragma MESSAGE DISABLE C4002 /* WARNING C4002: Result not used is ignored */

#include "AS1.h"
#include "RX_LED.h"
#include "TX_LED.h"
#include "HEARTBIT.h"
#include "ADC_ANALOG.h"
#include "ADQUIRIR.h"
#include "ENVIAR.h"
#include "CMP1.h"
#include "CMP2.h"
#include "CMP3.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR register */

/*Definition of global shadow variables*/
byte Shadow_PTC;


/*
** ===================================================================
**     Method      :  Cpu_Interrupt (component MC9S08QE128_80)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S08QE128_80)
**
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S08QE128_80)
**
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_Delay100US (component MC9S08QE128_80)
**
**     Description :
**         This method realizes software delay. The length of delay
**         is at least 100 microsecond multiply input parameter
**         [us100]. As the delay implementation is not based on real
**         clock, the delay time may be increased by interrupt
**         service routines processed during the delay. The method
**         is independent on selected speed mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**         us100           - Number of 100 us delay repetitions.
**     Returns     : Nothing
** ===================================================================
*/
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma MESSAGE DISABLE C5703
void Cpu_Delay100US(word us100)
{
  /* Total irremovable overhead: 16 cycles */
  /* ldhx: 5 cycles overhead (load parameter into register) */
  /* jsr:  5 cycles overhead (jump to subroutine) */
  /* rts:  6 cycles overhead (return from subroutine) */

  /* aproximate irremovable overhead for each 100us cycle (counted) : 8 cycles */
  /* aix:  2 cycles overhead  */
  /* cphx: 3 cycles overhead  */
  /* bne:  3 cycles overhead  */
  /*lint -save  -e950 -e522 Disable MISRA rule (1.1,14.2) checking. */
  asm {
loop:
    /* 100 us delay block begin */
    /*
     * Delay
     *   - requested                  : 100 us @ 25.165824MHz,
     *   - possible                   : 2517 c, 100016.59 ns, delta 16.59 ns
     *   - without removable overhead : 2509 c, 99698.7 ns
     */
    pshh                               /* (2 c: 79.47 ns) backup H */
    pshx                               /* (2 c: 79.47 ns) backup X */
    ldhx #$0138                        /* (3 c: 119.21 ns) number of iterations */
label0:
    aix #-1                            /* (2 c: 79.47 ns) decrement H:X */
    cphx #0                            /* (3 c: 119.21 ns) compare it to zero */
    bne label0                         /* (3 c: 119.21 ns) repeat 312x */
    pulx                               /* (3 c: 119.21 ns) restore X */
    pulh                               /* (3 c: 119.21 ns) restore H */
    /* 100 us delay block end */
    aix #-1                            /* us100 parameter is passed via H:X registers */
    cphx #0
    bne loop                           /* next loop */
    rts                                /* return from subroutine */
  }
  /*lint -restore Enable MISRA rule (1.1,14.2) checking. */
}

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S08QE128_80)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

#pragma NO_FRAME
#pragma NO_EXIT
void _EntryPoint(void)
{
  /* ### MC9S08QE128_80 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT1: COPE=0,COPT=1,STOPE=0,??=0,??=0,RSTOPE=0,BKGDPE=1,RSTPE=1 */
  setReg8(SOPT1, 0x43U);                
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,??=0,BGBE=0 */
  setReg8(SPMSC1, 0x1CU);               
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,??=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  setReg8(SPMSC2, 0x02U);               
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  clrReg8Bits(SPMSC3, 0x38U);           
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(uint8_t*)0xFFAFU != 0xFFU) {   /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(uint8_t*)0xFFAFU;       /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (uint8_t)((*(uint8_t*)0xFFAEU) & (uint8_t)0x01U); /* Initialize ICSSC register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  setReg8(ICSC1, 0x06U);               /* Initialization of the ICS control register 1 */ 
  /* ICSC2: BDIV=0,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  setReg8(ICSC2, 0x00U);               /* Initialization of the ICS control register 2 */ 
  while(ICSSC_IREFST == 0U) {          /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=2,DMX32=0 */
  clrSetReg8Bits(ICSSC, 0x60U, 0x80U); /* Initialization of the ICS status and control */ 
  while((ICSSC & 0xC0U) != 0x80U) {    /* Wait until the FLL switches to High range DCO mode */
  }

  /*** End of PE initialization code after reset ***/
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm   jmp _Startup ;               /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S08QE128_80)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* SCGC1: TPM3=1,TPM2=1,TPM1=1,ADC=1,IIC2=1,IIC1=1,SCI2=1,SCI1=1 */
  setReg8(SCGC1, 0xFFU);                
  /* SCGC2: DBG=1,FLS=1,IRQ=1,KBI=1,ACMP=1,RTC=1,SPI2=1,SPI1=1 */
  setReg8(SCGC2, 0xFFU);                
  /* Common initialization of the CPU registers */
  /* PTBDD: PTBDD1=1,PTBDD0=0 */
  clrSetReg8Bits(PTBDD, 0x01U, 0x02U);  
  /* PTBD: PTBD1=1 */
  setReg8Bits(PTBD, 0x02U);             
  /* PTCD: PTCD1=1,PTCD0=1 */
  setReg8Bits(PTCD, 0x03U);             
  /* PTCPE: PTCPE1=0,PTCPE0=0 */
  clrReg8Bits(PTCPE, 0x03U);            
  /* PTCDD: PTCDD1=1,PTCDD0=1 */
  setReg8Bits(PTCDD, 0x03U);            
  /* APCTL1: ADPC7=1,ADPC3=1,ADPC2=1,ADPC0=1 */
  setReg8Bits(APCTL1, 0x8DU);           
  /* APCTL2: ADPC11=1,ADPC10=1 */
  setReg8Bits(APCTL2, 0x0CU);           
  /* PTDDD: PTDDD1=0,PTDDD0=0 */
  clrReg8Bits(PTDDD, 0x03U);            
  /* PTDPE: PTDPE1=0,PTDPE0=0 */
  clrReg8Bits(PTDPE, 0x03U);            
  /* PTHPE: PTHPE7=0 */
  clrReg8Bits(PTHPE, 0x80U);            
  /* PTHDD: PTHDD7=0 */
  clrReg8Bits(PTHDD, 0x80U);            
  /* PTASE: PTASE7=0,PTASE6=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  clrReg8Bits(PTASE, 0xDFU);            
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  setReg8(PTBSE, 0x00U);                
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  setReg8(PTCSE, 0x00U);                
  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  setReg8(PTDSE, 0x00U);                
  /* PTESE: PTESE7=0,PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE1=0,PTESE0=0 */
  setReg8(PTESE, 0x00U);                
  /* PTFSE: PTFSE7=0,PTFSE6=0,PTFSE5=0,PTFSE4=0,PTFSE3=0,PTFSE2=0,PTFSE1=0,PTFSE0=0 */
  setReg8(PTFSE, 0x00U);                
  /* PTGSE: PTGSE7=0,PTGSE6=0,PTGSE5=0,PTGSE4=0,PTGSE3=0,PTGSE2=0,PTGSE1=0,PTGSE0=0 */
  setReg8(PTGSE, 0x00U);                
  /* PTHSE: PTHSE7=0,PTHSE6=0,PTHSE5=0,PTHSE4=0,PTHSE3=0,PTHSE2=0,PTHSE1=0,PTHSE0=0 */
  setReg8(PTHSE, 0x00U);                
  /* PTJSE: PTJSE7=0,PTJSE6=0,PTJSE5=0,PTJSE4=0,PTJSE3=0,PTJSE2=0,PTJSE1=0,PTJSE0=0 */
  setReg8(PTJSE, 0x00U);                
  /* PTADS: PTADS7=1,PTADS6=1,PTADS5=0,PTADS4=1,PTADS3=1,PTADS2=1,PTADS1=1,PTADS0=1 */
  setReg8(PTADS, 0xDFU);                
  /* PTBDS: PTBDS7=1,PTBDS6=1,PTBDS5=1,PTBDS4=1,PTBDS3=1,PTBDS2=1,PTBDS1=1,PTBDS0=1 */
  setReg8(PTBDS, 0xFFU);                
  /* PTCDS: PTCDS7=1,PTCDS6=1,PTCDS5=1,PTCDS4=1,PTCDS3=1,PTCDS2=1,PTCDS1=1,PTCDS0=1 */
  setReg8(PTCDS, 0xFFU);                
  /* PTDDS: PTDDS7=1,PTDDS6=1,PTDDS5=1,PTDDS4=1,PTDDS3=1,PTDDS2=1,PTDDS1=1,PTDDS0=1 */
  setReg8(PTDDS, 0xFFU);                
  /* PTEDS: PTEDS7=1,PTEDS6=1,PTEDS5=1,PTEDS4=1,PTEDS3=1,PTEDS2=1,PTEDS1=1,PTEDS0=1 */
  setReg8(PTEDS, 0xFFU);                
  /* PTFDS: PTFDS7=1,PTFDS6=1,PTFDS5=1,PTFDS4=1,PTFDS3=1,PTFDS2=1,PTFDS1=1,PTFDS0=1 */
  setReg8(PTFDS, 0xFFU);                
  /* PTGDS: PTGDS7=1,PTGDS6=1,PTGDS5=1,PTGDS4=1,PTGDS3=1,PTGDS2=1,PTGDS1=1,PTGDS0=1 */
  setReg8(PTGDS, 0xFFU);                
  /* PTHDS: PTHDS7=1,PTHDS6=1,PTHDS5=1,PTHDS4=1,PTHDS3=1,PTHDS2=1,PTHDS1=1,PTHDS0=1 */
  setReg8(PTHDS, 0xFFU);                
  /* PTJDS: PTJDS7=1,PTJDS6=1,PTJDS5=1,PTJDS4=1,PTJDS3=1,PTJDS2=1,PTJDS1=1,PTJDS0=1 */
  setReg8(PTJDS, 0xFFU);                
  /* ### Shared modules init code ... */
  /* ### Asynchro serial "AS1" init code ... */
  AS1_Init();
  /* ### BitIO "RX_LED" init code ... */
  Shadow_PTC |= (byte)0x01U;           /* Initialize pin shadow variable bit */
  /* ### BitIO "TX_LED" init code ... */
  Shadow_PTC |= (byte)0x02U;           /* Initialize pin shadow variable bit */
  /* ### TimerInt "HEARTBIT" init code ... */
  HEARTBIT_Init();
  /* ###  "ADC_ANALOG" init code ... */
  ADC_ANALOG_Init();
  /* ### TimerInt "ADQUIRIR" init code ... */
  ADQUIRIR_Init();
  /* ### TimerInt "ENVIAR" init code ... */
  ENVIAR_Init();
  /* ### External interrupt "CMP1" init code ... */
  /* KBI2PE: KBIPE1=1 */
  KBI2PE |= 0x02U;
  /* KBI2SC: ??=0,??=0,??=0,??=0,KBF=0,KBACK=0,KBIE=0,KBIMOD=0 */
  setReg8(KBI2SC, 0x00U);               
  KBI2SC_KBACK = 0x01U;                /* Clear Interrupt flag */
  KBI2SC_KBIE = 0x01U;
  /* ### BitIO "CMP2" init code ... */
  /* ### BitIO "CMP3" init code ... */
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/* NVPROT: FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPS0=1,FPOPEN=1 */
static const uint8_t NVPROT_INIT @0x0000FFBDU = 0xFFU;
/* NVOPT: KEYEN1=0,KEYEN0=1,??=1,??=1,??=1,??=1,SEC1=1,SEC0=0 */
static const uint8_t NVOPT_INIT @0x0000FFBFU = 0x7EU;
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
