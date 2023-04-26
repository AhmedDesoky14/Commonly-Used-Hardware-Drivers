/*
 *  led.c
 *  Created on: Jan 26, 2023
 *  Author: Ahmed Desoky
 *  Description:
 *  			Simple LED Driver for simple use
 */
/*==================================================INCLUDES=====================================================*/
#include "led.h"
/*============================================FUNCTIONS DEFINITIONS==============================================*/
/* Description:
 * 					Function to setup the led
 * [No Inputs]:
 * [No Returns]:
 */
void LED_init(void)
{
	GPIO_setupPinDirection(LED_PORT,LED_PIN,PIN_OUTPUT);
}
/*---------------------------------------------------------------------------------------------------------------*/
/* Description:
 * 					Function to set led on
 * [No Inputs]:
 * [No Returns]:
 */
void LED_ON(void)
{
	GPIO_writePin(LED_PORT,LED_PIN,LED_IS_ON);
}
/*---------------------------------------------------------------------------------------------------------------*/
/* Description:
 * 					Function to set led off
 * [No Inputs]:
 * [No Returns]:
 */
void LED_OFF(void)
{
	GPIO_writePin(LED_PORT,LED_PIN,LED_IS_OFF);
}
/*---------------------------------------------------------------------------------------------------------------*/
/* Description:
 * 					Function to toggle the led
 * [Inputs]:		time delay between every on and off
 * [No Returns]:
 */
void LED_Toggle(uint16 delay_time)
{
	LED_ON();
	_delay_ms(delay_time);
	LED_OFF();
	_delay_ms(delay_time);
}
