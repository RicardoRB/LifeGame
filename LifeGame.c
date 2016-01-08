#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define TAM 7
#define POBLACION 10
#define NUMLIFES 7

// 8 = Life person
// 9 = Dead person

void show (int mat[TAM][TAM]);

int main() {

  int mat[TAM][TAM] = {0}, mat2[TAM][TAM] = {0}, x, y, i, j, k = 0, l = 0, contador = 0, countPersons = 0, res, nAX, nAY, con = 0, num, opc;

  srand(time(NULL));

  printf("\e[1;1H\e[2J"); // Clean screen

  for (i = 0; i < NUMLIFES; i++) {
    int field = rand() % TAM;
    int row = rand() % TAM;

    if (mat[field][row] == 8) {
      i--;
    } else {
      mat[field][row] = 8;
    }
  }



  for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM; j++) {
      mat2[i][j] = mat[i][j];
    }
  }

  show(mat);

  while (con < num) {

    do {
      printf("Next generation [1 = Yes | 2 = Exit]: ");
      scanf("%d", &opc);
    } while (opc != 1 && opc != 2);
    if (opc == 2) {
      break;
    } else {

      for (j = 0; j < TAM; j++) {
        for (i = 0; i < TAM; i++) { // Se recorre la matriz en busca de personas
          x = i;          // Las coordenadas actuales pasaran
          y = j;          // a ser las corordenadas a comprobar

          if (mat[i][j] == 8) { // Si encuentra una persona viva la rodea
            for (k = x - 1; k <= x + 1; k++) {
              for (l = y - 1; l <= y + 1; l++) {
                if (k >= 0 && k < TAM && l >= 0 && l < TAM) {
                  if (mat[k][l] == 8) { // Si en este rodeo encuentra
                    // una persona viva, la cuenta
                    contador++;
                  }
                }
              }
            }
            // Luego se comprueba el contador...
            contador -= 1;
            if (contador < 2) {
              mat2[i][j] = 9;
            }
            if (contador > 3) {
              mat2[i][j] = 9;
            }

          } else { // Si no se encuentra ninguna persona viva se busca
            // en su alrededor también
            for (k = x - 1; k <= x + 1; k++) {
              for (l = y - 1; l <= y + 1; l++) {
                if (k >= 0 && k < TAM && l >= 0 && l < TAM) {
                  if (mat[k][l] == 8) { // Si en este rodeo
                    // encuentra una persona
                    // viva, la cuenta
                    contador++;
                  }
                }
              }
            }
            // Luego se comprueba el contador...
            if (contador == 3) {
              mat2[i][j] = 8;
            }

          }
          contador = 0;

        }
      }
      printf("\e[1;1H\e[2J"); // Limpiar pantalla antes de mostrar
      show(mat2);

      con++;

      for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
          mat[i][j] = mat2[i][j];
        }
      }
    }
  }

  return 0;
}

void show (int mat[TAM][TAM]) {
  int i = 0, j = 0;
  printf("\nLife Game:\n\n");

  for (i = 0; i < TAM; i++) {
    printf("\tF:%d ", i);
    for (j = 0; j < TAM; j++) {
      if (mat[i][j] == 8) {
        printf("[O]");
      }
      else if (mat[i][j] == 0) {
        printf("[X]");
      }
      else if (mat[i][j] == 9) {
        printf("[X]");
      }
      else {
        printf(" %d", mat[i][j]);
      }
    } printf("\n\n");
  }
}
