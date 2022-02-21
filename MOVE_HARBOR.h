int detectar_porto_na_linha(int altura, int largura, int *matrizPointer, int y, int x);

int detectar_portos_na_linha_de_cima(int altura, int largura, int *matrizPointer, int y, int linhas_a_cima);

int detectar_portos_na_linha_de_baixo(int altura, int largura, int *matrizPointer, int y, int linhas_a_baixo);

char *esquerda_ou_direita_pro_porto (int linhas, int colunas, int *matrizPointer, int y_do_jogador, int x_do_jogador);