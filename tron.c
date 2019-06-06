#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

#define MAPAL 58
#define MAPAC 174

int main() {
	char buf[1024];
	int i, j;
  int **mapa = criarMapa(MAPAL, MAPAC);

	system("clear");
	imprimeMapa(mapa, MAPAL, MAPAC);

	snprintf(buf, sizeof(buf), "printf \'\e[8;'%d';'%d't\'", MAPAL + 1, MAPAC);
	system(buf);

	system("sleep 500000");

  for(i = 0; i < MAPAL; i++) {
    free(mapa[i]);
  }
  free(mapa);

	return 0;
}
