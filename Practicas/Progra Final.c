#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
 
struct cuentas
{
	char nombre_cuenta[20];
	char direccion_cuenta[100];
	int numero_cuenta;
	float balance_cuenta;
};

struct cuentas cuenta[100];

int numero;

void Crear_cuenta();
void Info();
void Depositar();
void Retirar();
void Salir();
void Opciones_menu();

int main()
{
	char opc;
	numero=0;

	while(1)
	{
		printf("Bienvenido\n");
		Opciones_menu();
		printf("Por favor, ingrese alguna de las opciones para continuar\n");

		opc=getch();
		printf("%c\n",opc);
		scanf("%d",&opc);

		switch(opc)
		{
			case 1: Crear_cuenta();
			break;

			case 2: Depositar();
			break;

			case 3: Retirar();
			break;

			case 4: Info();
			break;

			case 5: return 0;

			default: system("No se encontro esa opcion");
			printf("Por favor, ingrese alguna de las opciones para continuar\n");
			break;
		}
	}

	return 0;
}

void Opciones_menu()
{
	printf("\n1. Crear una cuenta\n");
	printf("2. Depositar a una cuenta\n");
	printf("3. Retirar efectivo\n");
	printf("4. Revisar el balance \n");
	printf("5. Salir\n");
}

void Crear_cuenta()
{
	char nombre_cuenta[20];
	char direccion_cuenta[100];
	int numero_cuenta;
	float balance_cuenta=0;

	fflush(stdin);

	printf("A que nombre va a estar la cuenta:\n");
	scanf("%s",&nombre_cuenta);
	printf("Ingrese el numero de cuenta (1-100)\n");
	scanf("%d",&numero_cuenta);
	printf("Ingrese una direccion para la cuenta\n\n");
	scanf("%s",&direccion_cuenta);

	strcpy(cuenta[numero_cuenta-1].nombre_cuenta,nombre_cuenta);
	cuenta[numero_cuenta-1].numero_cuenta=numero_cuenta;
	strcpy(cuenta[numero_cuenta-1].direccion_cuenta,direccion_cuenta);
	cuenta[numero_cuenta-1].balance_cuenta=balance_cuenta;

	printf("Su cuenta se ha creado con exito!\n");
	printf("Nombre del principal de la cuenta: %s\n",cuenta[numero_cuenta-1].nombre_cuenta);
	printf("Numero de cuenta: %d\n", cuenta[numero_cuenta-1].numero_cuenta);
	printf("Direccion de la cuenta; %s\n",cuenta[numero_cuenta-1].direccion_cuenta);
	printf("El balance de la cuenta es de: %f\n\n",cuenta[numero_cuenta-1].balance_cuenta);



}

void Info()
{
	register int numero = 0;

	while(strlen(cuenta[numero].nombre_cuenta)>0)
	{
		printf("Nombre del principal de la cuenta: %s\n", cuenta[numero].nombre_cuenta);
	    printf("Numero de cuenta: %d\n", cuenta[numero].numero_cuenta);
	    printf("Direccion de la cuenta; %s\n", cuenta[numero].direccion_cuenta);
	    printf("El balance de la cuenta es de: %f\n\n", cuenta[numero].balance_cuenta);
	    numero++;
	}
}

void Depositar()
{
	auto int num_cuenta;
	float dinero;

	printf("Ingrese el numero de la cuenta a que desea agregar: \n");
	scanf("%d",&num_cuenta);
	printf("El balance de su cuenta %d es de %f \n",num_cuenta,cuenta[num_cuenta-1].balance_cuenta);
	printf("Ingrese el dinero que desea depositar: \n" );
	scanf("%f",&dinero);

	while (num_cuenta=cuenta[num_cuenta-1].numero_cuenta)
	{
		cuenta[num_cuenta-1].balance_cuenta=cuenta[num_cuenta-1].balance_cuenta+dinero;
		printf("El nuevo balance de su cuenta %d es de %f \n\n",num_cuenta, cuenta[num_cuenta-1].balance_cuenta );
		break;
	}num_cuenta++;
}

void Retirar()
{
	auto int num_cuenta;
	float dinero_retiro;

	printf("Ingrese el numero de la cuenta a que desea retirar: \n");
	scanf("%d",&num_cuenta);
	printf("El balance de su cuenta %d es de %f \n",num_cuenta,cuenta[num_cuenta-1].balance_cuenta);
	printf("Ingrese el dinero que desea retirar: \n" );
	scanf("%f",&dinero_retiro);

	while (num_cuenta=cuenta[num_cuenta-1].numero_cuenta)
	{
		cuenta[num_cuenta-1].balance_cuenta=cuenta[num_cuenta-1].balance_cuenta-dinero_retiro;
		printf("El nuevo balance de su cuenta %d es de %f \n\n",num_cuenta, cuenta[num_cuenta-1].balance_cuenta );
		break;
	}num_cuenta++;
}