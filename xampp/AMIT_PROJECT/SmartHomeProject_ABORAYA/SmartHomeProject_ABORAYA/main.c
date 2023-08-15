/*
 * SmartHomeProject_ABORAYA.c
 *
 * Created: 7/11/2023 10:16:49 PM
 * Author : Abo Raya
 */ 

	//   LIB
#include "4-LIB/STD_TYPES.h"
#include "4-LIB/BIT_MATH.h"

	//   MCAL 
#include "1-MCAL/1-DIO/DIO_inteface.h"
#include "1-MCAL/2-UART/UART_interface.h"
	
	
	//	 HAL
#include "2-HAL/5-SW/SW_interface.h"
	
	


int main(void)
{
	 //     DECLERATION OF VARIABLES
	u8 sw1=0 , sw2=0 , sw3=.0 , MSTR_SW = 0 , Command  ;
	
	
	//     CALL FUNCTIONS   
	UART_init();
	
	//     SET DIRECTION OF PINS & PULL UP
	DIO_u8SetPinDirection( DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection( DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection( DIO_u8PORTA , DIO_u8PIN2 , DIO_u8PIN_INPUT);
	
	// 	 DIRECTION OF MASTER SWITCH
 	DIO_u8SetPinDirection( DIO_u8PORTB , DIO_u8PIN7 , DIO_u8PIN_INPUT);

	//   PULL UP 
	DIO_u8SetPinVa1ue( DIO_u8PORTA , DIO_u8PIN0 , DIO_u8PIN_HIGH);
	DIO_u8SetPinVa1ue( DIO_u8PORTA , DIO_u8PIN1 , DIO_u8PIN_HIGH);
	DIO_u8SetPinVa1ue( DIO_u8PORTA , DIO_u8PIN2 , DIO_u8PIN_HIGH);
	DIO_u8SetPinVa1ue( DIO_u8PORTB , DIO_u8PIN7 , DIO_u8PIN_HIGH);
	
	
    /* Replace with your application code */
    while (1) 
    {
  		Command = 0 ;
  		//       GET PINS 
  		DIO_u8GetPinVaIue( DIO_u8PORTA , DIO_u8PIN0 , &sw1);
  		DIO_u8GetPinVaIue( DIO_u8PORTA , DIO_u8PIN1 , &sw2);
  		DIO_u8GetPinVaIue( DIO_u8PORTA , DIO_u8PIN2 , &sw3);
		DIO_u8GetPinVaIue( DIO_u8PORTB , DIO_u8PIN7 , &MSTR_SW);
		 
    		
    		//       CHANGE COMMAND TO TURN ON OR OFF LED OF ROOM 1
    		if ( 0 == sw1 )
    		{
  			  // pressed key
    			SET_BIT( Command , 0 );
    		}else
    		{
    			CLR_BIT( Command , 0 );
    		}
    		
    		//       CHANGE COMMAND TO TURN ON OR OFF LED OF ROOM 2
    		if ( 0 == sw2 )
    		{
  			  // pressed key
    			SET_BIT( Command , 1 );
    		}else
    		{
    			CLR_BIT( Command , 1 );
    		}
    		
    		//       CHANGE COMMAND TO TURN ON OR OFF LED OF ROOM 3
    		if ( 0 == sw3 )
    		{
  			  // pressed key
    			SET_BIT( Command , 2 );
    		}else
    		{
    			CLR_BIT( Command , 2 );
    		}
			
			
			if ( 0 == MSTR_SW )
			{
				// pressed key
				SET_BIT( Command , 7 );
			}else
			{
				CLR_BIT( Command , 7 );
			}
  		
  		UART_TxChar(Command);
     }
}

