#include "stdio.h"
#include"GENFUN.h"
#include"string.h"
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
/* Segundo problema*/
void main(void)
{
	printf("Testing Genfun_vCapsOn\n");
	uint8 au8BufferTest[12] = "HElLO WOrLd";
	printf("Buffer before function%s\n",au8BufferTest );
	Genfun_vCapsoff(&au8BufferTest[0],12);
	printf("Buffer after function%s\n",au8BufferTest );
}
void void Genfun_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfflist)
{
	while( u8Sizeofflist!=0)
	{
		if(*pu8Src>=ASCII_High_THRESHHOLD_CAPSON_TO_On && *pu8Srcz=ASCII_Low_THRESHHOLD_CAPSON_TO_On)
		{
			*pu8Src-=ASCII_CONVERTION_FACTOR;
		}
		else
		{
			/*Nothing to do */
		}
		pu8Src++;
		u8Sizeofflist -- ;
	}
}
/*Tercer problema */
int main()
{
	char *pu8Src= " COMO ESTA LA RAZA EL DIA DE HOY?";
	char u8Target = "A";
	char *Busqueda= NULL;
	int i= 0;
	uint8 GENFUN_u8GetOccurence(*pu8Src,u8Target);
	GENFUN_u8GetOccurence =(strstr(*pu8Src,u8Target));
	while(GENFUN_u8GetOccurence !=NULL)
	{
		i++;
		GENFUN_u8GetOccurence =strstr(Busqueda+1,u8Target);
	}
	printf("Total de coincidencias%i\n",i);
	if(Busqueda!=NULL)
	{
		printf("Se encontro el target %s\n",u8Target)
	}
	else
	{
		printf("No se encontro el target %s\n",u8Target);
	}

}
char* uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList)
{
	int i;

	else 
	{
		i=0;
		c= u8Target [0];
		while(u8Sizeofflist [i]  !=0)
		{
			if(*pu8Src[i]==c)
			{
				if(strncomp(*pu8Src[i],&u8Target, u8Sizeofflist)==0)
				{
					return &u8Target [i];
				}
			}
			i++;
		}
		return NULL;
	}

}
	
/*Cuarto problema*/

 