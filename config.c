#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <curses.h>
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
    dimensoes[0] = 37;
    dimensoes[1] = 122;
    fprintf(arq, "37 122\n\x1B[32m \x1B[34m\n");
    fclose(arq);
    return;
  }

  // Le configs do arquivo
  fscanf(arq, "%d %d", &dimensoes[0], &dimensoes[1]);
  fclose(arq);
}

void applyResolucao(int dimensoes[]) {
  char buf[1024];

  snprintf(buf, sizeof(buf), "printf \'\e[8;'%d';'%d't\'", dimensoes[0] + 2, dimensoes[1]);
  system(buf);
}

void setResolucao(int dimensoes[]) {

  FILE *arq;
  char cor1[10], cor2[10];
  int dimensao = 1;
  char setinha;

  getResolucao(dimensoes);
  applyResolucao(dimensoes);

	while(dimensao < 3){

		system("clear");

    printf("\nUse as teclas: CIMA, BAIXO e ENTER para alterar os valores.\n\n");

    if(dimensao == 1){
      printf("\nVertical:\t--> 0%d <--\n", dimensoes[0]+2);
      printf("\nHorizontal:\t    %d    \n", dimensoes[1]);
    }

    else if(dimensao == 2){
      printf("\nVertical:\t    0%d    \n", dimensoes[0]+2);
      printf("\nHorizontal:\t--> %d <--\n", dimensoes[1]);
    }

		setinha = _getch();

		if(setinha==65){ //setinha pra baixo
			if(dimensao == 1 && dimensoes[0] < 58) dimensoes[0]++;
			else if(dimensao == 2 && dimensoes[1] < 174) dimensoes[1]++;
  		applyResolucao(dimensoes);
		}
		else if(setinha == 66){ //setinha pra cima
			if(dimensao == 1 && dimensoes[0] > 35 ) dimensoes[0]--;
			else if(dimensao == 2 && dimensoes[1] > 122) dimensoes[1]--;
  		applyResolucao(dimensoes);

		}
		else if(setinha == 10){ //quando da enter
      dimensao++;
		}
  }

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

  printf("\n\nConfiguracoes aplicadas!\n\n");
  system("sleep 1s");

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
    fprintf(arq, "37 122\n%s %s\n", cores[0], cores[1]);
    fclose(arq);
    return;
  }

  fgets(cores[0], 80, arq);
  fscanf(arq, "%s %s", cores[0], cores[1]);
  fclose(arq);
}

void imprimirCores(int selecao, int jogador){

  printf("\nUse as teclas: CIMA, BAIXO e ENTER para navegar.\n\n"
    "Cores disponiveis:\n\n"
  );
  if(selecao == 1)
    printf(
      GRN "\t\t--> \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210 <--\n\n"
      YEL "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      BLU "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      MAG "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      CYN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      WHT
    );
  if(selecao == 2)
    printf(
      GRN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      YEL "\t\t--> \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210 <--\n\n"
      BLU "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      MAG "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      CYN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      WHT
    );
  if(selecao == 3)
    printf(
      GRN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      YEL "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      BLU "\t\t--> \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210 <--\n\n"
      MAG "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      CYN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      WHT
    );
  if(selecao == 4)
    printf(
      GRN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      YEL "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      BLU "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      MAG "\t\t--> \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210 <--\n\n"
      CYN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      WHT
    );
  if(selecao == 5)
    printf(
      GRN "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      YEL "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      BLU "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      MAG "\t\t    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\n\n"
      CYN "\t\t--> \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210 <--\n\n"
      WHT
    );

  printf("\n\nDefinindo cor para --> JOGADOR %d <--\n", jogador);
}

void setCores(char cores[][10]) {
  FILE *arq;
  int i, j, cor1, cor2, jogador = 1;
  char string[80];
  const char *codigos[5];
  int selecao = 1;
  char setinha;

  // Define codigos de cores
  codigos[0] = "\x1B[32m";
  codigos[1] = "\x1B[33m";
  codigos[2] = "\x1B[34m";
  codigos[3] = "\x1B[35m";
  codigos[4] = "\x1B[36m";

  // Imprime cores para o usuário e espera a escolha para os dois jogadores

	while(1){
		system("clear");
		printf("\n");
		system("clear");
		imprimirCores(selecao, jogador);

		setinha = _getch();

		if(setinha==65){ //setinha pra baixo
			if(selecao!=1) selecao--;
			else selecao=5;
		}
		else if(setinha == 66){ //setinha pra cima
			if(selecao != 5) selecao++;
			else selecao = 1;
		}
		else if(setinha == 10){ //quando da enter

      if(jogador == 1)
        cor1 = (selecao - 1);
      else if(jogador == 2)
        cor2 = (selecao - 1);

      jogador++;

      if(jogador == 3)
        break;
		}
  }

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

    fprintf(arq, "37 122\n%s %s\n", cores[0], cores[1]);
    fclose(arq);
    return;
  }

  fgets(string, 80, arq);
  fprintf(arq, "%s %s\n", cores[0], cores[1]);
  fclose(arq);
}
