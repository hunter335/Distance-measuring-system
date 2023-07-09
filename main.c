/*-------------------------------------------------------------------------------------------------
File Name : main.c
Author : Mostafa Elsayad
Date Created :
Description : source File for the AVR Ultrasonic Driver
--------------------------------------------------------------------------------------------------*/

#include "ultrasonic.h"
#include "lcd.h"
#include<avr/interrupt.h>
#include<util/delay.h>

int main (void){
    sei();//Global interrupt enable
	/*initialization  */
	LCD_init();
	Ultrasonic_init();
	uint16 distance =0;
	LCD_displayString("Distance=     cm");

	while(1){
		/*read distance */
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		/*read distance*/
		LCD_integerToString(distance);
		if(distance<100)
			LCD_displayCharacter(' ');
		/*delay between every trigger*/
		_delay_ms(100);
	}
}
