#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int _getch(void) {
	struct termios lxgetch_orig, lxgetch_new; 	//Define as variáveis 'lxgetch_orig' e 'lxgetch_new' como do tipo termios;
	int lxgetch_ch;				  	//Variável que armazena o código ascii da tecla pressionada;
	tcgetattr(STDIN_FILENO, &lxgetch_orig);   	//Armazena-os na variável lxgetch_orig,os parâmetros associados com os objectos de entrada estandardizada;
	lxgetch_new = lxgetch_orig; 		  	//Copia os parâmetros armazenados na variável lxgetch_orig para a variável lxgetch_new;
	lxgetch_new.c_lflag &= ~(ICANON | ECHO);  	//Muda os parâmetros dos modos locais da variável lxgetch_new, para modo canónico e ecoa caracteres de entrada;
	lxgetch_new.c_iflag &= ~(ISTRIP | INPCK); 	//Muda os parâmetros dos modos de entrada da variável lxgetch_new, para cortar o oitavo bit e verificar paridade na entrada;
	tcsetattr(STDIN_FILENO, TCSANOW, &lxgetch_new); //Define imediatamente os novos parâmetros de entrada estandardizada, que estão na variável lxgetch_new;
	lxgetch_ch = getchar(); 			//Lê a tecla pressionada;
	tcsetattr(STDIN_FILENO, TCSANOW, &lxgetch_orig);//Volta a colocar os parâmetros originais dos objectos de entrada estandardizada;
	return lxgetch_ch; 				//Retorna o código ascii da tecla pressionada;
}
