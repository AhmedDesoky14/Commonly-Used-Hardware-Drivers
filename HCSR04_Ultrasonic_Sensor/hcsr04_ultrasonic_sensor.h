/*
 *	hcsr04_ultrasonic_sensor.h
 *  Created on: Oct 17, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			HC-SR04 Ultrasonic sensor Driver
 *  			#Fully Configurable in case of microcontroller clock
 *  			 ,pre-scaler and pins configuration
 */
#ifndef HCSR04_ULTRASONIC_SENSOR_H_
#define HCSR04_ULTRASONIC_SENSOR_H_
/*==================================INCLUDES=============================================*/
#include "icu.h"
#include "gpio.h"
#include <avr./delay.h> /* For delay functions */
/*==============================Configuration Note=======================================*/
/*	to re-configure this driver go to line 21 in this .h file
 *  and go to line 88 in the .c file
 */
/*===========================DEFINITIONS & CONFIGURATIONS================================*/
#define TRIGGER_PORT_ID PORTD_ID
#define TRIGGER_PIN_ID 	PIN5_ID
/*=================================FUNCTIONS DECLARATIONS================================*/
/*Functions Description in .c file*/
void ULTRASONIC_edgeProcessing(void);
void ULTRASONIC_init(void);
uint16 ULTRASONIC_readDistance(void);
#endif /* HCSR04_ULTRASONIC_SENSOR_H_ */
