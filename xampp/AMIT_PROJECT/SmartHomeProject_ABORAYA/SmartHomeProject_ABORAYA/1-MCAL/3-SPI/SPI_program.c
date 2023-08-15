/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : MCAL		  *************************/
/*******************************		SWC    : SPI 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

 /* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA_REG.h"

/* MCAL */
#include "SPI_interface.h"

void SPI_initMaster(void)
{
	//select Data Order LSB transmitted first
	SET_BIT(SPCR,5);
	
	// select Master Mode
	SET_BIT(SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	
	// select CLK Rate = FCPU/16
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
	
	// enable SPI
	SET_BIT(SPCR,6);
}


void SPI_initSlave(void)
{
	//select Data Order LSB transmitted first
	SET_BIT(SPCR,5);
	
	// select Slave Mode
	CLR_BIT(SPCR,4);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);
	
	// enable SPI
	SET_BIT(SPCR,6);
}


u8 SPI_transieve(u8 TxData)
{

		SPDR = TxData;
		
		while(0 == GET_BIT(SPSR,7)); 
		return SPDR;
	
}