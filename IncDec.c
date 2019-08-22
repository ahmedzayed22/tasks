/*
 * IncDec.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Ahmed
 */
#include "../LIB/Bit_Math.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/BCDSevenSeg/BCDSevenSeg.h"
#include <avr/delay.h>
uint8 y=0;


void Inc(void) {

	/* Initialization */
	DIO_SetPortDirection(PORTA, DIO_Output);
	DIO_SetPortDirection(PORTB, DIO_Output);
	DIO_SetPortDirection(PORTC, DIO_Output);
	DIO_SetPortDirection(PORTD, DIO_Output);
    BCDSevenSegment_Initialization();
	DIO_SetPinDirection(PORTB, Pin0, DIO_Input);
	DIO_SetPinDirection(PORTD, Pin2, DIO_Input);
	DIO_SetPinDirection(PORTB, Pin4, DIO_Input);


	STD_levelType CurrentState1 = STD_LOW;
	STD_levelType CurrentState2 = STD_LOW;
	STD_levelType CurrentState3 = STD_LOW;

	/*STD_levelType PreviousState1 = STD_LOW;
	STD_levelType PreviousState2 = STD_LOW;
	STD_levelType PreviousState3 = STD_LOW;*/



	while(1){

				CurrentState1 = DIO_GetPinValue(PORTB, Pin0);
				CurrentState3 = DIO_GetPinValue(PORTD, Pin2);
				CurrentState2 = DIO_GetPinValue(PORTB, Pin4);


			if((STD_HIGH == CurrentState1)){
					if (y<99){
						y++;
					}else {
						y= 0 ;
					}
				while((DIO_GetPinValue(PORTB, Pin0))==STD_HIGH){

					BCDSevenSegment_WriteNumber(y);

				}

			}else if((STD_HIGH == CurrentState2)){

				if (y>0){
					y--;
				}else {
					y= 99 ;
				}
				while((DIO_GetPinValue(PORTB, Pin4))==STD_HIGH){

					BCDSevenSegment_WriteNumber(y);

				}
			}else if ((STD_HIGH == CurrentState3)){

				y = 0 ;
				while((DIO_GetPinValue(PORTD, Pin2))==STD_HIGH){

					BCDSevenSegment_WriteNumber(y);

				}

			}else {
					while(DIO_GetPinValue(PORTD, Pin2) == 0 && DIO_GetPinValue(PORTB, Pin0)==0 &&DIO_GetPinValue(PORTB, Pin4)==0 ){
						BCDSevenSegment_WriteNumber(y);

				      }
	        }



	}

}
