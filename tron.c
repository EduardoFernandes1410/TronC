#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio_ext.h>
#include <string.h>
#include "mapa.h"
#include "config.h"
#include "menu.h"

int main() {
	int i, menu, jogou = 0, res = 0, j1 = 0, j2 = 0;
  int dimensoes[2];
  int **mapa;
  char cores[2][10];

  // Pega configs do arquivo de config
  getResolucao(dimensoes);
  applyResolucao(dimensoes);
  getCores(cores);

  while(1) {
    system("clear");

    jogou = 0;
    menu = Menu(dimensoes, cores); //Exibe o menu

    //Recupera as novas informacoes inseridas pelo usuario
    getResolucao(dimensoes);
    applyResolucao(dimensoes);
    getCores(cores);
    system("sleep 0.01s");

    // Curses.h
    initscr();
    noecho();
    nodelay(stdscr, TRUE);


    j1 = j2 = 0; //Pontuacao = 0

    while(j1 != 3 && j2 != 3 && menu != 0) {
      jogou = 1;
      // Comeca jogo
      mapa = criarMapa(dimensoes[0], dimensoes[1]);
      imprimeMapa(mapa, dimensoes[0], dimensoes[1], cores);
      res = iniciaJogo(mapa, dimensoes[0], dimensoes[1], cores);

      if(res == 1){
        j1++;
        if(j1 != 3) pontoJogador(1, j1, j2);
      }
      else if(res == 2){
        j2++;
        if(j2 != 3) pontoJogador(2, j1, j2);
      }
      else if(res == 0){
        pontoJogador(0, j1, j2);
      }

      if(j1 == 3) {
        parabensGanhador(1, j1, j2);
      } else if(j2 == 3) {
        parabensGanhador(2, j1, j2);
      } else {
        printf("\n");
        system("sleep 2s");
      }
    }

    endwin();
    if(jogou == 1){
      liberaMapa(mapa, dimensoes[0]);
    }
    system("clear");

    if(menu == 0){
      exit(0);
    }
  }

}
