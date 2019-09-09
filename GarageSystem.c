/*
 * GarageSystem.c
 *
 *  Created on: Sep 8, 2019
 *      Author: Ahmed
 */
#include "../LIB/std_types.h"
#include "../LIB/Bit_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include <stdlib.h>
#include <string.h>
#include <avr/delay.h>

/*indicator for deciding whether it's registeration or signing in*/
uint8 indicator=0;

/*the first 4 numbers of password*/
 uint8 x=0;
 uint8 y=0;
 uint8 z=0;
 uint8 w=0;

 /*the next 4 numbers for check*/

 uint8 m=0;
 uint8 n=0;
 uint8 q=0;
 uint8 s=0;

uint8 pass[4];

uint8 array[4];
uint8 array1[4];
uint8 passcheck[4];

uint8 Col=8;
void Door_Unlock(void){

	/* initialization of prephirals */
LCD_Initialize();
DIO_SetPinDirection(PORTD, Pin2, DIO_Input);
DIO_SetPinDirection(PORTB, Pin0, DIO_Input);
DIO_SetPinDirection(PORTB, Pin4, DIO_Input);
DIO_SetPinDirection(PORTC, Pin2, DIO_Output);
DIO_SetPinDirection(PORTA,Pin3,DIO_Output);
DIO_SetPinDirection(PORTD,Pin3,DIO_Output);


/** Logic **/

STD_levelType CurrentState1 = STD_LOW;
STD_levelType CurrentState2 = STD_LOW;
STD_levelType CurrentState3 = STD_LOW;
while(1){

	CurrentState1 = DIO_GetPinValue(PORTD, Pin2);
	CurrentState2 = DIO_GetPinValue(PORTB, Pin0);
	CurrentState3 = DIO_GetPinValue(PORTB, Pin4);




LCD_WriteString("PASSWORD:",0,0);



/*INCREMNTING AND DECREMNTING THE  NUMBERS IN pass[x]*/
if((CurrentState1==STD_HIGH)&&(indicator==0)){

if((x>=0)&&(x<=9)&&(Col==9)){
	                 x++;
                     itoa(x,array,10);
                     LCD_WriteString(array,0,Col);
                     _delay_ms(500);

                     pass[0]=x;
	                       }

else if((y>=0)&&(y<=9)&&(Col==10)){
	 y++;
	                  itoa(y,array,10);
	                  LCD_WriteString(array,0,Col);
	                  _delay_ms(500);

	                  pass[1]=y;

                                   }
else if((z>=0)&&(z<=9)&&(Col==11)){
	 z++;
	                    itoa(z,array,10);
	                    LCD_WriteString(array,0,Col);
	                    _delay_ms(500);

		        	    pass[2]=z;
                                    }




else if((w>=0)&&(w<=9)&&(Col==12)){
	  w++;
	                  itoa(w,array,10);
	                  LCD_WriteString(array,0,Col);
	                  _delay_ms(500);

		        	  pass[3]=w;

                                   }





                           }

else if((CurrentState2==STD_HIGH)&&((indicator==0))){
	if((x>0)&&(Col==9)){
                 	x--;
          	        itoa(x,array,10);
                	LCD_WriteString(array,0,Col);
        	        _delay_ms(500);
        	        pass[0]=x;

	                   }



	else if((y>0)&&(Col==10)){
	         	    y--;
	          	    itoa(y,array,10);
	         	    LCD_WriteString(array,0,Col);
	        	    _delay_ms(500);
	        	    pass[1]=y;

		                       }




	else if((z>0)&&(Col==11)){
		         	z--;
		          	itoa(z,array,10);
		         	LCD_WriteString(array,0,Col);
		        	_delay_ms(500);
		        	 pass[2]=z;

			                  }





	else if((w>0)&&(Col==12)){
		         	w--;
		          	itoa(w,array,10);
		         	LCD_WriteString(array,0,Col);
		        	_delay_ms(500);
		      	    pass[3]=w;

			                 }




                                  }


/*********************************************************************************/

/******************************MOVING THE CURSOR TO THE NEXT NUMBER POSITION***********/
else if((CurrentState3==STD_HIGH)&&(indicator==0)){
	              Col++;

	              if((Col>=8)&&(Col<=12)){
	              LCD_GoToPos(0,Col);
	              _delay_ms(500);

                              }
	if((Col>12)){
             	Col=8;
             	indicator=1;
             	LCD_WriteCmd(0x01);
             	      _delay_ms(500);
                      LCD_WriteString("PASS SAVED !",0,1);
                      _delay_ms(1000);
    	              LCD_WriteCmd(0x01);
                      _delay_ms(1000);
                      LCD_WriteString("CONFIRM PASSWORD ",0,0);
                    	_delay_ms(1000);
       	           	LCD_WriteCmd(0x01);

                }
                            }
/***************************************************************************************/




/*Moving Cursor for the numbers position  for Checking */
else if((CurrentState3==STD_HIGH)&&(indicator==1)){
	              Col++;

	              if((Col>=8)&&(Col<=12)){
	              LCD_GoToPos(0,Col);
	              _delay_ms(500);

                              }
	if((Col>12)){
             Col=8;

             if(((pass[0]-passcheck[0])==0)&&((pass[1]-passcheck[1])==0)&&((pass[2]-passcheck[2])==0)&&((pass[3]-passcheck[3])==0)){

                       LCD_WriteString("APPROVED WELCOME",1,0);

                       DIO_SetPinValue(PORTD,Pin3,STD_HIGH);

                                    }
             else {
            	 LCD_WriteCmd(0X01);
            	 LCD_WriteString("ACCESS DENIED",0,0);
            	 LCD_WriteString("DOUCHBAG !!",1,5);
            	 _delay_ms(1000);
            	 DIO_SetPinValue(PORTA ,Pin3,STD_HIGH);
            	 _delay_ms(100);
            	 DIO_SetPinValue(PORTA ,Pin3,STD_LOW);
            	 LCD_WriteCmd(0X01);
            	 _delay_ms(1000);
             }
                }
                            }


/***************************************************************************************/
if((CurrentState1==STD_HIGH)&&(indicator==1)){

if((m>=0)&&(m<=9)&&(Col==9)){
	                 m++;
                     itoa(m,array1,10);
                     LCD_WriteString(array1,0,Col);
                     _delay_ms(500);

                     passcheck[0]=m;
	                       }

else if((n>=0)&&(n<=9)&&(Col==10)){
	 n++;
	                     itoa(n,array1,10);
	                     LCD_WriteString(array1,0,Col);
	                     _delay_ms(500);

	                     passcheck[1]=n;

                                   }
else if((q>=0)&&(q<=9)&&(Col==11)){
	 q++;
	                     itoa(q,array1,10);
	                     LCD_WriteString(array1,0,Col);
	                     _delay_ms(500);

	                     passcheck[2]=q;
                                    }




else if((s>=0)&&(s<=9)&&(Col==12)){
	 s++;
	                     itoa(s,array1,10);
	                     LCD_WriteString(array1,0,Col);
	                     _delay_ms(500);

	                     passcheck[3]=s;

                                   }





                           }

else if((CurrentState2==STD_HIGH)&&((indicator==1))){
	if((m>0)&&(Col==9)){
                 	m--;
          	        itoa(m,array1,10);
                	LCD_WriteString(array1,0,Col);
        	        _delay_ms(500);
        	        passcheck[0]=m;

	                   }



	else if((n>0)&&(Col==10)){
	   	n--;
	          	        itoa(n,array1,10);
	                	LCD_WriteString(array1,0,Col);
	        	        _delay_ms(500);
	        	        passcheck[1]=n;
		                       }




	else if((q>0)&&(Col==11)){
	   	q--;
	          	        itoa(q,array1,10);
	                	LCD_WriteString(array1,0,Col);
	        	        _delay_ms(500);
	        	        passcheck[2]=q;
			                  }





	else if((s>0)&&(Col==12)){
	   	s--;
	          	        itoa(s,array1,10);
	                	LCD_WriteString(array1,0,Col);
	        	        _delay_ms(500);
	        	        passcheck[3]=s;
			                 }




                                  }





/***************************************************************************************/





}
}
