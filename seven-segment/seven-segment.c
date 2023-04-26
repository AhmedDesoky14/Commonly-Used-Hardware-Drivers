/*
 *  seven-segment.c
 *  Created on: Dec 4, 2022
 *  Author: Ahmed Desoky
 *  Description:
 *  			Single 7-segment Driver to easily use it in Layered Architecture Model
 *  			it supports common anode or common cathode 7-segments
 *  			also supports using decoder or not and supports enabling using one of MCU pins
 */
/*==================================================INCLUDES=====================================================*/
#include "seven-segment.h"
/*============================================FUNCTIONS DEFINITIONS==============================================*/
/* Description:
 * 					Function to setup the 7-segment for different connections situations
 * [No Inputs]:
 * [No Returns]:
 */
void Segment_Init(void)
{
	/*set pins as output pins*/
	GPIO_setupPinDirection(SS_PORT,SSA_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SS_PORT,SSB_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SS_PORT,SSC_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SS_PORT,SSD_PIN,PIN_OUTPUT);
#if(CONNECTION_MODE == 1)
	GPIO_setupPinDirection(SS_PORT,SSE_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SS_PORT,SSF_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SS_PORT,SSG_PIN,PIN_OUTPUT);
#endif
#if(ALLOW_ENABLING == 1)
	GPIO_setupPinDirection(SEVEN_SEGMENT_ENABLE_PORT,SEVEN_SEGMENT_ENABLE_PIN,PIN_OUTPUT);	/*set control pin as output*/
#endif
}
/*---------------------------------------------------------------------------------------------------------------*/
#if(ALLOW_ENABLING == 1)
/* Description:
 * 					Function to Enable the 7-segment display if Enabling is allowed using one of the MCU pins
 * [No Inputs]:
 * [No Returns]:
 */
void Segment_Enable(void)
{
#if(OPERATION_MODE == 0)
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT,SEVEN_SEGMENT_ENABLE_PIN,LOGIC_LOW);
#elif(OPERATION_MODE == 1)
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT,SEVEN_SEGMENT_ENABLE_PIN,LOGIC_HIGH);
#endif
}
/*---------------------------------------------------------------------------------------------------------------*/
/* Description:
 * 					Function to Disable the 7-segment display if Enabling is allowed using one of the MCU pins
 * [No Inputs]:
 * [No Returns]:
 */
void Segment_Disable(void)
{
#if(OPERATION_MODE == 0)
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT,SEVEN_SEGMENT_ENABLE_PIN,LOGIC_HIGH);
#elif(OPERATION_MODE == 1)
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT,SEVEN_SEGMENT_ENABLE_PIN,LOGIC_LOW);
#endif
}
#endif
/*---------------------------------------------------------------------------------------------------------------*/
/* Description:
 * 					Function to set the digit into the 7-segment
 * 					this function supports connection in case of MCU controlling or not
 * 					also supports using of decoders or not and supports common cathode or common anode 7-segments
 * [Inputs]:		Digit to be set
 * [No Returns]:
 */
/*Important Coding Note: Check line 25 in the .h file*/
void Segment_setDigit(uint8 digit)
{
#if(CONNECTION_MODE == 0)	/*using decoder*/
#if(OPERATION_MODE == 0)	/*Common Cathode*/  /*used decoder is 7448*/
	SS_PORT &= 0xF0;	/*Reset the 7-segment at first*/
	SS_PORT |= digit;
#elif(OPERATION_MODE == 1)	/*Common Anode*/	/*used decoder is 7447*/
	SS_PORT &= 0xF0;	/*Reset the 7-segment at first*/
	SS_PORT |= digit;
#endif
#elif(CONNECTION_MODE == 1)	/*without using decoder*/
#if(OPERATION_MODE == 0)	/*Common Cathode*/
	SS_PORT &= 0x1;	/*Reset the 7-segment at first*/
	switch(digit)
	{
		case 0:
			SS_PORT |= 0x7E;
			break;
		case 1:
			SS_PORT |= 0x0C;
			break;
		case 2:
			SS_PORT |= 0xB6;
			break;
		case 3:
			SS_PORT |= 0x9E;
			break;
		case 4:
			SS_PORT |= 0xCC;
			break;
		case 5:
			SS_PORT |= 0xDA;
			break;
		case 6:
			SS_PORT |= 0xFB;
			break;
		case 7:
			SS_PORT |= 0x0E;
			break;
		case 8:
			SS_PORT |= 0xFE;
			break;
		case 9:
			SS_PORT	|= 0xDE;
			break;
	}
#elif(OPERATION_MODE == 1)	/*Common Anode*/
	SS_PORT |= 0xFE;	/*Reset the 7-segment at first*/
	switch(digit)
	{
		case 0:
			SS_PORT &= 0x80;
			break;
		case 1:
			SS_PORT &= 0xF2;
			break;
		case 2:
			SS_PORT &= 0x48;
			break;
		case 3:
			SS_PORT &= 0x60;
			break;
		case 4:
			SS_PORT &= 0x32;
			break;
		case 5:
			SS_PORT &= 0x24;
			break;
		case 6:
			SS_PORT &= 0x03;
			break;
		case 7:
			SS_PORT &= 0xF0;
			break;
		case 8:
			SS_PORT &= 0x00;
			break;
		case 9:
			SS_PORT	&= 0x20;
			break;
		}
#endif
#endif
}
