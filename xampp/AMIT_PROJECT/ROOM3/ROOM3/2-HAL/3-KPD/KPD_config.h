/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : KPD 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


/* MACROS FOR KPD COLUMNS PORTS & PINS CONFIGURATION */

#define KPD_u8_PORT         DIO_u8PORTB
#define KPD_u8_R0_PIN       DIO_u8PIN0
#define KPD_u8_R1_PIN       DIO_u8PIN1
#define KPD_u8_R2_PIN       DIO_u8PIN2
#define KPD_u8_R3_PIN       DIO_u8PIN3
#define KPD_u8_C0_PIN       DIO_u8PIN4
#define KPD_u8_C1_PIN       DIO_u8PIN5
#define KPD_u8_C2_PIN       DIO_u8PIN6
#define KPD_u8_C3_PIN       DIO_u8PIN7


// Key Bad Data
#define KPD_u8_BUTTON_VAL  {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}}

// Number Of Rows And Columns
#define KPD_u8_ROW_NUM					 4
#define KPD_u8_COL_NUM					 3


// Make Port High If Not Pressed
#define KPD_u8_NO_PRESSED_KEY_VAL        0xff



#endif /* KPD_CONFIG_H_ */
