/*
 * ADC_program.c
 *
 *  Created on: Jan 21, 2023
 *      Author: AMIT
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA_REG.h"

/* MCAL */
#include "ADC_interface.h"


void ADC_init(void)
{
	// Select Vref = AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	// Select Right Adjustment
	CLR_BIT(ADMUX,5);
	
	// Single Conversation Mode
	CLR_BIT(ADCSRA,5);
	
	// Prescaler 128 For 16MHZ (125 KHZ)
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	// ADC Enable
	SET_BIT(ADCSRA,7);
}


void ADC_getDigitalValue(u8 channelNum,u16* digitalValue)
{
	if((channelNum<32) && (digitalValue != 0))
	{
	    //Clear ADMUX Channel Bits
		ADMUX &= 0b11100000;

		// Select Channel Number
		ADMUX |= channelNum;
	
	    // Start Conversition
		SET_BIT(ADCSRA,6);
		
		// Wait For The Flag Of ADC
		while(0 == GET_BIT(ADCSRA,4));
		
		// Clear Flag
		SET_BIT(ADCSRA,4);
		
		// Read Digital Value
		*digitalValue = ADC_u16;
	}
}