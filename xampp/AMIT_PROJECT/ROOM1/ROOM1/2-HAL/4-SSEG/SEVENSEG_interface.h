/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : SSEG 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/


#ifndef HALL_SEVEN_SEG_SEVENSEG_INTERFACE_H_
#define HALL_SEVEN_SEG_SEVENSEG_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_Types.h"

#include "../1-MCAL/1-DIO/DIO_inteface.h"
#include "SEVENSEG_config.h"


//     Structure Of Seven Segment
typedef struct {

	u8 SEVENSEG_DataPort ;
	u8 SEVENSEG_Type;

#if SEVENSEG_ENABLE_SELECTION == SEVENSEG_PIN

	u8 SEVENSEG_EnablePort;
	u8 SEVENSEG_EnablePin;

#endif

}SEVENSEG_Type;


//      Set Configration Of Seven Segment
void SEVENSEG_voidSetConfig(SEVENSEG_Type Copy_strSegConfig);


//      Send Number To Seven Segment
void SEVENSEG_voidSendNumber(SEVENSEG_Type Copy_strSegConfig , u8 Copy_u8Number);


//      Run Seven Segment
void SEVENSEG_voidEnable(SEVENSEG_Type Copy_strSegConfig);


//      Stop Seven Segment
void SEVENSEG_voidDisable(SEVENSEG_Type Copy_strSegConfig);


//       Cathode And Anode Of Seven Segment
#define CATHODE 0
#define ANODE   1


//      Port Of Seven Segment
#define SEVENSEG_PORTA      DIO_PORTA
#define SEVENSEG_PORTB      DIO_PORTB
#define SEVENSEG_PORTC	    DIO_PORTC
#define SEVENSEG_PORTD      DIO_PORTD




//      Pin Of Seven Segment
#define SEVENSEG_PIN0       DIO_PIN0
#define SEVENSEG_PIN1       DIO_PIN1
#define SEVENSEG_PIN2       DIO_PIN2
#define SEVENSEG_PIN3       DIO_PIN3
#define SEVENSEG_PIN4       DIO_PIN4
#define SEVENSEG_PIN5       DIO_PIN5
#define SEVENSEG_PIN6       DIO_PIN6
#define SEVENSEG_PIN7       DIO_PIN7



#endif /* HALL_SEVEN_SEG_SEVENSEG_INTERFACE_H_ */
