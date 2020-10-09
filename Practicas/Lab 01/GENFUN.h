
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;

/*Prototypes*/
void Genfun_vCapsoff (uint8 *pu8Src, uint8 u8SizeOfflist);
void Genfun_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfflist);
uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList);
/*Definitions*/
#define ASCII_HIGH_THRESHHOLD_CAPSON_TO_OFF     90
#define ASCII_LOW_THRESHHOLD_CAPSON_TO_OFF      65
#define ASCII_CONVERTION_FACTOR  				32
#define ASCII_LOW_THRESHHOLD_CAPSO_TO_ON 		97
#define ASCII_HIGH_THRESHHOLD_CAPSON_TO_ON      122
#define ASCII_CONVERTION_FACTOR					32
