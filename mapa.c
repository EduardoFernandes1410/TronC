#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>
#include <stdio_ext.h>
#include <string.h>
#include "mapa.h"

#define RESET "\x1B[0m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"

void liberaMapa(int **mapa, int lin) {
  int i;

  for(i = 0; i < lin; i++) {
    free(mapa[i]);
  }
  free(mapa);
}

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

void imprimeMapa(int **mapa, int lin, int col, char cores[][10]) {
	int i, j;

  system("clear");
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
        printf("%s", cores[0]);
				printf("\342\226\210" RESET);
			}
			else if(mapa[i][j] == 3) {
        printf("%s", cores[1]);
				printf("\342\226\210" RESET);
			}
		}
		printf("\n");
  }

  __fpurge(stdin);
  reset_prog_mode();
}

int iniciaJogo(int **mapa, int lin, int col, char cores[][10]) {
  int i = 0, j, linha1 = (lin / 2), coluna1 = 10, linha2 = (lin / 2), coluna2 = (col - 11), res = 0, c1 = 0, c2 = 0;
  int last1[2] = {linha1, coluna1}, last2[2] = {linha2, coluna2};
  char comando, comando1 = 'd', comando2 = 'j';

  // Limpa buffer
  __fpurge(stdin);
  for(i = 0; i < 1000; i++) getch();

  // Modo automatico
  while(1) {
    c1 = c2 = 0;

    for(i = 0; i < 2; i++) {
      comando = tolower(getch());

      if(comando == 'w' || comando == 'a' || comando == 's' || comando == 'd') {
        if(abs(comando1 - comando) != 3 && abs(comando1 - comando) != 4 && c1 == 0) {
          comando1 = comando;
          c1 = 1;
        }
      } else if(comando == 'i' || comando == 'j' || comando == 'k' || comando == 'l') {
        if(abs(comando2 - comando) != 2 && c2 == 0) {
          comando2 = comando;
          c2 = 1;
        }
      } else if(comando == 3) {
        endwin();
        return 0;
      }
    }

    // Player 1
    last1[0] = linha1;
    last1[1] = coluna1;
    switch(comando1) {
      case 'w': //setinha cima
        linha1--;
        break;
      case 's': //setinha baixo
        linha1++;
        break;
      case 'd': //setinha direita
        coluna1++;
        break;
      case 'a': //setinha esquerda
        coluna1--;
        break;
    }

    // Player 2
    last2[0] = linha2;
    last2[1] = coluna2;
    switch(comando2) {
      case 'i': //setinha cima
        linha2--;
        break;
      case 'k': //setinha baixo
        linha2++;
        break;
      case 'l': //setinha direita
        coluna2++;
        break;
      case 'j': //setinha esquerda
        coluna2--;
        break;
    }

    // Se J1 colidiu
    if(mapa[linha1][coluna1] != 0) {
      res += 2;
      mapa[last1[0]][last1[1]] = 1;
    } else {
      mapa[linha1][coluna1] = 2;
    }

    // Se J2 colidiu
    if(mapa[linha2][coluna2] != 0) {
      res += 1;
      mapa[last2[0]][last2[1]] = 1;
    } else {
      mapa[linha2][coluna2] = 3;
    }

    // Verifica se empatou
    if(res == 3) {
      imprimeMapa(mapa, lin, col, cores);
      //printf("Empate!\t");
      system("sleep 1s");
      return 0;
    } else if(res != 0) {
      imprimeMapa(mapa, lin, col, cores);
      //printf("J%d venceu a queda!\t", res);
      system("sleep 1s");
      return res;
    }

    system("sleep 0.1s");
    imprimeMapa(mapa, lin, col, cores);
  }
}
