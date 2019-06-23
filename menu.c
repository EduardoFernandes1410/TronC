#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "config.h"

void imprimir(int selecao){
	printf("\n\n\n\n\n\n\n\n\n\n"

"\t                             ___ \n"
"\t                           /~   ~\\ \n"
"\t                          |_      |\n"
"\t                          |/     __-__         \n"
"\t                           \\   /~     ~~-_      \n"
"\t                            ~~ -~~\\       ~\\    \n"
"\t                             /     |        \\                                \n"
"\t                ,           /     /          \\                               \n"
"\t              //   _ _---~~~    //-_          \\                              \n"
"\t            /  (/~~ )    _____/-__  ~-_       _-\\             _________      \n"
"\t          /  _-~\\0) ~~~~         ~~-_ \\__--~~   `\\  ___---~~~        /'    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t         /_-~                       _-/'          )~/               /'     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t         (___________/           _-~/'         _-~~/             _-~       \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t      _ ----- _~-_\\\\        _-~ /'      __--~   (_ ______---~~~--_         \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t   _-~         ~-_~\\\\      (   (     -_~          ~-_  |          ~-_      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t  /~~~~\\          \\ \\~~       ~-_ ~-_    ~\\            ~~--__-----_    \\   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t ;    / \\ ______-----\\           ~-__~-~~~~~~--_             ~~--_ \\    .  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t |   | \\((*)~~~~~~~~~~|      __--~~             ~-_               ) |   |  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t |    \\  |~|~---------)__--~~                      \\_____________/ /    ,  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t  \\    ~-----~    /  /~                             )  \\    ~-----~    /   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t   ~-_         _-~ /_______________________________/    `-_         _-~    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n"
"\t      ~ ----- ~                                            ~ ----- ~  -    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n"


"\t\t     _____ ____   ___  _   _           _____ _             ____                       \n"
"\t\t    |_   _|  _ \\ / _ \\| \\ | |         |_   _| |__   ___   / ___| __ _ _ __ ___   ___  \n"
"\t\t      | | | |_) | | | |  \\| |  _____    | | | '_ \\ / _ \\ | |  _ / _` | '_ ` _ \\ / _ \\ \n"
"\t\t      | | |  _ <| |_| | |\\  | |_____|   | | | | | |  __/ | |_| | (_| | | | | | |  __/ \n"
"\t\t      |_| |_| \\_\\\\___/|_| \\_|           |_| |_| |_|\\___|  \\____|\\__,_|_| |_| |_|\\___| \n");



	if(selecao==1) printf("\t\t\n\n\n\t\t\t\t\t\t\t> JOGAR\n\t\t\t\t\t\t\t  MUDAR RESOLUCAO\n\t\t\t\t\t\t\t  MUDAR CORES\n\t\t\t\t\t\t\t  INFORMACOES\n\t\t\t\t\t\t\t  SAIR\n");
	else if(selecao==2) printf("\t\t\n\n\n\t\t\t\t\t\t\t  JOGAR\n\t\t\t\t\t\t\t> MUDAR RESOLUCAO\n\t\t\t\t\t\t\t  MUDAR CORES\n\t\t\t\t\t\t\t  INFORMACOES\n\t\t\t\t\t\t\t  SAIR\n");
	else if(selecao==3) printf("\t\t\n\n\n\t\t\t\t\t\t\t  JOGAR\n\t\t\t\t\t\t\t  MUDAR RESOLUCAO\n\t\t\t\t\t\t\t> MUDAR CORES\n\t\t\t\t\t\t\t  INFORMACOES\n\t\t\t\t\t\t\t  SAIR\n");
	else if(selecao==4) printf("\t\t\n\n\n\t\t\t\t\t\t\t  JOGAR\n\t\t\t\t\t\t\t  MUDAR RESOLUCAO\n\t\t\t\t\t\t\t  MUDAR CORES\n\t\t\t\t\t\t\t> INFORMACOES\n\t\t\t\t\t\t\t  SAIR\n");
	else if(selecao==5) printf("\t\t\n\n\n\t\t\t\t\t\t\t  JOGAR\n\t\t\t\t\t\t\t  MUDAR RESOLUCAO\n\t\t\t\t\t\t\t  MUDAR CORES\n\t\t\t\t\t\t\t  INFORMACOES\n\t\t\t\t\t\t\t> SAIR\n");
}

