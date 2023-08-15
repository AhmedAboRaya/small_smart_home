/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : SW 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

#ifndef HALL_SW_SW_INTERFACE_H_
#define HALL_SW_SW_INTERFACE_H_

// typedef struct
// {
// 
// 	u8 SW_port ;
// 	u8 SW_Pin ;
// 	u8 SW_PullState ;
// 
// }SW_Type;


#define SW_PULL_UP   1
#define SW_FLOATING  0


//     SW Pull Up Pressed
#define SW_PULLUP_PRESSED    0
#define SW_PULLUP_NOTPRESSED 1


//     SW Pull Down Pressed
#define SW_PULLDOWN_PRESSED    1
#define SW_PULLDOWN_NOTPRESSED 0


//     SW Ports
#define SW_PORTA  DIO_u8PORTA
#define SW_PORTB  DIO_u8PORTB
#define SW_PORTC  DIO_u8PORTC
#define SW_PORTD  DIO_u8PORTD


//     SW Pins
#define SW_PIN0   DIO_u8PIN0
#define SW_PIN1   DIO_u8PIN1
#define SW_PIN2   DIO_u8PIN2
#define SW_PIN3   DIO_u8PIN3
#define SW_PIN4   DIO_u8PIN4
#define SW_PIN5   DIO_u8PIN5
#define SW_PIN6   DIO_u8PIN6
#define SW_PIN7   DIO_u8PIN7


void SW_voidSetConfig ( u8 SW_port , u8 SW_Pin , u8 SW_PullState );
void SW_voidGetButtonState( u8 SW_port , u8 SW_Pin , u8 SW_PullState , u8 * PCopy_u8data );

#endif /* HALL_SW_SW_INTERFACE_H_ */
