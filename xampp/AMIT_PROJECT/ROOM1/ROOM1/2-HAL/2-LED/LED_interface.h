/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : LED 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "DIO_inteface.h"

#define LED_PORTA           DIO_u8PORTA
#define LED_PORTB           DIO_u8PORTB
#define LED_PORTC           DIO_u8PORTC
#define LED_PORTD           DIO_u8PORTD
 
 
#define LED_PIN0            DIO_u8PIN0
#define LED_PIN1            DIO_u8PIN1
#define LED_PIN2            DIO_u8PIN2
#define LED_PIN3            DIO_u8PIN3
#define LED_PIN4            DIO_u8PIN4
#define LED_PIN5            DIO_u8PIN5
#define LED_PIN6            DIO_u8PIN6
#define LED_PIN7			DIO_u8PIN7

#define SOURCE             1
#define SINK               0


void LED_voidInit ( u8 Copy_u8Port, u8 Copy_u8Pin );
void LED_voidOn ( u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Conn );
void LED_voidOff ( u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Conn );
void LED_voidToggle ( u8 Copy_u8Port, u8 Copy_u8Pin );

#endif /* LED_INTERFACE_H_ */