#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

#define RESET "\x1B[0m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"

int** criarMapa(int lin, int col) {
  int **mapa, i;

  // Cria mapa
  mapa = (int **)malloc(lin * sizeof(int *));
  if(mapa == NULL || mapa == 0) {
    printf("Problema ao alocar memoria :/");
    exit(-1);
  }

  for(i = 0; i < lin; i++) {
    mapa[i] = (int *)calloc(col, sizeof(int));
    if(mapa[i] == NULL || mapa[i] == 0) {
      printf("Problema ao alocar memoria :/");
      exit(-1);
    }
  }

  // Preenche mapa
  for(i = 0; i < col; i++) mapa[0][i] = 1; //Topo
  for(i = 0; i < col; i++) mapa[lin - 1][i] = 1; //Chao
  for(i = 0; i < lin; i++) mapa[i][0] = 1; //Esquerda
  for(i = 0; i < lin; i++) mapa[i][col - 1] = 1; //Direita

  return mapa;
}

void imprimeMapa(int **mapa, int lin, int col) {
	int i, j;

	// system("clear");
	for(i = 0; i < lin; i++) {
		for(j = 0; j < col; j++) {
			if(mapa[i][j] == 1) {
				printf(RED "\342\226\210" RESET);
			}
			else if(mapa[i][j] == 0) {
				printf(WHT "\342\226\210" RESET);
			}
			else if(mapa[i][j] == 2) {
				printf(GRN "\342\226\210" RESET);
			}
			else if(mapa[i][j] == 3) {
				printf(BLU "\342\226\210" RESET);
			}
		}
		printf("\n");
	}
}

void percorreMapa(int **mapa, int lin, int col) {
  int i = 0, j;
  char comando = 67, linha = (lin / 2), coluna = 2;

  // set_conio_terminal_mode();
  // for(i = 0; i < 10; i++) {
    // while(!kbhit()) {
    while(1) {
      comando = getch();

      switch(comando) {
        case 65: //setinha cima
          mapa[--linha][coluna] = 2;
          break;
        case 66: //setinha baixo
          mapa[++linha][coluna] = 2;
          break;
        case 67: //setinha direita
          mapa[linha][++coluna] = 2;
          break;
        case 68: //setinha esquerda
          mapa[linha][--coluna] = 2;
          break;
      }

      // system("sleep 0.1s");
      imprimeMapa(mapa, lin, col);
    }
  // }
}
