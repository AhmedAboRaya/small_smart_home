/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : HAL		  *************************/
/*******************************		SWC    : LCD 		  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define CLCD_SHIFT_LEFT         0
#define CLCD_SHIFT_RIGHT        1



u8 CLCD_u8SendChar( u8 Copy_u8Char );

u8 CLCD_u8SendCommand( u8 Copy_u8Command );

void CLCD_voidInit( void );

u8 CLCD_u8SendString( u8 const *Copy_u8String );

void CLCD_voidGoToXY( u8 Copyy_XPos , u8 Copyy_YPos );

void CLCD_voidClear(void);

void CLCD_voidShift(u8 shifttingDirection);

void CLCD_voidWriteNumber(u32 number);

void CLCD_voidWriteHalfPort(u8 Value);

#endif