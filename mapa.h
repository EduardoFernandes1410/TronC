void liberaMapa(int **mapa, int lin);
int** criarMapa(int lin, int col);
void imprimeMapa(int **mapa, int lin, int col, char cores[][10]);
int iniciaJogo(int **mapa, int lin, int col, char cores[][10]);

int _getch(void);
void set_conio_terminal_mode();
int kbhit();
void reset_terminal_mode();
