/*-------------------------------------------------------------------------------------------------
File Name : gpio
Author : Mostafa Elsayad
Date Created :
Description : Header File for the AVR GPIO Driver
--------------------------------------------------------------------------------------------------*/

#ifndef GPIO_H_
#define GPIO_H_
#include "std_types.h"

/***********************************************DEFINITIONS***********************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/***********************************************TYPES DECLARATION***********************************************/


/*-------------------------------------------------------------------------------------------------------
 Enum Name : GPIO_PinDirectionType
 Enum Description : This Enum is responsible for assign Direction (input , output) for pins
--------------------------------------------------------------------------------------------------------*/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

/*-------------------------------------------------------------------------------------------------------
 Enum Name : GPIO_PortDirectionType
 Enum Description : This Enum is responsible for assign Direction (input, output) for ports
--------------------------------------------------------------------------------------------------------*/
typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/***********************************************Functions Prototypes***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name : Setup Pin Direction
Description : Setup the direction of the required pin input/output,If the input port number or pin number are not correct, The function will not handle the request.
Args :
[in]
uint8 port_num : ID for the port number
uint8 pin_num :ID for the pin number
GPIO_PinDirectionType direction : the Direction of the Pin (input , Output)
[out]
void
--------------------------------------------------------------------------------------------------------*/
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/*-------------------------------------------------------------------------------------------------------
Function Name : write pin
Description : Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
Args :
[in]
uint8 port_num : ID for the port number
uint8 pin_num :ID for the pin number
uint8 value : value to be written on the pin (LOGIC_HIGH , LOGIC_LOW)
[out]
void
--------------------------------------------------------------------------------------------------------*/
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);
/*-------------------------------------------------------------------------------------------------------
Function Name : read pin
Description : Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
Args :
[in]
uint8 port_num : ID for the port number
uint8 pin_num :ID for the pin number
[out]
uint8 value : value to be written on the pin (LOGIC_HIGH , LOGIC_LOW)

--------------------------------------------------------------------------------------------------------*/
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/*-------------------------------------------------------------------------------------------------------
Function Name : setupPortDirection
Description : Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
Args :
[in]
uint8 port_num : ID for the port number
uint8 direction : direction for all port (INPUT_PORT ,OUTPUT_PORT)
[out]
void
--------------------------------------------------------------------------------------------------------*/
void GPIO_setupPortDirection(uint8 port_num, uint8 direction);

/*-------------------------------------------------------------------------------------------------------
Function Name : write port
Description : Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
Args :
[in]
uint8 port_num : ID for the port number
uint8 value : value to be written on all port pins
[out]
void
--------------------------------------------------------------------------------------------------------*/
void GPIO_writePort(uint8 port_num, uint8 value);

/*-------------------------------------------------------------------------------------------------------
Function Name : read port
Description : Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
Args :
[in]
uint8 port_num : ID for the port number
[out]
uint8 value : value to be written on all port pins
--------------------------------------------------------------------------------------------------------*/
uint8 GPIO_readPort(uint8 port_num);
#endif /* GPIO_H_ */
