/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : LCD 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

#include <util/delay.h>

#include "../4-LIB/BIT_MATH.h"
#include "../4-LIB/STD_TYPES.h"

#include "ATMEGA_REG.h"
#include "../1-DIO/DIO_inteface.h"

#include "CLCD_cofig.h"
#include "CLCD_private.h"
#include "CLCD_interface.h"




void CLCD_voidInit( void )
{
	
				/*      Delay For Start    */
	_delay_ms(40);
	
	
	#if CLCD_MODE == LCD_8_BIT_MODE 
	
		// Set Pins Directions For LCD
			// CTRL PINS
		DIO_u8SetPinDirection(CLCD_RS_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_RW_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_EN_PORT,CLCD_EN_PIN,DIO_u8PIN_OUTPUT);
		
			// DATA PINS 
		DIO_u8SetPinDirection(CLCD_D0_PORT,CLCD_D0_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D1_PORT,CLCD_D1_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D2_PORT,CLCD_D2_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D3_PORT,CLCD_D3_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D4_PORT,CLCD_D4_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D5_PORT,CLCD_D5_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D6_PORT,CLCD_D6_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D7_PORT,CLCD_D7_PIN,DIO_u8PIN_OUTPUT);
	
	
		/*Function set command : 2 lines, 5* 8 Font size*/
		CLCD_u8SendCommand( 0b00111000 );
	
		/* Display on off control: display enable, disable cursor, no blink cursor */
		CLCD_u8SendCommand( 0b00001100 );
	
		/*clear LCD*/
		CLCD_u8SendCommand(1);
	#elif CLCD_MODE == LCD_4_BIT_MODE 
		_delay_ms(40);
		// Set Pins Directions For LCD
			// CTRL PINS
		DIO_u8SetPinDirection(CLCD_RS_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_RW_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_EN_PORT,CLCD_EN_PIN,DIO_u8PIN_OUTPUT);
			// DATA PINS
		DIO_u8SetPinDirection(CLCD_D4_PORT,CLCD_D4_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D5_PORT,CLCD_D5_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D6_PORT,CLCD_D6_PIN,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinDirection(CLCD_D7_PORT,CLCD_D7_PIN,DIO_u8PIN_OUTPUT);
		
		// Display on off Control (DisplayOn, Cursor on, Blink on)
		CLCD_u8SendCommand(0b00001111);
		_delay_us(45);
		
		/* Display on off control: display enable, disable cursor, no blink cursor */
		//CLCD_u8SendCommand( 0b00001100 );
		
		// Clear Display
		CLCD_u8SendCommand(0b00000001);
		_delay_ms(2);
		
		// Set Entry Mode
		CLCD_u8SendCommand(0b00000110);
	#endif
}

u8 CLCD_u8SendCommand( u8 Copy_u8Command )
{
	u8 LocalErrorState = OK ;
	
	if( DIO_u8PORTD >= CLCD_EN_PORT && DIO_u8PORTD >= CLCD_RW_PORT && DIO_u8PORTD >= CLCD_RS_PORT )
	{
		// set Rs pin = 0 (write command)
		DIO_u8SetPinVa1ue( CLCD_RS_PORT , CLCD_RS_PIN , DIO_u8PIN_LOW );

	    // set Rw pin = 0 (write)
		DIO_u8SetPinVa1ue( CLCD_RW_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW );
		
		#if CLCD_MODE == LCD_8_BIT_MODE
			DIO_u8SetPortVa1ue( CLCD_DATA_PORT , Copy_u8Command );
			
			DIO_u8SetPinVa1ue( CLCD_EN_PORT , CLCD_EN_PIN , DIO_u8PIN_HIGH );
			
			_delay_ms(1);
			
			DIO_u8SetPinVa1ue( CLCD_EN_PORT , CLCD_EN_PIN , DIO_u8PIN_LOW );
		#elif CLCD_MODE == LCD_4_BIT_MODE
			writeHalfPort(Copy_u8Command>>4);
			
			/* Enable Pulse *//* H => L */
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_HIGH);
			_delay_ms(1);								 
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_LOW);
														 
			// Write The Least 4 bits Of command on Data u8Pins
			writeHalfPort(Copy_u8Command);						 
														 				 
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_HIGH);
			
			_delay_ms(1);								 
			
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_LOW);
		#endif
	}
	else
	{
		LocalErrorState = NOK ;
	}
	return LocalErrorState ;
}

