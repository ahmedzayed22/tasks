/*
 * assignment.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Ahmed
 */

#include "../LIB/Bit_Math.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCDSevenSeg/BCDSevenSeg.h"
#include <avr/delay.h>

#define  x RedLight
#define  y YellowLight
#define  z GreenLight
void led (void){
uint8 RedLight=30;
uint8 YellowLight =5;
uint8 GreenLight =60;
/*Setting all led pins as an outputs*/
DIO_SetPinDirection(PORTD,Pin3,DIO_Output);
DIO_SetPinDirection(PORTC,Pin2,DIO_Output);
DIO_SetPinDirection(PORTC,Pin7,DIO_Output);
	BCDSevenSegment_Initialization();
	/* count down for red light and it stands for 30 seconds */
while(x<=30){
	DIO_SetPinValue(PORTD,Pin3,STD_HIGH);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(x);
	_delay_ms(10);
	x--;

}
DIO_SetPinValue(PORTD,Pin3,STD_LOW);
/* count down for yellow light and it stands for 5 seconds */
while(y<=5){
	DIO_SetPinValue(PORTC,Pin7,STD_HIGH);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(y);
	_delay_ms(10);
	y--;

}
DIO_SetPinValue(PORTC,Pin7,STD_LOW);

while(z<=60){
	DIO_SetPinValue(PORTC,Pin2,STD_HIGH);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	BCDSevenSegment_WriteNumber(z);
	_delay_ms(10);
	z--;

}
DIO_SetPinValue(PORTC,Pin2,STD_LOW);



}

