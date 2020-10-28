
#include "stdio.h"
#include "Structs.h"

/* Descripcion 

->Crear un programa que simule un estacionamiento con 5 diferentes secciones 0, 1, 2, 3 o 4. Cada seccion tendra un cupo maximo de carros que sera definido por Defines diferentes. 
->Se tiene que usar un arreglo de estructuras para manejar los estacionamientos, la estructura es la de abajo.
->El programa correra en un ciclo infinito y habra funciones aleatorias que metan y saquen carros de las diferentes secciones.
->El programa debe tener una logica que atienda las peticiones siguientes con funciones:
	*Obtener el numero de espacios disponibles de una seccion (F1)
	*Obtener el numero de espacios no disponibles de una seccion (F2)
	*Obtener ganancias de sección(F3)
	*Registrar vehiculo ingresado(F4)
	*Remover vehiculo(F5)
	*Registrar pago de vehiculo ingresado(F6)
*/

/* Fucniones */
/*
->(F1) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios disponibles de esa seccion
->(F2) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de espacios no disponibles de esa seccion
->(F3) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento (0, 1, 2, 3 o 4) e imprima la cantidad de dinero acumulada en esa sección
->(F4) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita ingresar un vehiculo a esa seccion
->(F5) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y permita retirar un vehiculo de la cuenta de la seccion
->(F6) Una funcion con 1 parametro, la cual reciba la seccion de estacionamiento y registre el pago por haber ingresado el vehiculo
*/

tstParkingInfo astMyParks[enMaxSectors] = INIT_PARKING_SLOTS;						/*Struct to Use*/

void main ( void )
{
	uint8 u8InputAction = 0;
	tenParkingSectors enSector; 
	uint8 u8ConfirmationFromAction = 0;
	while(1)
	{
		fflush(stdin);
		printf("Press 1 to -> Read Available Slots\n");
		printf("Press 2 to -> Read Unavailable Slots\n");
		printf("Press 3 to -> Read Earned Money\n");
		printf("Press 4 to -> Enter a Car to a Section\n");
		printf("Press 5 to -> Remove a Car from a Section\n");
		printf("Enter selection: ");
		scanf("%d", &u8InputAction);
		printf("Action Selected %d\n", u8InputAction );

		printf("Enter Sector from 0 to 4: ");
		scanf("%d", &enSector);
		printf("Sector Selected %d\n", enSector );

		if( enSector < enMaxSectors )
		{
			if( u8InputAction == 1 )
			{
              scanf( INIT_PARKING_SLOTS);
              while( INIT_PARKING_SLOTS !0)
              {
                  printf("Hay lugares disponibles: %d\n",enSector < enMaxSectors);
              }
              if ( INIT_PARKING_SLOTS > 0)
              {
                 /*Nothing to do*/
              }
			}
			else if( u8InputAction == 2 )
			{
                 scanf( INIT_PARKING_SLOTS);
                 while ( INIT_PARKING_SLOTS =0)
                {
                    printf("No hay lugares disponibles  %d\n",enSector > enMaxSectors);
                }
                if( INIT_PARKING_SLOTS < 0)
                {
                    /*Nothing to do*/
                }
			}
			else if( u8InputAction == 3 )
			{
			  scanf( "%d"&u32MoneyEarn );
			   
			  printf("El dinero recaudado es: %d\n ", ShowEarnedMoney);
			}
			
			else if( u8InputAction == 4 )
			{
			    scanf(" %d"&tenParkingSectors);
			    while( enCurrentSector < tenParkingSectors)
                  {
                      INIT_PARKING_SLOTS ++1;
                      pritf("El Auto ha sido añadido \n ");
                  }
			}
			else if ( u8InputAction == 5 )
			{
                scanf(" %d"&tenParkingSectors);
			    while( enCurrentSector > tenParkingSectors)
                  {
                      INIT_PARKING_SLOTS ++1;
                      pritf("El Auto ha sido removido \n ");
			}
			else
			{
                /*Nothing to do*/
			}
			printf("\n\n");
		}
		else
		{
			/*Not a valid sector*/
		}

	}
}

/*F1*/
void ShowAvailableSlots ( tenParkingSectors enCurrentSector )
{
	scanf(tenParkingSectors);
	if(u8InputAction ==0)
	{
		printf("La seccion que selecciono es la 0  %s\n", {SECTOR0_SLOTS,SECTOR0_SLOTS,0,0});
	}
	if(u8InputAction ==1)
	{
		printf("La seccion que selecciono es la 1  %s\n", {SECTOR1_SLOTS,SECTOR1_SLOTS,0,0});
	}
	if( u8InputAction == 2)
	{

		printf("La seccion que selecciono es la 2  %s\n", {SECTOR1_SLOTS,SECTOR2_SLOTS,0,0});
	}
	if(u8InputAction == 3)
	{
		printf("La seccion que selecciono es la 3  %s\n", {SECTOR1_SLOTS,SECTOR3_SLOTS,0,0});
	}
	if(u8InputAction == 4)
	{
		printf("La seccion que selecciono es la 4  %s\n", {SECTOR1_SLOTS,SECTOR4_SLOTS,0,0});
	} 
} 

/*F2*/
void ShowNotAvailableSlots ( tenParkingSectors enCurrentSector )
{
	while( SECTOR0_SLOTS==0)
	{
		printf("No hay lugares disponibles en el sector 0. %s\n" &SECTOR0_SLOTS);
	}
	if(SECTOR1_SLOTS==0)
	{
		printf("No hay lugares disponibles en el sector 1. %s\n" &SECTOR1_SLOTS);
	}
	  if(SECTOR2_SLOTS == 0)
	{
		printf("No hay lugares disponibles en el sector 2. %s\n" &SECTOR2_SLOTS);
	}
	if (SECTOR3_SLOTS ==0)
	{
		printf("No hay lugares disponibles en el sector 3. %s\n" &SECTOR3_SLOTS);
	}
	if (SECTOR4_SLOTS == 0 )
	{
		printf("No hay ligares disponibles en el sector 4. %s\n", &SECTOR4_SLOTS );
	}
}

/*F3*/
void ShowEarnedMoney ( tenParkingSectors enCurrentSector )
{

}
/*F4*/
uint8 u8AddCarToSector( tenParkingSectors enCurrentSector )
{

}
/*F5*/
uint8 u8RemoveCarFromSector( tenParkingSectors enCurrentSector )
{

}
/*F6*/
void u8ImportPaymentOfSlot( tenParkingSectors enCurrentSector )
{

}
