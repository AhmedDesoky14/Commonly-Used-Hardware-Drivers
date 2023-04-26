/*
 *	hcsr04_ultrasonic_sensor.c
 *  Created on: Oct 17, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			HC-SR04 Ultrasonic sensor Driver
 *  			#Fully Configurable in case of microcontroller clock
 *  			 ,pre-scaler and pins configuration
 */
/*==================================INCLUDES=============================================*/
#include "hcsr04_ultrasonic_sensor.h"
/*===============================GLOBAL VARIABLES========================================*/
float32 Distance=0;
uint16 g_echoTime=0;
uint8 g_edgeCounter=0;
/*Make ICU_config structure with initially N=8*/
ICU_CONFIG_STRUCT ICU_Config = {F_CPU_N8,Noise_Canceler_ON,RISING};
/*========================PRIVATE FUNCTIONS DECLARATIONS=================================*/
static void ULTRASONIC_Trigger(void);
/*=============================FUNCTIONS DEFINITIONS=====================================*/
/* Description:
 * 				the callback function called by the ICU interrupt service routine
 * 				to regulate echo pin ON period to calculate its time
 * [No Inputs]:
 * [No Returns]:
 */
void ULTRASONIC_edgeProcessing(void)
{
	g_edgeCounter++;
	if(g_edgeCounter==1)
	{
		ICU_resetTimer();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCounter==2)
	{
		g_echoTime = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RISING);
		ICU_resetTimer();
		g_edgeCounter=0;
	}
}
/*----------------------------------------------------------------------------------------*/
/* Description:
 * 				Function to Initialize the Ultrasonic sensor
 * 				using the ICU Config structure
 * [No Inputs]:
 * [No Returns]:
 */
void ULTRASONIC_init(void)
{
	/*if Microcontroller frequency less than 8MHz*/
	/*Set no Pre-scaler*/
	if(F_CPU<8000000)
		ICU_Config.ICU_clock = F_CPU_CLOCK;
	/*if Microcontroller frequency greater than or equal 8MHz*/
	/*Set pre-scaler N=8*/
	else if(F_CPU>=8000000)
		ICU_Config.ICU_clock = F_CPU_N8;
	ICU_setCallBackFunction(ULTRASONIC_edgeProcessing);
	ICU_init(&ICU_Config);
	GPIO_setupPinDirection(TRIGGER_PORT_ID,TRIGGER_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);
}
/*----------------------------------------------------------------------------------------*/
/* Description:
 * 				Private Function to trigger the Ultrasonic sensor ON
 * [No Inputs]:
 * [No Returns]:
 */
static void ULTRASONIC_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(TRIGGER_PORT_ID,TRIGGER_PIN_ID,LOGIC_LOW);
}
/*----------------------------------------------------------------------------------------*/
/* Description:
 * 				Function to calculate Distance read by
 * 				the Ultrasonic sensor and returns it
 * [No Inputs]:
 * [Returns]:	Distance read by the Ultrasonic sensor
 */
uint16 ULTRASONIC_readDistance(void)
{
	ULTRASONIC_Trigger();
	/*=========================RE-CONFIGUE HERE=============================================*/
	/*This number (58) must be changed every time chosen pre-scaler is changed*/
	Distance = (g_echoTime/58);
	return Distance+1;
}
