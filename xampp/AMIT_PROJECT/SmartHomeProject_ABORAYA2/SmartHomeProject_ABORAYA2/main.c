/*
 * SmartHomeProject_ABORAYA2.c
 *
 * Created: 7/12/2023 5:59:08 PM
 * Author : Abo Raya
 */ 

#include <util/delay.h>

//    LIB
#include "4-LIB/STD_TYPES.h"
#include "4-LIB/BIT_MATH.h"

//    MCAL
#include "1-MCAL/2-UART/UART_interface.h"
#include "TMR1_interface.h"


//	  HAL
#include "2-HAL/3-KPD/KPD_interface.h"
#include "2-HAL/1-LCD/CLCD_interface.h"
#include "2-HAL/2-LED/LED_interface.h"

//	 APP
#include "3-APP/APP_interface.h"

int main(void)
{
	
	//      CALL FUNCTIONS
	KPD_init();
	CLCD_voidInit();
	UART_init();
	LED_voidInit( LED_PORTB , LED_PIN7 );
	TMR1_init();
	

	//    initialization variables

	u8 Pressed_key = 0 ;
	u8 pass[4] = {'1','2','3','4'};
	u8  counter = 0 , Check = 1 , count_wrong = 0 , RESET_SYS = 0 ;
	
	
	
	/* Replace with your application code */
	while (1)
	{
		
		
		do{
			Pressed_key=KPD_u8GetPressedKey();
		}
		while(Pressed_key == 0xff);
		
		switch (Pressed_key)
		{
			
			case '*' : CLCD_voidClear();
					   
					   //    WHEN SYSTEM RESET
					   RESET_SYS = UART_RxChar();
					   while( GET_BIT(RESET_SYS,7) )
					   {
						   CLCD_voidClear();
						   RESET_SYS = UART_RxChar();
						   counter = 0 ;
						   Check = 1 ;
						   count_wrong = 0 ;
					   }
			 break;
			
			//__________________________________________
			
			case '#' : 
						if ( Check == 0 )
						{
							CLCD_voidClear();
							CLCD_u8SendString("Wrong Password");
							//////////
// 							CLCD_voidGoToXY(1,0);
// 							CLCD_u8SendChar(RESET_SYS);
							_delay_ms(1000);
							CLCD_voidClear();
							count_wrong++ ;
							counter = 0 ;
							Check = 1 ;
							
							//    WHEN SYSTEM RESET
							RESET_SYS = UART_RxChar();
							while( GET_BIT(RESET_SYS,7) )
							{
								CLCD_voidClear();
								RESET_SYS = UART_RxChar();
								counter = 0 ;
								Check = 1 ;
								count_wrong = 0 ;
							}
							if ( 3 == count_wrong)
							{
								
								CLCD_u8SendString("System Locked^_^");
								LED_voidOn(LED_PORTB , LED_PIN7 , SINK);
								
								//    WHEN SYSTEM RESET 
								RESET_SYS = UART_RxChar();
								while( GET_BIT(RESET_SYS,7) )
								{
									CLCD_voidClear();
									RESET_SYS = UART_RxChar();
									counter = 0 ;
									Check = 1 ;
									count_wrong = 0 ;
								}
								
							}
						}
						else if ( Check == 1 )
						{
							CLCD_voidClear();
							CLCD_u8SendString("Welcome");
							_delay_ms(1000);
							CLCD_voidClear();
							
							//  Open Door
							CLCD_u8SendString("Door Is Open");
							TMR1_setCompareMatchValueA(249);
							TMR1_start();
							_delay_ms(5000);
							CLCD_voidClear();
							
							// Close Door 
							CLCD_u8SendString("Door Is Closed");
							_delay_ms(1000);
							TMR1_setCompareMatchValueA(499);
							TMR1_start();
							//    WHEN SYSTEM RESET
							RESET_SYS = UART_RxChar();
							while( GET_BIT(RESET_SYS,7) )
							{
								CLCD_voidClear();
								RESET_SYS = UART_RxChar();
								counter = 0 ;
								Check = 1 ;
								count_wrong = 0 ;
							}
						}
						 break;
						 
						 
						 
			//___________________________________________________________
			
			
			default: 
					 if ( pass[counter] != Pressed_key ) 
					 {
						 Check =0 ;
					 }
					 CLCD_u8SendChar(Pressed_key);
					 counter++;
					 //    WHEN SYSTEM RESET
					 RESET_SYS = UART_RxChar();
					 while( GET_BIT(RESET_SYS,7) )
					 {
						 CLCD_voidClear();
						 RESET_SYS = UART_RxChar();
						 counter = 0 ;
						 Check = 1 ;
						 count_wrong = 0 ;
					 }
					 break;
		}
			
	}
	
}



