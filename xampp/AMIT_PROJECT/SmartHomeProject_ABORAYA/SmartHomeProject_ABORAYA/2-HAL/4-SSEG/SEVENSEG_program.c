/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : SSEG 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/


#include "BIT_MATH.h"
#include "STD_Types.h"


#include "../1-MCAL/1-DIO/DIO_inteface.h"


#include "SEVENSEG_interface.h"
#include "SEVENSEG_config.h"
#include "SEVENSEG_private.h"







void SEVENSEG_voidSetConfig(SEVENSEG_Type Copy_strSegConfig)
{

	DIO_voidSetPortDirection( Copy_strSegConfig.SEVENSEG_DataPort , 255 );
#if SEVENSEG_ENABLE_SELECTION == SEVENSEG_PIN

		DIO_voidSetPinValue( Copy_strSegConfig.SEVENSEG_EnablePort , Copy_strSegConfig.SEVENSEG_EnablePin , DIO_OUTPUT );

#endif

}


void SEVENSEG_voidSendNumber(SEVENSEG_Type Copy_strSegConfig , u8 Copy_u8Number)
{

	u8 Seven_SegValues[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

	if( Copy_strSegConfig.SEVENSEG_Type == CATHODE )
	{
		DIO_voidSetPortValue( Copy_strSegConfig.SEVENSEG_DataPort , Seven_SegValues[Copy_u8Number] );
	}else if( Copy_strSegConfig.SEVENSEG_Type == ANODE )
	{
		DIO_voidSetPortValue( Copy_strSegConfig.SEVENSEG_DataPort , ~Seven_SegValues[Copy_u8Number] );
	}
}





#if SEVENSEG_ENABLE_SELECTION == SEVENSEG_PIN


//      Enable Seven Segment

void SEVENSEG_voidEnable(SEVENSEG_Type Copy_strSegConfig)
{

	if( Copy_strSegConfig.SEVENSEG_Type == CATHODE )
	{
		DIO_voidSetPinValue( Copy_strSegConfig.SEVENSEG_EnablePort , Copy_strSegConfig.SEVENSEG_EnablePin , DIO_LOW );
	}else if( Copy_strSegConfig.SEVENSEG_Type == ANODE )
	{
		DIO_voidSetPinValue( Copy_strSegConfig.SEVENSEG_EnablePort , Copy_strSegConfig.SEVENSEG_EnablePin , DIO_HIGH );
	}

}


//      Disable Seven Segment

void SEVENSEG_voidDisable(SEVENSEG_Type Copy_strSegConfig)
{

	if( Copy_strSegConfig.SEVENSEG_Type == CATHODE )
	{
		DIO_voidSetPinValue( Copy_strSegConfig.SEVENSEG_EnablePort , Copy_strSegConfig.SEVENSEG_EnablePin , DIO_HIGH );
	}else if( Copy_strSegConfig.SEVENSEG_Type == ANODE )
	{
		DIO_voidSetPinValue( Copy_strSegConfig.SEVENSEG_EnablePort , Copy_strSegConfig.SEVENSEG_EnablePin , DIO_LOW );
	}

}

#endif


