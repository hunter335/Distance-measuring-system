/*-------------------------------------------------------------------------------------------------
File Name : icu.h
Author : Mostafa Elsayad
Date Created :
Description : Header File for the AVR ICU Driver
--------------------------------------------------------------------------------------------------*/

#ifndef ICU_H_
#define ICU_H_
#include "std_types.h"

/***********************************************TYPES DECLARATION***********************************************/
/*-------------------------------------------------------------------------------------------------------
 Enum Name : Icu_Clock
 Enum Description : This Enum is responsible for assign numbers for clock select bit
--------------------------------------------------------------------------------------------------------*/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

/*-------------------------------------------------------------------------------------------------------
 Enum Name : Icu_EdgeType
 Enum Description : This Enum is responsible for detect the edge
--------------------------------------------------------------------------------------------------------*/
typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

/*-------------------------------------------------------------------------------------------------------
 struct Name : Icu_ConfigType
 struct Description : This struct is responsible for assign values for configuration type
--------------------------------------------------------------------------------------------------------*/
typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;

/***********************************************Functions Prototypes***********************************************/

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
void Icu_init(const Icu_ConfigType * Config_Ptr);

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_setCallBack
Description : Function to set the call back function address
Args :
[in]
void(*a_ptr)(void)
[Return]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_setCallBack(void(*a_ptr)(void));

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_setEdgeDetectionType
Description :Function to set the required edge detection.
Args :
[in]
const Icu_EdgeType edgeType
[return]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_setEdgeDetectionType(const Icu_EdgeType a_edgeType);

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
uint16 Icu_getInputCaptureValue(void);

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_clearTimerValue
Description : this function used to clear Timer1 value to start count from zero
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_clearTimerValue(void);

/*-------------------------------------------------------------------------------------------------------
Function Name :  Icu_Deinit
Description : function to disable Timer1 to stop the Icu driver
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void Icu_DeInit(void);
#endif /* ICU_H_ */
