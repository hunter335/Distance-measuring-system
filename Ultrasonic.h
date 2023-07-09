/*-------------------------------------------------------------------------------------------------
File Name : Ultrasonic.h
Author : Mostafa Elsayad
Date Created :
Description : Header File for the AVR Ultrasonic Driver
--------------------------------------------------------------------------------------------------*/


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"
#include "gpio.h"
/***********************************************DEFINITIONS***********************************************/
#define ULTRASONIC_TRIGGER_PULSE   10
#define ULTRASONIC_TRIGGER_PORT    PORTB_ID
#define ULTRASONIC_TRIGGER_PIN     PIN5_ID      /*trigger PB5*/
#define ULTRASONIC_ECHO_PORT       PORTD_ID
#define ULTRASONIC_ECHO_PIN        PIN6_ID      /*echo PD6*/
/***********************************************Functions Prototypes***********************************************/
/*-------------------------------------------------------------------------------------------------------
Function Name : Ultrasonci_init
Description :
 Initialize the ICU driver as required.
 Setup the ICU call back function.
 Setup the direction for the trigger pin as output pin through the GPIO driver.
Args :
[in]
void
[Return]
void
--------------------------------------------------------------------------------------------------------*/
void Ultrasonic_init(void);
/*-------------------------------------------------------------------------------------------------------
Function Name : Ultrasonci_Trigger
Description :send the trigger pulse to ultrasonic
Args :
[in]
void
[Return]
void
--------------------------------------------------------------------------------------------------------*/
void Ultrasonic_Trigger(void);
/*-------------------------------------------------------------------------------------------------------
Function Name : Ultrasonci_readDistance
Description :
 Send the trigger pulse by using Ultrasonic_Trigger function.
 Start the measurements by the ICU from this moment.
Args :
[in]
void
[Return]
uint16
--------------------------------------------------------------------------------------------------------*/
uint16 Ultrasonic_readDistance(void);
/*-------------------------------------------------------------------------------------------------------
Function Name : Ultrasonci_edgeProcessing
Description :
This is the call back function called by the ICU driver.
This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
Args :
[in]
void
[Return]
void
--------------------------------------------------------------------------------------------------------*/
void Ultrasonic_edgeProcessing(void);
#endif /* ULTRASONIC_H_ */