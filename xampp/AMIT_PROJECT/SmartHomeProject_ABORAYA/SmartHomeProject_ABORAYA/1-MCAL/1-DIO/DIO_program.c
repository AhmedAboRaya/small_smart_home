/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : MCAL		  *************************/
/*******************************		SWC    : DIO 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

#include "../4-LIB/BIT_MATH.h"
#include "../4-LIB/STD_TYPES.h"



#include "DIO_config.h"
#include "DIO_inteface.h"
#include "DIO_private.h"
#include "ATMEGA_REG.h"


u8 DIO_u8SetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = OK ;
	
	if( DIO_u8PORTD >= Copy_u8Port )
	{
		if( DIO_u8PIN7 >= Copy_u8Pin )
		{
			if( DIO_u8PIN_INPUT == Copy_u8Direction )
			{
				switch(Copy_u8Port)
				{
					case DIO_u8PORTA : CLR_BIT( DIO_DDRA_REG , Copy_u8Pin ) ; break;
					case DIO_u8PORTB : CLR_BIT( DIO_DDRB_REG , Copy_u8Pin ) ; break;
					case DIO_u8PORTC : CLR_BIT( DIO_DDRC_REG , Copy_u8Pin ) ; break;
					case DIO_u8PORTD : CLR_BIT( DIO_DDRD_REG , Copy_u8Pin ) ; break;
					default: Local_u8ErrorState = NOK ; break;
				}
			}
			else if ( DIO_u8PIN_OUTPUT == Copy_u8Direction )
			{
				switch(Copy_u8Port)
				{
					case DIO_u8PORTA : SET_BIT( DIO_DDRA_REG , Copy_u8Pin ) ; break;
					case DIO_u8PORTB : SET_BIT( DIO_DDRB_REG , Copy_u8Pin ) ; break;
					case DIO_u8PORTC : SET_BIT( DIO_DDRC_REG , Copy_u8Pin ) ; break;
					case DIO_u8PORTD : SET_BIT( DIO_DDRD_REG , Copy_u8Pin ) ; break;
					default: Local_u8ErrorState = NOK ; break;
				}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState ;
}

u8 DIO_u8SetPortDirection (u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8ErrorState = OK ;
	
	if( DIO_u8PORTD >= Copy_u8Port )
	{
		switch ( Copy_u8Port )
		{
			case DIO_u8PORTA : DIO_DDRA_REG = Copy_u8Direction ; break;
			case DIO_u8PORTB : DIO_DDRB_REG = Copy_u8Direction ; break;
			case DIO_u8PORTC : DIO_DDRC_REG = Copy_u8Direction ; break;
			case DIO_u8PORTD : DIO_DDRD_REG = Copy_u8Direction ; break;
			default: Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState ;
}

u8 DIO_u8SetPinVa1ue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Va1ue)
{
	u8 Local_u8ErrorState = OK ;
	
	if( DIO_u8PORTD >= Copy_u8Port )
	{
		if( DIO_u8PIN7 >= Copy_u8Pin )
		{
			if ( DIO_u8PIN_HIGH == Copy_u8Va1ue )
			{
				switch ( Copy_u8Port )
				{
					case DIO_u8PORTA : SET_BIT( DIO_PORTA_REG , Copy_u8Pin) ; break;
					case DIO_u8PORTB : SET_BIT( DIO_PORTB_REG , Copy_u8Pin) ; break;
					case DIO_u8PORTC : SET_BIT( DIO_PORTC_REG , Copy_u8Pin) ; break;
					case DIO_u8PORTD : SET_BIT( DIO_PORTD_REG , Copy_u8Pin) ; break;
					default: Local_u8ErrorState = NOK ; break;
				}
			}
			else if ( DIO_u8PIN_LOW == Copy_u8Va1ue )
			{
				switch ( Copy_u8Port )
				{
					case DIO_u8PORTA : CLR_BIT( DIO_PORTA_REG , Copy_u8Pin) ; break;
					case DIO_u8PORTB : CLR_BIT( DIO_PORTB_REG , Copy_u8Pin) ; break;
					case DIO_u8PORTC : CLR_BIT( DIO_PORTC_REG , Copy_u8Pin) ; break;
					case DIO_u8PORTD : CLR_BIT( DIO_PORTD_REG , Copy_u8Pin) ; break;
					default: Local_u8ErrorState = NOK ; break;
				}
			}
			else
			{
				Local_u8ErrorState = NOK ;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState ;
}

u8 DIO_u8SetPortVa1ue (u8 Copy_u8Port, u8 Copy_u8Va1ue) 
{
	u8 Local_u8ErrorState = OK ;
	
	if ( DIO_u8PORTD >= Copy_u8Port )
	{
		switch ( Copy_u8Port )
		{
			case DIO_u8PORTA : DIO_PORTA_REG = Copy_u8Va1ue ; break;
			case DIO_u8PORTB : DIO_PORTB_REG = Copy_u8Va1ue ; break;
			case DIO_u8PORTC : DIO_PORTC_REG = Copy_u8Va1ue ; break;
			case DIO_u8PORTD : DIO_PORTD_REG = Copy_u8Va1ue ; break;
			default: Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState ;
}

u8 DIO_u8GetPinVaIue (u8 Copy_u8Port,u8 Copy_u8Pin, u8 *Copy_pu8Value )
{
	u8 Local_u8ErrorState = OK ;
	
	if( DIO_u8PORTD >= Copy_u8Port )
	{
		if( DIO_u8PIN7 >= Copy_u8Pin )
		{
			switch ( Copy_u8Port )
			{
				case DIO_u8PORTA : *(Copy_pu8Value) = GET_BIT( DIO_PINA_REG , Copy_u8Pin ); break;
				case DIO_u8PORTB : *(Copy_pu8Value) = GET_BIT( DIO_PINB_REG , Copy_u8Pin ); break;
				case DIO_u8PORTC : *(Copy_pu8Value) = GET_BIT( DIO_PINC_REG , Copy_u8Pin ); break;
				//case DIO_u8PORTD : *(Copy_pu8Value) = GET_BIT( DIO_PIND_REG , Copy_u8Pin ); break;
				default: Local_u8ErrorState = NOK ; break;
			}
		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState ;
}
