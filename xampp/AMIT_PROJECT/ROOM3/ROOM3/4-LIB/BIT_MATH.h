/**************************************************************************************/
/*******************************		Author : AboRaya	  *************************/
/*******************************		Layer  : LIB		  *************************/
/*******************************		SWC    : BIT_MATH 	  *************************/
/*******************************		Version: 1.00		  *************************/
/**************************************************************************************/


#ifndef SERVICES_BIT_MATH_H_
#define SERVICES_BIT_MATH_H_

#define SET_BIT(REG , BITNUM) REG |= 1<<BITNUM
#define CLR_BIT(REG , BITNUM) REG &= ~(1<<BITNUM)
#define TOG_BIT(REG , BITNUM) REG ^= 1<<BITNUM
//#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1 )
#define GET_BIT(REG,BITNUM)	 (((REG)>>(BITNUM))&1)


#endif