void printInformacoes(){
  reset_shell_mode();
	system("clear");

	printf("\nControles:\n\n"
	"-> Jogador 1: w/a/s/d\n\n"
	"-> Jogador 2: i/j/k/l\n\n"
	"\nRegras:\n\n"
	"- A regiao onde eh permitido andar esta na cor branca.\n"
	"- As bordas coloridas de vermelho sao paredes e colidir contra elas resultara em morte.\n"
	"- A sua moto assim como a de seu oponente deixam um rastro que deve ser evitado, pois tambem sao paredes.\n"
	"  (Os rastros sao uma boa arma contra seu oponente!)\n"
	"- Sobreviva e divirta-se!\n\n\n"
	"Sobre:\n\n"
	"O jogo é inspirado no filme \"Tron\" lancado em 1982 e foi escolhido devido ao interesse dos envolvidos\n e as possibilidades de aplicar o conhecimento adquirido.\n\n\n"
	"Desenvolvedores:\n\n"
	"\t\tArthur de Brito Bonifacio | Eduardo Augusto Militao Fernandes");

	printf("\n\n\nAperte <enter> para continuar...");
	system("sleep 3s");
	getchar();
}


void pontoJogador(int jogadorPontuador, int totalJ1, int totalJ2){
  reset_shell_mode();
	system("clear");

	if(jogadorPontuador == 0){
		printf(
			"__________                             _____              ______   \n"
			"___  ____/_______ ___ ________ ______ ___  /______        ___  /   \n"
			"__  __/   __  __ `__ \\___  __ \\_  __ `/_  __/_  _ \\       __  / \n"
			"_  /___   _  / / / / /__  /_/ // /_/ / / /_  /  __/        /_/     \n"
			"/_____/   /_/ /_/ /_/ _  .___/ \\__,_/  \\__/  \\___/        (_)   \n"
			"                      /_/                                          \n"
			"\n\nJogador 1 -> %d X %d <- Jogador 2", totalJ1, totalJ2
		);
	}

	if(jogadorPontuador == 1){
		printf("\n"
			"\t________                _____                                                                     \n"
			"\t___  __ \\______ _______ __  /_______        ________ ______ _______________ _       ______        \n"
			"\t__  /_/ /_  __ \\__  __ \\_  __/_  __ \\       ___  __ \\_  __ `/__  ___/_  __ `/       _  __ \\       \n"
			"\t_  ____/ / /_/ /_  / / // /_  / /_/ /       __  /_/ // /_/ / _  /    / /_/ /        / /_/ /       \n"
			"\t/_/      \\____/ /_/ /_/ \\__/  \\____/        _  .___/ \\__,_/  /_/     \\__,_/         \\____/        \n"
			"\t                                            /_/                                                   \n"
			"\t_________                        _________                      ______       __________________   \n"
			"\t______  /______ _______ _______ _______  /______ ________       __<  /       ___/ /___/ /___/ /   \n"
			"\t___ _  / _  __ \\__  __ `/_  __ `/_  __  / _  __ \\__  ___/         / /        __/ / __/ / __/ /    \n"
			"\t/ /_/ /  / /_/ /_  /_/ / / /_/ / / /_/ /  / /_/ /_  /            / /          /_/   /_/   /_/     \n"
			"\t\\____/   \\____/ _\\__, /  \\__,_/  \\__,_/   \\____/ /_/            /_/          (_)   (_)   (_)      \n"
			"\t                /____/                                                                            \n"
			"\n\nJogador 1 -> %d X %d <- Jogador 2", totalJ1, totalJ2
		);
	}

	if(jogadorPontuador == 2){
		printf("\n"
			"\t________                _____                                                                     \n"
			"\t___  __ \\______ _______ __  /_______        ________ ______ _______________ _       ______        \n"
			"\t__  /_/ /_  __ \\__  __ \\_  __/_  __ \\       ___  __ \\_  __ `/__  ___/_  __ `/       _  __ \\       \n"
			"\t_  ____/ / /_/ /_  / / // /_  / /_/ /       __  /_/ // /_/ / _  /    / /_/ /        / /_/ /       \n"
			"\t/_/      \\____/ /_/ /_/ \\__/  \\____/        _  .___/ \\__,_/  /_/     \\__,_/         \\____/        \n"
			"\t                                            /_/                                                   \n"
			"\t_________                        _________                     _______        __________________  \n"
			"\t______  /______ _______ _______ _______  /______ ________      __|___ \\       ___/ /___/ /___/ /  \n"
			"\t___ _  / _  __ \\__  __ `/_  __ `/_  __  / _  __ \\__  ___/      _____/ /       __/ / __/ / __/ /   \n"
			"\t/ /_/ /  / /_/ /_  /_/ / / /_/ / / /_/ /  / /_/ /_  /          __/ __/         /_/   /_/   /_/    \n"
			"\t\\____/   \\____/ _\\__, /  \\__,_/  \\__,_/   \\____/ /_/           _/____/        (_)   (_)   (_)     \n"
			"\t                /____/                                                                            \n"
			"\n\nJogador 1 -> %d X %d <- Jogador 2", totalJ1, totalJ2
		);
	}

  reset_prog_mode();
}

