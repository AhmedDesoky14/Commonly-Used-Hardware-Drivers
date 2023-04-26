/*
 *  lm35.c
 *  Created on: Oct 6, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			LM35 Temperature Sensor Driver
 */
/*==================================INCLUDES=============================================*/
#include "lm35.h"
/*=============================FUNCTIONS DEFINITIONS=====================================*/
/* Description:
 * Function to get the temperature sensor reading
 * [No Inputs]
 * [Returns]:
 * 				Measured Temperature
 */
uint8 LM35_getTempreture(void)
{
	uint16 ADC_value;
	ADC_value = ADC_readChannel(LM35_ADC_CHANNEL);
	return((uint8)(((uint32)(ADC_value)*LM35_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(LM35_MAX_VOLT*ADC_MAXIMUM_VALUE)));
}
