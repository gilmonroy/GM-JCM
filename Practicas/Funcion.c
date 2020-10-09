#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned short uint16;

void vCalcSum (uint8 u8FirstN, uint8 u8SecondN)

void main (void)
{
	uint8 u8Result = 0;
	u8Result = vCalcSum(10,10);
	printd("This is the result: %d\n", u8Result); 
}

void vCalcSum (uint8 u8FirstN, uint8 u8SecondN)
{
	return (u8FirstN + u8SecondN);
}