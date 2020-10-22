#include "stdio.h"
int main(void) 
{
  printf("Ingresa tu numero de tarjeta > ");
  char u8Numbers[16];
  gets(u8Numbers);
  printf("Numeros ingresados %s\n", u8Numbers);
  verificar(u8Numbers);
  return 0;
}

void verificar(char u8Numbers[])
{
  int u8Operacion = 0,
      u8Suma = 0;
  //Ciclo para ir sumando los numeros ya sea multiplicados x2 o con su valor original segun 
  //dice el algoritmo de Luhn
  for(int i = 0; i < 16; i++)
  {
    if(i%2 == 0)
    {
      u8Operacion = (u8Numbers[i]-'0') * 2;
      if(u8Operacion >= 10)
        u8Operacion = (u8Operacion - 10) + 1;
    } 
    else
    {
      u8Operacion = u8Numbers[i]-'0';
    }
    u8Suma = u8Suma + u8Operacion;
  }
  //Si el resultado es multiplo de 10 entonces la sumatoria es correcta
  if(u8Suma%10 == 0)
  {
    printf("Tarjeta valida %d\n", u8Suma);
  }//%d la usamos para verificar que sean correctos las sumatorias
  else 
  {
    printf("Tarjeta invalida %d\n", u8Suma);
  }
}