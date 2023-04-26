/*
 *  pushbutton.h
 *  Created on: Nov 9, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			push button Driver to easily control the push button in a layered architecture model
 */
#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
/*=================================================INCLUDES======================================================*/
#include "gpio.h"
#include "std_types.h"
#include <avr/io.h>
/*=============================================Configuration Note================================================*/
/*to re-configure this driver go to line 18 in the .h file*/
/*========================================DEFINITIONS & CONFIGURATIONS===========================================*/
#define PULL_DOWN			0
#define PULL_UP				1
#define INTERNAL_PULL_UP	0
#if((PULL_DOWN&PULL_UP != 0) || (PULL_DOWN&INTERNAL_PULL_UP != 0) || (PULL_UP&INTERNAL_PULL_UP != 0) \
		|| (PULL_DOWN||PULL_UP||INTERNAL_PULL_UP) == 0)
	#error Configuration Error
#endif
#define BUTTON_PORT_ID		PORTD_ID
#define BUTTON_PIN_ID		PIN2_ID
/*---------------------------------------------------------------------------------------------------------------*/
#if (PULL_DOWN == 1)
#define BUTTON_PUSHED		LOGIC_HIGH
#define BUZZER_RELEASED		LOGIC_LOW
#elif(PULL_UP == 1 || INTERNAL_PULL_UP == 1)
#define BUTTON_PUSHED		LOGIC_LOW
#define BUZZER_RELEASED		LOGIC_HIGH
#endif
/*============================================FUNCTIONS DECLARATIONS=============================================*/
/*Functions Description in .c file*/
void Button_init(void);
uint8 Button_getStatus(void);
#endif /* PUSHBUTTON_H_ */
