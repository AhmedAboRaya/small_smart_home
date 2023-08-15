/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : SW 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/


#include "STD_types.h"
#include "BIT_math.h"

#include "../1-MCAL/1-DIO/DIO_inteface.h"

#include "SW_interface.h"
#include "SW_config.h"
#include "SW_private.h"



void SW_voidSetConfig ( u8 SW_port , u8 SW_Pin , u8 SW_PullState )
{

	DIO_u8SetPinDirection( SW_port , SW_Pin , DIO_u8PIN_INPUT );
	if(SW_PullState == SW_PULL_UP)
	{
		DIO_u8SetPinVa1ue( SW_port , SW_Pin , DIO_u8PIN_HIGH);
	}

}
void SW_voidGetButtonState( u8 SW_port , u8 SW_Pin , u8 SW_PullState , u8 * PCopy_u8data )
{
	*PCopy_u8data = DIO_u8GetPinVaIue( SW_port , SW_Pin , PCopy_u8data ) ;

}
