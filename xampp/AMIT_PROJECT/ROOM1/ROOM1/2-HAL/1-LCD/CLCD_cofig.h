/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : LCD 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
		/*****************************/
		/*    Configuration Of LCD    */ 
		/*****************************/
				
		/*      8 Bit Mode Data Port          */ 
#define CLCD_DATA_PORT       DIO_u8PORTC

//______________________________________________________

#define CLCD_D0_PIN            DIO_u8PIN0
#define CLCD_D0_PORT           DIO_u8PORTC

#define CLCD_D1_PIN            DIO_u8PIN1
#define CLCD_D1_PORT           DIO_u8PORTC

#define CLCD_D2_PIN            DIO_u8PIN2
#define CLCD_D2_PORT           DIO_u8PORTC

#define CLCD_D3_PIN            DIO_u8PIN3
#define CLCD_D3_PORT           DIO_u8PORTC

		/*   4 Bit Mode Pins Configuration   */


#define CLCD_D4_PIN            DIO_u8PIN4
#define CLCD_D4_PORT           DIO_u8PORTC

#define CLCD_D5_PIN            DIO_u8PIN5
#define CLCD_D5_PORT           DIO_u8PORTC

#define CLCD_D6_PIN            DIO_u8PIN6
#define CLCD_D6_PORT           DIO_u8PORTC

#define CLCD_D7_PIN            DIO_u8PIN7
#define CLCD_D7_PORT           DIO_u8PORTC

//______________________________________________________

		/*        CTRL PORT AND PINS        */
		
/* Macros For Rs configuration */
#define CLCD_RS_PORT           DIO_u8PORTA
#define CLCD_RS_PIN            DIO_u8PIN1

/* Macros For Rw configuration */
#define CLCD_RW_PORT           DIO_u8PORTA
#define CLCD_RW_PIN            DIO_u8PIN0

/* Macros For En configuration */
#define CLCD_EN_PORT           DIO_u8PORTA
#define CLCD_EN_PIN		       DIO_u8PIN2

//______________________________________________________

/* Options FOR LCD Mode:
1- LCD_8_BIT_MODE
2- LCD_4_BIT_MODE */

#define CLCD_MODE   		  LCD_4_BIT_MODE

#endif