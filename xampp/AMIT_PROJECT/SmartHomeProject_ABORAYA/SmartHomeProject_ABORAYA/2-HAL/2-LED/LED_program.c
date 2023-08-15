/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : LED 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/
 

/* UTILES_LIB */
  #include "STD_TYPES.h"
  #include "BIT_MATH.h"
  #include "ATMEGA_REG.h"
  
/* MCAL */
  #include "../1-MCAL/1-DIO/DIO_inteface.h"

/* HAL */
  #include "../2-HAL/2-LED/LED_interface.h"

void LED_voidInit( u8 Copy_u8Port, u8 Copy_u8Pin )
{
	DIO_u8SetPinDirection(Copy_u8Port , Copy_u8Pin , DIO_u8PIN_OUTPUT);
}


void LED_voidOn( u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Conn )
{
	if ( SOURCE == Copy_u8Conn )
	{
		DIO_u8SetPinVa1ue( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_HIGH );
	}else if( SINK == Copy_u8Conn )
	{
		DIO_u8SetPinVa1ue( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_LOW );
	}
	
}


void LED_voidOff ( u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Conn )
{
	if ( SOURCE == Copy_u8Conn )
	{
		DIO_u8SetPinVa1ue( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_LOW );
	}else if( SOURCE == Copy_u8Conn )
	{
		DIO_u8SetPinVa1ue( Copy_u8Port , Copy_u8Pin , DIO_u8PIN_HIGH );
	}

}


void LED_voidToggle( u8 Copy_u8Port, u8 Copy_u8Pin )
{
	TOG_BIT(Copy_u8Port,Copy_u8Pin);
}