void parabensGanhador(int jogador, int totalJ1, int totalJ2){
  reset_shell_mode();
  system("clear");

	FILE *arq;
	time_t current_time;
  char* c_time_string;

	current_time = time(NULL); //pega o tempo
	c_time_string = ctime(&current_time); //converte para o formato local
	arq = fopen("registro.txt", "a");

	if(jogador == 1){
		printf(
			"___    _______ _____ _______        _____                _________                              \n"
			"__ |  / /___(_)__  /_____/_/___________(_)______ _       ______  /______                        \n"
			"__ | / / __  / _  __/_  __ \\__  ___/__  / _  __ `/       _  __  / _  __ \\                       \n"
			"__ |/ /  _  /  / /_  / /_/ /_  /    _  /  / /_/ /        / /_/ /  / /_/ /                       \n"
			"_____/   /_/   \\__/  \\____/ /_/     /_/   \\__,_/         \\__,_/   \\____/                        \n"
			"                                                                                                \n"
			"_________                        _________                      ______       __________________ \n"
			"______  /______ _______ _______ _______  /______ ________       __<  /       ___  /___  /___  / \n"
			"___ _  / _  __ \\__  __ `/_  __ `/_  __  / _  __ \\__  ___/       __  /        __  / __  / __  /  \n"
			"/ /_/ /  / /_/ /_  /_/ / / /_/ / / /_/ /  / /_/ /_  /           _  /          /_/   /_/   /_/   \n"
			"\\____/   \\____/ _\\__, /  \\__,_/  \\__,_/   \\____/ /_/            /_/          (_)   (_)   (_)    \n"
			"                /____/                                                                          \n"
		);

		fprintf(arq, "%s Jogador 1 ganhou -> %d X %d\n\n", c_time_string, totalJ1, totalJ2);
	}

	if(jogador == 2){
		printf(
			"___    _______ _____ _______        _____                _________                               \n"
			"__ |  / /___(_)__  /_____/_/___________(_)______ _       ______  /______                         \n"
			"__ | / / __  / _  __/_  __ \\__  ___/__  / _  __ `/       _  __  / _  __ \\                        \n"
			"__ |/ /  _  /  / /_  / /_/ /_  /    _  /  / /_/ /        / /_/ /  / /_/ /                        \n"
			"_____/   /_/   \\__/  \\____/ /_/     /_/   \\__,_/         \\__,_/   \\____/                         \n"
			"                                                                                                 \n"
			"_________                        _________                      ______        __________________ \n"
			"______  /______ _______ _______ _______  /______ ________       __|__ \\       ___  /___  /___  / \n"
			"___ _  / _  __ \\__  __ `/_  __ `/_  __  / _  __ \\__  ___/       ____/ /       __  / __  / __  /  \n"
			"/ /_/ /  / /_/ /_  /_/ / / /_/ / / /_/ /  / /_/ /_  /           _  __/         /_/   /_/   /_/   \n"
			"\\____/   \\____/ _\\__, /  \\__,_/  \\__,_/   \\____/ /_/            /____/        (_)   (_)   (_)    \n"
			"                /____/                                                                           \n"
		);

		fprintf(arq, "%s Jogador 2 ganhou -> %d X %d\n\n", c_time_string, totalJ1, totalJ2);
	}

	system("sleep 3s");
	fclose(arq);
  reset_prog_mode();
}

void agradecerJogadores(){
  reset_shell_mode();
	system("clear");

	printf(
		"_____________        _____               _________                       \n"
		"__  __ \\__  /___________(_)______ ______ ______  /_____                  \n"
		"_  / / /_  __ \\_  ___/_  /__  __ `/  __ `/  __  /_  __ \\                 \n"
		"/ /_/ /_  /_/ /  /   _  / _  /_/ // /_/ // /_/ / / /_/ /                 \n"
		"\\____/ /_.___//_/    /_/  _\\__, / \\__,_/ \\__,_/  \\____/                  \n"
		"                          /____/                                         \n"
		"                          ________                                 ______\n"
		"______________________    ______(_)____________ ______ ________    ___  /\n"
		"___  __ \\  __ \\_  ___/    _____  /_  __ \\_  __ `/  __ `/_  ___/    __  / \n"
		"__  /_/ / /_/ /  /        ____  / / /_/ /  /_/ // /_/ /_  /         /_/  \n"
		"_  .___/\\____//_/         ___  /  \\____/_\\__, / \\__,_/ /_/         (_)   \n"
		"/_/                       /___/         /____/                           \n"
	);

	system("sleep 3s");
	system("clear");
  reset_prog_mode();
}

int Menu(int dimensoes[2], char cores[2][10]){
	int selecao=1;
	char setinha;
	int resolucaoMenu[2] = {37, 122};

	while(1){
		system("clear");
		printf("\n");
		system("clear");
		applyResolucao(resolucaoMenu);
		imprimir(selecao);

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
			setinha == 1;

      if(selecao == 1) {
        return 1;
      } else if(selecao == 2){
				system("clear");
				setResolucao(dimensoes);
			} else if(selecao == 3){
				system("clear");
        setCores(cores);
			} else if(selecao == 4){
				printInformacoes();
			} else if(selecao == 5){
				agradecerJogadores();
				return 0;
			}
		}
	}
}
