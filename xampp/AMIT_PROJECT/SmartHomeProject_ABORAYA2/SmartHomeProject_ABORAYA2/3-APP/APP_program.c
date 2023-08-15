/*
 * APP_program.c
 *
 * Created: 7/12/2023 6:48:32 PM
 *  Author: Abo Raya
 */ 
 
 //    LIB
 #include "STD_TYPES.h"
 
 
 #include "APP_config.h"

u8 APP_u8CheckPass( u8 *Copy_u8Pass )
{
	u8 Local_Real_Pass[4] = {'1','2','3','4'} ;
	u8 Local_Flag = 1 ;
	
	
	u8 Count = 0 ;
	for ( Count = 0 ; Count < 4 ; Count++ )
	{
		if ( Local_Real_Pass[Count] != Copy_u8Pass+Count  )
		{
			Local_Flag = 0 ; 
			break;
		}
	}
	
	
	return Local_Flag ;
}