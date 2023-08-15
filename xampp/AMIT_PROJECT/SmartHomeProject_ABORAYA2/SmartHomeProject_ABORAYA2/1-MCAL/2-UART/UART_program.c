/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : MCAL		  *************************/
/*******************************		SWC    : UART 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/


 /* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "../4-LIB/ATMEGA_REG.h"

/* MCAL */
#include "UART_interface.h"

#include "DIO_inteface.h"

#include "UART_config.h"
 
void UART_init(void)
{
	
	// set buad rate = 9600
	UBRRL = 103;
	
	
	//configure data bits = 8,configure no parity,configure stop bits = 1,selct UART MODE = Asynchronous,writing the UCSRC
	UCSRC = 0x86;
	CLR_BIT(UCSRB,2);
	
	//Enable Tx
	SET_BIT(UCSRB,3);
	//Enable Rx
	SET_BIT(UCSRB,4);
	
	DIO_u8SetPinDirection( UART_u8PORT_RX , UART_u8PIN_RX , DIO_u8PIN_INPUT );
	DIO_u8SetPinDirection( UART_u8PORT_TX , UART_u8PIN_TX , DIO_u8PIN_OUTPUT );
	
}


void UART_TxChar(u8 Copy_u8Data)
{
	UDR = Copy_u8Data;
	while ( 0 == GET_BIT(UCSRA,5));
}


u8 UART_RxChar(void)
{

		while ( 0 == GET_BIT(UCSRA,7));
		return UDR;
	
}