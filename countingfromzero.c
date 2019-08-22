/*
 * countingfromzero.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Ahmed
 */


#include "../LIB/Bit_Math.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCDSevenSeg/BCDSevenSeg.h"
#include <avr/delay.h>



uint8 x=0;


void Count(void)

{

	/* Check the switch (button0)[PINB0] if pressed --> COUNT */

	/* Initialization */
	DIO_SetPortDirection(PORTA, DIO_Output);
	DIO_SetPortDirection(PORTB, DIO_Output);
	DIO_SetPortDirection(PORTC, DIO_Output);
	DIO_SetPortDirection(PORTD, DIO_Output);
    BCDSevenSegment_Initialization();
	DIO_SetPinDirection(PORTB, Pin0, DIO_Input);


	/** Logic **/

	STD_levelType CurrentState = STD_LOW;

while(1){

			CurrentState = DIO_GetPinValue(PORTB, Pin0);


			if(STD_HIGH == CurrentState)
			{

		while((DIO_GetPinValue(PORTB, Pin0))==STD_HIGH){
			BCDSevenSegment_WriteNumber(x);
			_delay_ms(50);
			x++;
			if((x==99)&&(STD_HIGH == CurrentState)){
				while((DIO_GetPinValue(PORTB, Pin0))==STD_HIGH){
					DIO_SetPinDirection(PORTA, Pin3, DIO_Output);
					DIO_SetPinValue(PORTA,Pin3,STD_HIGH);

					_delay_ms(1000);
					DIO_SetPinValue(PORTA,Pin3,STD_LOW);
				Count();

				}
			}
		}


			}

else if(STD_LOW == CurrentState){

				while((DIO_GetPinValue(PORTB, Pin0))==STD_LOW){
					BCDSevenSegment_WriteNumber(x);

				}
			}


}
		}

