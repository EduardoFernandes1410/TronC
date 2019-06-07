#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "mapa.h"

#define MAPAL 58
// #define MAPAL 18
#define MAPAC 174
// #define MAPAC 100

int main() {
	char buf[1024];
	int i, j;
  int **mapa = criarMapa(MAPAL, MAPAC);

  // Redimensiona terminal
	snprintf(buf, sizeof(buf), "printf \'\e[8;'%d';'%d't\'", MAPAL + 1, MAPAC);
	system(buf);
  
  // Curses.h
  initscr();
  noecho();
  nodelay(stdscr, TRUE);

  // Comeca jogo
  imprimeMapa(mapa, MAPAL, MAPAC);
  percorreMapa(mapa, MAPAL, MAPAC);

  // Libera memoria
  for(i = 0; i < MAPAL; i++) {
    free(mapa[i]);
  }
  free(mapa);

  endwin();
	return 0;
}
