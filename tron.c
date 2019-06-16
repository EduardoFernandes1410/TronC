#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio_ext.h>
#include <string.h>
#include "mapa.h"
#include "config.h"

int main() {
	int i, menu, res = 0, j1 = 0, j2 = 0;
  int dimensoes[2];
  int **mapa;
  char cores[2][10], cor[8];

  // Pega configs do arquivo de config
  getResolucao(dimensoes);
  applyResolucao(dimensoes);
  getCores(cores);

  while(1) {
    // Exibe menu
    system("clear");
    printf("(0) Jogar\n(1) Mudar resolucao\n(2) Mudar cores\n(3) Sair\n");

    menu = -1;
    __fpurge(stdin);
    scanf("%d", &menu);

    j1 = j2 = 0;
    switch(menu) {
      case 0:
        // Curses.h
        initscr();
        noecho();
        nodelay(stdscr, TRUE);

        while(j1 != 3 && j2 != 3) {
          // Comeca jogo
          mapa = criarMapa(dimensoes[0], dimensoes[1]);
          imprimeMapa(mapa, dimensoes[0], dimensoes[1], cores);
          res = iniciaJogo(mapa, dimensoes[0], dimensoes[1], cores);

          if(res == 1) j1++;
          else if(res == 2) j2++;
          printf("J1: %d J2: %d\t", j1, j2);

          if(j1 == 3) {
            printf("J1 venceu o jogo!\n");
            system("sleep 2s");
          } else if(j2 == 3) {
            printf("J2 venceu o jogo!\n");
            system("sleep 2s");
          } else {
            printf("\n");
            system("sleep 2s");
          }
        }

        endwin();
        liberaMapa(mapa, dimensoes[0]);
        break;
      case 1:
        // Redimensiona terminal
        setResolucao(dimensoes);
        applyResolucao(dimensoes);
        break;
      case 2:
        // Altera cores das motos
        setCores(cores);
        break;
      case 3:
        endwin();
        return 0;
        break;
    }
  }

}
