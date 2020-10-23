#include <stdio.h>
#include <string.h>

int main(void)
{
    long NumeroDeTarjeta;

    do
    {
        printf("Please input CC number: \n");
        scanf("%ld", &NumeroDeTarjeta);
    }
    while (NumeroDeTarjeta <= 0);

    long NumeroValido = NumeroDeTarjeta;
    int Sumatoria = 0;
    int count = 0;
    long divisor = 10;
    char result[11];

    while (NumeroValido > 0)
    {
        int UltimoNumeroDeSuTarjeta = NumeroValido % 10;
        Sumatoria = Sumatoria + UltimoNumeroDeSuTarjeta;
        NumeroValido = NumeroValido / 100;
    }

    NumeroValido = NumeroDeTarjeta / 10;
    while (NumeroValido > 0)
    {
        int UltimoNumeroDeSuTarjeta = NumeroValido % 10;
        int timesTwo = UltimoNumeroDeSuTarjeta * 2;
        Sumatoria = Sumatoria + (timesTwo % 10) + (timesTwo / 10);
        NumeroValido = NumeroValido / 100;
    }

    // length of the number / digit count
    NumeroValido = NumeroDeTarjeta;
    while (NumeroValido != 0)
    {
        NumeroValido = NumeroValido / 10;
        count++;
    }

    // divisor
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int PrimerDigitoDeTuTarjeta = NumeroDeTarjeta / divisor;
    int PrimerosDosDigitosDeTuTarjeta = NumeroDeTarjeta / (divisor / 10);

    // final checks
    if (Sumatoria % 10 == 0)
    {
        if (PrimerDigitoDeTuTarjeta == 4 && (count == 13 || count == 16))
        {
            strcpy(result, "VISA");
        }
        else if ((PrimerosDosDigitosDeTuTarjeta == 34 || PrimerosDosDigitosDeTuTarjeta == 37) && count == 15)
        {
            strcpy(result, "AMEX");
        }
        else if ((50 < PrimerosDosDigitosDeTuTarjeta && PrimerosDosDigitosDeTuTarjeta < 56) && count == 16)
        {
            strcpy(result, "MASTERCARD");
        }
        else 
        {
            strcpy(result, "Error");
        }
    }
    else
    {
        strcpy(result, "Error");
    }

    printf("%s\n", result);
}