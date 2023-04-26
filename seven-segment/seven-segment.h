/*
 *  seven-segment.h
 *  Created on: Dec 4, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			Single 7-segment Driver to easily control the push button in a layered architecture model
 */
#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
/*======================================================INCLUDES=========================================================*/
#include "gpio.h"
#include "std_types.h"
/*==================================================Configuration Note===================================================*/
/*to re-configure this driver go to line 17 in the .h file*/
/*=============================================DEFINITIONS & CONFIGURATIONS==============================================*/
#define OPERATION_MODE 	0 /*0=Common Cathode (to enable segment set high) - 1=Common Anode (to enable segment set low)*/
#define CONNECTION_MODE	1 /*0=using Decoder (7447 for common anode or 7448 for common cathode) - 1=without using decoder*/
#define ALLOW_ENABLING	1 /*0=7-Segment is enabled by VCC or GND - 1=7-Segment is enabled by a signal from the MCU*/
#if(ALLOW_ENABLING == 1)
#define SEVEN_SEGMENT_ENABLE_PORT 	PORTA_ID
#define SEVEN_SEGMENT_ENABLE_PIN	PIN1_ID
#endif
#define SS_PORT	PORTC_ID
/*Important Note: Make sure that pins are connected to a single port and connected starting from pin 1 to pin 7*/
#define SSA_PIN	PIN1_ID
#define SSB_PIN	PIN2_ID
#define SSC_PIN	PIN3_ID
#define SSD_PIN	PIN4_ID
#if(CONNECTION_MODE == 1)
#define SSE_PIN	PIN5_ID
#define SSF_PIN	PIN6_ID
#define SSG_PIN	PIN7_ID
#endif
/*=================================================FUNCTIONS DECLARATIONS================================================*/
/*Functions Description in .c file*/
void Segment_Init(void);
#if(ALLOW_ENABLING == 1)
void Segment_Enable(void);
void Segment_Disable(void);
#endif
void Segment_setDigit(uint8 digit);
#endif /* SEVEN_SEGMENT_H_ */
