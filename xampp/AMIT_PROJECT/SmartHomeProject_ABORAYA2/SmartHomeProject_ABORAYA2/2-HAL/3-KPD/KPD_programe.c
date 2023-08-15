/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : KPD 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../4-LIB/ATMEGA_REG.h"

/* MCAL */
#include "../1-MCAL/1-DIO/DIO_inteface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"


void KPD_init(void)
{
	/*KPD PINS*/
	//ROWS C0-->C3 INPUT PULLED_UP
	//COLOUMNS C4--->C7  OUTPUT HIGH
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_C0_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_C1_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_C2_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_C3_PIN,DIO_u8PIN_OUTPUT);
	
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_R0_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_R1_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_R2_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KPD_u8_PORT,KPD_u8_R3_PIN,DIO_u8PIN_INPUT);
	DIO_u8SetPortVa1ue   (KPD_u8_PORT,DIO_u8PORT_HIGH);
}


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState,Local_u8PressedKey=KPD_u8_NO_PRESSED_KEY_VAL;
	
	u8 Local_u8ColumnArr[KPD_u8_COL_NUM]={KPD_u8_C0_PIN,KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN};
	
	u8 Local_u8RowArr[KPD_u8_ROW_NUM]={KPD_u8_R0_PIN,KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN};
	
	u8 Local_u8KPDArr[KPD_u8_ROW_NUM][KPD_u8_COL_NUM]=KPD_u8_BUTTON_VAL;
	
	for( Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx < KPD_u8_COL_NUM ; Local_u8ColumnIdx++ )
	{
		/*1-Activate the current column*/
		//initially column pins output high
		//initially row pins input pulled up
		//activation signal low
		DIO_u8SetPinVa1ue(KPD_u8_PORT,Local_u8ColumnArr[Local_u8ColumnIdx],DIO_u8PIN_LOW);
		
		
		for( Local_u8RowIdx = 0 ; Local_u8RowIdx < KPD_u8_ROW_NUM ; Local_u8RowIdx++ )
		{
			/*2-Read current rows*/
			DIO_u8GetPinVaIue(KPD_u8_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);
			
			/*3-Check if a button is pressed*/
			/*pull up when pressed button is active low*/
			if(Local_u8PinState == DIO_u8PIN_LOW)
			{
				Local_u8PressedKey= Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
				
				/*5-wait until the key is released (polling or busy waiting)*/
				while(Local_u8PinState == DIO_u8PIN_LOW)
				{
					DIO_u8GetPinVaIue(KPD_u8_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);
				}
				
				return Local_u8PressedKey;
			}
			
			
		}
		/*4-deactivate current column with high, if row not low*/
		DIO_u8SetPinVa1ue(KPD_u8_PORT,Local_u8ColumnArr[Local_u8ColumnIdx],DIO_u8PIN_HIGH);
		
	}
	
	return Local_u8PressedKey;
}