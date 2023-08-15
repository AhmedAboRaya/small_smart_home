/*
 * ROOM1.c
 *
 * Created: 7/12/2023 8:58:22 PM
 * Author : Abo Raya
 */ 

	//   LIB
	#include "4-LIB/STD_TYPES.h"
	#include "4-LIB/BIT_MATH.h"
	#include "util/delay.h"


	//   MCAL
	#include "1-MCAL/1-DIO/DIO_inteface.h"
	#include "1-MCAL/2-UART/UART_interface.h"
	#include "1-MCAL/4-ADC/ADC_interface.h"
	
	
	//	 HAL
	#include "2-HAL/5-SW/SW_interface.h"
	#include "2-HAL/1-LCD/CLCD_interface.h"
	#include "2-HAL/2-LED/LED_interface.h"


int main(void)
{
	//	    DECLERATION OF VARIABLES
	u8 receive_comnd = 0 ;
	u8 value = 0 ;
	u8 temp_value =  0 ;
	u8 check_room_sw =0 ;
	
	//		CALL FUNCTION 
	UART_init();
	CLCD_voidInit();
	DIO_u8SetPinDirection( DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_OUTPUT);
	
	
	//   ADC 
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_INPUT);
	ADC_init();
	
	
	// DC MOTOR
	DIO_u8SetPinDirection(DIO_u8PORTD , DIO_u8PIN7 , DIO_u8PIN_OUTPUT);
	
	
	//     SET DIRECTION OF PIN & PULL UP
	DIO_u8SetPinDirection( DIO_u8PORTB , DIO_u8PIN0 , DIO_u8PIN_INPUT);
	DIO_u8SetPinVa1ue( DIO_u8PORTB , DIO_u8PIN0 , DIO_u8PIN_HIGH);
	
	
    /* Replace with your application code */
    while (1)
    {
		
		ADC_getDigitalValue(ADC_CHANNEL_5,&value);
		temp_value=(u32)(value*500)/(1023);
		
		//     CHECH ROOM SWITCH 
		DIO_u8GetPinVaIue( DIO_u8PORTB , DIO_u8PIN0 , &check_room_sw );
		
		if ( temp_value >= 30 )
		{
			//   motor on 
			DIO_u8SetPinVa1ue(DIO_u8PORTD , DIO_u8PIN7 , DIO_u8PIN_HIGH);
			//-----------
  			CLCD_voidGoToXY(1,0);
  			CLCD_u8SendString("Temp= ");
  			CLCD_voidWriteNumber((temp_value));
  			CLCD_u8SendString(" C");		
		}
		else
		{
			CLCD_voidClear();
			// motor off 
			DIO_u8SetPinVa1ue(DIO_u8PORTD , DIO_u8PIN7 , DIO_u8PIN_LOW);
		}
		
		
		
		//     TO TURN ON OR OFF LED
		//      RECEIVE SIGNAL FROM MASTER ROOM
		receive_comnd = UART_RxChar() ;
		
		if( GET_BIT(receive_comnd,0) )
		{
			
			if ( 0 == check_room_sw )
			{
				DIO_u8SetPinVa1ue( DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_HIGH );
				CLCD_voidGoToXY(0,0);
				CLCD_u8SendString("Led On :)");
				_delay_ms(200);
				CLCD_voidClear();
			}
			else
			{
				DIO_u8SetPinVa1ue( DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_LOW );
				CLCD_voidGoToXY(0,0);
				CLCD_u8SendString("Led Off :(");
				_delay_ms(200);
				CLCD_voidClear();
			}
		}
		else
		{
			DIO_u8SetPinVa1ue( DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PIN_LOW );
			CLCD_voidGoToXY(0,0);
			CLCD_u8SendString("Led Off :(");
			_delay_ms(200);
			CLCD_voidClear();
		}
	
    }
}

