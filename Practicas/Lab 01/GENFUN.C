#include "stdio.h"
#include"GENFUN.h"
void main( void  )
{
	printf("Testing  Genfun_vCapsoff\n");
	uint8 au8BufferTest[12] = "HElLO WOrLd";
	printf("Buffer before function%s\n",au8BufferTest );
	Genfun_vCapsoff(&au8BufferTest[0],12);
	printf("Buffer after function%s\n",au8BufferTest );
}
void Genfun_vCapsoff (uint8 *pu8Src, uint8 u8SizeOfflist)
{
	while( u8Sizeofflist !=0 )
	{
		if(*pu8Src>=ASCII_LOW_THRESHHOLD_CAPSON_TO_OFF && *pu8Src<=ASCII_HIGH_THRESHHOLD_CAPSON_TO_OFF)
		{
			*pu8Src+=ASCII_CONVERTION_FACTOR;
		}
		else
		{
			/*Nothing to do */
		}
		pu8Src++;
	    u8Sizeofflist --;
	}
}