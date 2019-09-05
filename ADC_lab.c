/*
 * ADC_lab.c
 *
 *  Created on: Sep 2, 2019
 *      Author: Ahmed
 */

#include "../LIB/std_types.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/GIE/GIE.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/BCDSevenSeg/BCDSevenSeg.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/DIO/DIO.h"
#include <stdlib.h>
#include <avr/delay.h>
uint8 ADC_COMPLETE=0;
uint8 Flag=0;
void ADC_Interrupt (void){

	ADC_COMPLETE=1;


}

void EXTI_Interrupt (void){

	Flag=1;


}



void Adc_temp (void){
	DIO_SetPinDirection(PORTA,Pin1,DIO_Input);
	DIO_SetPinDirection(PORTA,Pin0,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin2,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin3,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin4,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin5,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin6,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin7,DIO_Output);
	DIO_SetPortDirection(PORTB,DIO_Output);
uint16 DigitalValue=0;
//uint8 string_array[8];
uint8 degreepattern[8]=  {0x1C, 0x14, 0x1C, 0x03, 0x04, 0x04, 0x04, 0x03};
ADC_SetCallBack(ADC_Interrupt);
EXTI_SetCallback(EXTI_Interrupt);
EXTI_Initialization();
EXTI_EnableInt0();
ADC_Initialize();
ADC_EnableInt();
GIE_Enable();

LCD_StoreCustomChr(degreepattern,0);

//ADC_StartConversion(ADC_Channel_1);

	while(1){
		ADC_StartConversion(ADC_Channel_1);
		if((ADC_COMPLETE==1)&&(Flag==1)){
			ADC_COMPLETE=0;

		DigitalValue=ADC_GetResult();
		uint16 m_voltage = (DigitalValue)*(5000/1023);
	uint8 temp=m_voltage/10;
	BCDSevenSegment_Initialization();
	//	itoa(temp,string_array,10);

		//LCD_WriteString(string_array,0,5);
		//LCD_DisplayCustomChr(0,0,8);


		uint8 SevenSegOne, SevenSegTwo;
		uint8 i;

		uint8 Value = temp;

			if (Value < 100){

				while(Flag==1){
for(i=0;i<50;i++){
					/* 53 / 10 = 5 */
					SevenSegOne = Value / 10;
					/* 53 % 10 = 3*/
					SevenSegTwo = Value % 10;

					/* Disable seven segment 1 */
					BCDSevenSegment_Disable1();
					/* Disable seven segment 2 */
					BCDSevenSegment_Disable2();

					BCDSevenSegment_WriteNumber(SevenSegOne);

					/* Enable seven segment 1 */
					BCDSevenSegment_Enable1();

					/* 10 mSec delay */
					_delay_ms(0.1);

					/* Disable seven segment 1 */
					BCDSevenSegment_Disable1();

					BCDSevenSegment_WriteNumber(SevenSegTwo);

					/* Enable seven segment 2 */
					BCDSevenSegment_Enable2();

					/* 10 mSec delay */
					_delay_ms(0.1);
					BCDSevenSegment_Disable2();
					Flag=0;
}
				}
			}

	}




}


		}
