#include "Types.h"

typedef enum
{
	enMenu = 0;
	enDispensorOn,
	enDelay
	enDispensorOff,
	enMaxStates,
}SM_States;

typedef enum 
{

	enOpen = 0,
	enClose,	
}SM_BombDispensorStatus;

void SM_BombaDeInfusionStateMachine ( void);
