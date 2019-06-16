#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>
#include <string.h>
#include "mapa.h"

void getResolucao(int dimensoes[]) {
  FILE *arq;

  arq = fopen("configs.txt", "r+");
  if(!arq) {
    arq = fopen("configs.txt", "w+");
    if(!arq) {
      printf("Erro ao acessar as configuracoes do programa!\n");
      return;
    }

    // Escreve configs default
    dimensoes[0] = 24;
    dimensoes[1] = 88;
    fprintf(arq, "24 88\n\x1B[32m \x1B[34m\n");
    fclose(arq);
    return;
  }

  // Le configs do arquivo
  fscanf(arq, "%d %d", &dimensoes[0], &dimensoes[1]);
  fclose(arq);
}

void setResolucao(int dimensoes[]) {
  FILE *arq;
  char cor1[10], cor2[10];

  printf("Vertical: ");
  scanf("%d", &dimensoes[0]);

  printf("Horizontal: ");
  scanf("%d", &dimensoes[1]);

  // Salva no arquivo de configuracoes
  arq = fopen("configs.txt", "r+");
  if(!arq) {
    arq = fopen("configs.txt", "w+");
    if(!arq) {
      printf("Erro ao acessar as configuracoes do programa!\n");
      return;
    }

    fprintf(arq, "%d %d\n\x1B[32m \x1B[34m\n", dimensoes[0], dimensoes[1]);
    fclose(arq);
    return;
  }

  fgets(cor1, 80, arq);
  fscanf(arq, "%s %s", cor1, cor2);

  fseek(arq, 0, SEEK_SET);
  fprintf(arq, "%d %d\n%s %s\n", dimensoes[0], dimensoes[1], cor1, cor2);
  fclose(arq);
}

void applyResolucao(int dimensoes[]) {
  char buf[1024];

  snprintf(buf, sizeof(buf), "printf \'\e[8;'%d';'%d't\'", dimensoes[0] + 2, dimensoes[1]);
  system(buf);
}

void getCores(char cores[][10]) {
  FILE *arq;

  arq = fopen("configs.txt", "r+");
  if(!arq) {
    arq = fopen("configs.txt", "w+");
    if(!arq) {
      printf("Erro ao acessar as configuracoes do programa!\n");
      return;
    }

    // Escreve configs default
    strcpy(cores[0], "\x1B[32m");
    strcpy(cores[1], "\x1B[34m");
    fprintf(arq, "24 88\n%s %s\n", cores[0], cores[1]);
    fclose(arq);
    return;
  }

  fgets(cores[0], 80, arq);
  fscanf(arq, "%s %s", cores[0], cores[1]);
  fclose(arq);
}

void setCores(char cores[][10]) {
  FILE *arq;
  int i, j, cor1, cor2;
  char string[80];
  const char *codigos[5];

  // Define codigos de cores
  codigos[0] = "\x1B[32m";
  codigos[1] = "\x1B[33m";
  codigos[2] = "\x1B[34m";
  codigos[3] = "\x1B[35m";
  codigos[4] = "\x1B[36m";

  printf("Cor J1 ((0) GRN, (1) YEL, (2) BLU, (3) MAG, (4) CYN): ");
  scanf("%d", &cor1);

  printf("Cor J2 ((0) GRN, (1) YEL, (2) BLU, (3) MAG, (4) CYN): ");
  scanf("%d", &cor2);

  // Mapear cores para codigo
  strcpy(cores[0], codigos[cor1]);
  strcpy(cores[1], codigos[cor2]);

  // Salva no arquivo de configuracoes
  arq = fopen("configs.txt", "r+");
  if(!arq) {
    arq = fopen("configs.txt", "w+");
    if(!arq) {
      printf("Erro ao acessar as configuracoes do programa!\n");
      return;
    }

    fprintf(arq, "24 88\n%s %s\n", cores[0], cores[1]);
    fclose(arq);
    return;
  }

  fgets(string, 80, arq);
  fprintf(arq, "%s %s\n", cores[0], cores[1]);
  fclose(arq);
}
