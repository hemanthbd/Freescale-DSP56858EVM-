/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TI1.H
**     Project   : Combo
**     Processor : 56858
**     Component : TimerInt
**     Version   : Component 02.157, Driver 02.02, CPU db: 2.87.105
**     Compiler  : Metrowerks DSP C Compiler
**     Date/Time : 2/16/2018, 4:17 PM
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
**           Initial period/frequency
**             Xtal ticks              : 1000000
**             microseconds            : 250000
**             milliseconds            : 250
**             seconds (real)          : 0.25
**             Hz                      : 4
**
**         Runtime setting             : modes (list of settings)
**            -----------------------------------------------------------------------
**            |  period  |     Prescaler      |        Real period [seconds]        |
**     --------    or    |-----------------------------------------------------------
**     | mode | freqency | high | low  | slow |    high    |    low     |    slow   |
**     ------------------------------------------------------------------------------
**     |  0   |  0_25sec | 1    | -    | -    | 0.25       | -          | -         |
**     |  1   |  0_5sec  | 1    | -    | -    | 0.5        | -          | -         |
**     |  2   |  0_75sec | 1    | -    | -    | 0.75       | -          | -         |
**     |  3   |  1sec    | 1    | -    | -    | 1.0        | -          | -         |
**     ------------------------------------------------------------------------------
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
**         SetPeriodMode - byte TI1_SetPeriodMode(byte Mode);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TI1
#define __TI1

/* MODULE TI1. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#define TI1_PM_0_25sec       0         /* Constant for switch to mode 0 */
#define TI1_PM_0_5sec        1         /* Constant for switch to mode 1 */
#define TI1_PM_0_75sec       2         /* Constant for switch to mode 2 */
#define TI1_PM_1sec          3         /* Constant for switch to mode 3 */
/* Deprecated constants */
#define TI1_Pm_0_25sec       0         /* Constant for switch to mode 0 */
#define TI1_Pm_0_5sec        1         /* Constant for switch to mode 1 */
#define TI1_Pm_0_75sec       2         /* Constant for switch to mode 2 */
#define TI1_Pm_1sec          3         /* Constant for switch to mode 3 */


byte TI1_SetPeriodMode(byte Mode);
/*
** ===================================================================
**     Method      :  TI1_SetPeriodMode (component TimerInt)
**
**     Description :
**         Switches the bean to a specified mode (changes the period/frequency
**         using the mode values). This method reduces the time needed
**         for setting of a new period value. This method can be used only when
**         a list of possible period settings is specified at design time.
**         Each of these settings constitutes a mode and Processor Expert
**         assigns them a mode identifier. The prescaler and compare values
**         corresponding to each mode are calculated at design time.
**         Modes can be switched at runtime just by referring to a mode
**         identifier. No run-time calculations are performed, all the
**         calculations are performed at design time. The modes and mode
**         identifiers may be found in the include file *.h.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Mode              Mode to switch to (0 to 3)
**                           TI1_PM_0_25sec
**                           TI1_PM_0_5sec
**                           TI1_PM_0_75sec
**                           TI1_PM_1sec
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_VALUE - Value out of range,
**                           requested timing mode is not defined
** ===================================================================
*/

void TI1_Init(void);
/*
** ===================================================================
**     Method      :  TI1_Init (component TimerInt)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void TI1_Interrupt(void);
/*
** ===================================================================
**     Method      :  TI1_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the beans event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END TI1. */

#endif /* ifndef __TI1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.00 [04.35]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
