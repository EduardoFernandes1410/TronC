#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>
#include <stdio_ext.h>
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
    endwin();
    exit(-1);
  }

  for(i = 0; i < lin; i++) {
    mapa[i] = (int *)calloc(col, sizeof(int));
    if(mapa[i] == NULL || mapa[i] == 0) {
      printf("Problema ao alocar memoria :/");
      endwin();
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

  reset_shell_mode();
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

  __fpurge(stdin);
  reset_prog_mode();
}

void percorreMapa(int **mapa, int lin, int col) {
  int i = 0, j, linha1 = (lin / 2), coluna1 = 2, linha2 = (lin / 2), coluna2 = (col - 3);
  char comando, comando1 = 'd', comando2 = 'j';

  // Modo automatico
  while(1) {
    for(i = 0; i < 2; i++) {
      comando = getch();

      if(tolower(comando) == 'w' || tolower(comando) == 'a' || tolower(comando) == 's' || tolower(comando) == 'd') {
        comando1 = comando;
      } else if(tolower(comando) == 'i' || tolower(comando) == 'j' || tolower(comando) == 'k' || tolower(comando) == 'l') {
        comando2 = comando;
      } else if(tolower(comando) == 3) {
        endwin();
        exit(-1);
      }
    }

    // Player 1
    switch(tolower(comando1)) {
      case 'w': //setinha cima
        mapa[--linha1][coluna1] = 2;
        break;
      case 's': //setinha baixo
        mapa[++linha1][coluna1] = 2;
        break;
      case 'd': //setinha direita
        mapa[linha1][++coluna1] = 2;
        break;
      case 'a': //setinha esquerda
        mapa[linha1][--coluna1] = 2;
        break;
    }

    // Player 2
    switch(tolower(comando2)) {
      case 'i': //setinha cima
        mapa[--linha2][coluna2] = 3;
        break;
      case 'k': //setinha baixo
        mapa[++linha2][coluna2] = 3;
        break;
      case 'l': //setinha direita
        mapa[linha2][++coluna2] = 3;
        break;
      case 'j': //setinha esquerda
        mapa[linha2][--coluna2] = 3;
        break;
    }

    system("sleep 0.1s");
    imprimeMapa(mapa, lin, col);
  }
}
