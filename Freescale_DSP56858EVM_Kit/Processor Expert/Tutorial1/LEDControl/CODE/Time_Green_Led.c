/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Time_Green_Led.C
**     Project   : LEDControl
**     Processor : 56858
**     Component : TimerInt
**     Version   : Component 02.157, Driver 02.02, CPU db: 2.87.105
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/16/2018, 12:17 PM
**     Abstract  :
**         This bean "TimerInt" implements a periodic interrupt.
**         When the bean and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings  :
**         Timer name                  : TMR0123 (64-bit)
**         Compare name                : TMR0123_Compare
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 60000000 Hz
**           Initial period/frequency
**             Xtal ticks              : 4000000
**             microseconds            : 1000000
**             milliseconds            : 1000
**             seconds                 : 1
**             seconds (real)          : 1.0
**             Hz                      : 1
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : TMR3_CNTR [2096797]
**              Mode                   : TMR3_CTL  [2096798]
**              Run                    : TMR3_CTL  [2096798]
**              Prescaler              : TMR3_CTL  [2096798]
**
**         Compare registers
**              Compare                : TMR3_CMP1 [2096792]
**
**         Flip-flop registers
**              Mode                   : TMR3_CTL  [2096798]
**     Contents  :
**         No public methods
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE Time_Green_Led. */

#include "Events.h"
#include "Time_Green_Led.h"



/* Internal method prototypes */
static void SetCV(word Val0, word Val1, word Val2, word Val3);
static void SetPV(byte Val);

/*
** ===================================================================
**     Method      :  SetCV (component TimerInt)
**
**     Description :
**         Sets compare or preload register value. The method is called 
**         automatically as a part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetCV(word Val0, word Val1, word Val2, word Val3)
{
  EnterCritical();                     /* Disable global interrupts */
  setReg(TMR3_CMP1,Val3);              /* Store given value to the compare registers */
  setReg(TMR2_CMP1,Val2);
  setReg(TMR1_CMP1,Val1);
  setReg(TMR0_CMP1,Val0);
  ExitCritical();                      /* Enable global interrupts */
}

/*
** ===================================================================
**     Method      :  SetPV (component TimerInt)
**
**     Description :
**         Sets prescaler value. The method is called automatically as a 
**         part of several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetPV(byte Val)
{
  EnterCritical();                     /* Disable global interrupts */
  setRegBitGroup(TMR0_CTL,PCS,Val);    /* Store given value to the prescaler */
  setReg(TMR0_CNTR,0);                 /* Reset counter */
  setReg(TMR1_CNTR,0);
  setReg(TMR2_CNTR,0);
  setReg(TMR3_CNTR,0);
  ExitCritical();                      /* Enable global interrupts */
}

/*
** ===================================================================
**     Method      :  Time_Green_Led_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Time_Green_Led_Init(void)
{
  /* TMR0_CTL: CM=0,PCS=0,SCS=0,ONCE=0,LENGTH=1,DIR=0,EXT_INIT=0,OM=0 */
  setReg(TMR0_CTL,32);                 /* Stop all functions of the timer */
  /* TMR1_CTL: CM=7,PCS=4,SCS=0,ONCE=0,LENGTH=1,DIR=0,EXT_INIT=0,OM=0 */
  setReg(TMR1_CTL,59424);
  /* TMR2_CTL: CM=7,PCS=5,SCS=0,ONCE=0,LENGTH=1,DIR=0,EXT_INIT=0,OM=0 */
  setReg(TMR2_CTL,59936);
  /* TMR3_CTL: CM=7,PCS=6,SCS=0,ONCE=0,LENGTH=1,DIR=0,EXT_INIT=0,OM=0 */
  setReg(TMR3_CTL,60448);              /* Set up cascade counter mode */
  /* TMR3_SCR: TCF=0,TCFIE=1,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMR3_SCR,16384);
  /* TMR2_SCR: TCF=0,TCFIE=0,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMR2_SCR,0);
  /* TMR1_SCR: TCF=0,TCFIE=0,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMR1_SCR,0);
  /* TMR0_SCR: TCF=0,TCFIE=0,TOF=0,TOFIE=0,IEF=0,IEFIE=0,IPS=0,INPUT=0,Capture_Mode=0,MSTR=0,EEOF=0,VAL=0,FORCE=0,OPS=0,OEN=0 */
  setReg(TMR0_SCR,0);
  setReg(TMR3_CNTR,0);                 /* Reset counter register */
  setReg(TMR2_CNTR,0);
  setReg(TMR1_CNTR,0);
  setReg(TMR0_CNTR,0);
  setReg(TMR3_LOAD,0);                 /* Reset load register */
  setReg(TMR2_LOAD,0);
  setReg(TMR1_LOAD,0);
  setReg(TMR0_LOAD,0);
  SetCV((word)46874,(word)1279,(word)0,(word)0); /* Store appropriate value to the compare register according to the selected high speed CPU mode */
  SetPV((byte)8);                      /* Set prescaler register according to the selected high speed CPU mode */
  setRegBitGroup(TMR0_CTL,CM,1);       /* Run counter */
}

/*
** ===================================================================
**     Method      :  Time_Green_Led_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma interrupt alignsp saveall
void Time_Green_Led_Interrupt(void)
{
  clrRegBit(TMR3_SCR,TCF);             /* Reset interrupt request flag */
  Time_Green_Led_OnInterrupt();        /* Invoke user event */
}

/* END Time_Green_Led. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/