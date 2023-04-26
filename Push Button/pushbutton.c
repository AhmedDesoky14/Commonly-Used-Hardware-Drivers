/*
 *  pushbutton.c
 *  Created on: Nov 9, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			push button Driver to easily control the push button in a layered architecture model
 */
/*==================================================INCLUDES=====================================================*/
#include "pushbutton.h"
/*============================================FUNCTIONS DEFINITIONS==============================================*/
/* Description:
 * 					Function to setup the push button
 * [No Inputs]:
 * [No Returns]:
 */
void Button_init(void)
{
	GPIO_setupPinDirection(BUTTON_PORT_ID,BUTTON_PIN_ID,PIN_INPUT);	/*Setup the pushbutton*/
#if(INTERNAL_PULL_UP == 1)
	CLEAR_BIT(SFIOR,PUD);								/*Enable Internal Pull-up in general*/
	GPIO_writePin(BUTTON_PORT_ID,BUTTON_PIN_ID,1);		/*Enable Internal Pull-up of the button*/
#endif
}
/*---------------------------------------------------------------------------------------------------------------*/
/* Description:
 * 					Function to get button status
 * [No Inputs]:
 * [Returns]:		Button pin status
 */
uint8 Button_getStatus(void)
{
	return GPIO_readPin(BUTTON_PORT_ID,BUTTON_PIN_ID); /*return value taken from pushbutton*/
}
