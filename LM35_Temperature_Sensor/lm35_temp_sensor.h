/*
 *  lm35.h
 *  Created on: Oct 6, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			LM35 Temperature Sensor Driver
 */
#ifndef LM35_H_
#define LM35_H_
/*==================================INCLUDES=============================================*/
#include "adc.h" /*ADC Driver*/
#include "std_types.h"
/*===========================DEFINITIONS & CONFIGURATIONS================================*/
#define LM35_ADC_CHANNEL 		  2 /*ADC Channel where sensor is connected*/
#define LM35_MAX_VOLT     	      1.5 /*Vmax of the sensor*/
#define LM35_MAX_TEMPERATURE      150 /*Tmax of the sensor*/
/*=================================FUNCTIONS DECLARATIONS================================*/
/*Functions Description in .c file*/
uint8 LM35_getTempreture(void);
#endif /* LM35_H_ */
