/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : MCAL		  *************************/
/*******************************		SWC    : DIO 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8PIN_OUTPUT      1 
#define DIO_u8PIN_INPUT       0 

#define DIO_u8PORT_OUTPUT     0xff
#define DIO_u8PORT_INPUT      0

#define DIO_u8PIN_HIGH        1
#define DIO_u8PIN_LOW         0

#define DIO_u8PORT_LOW        0
#define DIO_u8PORT_HIGH       0xff

#define DIO_u8PORTA           0 
#define DIO_u8PORTB           1
#define DIO_u8PORTC           2
#define DIO_u8PORTD           3

#define DIO_u8PIN0            0
#define DIO_u8PIN1            1
#define DIO_u8PIN2            2
#define DIO_u8PIN3            3
#define DIO_u8PIN4            4
#define DIO_u8PIN5            5
#define DIO_u8PIN6            6
#define DIO_u8PIN7            7 

#define OK					  0
#define NOK					  1


/* To make direction input
   To make direction output   */
u8 DIO_u8SetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) ;

/*  */
u8 DIO_u8SetPortDirection (u8 Copy_u8Port, u8 Copy_u8Direction) ;

/*  */
u8 DIO_u8SetPinVa1ue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Va1ue) ;

/*  */
u8 DIO_u8SetPortVa1ue (u8 Copy_u8Port, u8 Copy_u8Va1ue) ;

/*  */
u8 DIO_u8GetPinVaIue (u8 Copy_u8Port,u8 Copy_u8Pin, u8 * Copy_pu8Value );

u8 DIO_u8GetPinVaIuex (u8 Copy_u8Port,u8 Copy_u8Pin);

#endif
