/*
 *  led.h
 *  Created on: Jan 26, 2023
 *  Author: Ahmed Desoky
 *  Description:
 *  			Simple LED Driver for simple use
 */
#ifndef LED_H_
#define LED_H_
/*==================================INCLUDES=============================================*/
#include "gpio.h"
#include "std_types.h"
#include <util/delay.h>
/*=============================================Configuration Note================================================*/
/*to re-configure this driver go to line 17 in the .h file*/
/*========================================DEFINITIONS & CONFIGURATIONS===========================================*/
#define LOGIC_HIGH 		1			/*Is the LED connected logic high or low*/
#define LED_PORT		PORTC_ID
#define LED_PIN			PIN1_ID
#if(LOGIC_HIGH == 1)
#define LED_IS_ON 		LOGIC_HIGH
#define LED_IS_OFF 		LOGIC_LOW
#elif(LOGIC_HIGH == 0)
#define LED_IS_ON 		LOGIC_LOW
#define LED_IS_OFF 		LOGIC_HIGH
#endif
/*============================================FUNCTIONS DECLARATIONS=============================================*/
/*Functions Description in .c file*/
void LED_init(void);
void LED_ON(void);
void LED_OFF(void);
void LED_Toggle(uint16 delay_time);
#endif /* LED_H_ */
