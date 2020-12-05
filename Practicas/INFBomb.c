#include "Sm.h"

static void SM_BombaDeInfusionStateMachine (void)
{
	static SM_States enCurrentState = enMenu;
	static SM_BombDispensorStatus enDispensorOff = enClose;

	uint32 u32BombRequest = 0;

	switch (enCurrentState)
	{

		case enMenu:
		{
			if ( enBombState == enDispensorOff;
			{
				printf("press 0 to Turn On the Dispensor, 1 to Turn On the Medicine Flow \n ");
				sacanf("%d", &u32BombRequest);
				if( u32BombRequest == 0 )
				{
					enBombState = en
				}
				else
				{
					printf("Turn On The Medicine Flow \n")
					sacanf(%d", &u8MedicineML");
					u8MedicineML = u8MedicineML:
					enCurrentState = enDispensorON
				}

			}
		}
		case enDispensorOn
		{
			printf("Start The Medicine Flow\n ");
			enCurrentState = enDelay;
			break;

		}
		case enDelay:
		{
			if(u8MedicineML ! = 0)
			{
				printf("Medicine Left: %d\n", u8MedicineML);
				u8MedicineML--;
			}
			else
			{
				enCurrentState = enDispensorOff;
			}
		}
		case enDispensorOff:
		{
			printf("Stop Medicine Flow \n");
			enCurrentState = enMenu;
			break;
		}

		printf("Ends\n");

	}

}