u8 CLCD_u8SendChar( u8 Copy_u8Char )
{
	u8 LocalErrorState = OK ;
	
	if( DIO_u8PORTD >= CLCD_EN_PORT && DIO_u8PORTD >= CLCD_RW_PORT && DIO_u8PORTD >= CLCD_RS_PORT )
	{
		DIO_u8SetPinVa1ue( CLCD_RS_PORT , CLCD_RS_PIN , DIO_u8PIN_HIGH );
		
		DIO_u8SetPinVa1ue( CLCD_RW_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW );
		
		#if CLCD_MODE == LCD_8_BIT_MODE
			DIO_u8SetPortVa1ue( CLCD_DATA_PORT , Copy_u8Char );
			
			DIO_u8SetPinVa1ue( CLCD_EN_PORT , CLCD_EN_PIN , DIO_u8PIN_HIGH );
			
			_delay_ms(2);
			
			DIO_u8SetPinVa1ue( CLCD_EN_PORT , CLCD_EN_PIN , DIO_u8PIN_LOW );
		#elif CLCD_MODE == LCD_8_BIT_MODE
			writeHalfPort(Copy_u8Char>>4);
			
			/* Enable Pulse *//* H => L */
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_HIGH);
			_delay_ms(1);								 
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_LOW);
														 
			// Write The Least 4 bits Of Data on Data Pinu8s
			writeHalfPort(Copy_u8Char);					 
														 			 
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_HIGH);
			
			_delay_ms(1);	
										
			DIO_u8SetPinVa1ue(LCD_EN_PORT,LCD_EN_PIN,DIO_u8PIN_LOW);
		#endif
	}
	else
	{
		LocalErrorState = NOK ;
	}
	return LocalErrorState ;
}

u8 CLCD_u8SendString( u8 const *Copy_u8String )
{
	u8 LocalErrorState = OK ;
	
	u8 LocalCounter = 0 ;
	
	while( '\0' != Copy_u8String[LocalCounter] )
	{
		CLCD_u8SendChar( Copy_u8String[LocalCounter] );
		LocalCounter++ ;
	}
	return LocalErrorState ;
}

void CLCD_voidGoToXY( u8 Copy_XPos , u8 Copy_YPos )
{
	u8 Local_u8Address ;
	
	if( 0 == Copy_XPos )
	{
		/* Location is at first line */
		Local_u8Address = Copy_YPos ;
	}
	else if( 1 == Copy_XPos )
	{
		/* Location is at second line */
		Local_u8Address = Copy_YPos + 0x40 ;
	}
	
	/* 128 represent 0b10000000 */
	CLCD_u8SendCommand(Local_u8Address + 128);
}

void CLCD_voidClear(void)
{
	// Clear Display
	CLCD_u8SendCommand(0b00000001);
	_delay_ms(2);
}

void CLCD_voidShift(u8 shifttingDirection)
{
	if (shifttingDirection == CLCD_SHIFT_LEFT)
	{
		CLCD_u8SendCommand(0b00011000);
		_delay_ms(10);
	}
	else if (shifttingDirection == CLCD_SHIFT_RIGHT)
	{
		CLCD_u8SendCommand(0b00011100);
		_delay_ms(10);
	}
}

void CLCD_voidWriteNumber(u32 number)
{
	u32 Local_reversed = 1;
	if (number == 0)
	{
		CLCD_u8SendChar('0');
	}
	else
	{
		// Reverse Number
		while (number != 0)
		{
			Local_reversed = Local_reversed*10 + (number%10);
			number /= 10;
		}
		
		do
		{
			CLCD_u8SendChar((Local_reversed%10)+'0');
			Local_reversed /= 10;
		}while (Local_reversed != 1);
	}
}


void CLCD_voidWriteHalfPort(u8 Value)
{
	if (0 == GET_BIT(Value, 0))
	{
		DIO_u8SetPinVa1ue(CLCD_D4_PORT, CLCD_D4_PIN, DIO_u8PIN_LOW);
	}
	else
	{
		DIO_u8SetPinVa1ue(CLCD_D4_PORT, CLCD_D4_PIN, DIO_u8PIN_HIGH);
	}
	
	if (0 == GET_BIT(Value, 1))
	{
		DIO_u8SetPinVa1ue(CLCD_D5_PORT, CLCD_D5_PIN, DIO_u8PIN_LOW);
	}
	else
	{
		DIO_u8SetPinVa1ue(CLCD_D5_PORT, CLCD_D5_PIN, DIO_u8PIN_HIGH);
	}
	
	if (0 == GET_BIT(Value, 2))
	{
		DIO_u8SetPinVa1ue(CLCD_D6_PORT, CLCD_D6_PIN, DIO_u8PIN_LOW);
	}												   
	else											   
	{												   
		DIO_u8SetPinVa1ue(CLCD_D6_PORT, CLCD_D6_PIN, DIO_u8PIN_HIGH);
	}												   
													   
	if (0 == GET_BIT(Value, 3))						   
	{												   
		DIO_u8SetPinVa1ue(CLCD_D7_PORT, CLCD_D7_PIN, DIO_u8PIN_LOW);
	}												   
	else											   
	{												   
		DIO_u8SetPinVa1ue(CLCD_D7_PORT, CLCD_D7_PIN, DIO_u8PIN_HIGH);
	}
}
