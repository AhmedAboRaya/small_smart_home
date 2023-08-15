/*
 * TMR1_program.c
 *
 *  Created on: Feb 4, 2023
 *      Author: AMIT
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA_REG.h"

/* MCAL */
#include "TMR1_interface.h"
#include "DIO_inteface.h"


void TMR1_init(void)
{
	// Select Mode = Fast PWM Mode(14)
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	// Select Non Inverting Mode
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	
	//Set OC1A pin as O/P pin
	SET_BIT(DIO_DDRD_REG,5); 
	
	// ICR1 >> period time = 20ms >> freq. = 50HZ
	ICR1_u16 = 4999;
}


void TMR1_start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}


void TMR1_setCompareMatchValueA(u16 value)
{
	// Init Timer With Compare Value (Duty Cycle)
	OCR1A_u16 = value;
}
