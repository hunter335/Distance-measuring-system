/*-------------------------------------------------------------------------------------------------
File Name : icu.c
Author : Mostafa Elsayad
Date Created :
Description : source File for the AVR ICU Driver
--------------------------------------------------------------------------------------------------*/
#include "icu.h"
#include "common_macros.h"   /*to use macros */
#include <avr/io.h>          /* to use ICU/Timer1 register*/
#include <avr/interrupt.h>   /* for ICU ISR*/

/***********************************************GLOBAL VARIABLES***********************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/***********************************************INTERRUPT SERVICE ROUTINE***********************************************/

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/***********************************************FUNCTIONS DEFINITIONS***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_init
Description : this function used to initialize icu
 *  Set the required clock.
 *  Set the required edge detection.
 *  Enable the Input Capture Interrupt.
 *  Initialize Timer1 Registers
Args :
[in]
const Icu_configType * config_ptr
[out]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_init(const Icu_ConfigType * Config_Ptr){
    /*configure ICP1/PD6 as input pin*/
	DDRD &= ~(1<<PD6);
	/*Timer1 operate in Normal mode
	 * FOC1A =1
	 * FOC1B=1 non_PWM mode*/
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);

	/*insert the required clock value in the first three bits (CS10, CS11 and CS12) of TCCR1B Register*/
	TCCR1B = (TCCR1B & 0xF8)| (Config_Ptr->clock);
	/*Insert the required edge type in ICES1 bit in TCCR1B register*/
	TCCR1B = (TCCR1B & 0xBF)| ((Config_Ptr->edge)<<6);
	 /*initial value for Timer1*/
	TCNT1 =0;
	/*initial value for the input capture register */
	ICR1=0;
	/*Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin*/
    TIMSK = (1<<TICIE1);
}

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_setCallBack
Description : Function to set the call back function address
Args :
[in]
void(*a_ptr)(void)
[Return]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_setCallBack(void(*a_ptr)(void)){
	g_callBackPtr = a_ptr;
}

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_setEdgeDetectionType
Description :Function to set the required edge detection.
Args :
[in]
const Icu_EdgeType edgeType
[return]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_setEdgeDetectionType(const Icu_EdgeType a_edgeType){
	/*insert the required edge type in ICES1 bit in TCCR1B register*/
	TCCR1B = (TCCR1B & 0xBF) | (a_edgeType<<6);
}

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_getInputCaptureValue
Description : Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
Args :
[in]
void
[Return]
void
--------------------------------------------------------------------------------------------------------*/
uint16 Icu_getInputCaptureValue(void){
	return ICR1;
}

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_clearTimerValue
Description : this function used to clear Timer1 value to start count from zero
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_clearTimerValue(void){
	TCNT1 = 0;
}

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_Deinit
Description : function to disable Timer1 to stop the Icu driver
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_DeInit(void){
	/*clear all Timer1 registers */
	TCCR1A =0 ;
	TCCR1B =0;
	TCNT1 =0 ;
	ICR1 =0;
	/*Disable input capture interrupt */
	TIMSK &= ~(1<<TICIE1);
}
