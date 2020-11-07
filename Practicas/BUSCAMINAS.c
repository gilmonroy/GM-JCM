#include <stdio.h>
 #include <assert.h> 
#include <ctype.h>    
#include <stdlib.h>  
#include <unistd.h>  
#include "buscaminas.h"

int MIN=20;

int obtenerMinasCercanas(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  int conteo = 0, filaInicio, filaFin, u16columnaInicio, u16columnaFin;
  if (fila <= 0) {
    filaInicio = 0;
  } else {
    filaInicio = fila - 1;
  }

  if (fila + 1 >= FILAS) {
    filaFin = FILAS - 1;
  } else {
    filaFin = fila + 1;
  }

  if (columna <= 0) {
    u16columnaInicio = 0;
  } else {
    u16columnaInicio = columna - 1;
  }
  if (columna + 1 >= COLUMNAS) {
    u16columnaFin = COLUMNAS - 1;
  } else {
    u16columnaFin = columna + 1;
  }
  int m;
  for (m = filaInicio; m <= filaFin; m++) {
    int l;
    for (l = u16columnaInicio; l <= u16columnaFin; l++) {
      if (tablero[m][l] == MINA) {
        conteo++;
      }
    }
  }
  return conteo;
}

// Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y
// maximo

int aleatorioEnRango(int minimo, int maximo) {
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
// Rellena el tablero de espacios sin descubrir
void iniciarTablero(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNAS; m++) {
      tablero[l][m] = ESPACIO_SIN_DESCUBRIR;
    }
  }
}

// Coloca una mina en las coordenadas indicadas
void colocarMina(int fila, int columna, char tablero[FILAS][COLUMNAS]) {
  tablero[fila][columna] = MINA;
}

// Coloca minas de manera aleatoria. El número depende de CANTIDAD_MINAS
void colocarMinasAleatoriamente(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < MIN; l++) {
    int fila = aleatorioEnRango(0, FILAS - 1);
    int columna = aleatorioEnRango(0, COLUMNAS - 1);
    colocarMina(fila, columna, tablero);
  }
}

void imprimirSeparadorEncabezado() {
  int m;
  for (m = 0; m <= COLUMNAS; m++) {
    printf("----");
    if (m + 2 == COLUMNAS) {
      printf("-");
    }
  }
  printf("\n");
}

void imprimirSeparadorFilas() {
  int m;
  for (m = 0; m <= COLUMNAS; m++) {
    printf("+---");
    if (m == COLUMNAS) {
      printf("+");
    }
  }
  printf("\n");
}

void imprimirEncabezado() {
  imprimirSeparadorEncabezado();
  printf("|   ");
  int l;
  for (l = 0; l < COLUMNAS; l++) {
    printf("| %d ", l + 1);
    if (l + 1 == COLUMNAS) {
      printf("|");
    }
  }
  printf("\n");
}
// Convierte un int a un char. Por ejemplo 0 a '0'
char enteroACaracter(int u8numero) {
  return u8numero + '0';
}

void imprimirTablero(char tablero[FILAS][COLUMNAS], int deberiaMostrarMinas) {
  imprimirEncabezado();
  imprimirSeparadorEncabezado();
  char letra = 'A';
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    // Imprimir la letra de la fila
    printf("| %c ", letra);
    letra++;
    for (m = 0; m < COLUMNAS; m++) {
      // No le vamos a mostrar al usuario si hay una mina...
      char verdaderaLetra = ESPACIO_SIN_DESCUBRIR;
      char letraActual = tablero[l][m];
      if (letraActual == MINA) {
        verdaderaLetra = ESPACIO_SIN_DESCUBRIR;
      } else if (letraActual == ESPACIO_DESCUBIERTO) {
        // Si ya lo abrió, entonces mostramos las minas cercanas
        int u8minasCercanas = obtenerMinasCercanas(l, m, tablero);
        verdaderaLetra = enteroACaracter(u8minasCercanas);
      }
      // Si DEBUG está en 1, o debería mostrar las minas (porque perdió o ganó)
      // mostramos la mina original
      if (letraActual == MINA && (DEBUG || deberiaMostrarMinas)) {
        verdaderaLetra = MINA;
      }
      printf("| %c ", verdaderaLetra);
      if (m + 1 == COLUMNAS) {
        printf("|");
      }
    }
    printf("\n");
    imprimirSeparadorFilas();
  }
}

