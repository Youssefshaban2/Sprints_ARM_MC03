/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef WDT_H
#define WDT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void WDT_init(const Wdg_Config *WdgPtr);
void Wdt_SetTriggerCondition(uint16 timeout);
 
#endif  /* WDT_H */

/**********************************************************************************************************************
 *  END OF FILE: WDT.h
 *********************************************************************************************************************/