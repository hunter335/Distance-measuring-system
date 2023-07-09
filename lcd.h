/*-------------------------------------------------------------------------------------------------
File Name : lcd.h
Author : Mostafa Elsayad
Date Created :
Description : Header File for the AVR LCD Driver
--------------------------------------------------------------------------------------------------*/

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"

/***********************************************DEFINITIONS***********************************************/

#define LCD_DATA_BITS_MODE 8
/* lcd data bits configuration */
#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#if (LCD_DATA_BITS_MODE == 4)

#ifdef LCD_LAST_PORT_PINS
#define LCD_FIRST_DATA_PIN_ID         PIN4_ID
#else
#define LCD_FIRST_DATA_PIN_ID         PIN0_ID
#endif

#endif

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTB_ID
#define LCD_RS_PIN_ID                  PIN0_ID    /*RS → PB0*/

#define LCD_RW_PORT_ID                 PORTB_ID
#define LCD_RW_PIN_ID                  PIN1_ID    /*RS → PB1*/

#define LCD_E_PORT_ID                  PORTB_ID
#define LCD_E_PIN_ID                   PIN2_ID    /*RS → PB2*/

#define LCD_DATA_PORT_ID               PORTA_ID   /*Data Bus → all PORTA pins*/

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

/***********************************************Functions Prototypes***********************************************/

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_init
Description :Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_init(void);

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_sendCommand
Description : Send the required command to the screen
Args :
[in]
uint8 command : command will be send to screen .
[out]
void
--------------------------------------------------------------------------------------------------------*/

void LCD_sendCommand(uint8 command);
/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_displayCharacter
Description : Send the required character to the screen
Args :
[in]
uint8 data :  character will be display on screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_displayCharacter (uint8 data);

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_displayString
Description : Send the required String to the screen
Args :
[in]
const char *Str :  String will be display on screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_displayString (const char *Str);

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_moveCursor
Description : Move the cursor to a specified row and column index on the screen
Args :
[in]
uint8 row : row number the cursor will be move to it
uint8 col : column  number the cursor will be move to it
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_moveCursor (uint8 row , uint8 col );

/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_displayStringRowColumn
Description : Display the required string in a specified row and column index on the screen
Args :
[in]
uint8 row : row number
uint8 col : column  number
const char *Str :  String will be display on screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_displayStringRowColumn(uint8 row , uint8 col , const char *Str);
/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_clearScreen
Description : send the clear screen
Args :
[in]
void
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_clearScreen(void);
/*-------------------------------------------------------------------------------------------------------
Function Name : LCD_integerToString
Description : Display the required decimal value on the screen
Args :
[in]
int data : decimal value will be send to screen
[out]
void
--------------------------------------------------------------------------------------------------------*/
void LCD_integerToString(int data);
#endif /* LCD_H_ */