// Recibe la fila, columna y tablero. La fila y columna deben ser tal y como las
// proporciona el usuario. Es decir, la columna debe comenzar en 1 (no en cero
// como si fuera un índice) y la fila debe ser una letra
int abrirCasilla(char filaLetra, int columna, char tablero[FILAS][COLUMNAS]) {
  // Convertir a mayúscula
  filaLetra = toupper(filaLetra);
  // Restamos 1 porque usamos la columna como índice
  columna--;
  // Convertimos la letra a índice
  int fila = filaLetra - 'A';
  assert(columna < COLUMNAS && columna >= 0);
  assert(fila < FILAS && fila >= 0);
  if (tablero[fila][columna] == MINA) {
    return ERROR_MINA_ENCONTRADA;
  }
  if (tablero[fila][columna] == ESPACIO_DESCUBIERTO) {
    return ERROR_ESPACIO_YA_DESCUBIERTO;
  }
  // Si no hay error, colocamos el espacio descubierto
  tablero[fila][columna] = ESPACIO_DESCUBIERTO;
  return ERROR_NINGUNO;
}

// Para saber si el usuario ganó
int noHayCasillasSinAbrir(char tablero[FILAS][COLUMNAS]) {
  int l;
  for (l = 0; l < FILAS; l++) {
    int m;
    for (m = 0; m < COLUMNAS; m++) {
      char actual = tablero[l][m];
      if (actual == ESPACIO_SIN_DESCUBRIR) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  printf("** BUSCAMINAS **\n");
  int u8niv;
  printf("Que nivel quieres?\n");
  scanf("%i",&u8niv);

  if(u8niv>3)
  {
    exit(1);
  }

  if(u8niv=1){
    
      char tablero[FILAS][COLUMNAS];
  int deberiaMostrarMinas = 0;
  // Alimentar rand
  srand(getpid());
  iniciarTablero(tablero);
  colocarMinasAleatoriamente(tablero);
  // Ciclo infinito. Se rompe si gana o pierde, y eso se define con
  // "deberiaMostrarMinas"
  while (1) {
    imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    int columna;
    char fila;
    printf("Ingresa la fila: ");
    scanf(" %c", &fila);
    printf("Ingresa la columna: ");
    scanf("%d", &columna);
    int status = abrirCasilla(fila, columna, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("Has ganado\n");
      deberiaMostrarMinas = 1;
    } else if (status == ERROR_ESPACIO_YA_DESCUBIERTO) {
      printf("Ya has abierto esta casilla\n");
    } else if (status == ERROR_MINA_ENCONTRADA) {
      printf("Has perdido\n");
      deberiaMostrarMinas = 1;
    }
    }
  }
  
 if(u8niv=2){
    MIN+10;
      char tablero[FILAS][COLUMNAS];
  int deberiaMostrarMinas = 0;
  // Alimentar rand
  srand(getpid());
  iniciarTablero(tablero);
  colocarMinasAleatoriamente(tablero);
  // Ciclo infinito. Se rompe si gana o pierde, y eso se define con
  // "deberiaMostrarMinas"
  while (1) {
    imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    int columna;
    char fila;
    printf("Ingresa la fila: ");
    scanf(" %c", &fila);
    printf("Ingresa la columna: ");
    scanf("%d", &columna);
    int status = abrirCasilla(fila, columna, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("Has ganado\n");
      deberiaMostrarMinas = 1;
    } else if (status == ERROR_ESPACIO_YA_DESCUBIERTO) {
      printf("Ya has abierto esta casilla\n");
    } else if (status == ERROR_MINA_ENCONTRADA) {
      printf("Has perdido\n");
      deberiaMostrarMinas = 1;
    }
    }
  }
 
 if(u8niv=3){
    MIN+20;
      char tablero[FILAS][COLUMNAS];
  int deberiaMostrarMinas = 0;
  // Alimentar rand
  srand(getpid());
  iniciarTablero(tablero);
  colocarMinasAleatoriamente(tablero);
  // Ciclo infinito. Se rompe si gana o pierde, y eso se define con
  // "deberiaMostrarMinas"
  while (1) {
    imprimirTablero(tablero, deberiaMostrarMinas);
    if (deberiaMostrarMinas) {
      break;
    }
    int columna;
    char fila;
    printf("Ingresa la fila: ");
    scanf(" %c", &fila);
    printf("Ingresa la columna: ");
    scanf("%d", &columna);
    int status = abrirCasilla(fila, columna, tablero);
    if (noHayCasillasSinAbrir(tablero)) {
      printf("Has ganado\n");
      deberiaMostrarMinas = 1;
    } else if (status == ERROR_ESPACIO_YA_DESCUBIERTO) {
      printf("Ya has abierto esta casilla\n");
    } else if (status == ERROR_MINA_ENCONTRADA) {
      printf("Has perdido\n");
      deberiaMostrarMinas = 1;
    }
    }
   }
 

  return 0;
}