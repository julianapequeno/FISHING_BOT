void *readData(int h, int w, char IdBOT[MAX_STR], int *vetorXY, int *matrizPointer, int flag);

int qual_peixe(int linhas, int colunas, int * matrizPointer, int y_do_jogador, int x_do_jogador);

void ler_e_executar_comando(char comando[], int x_do_jogador, int y_do_jogador, int linhas, int colunas, int *vetorXY, int *matrizPointer,int *vetorLinhaCopy, char *comeback_ponteiro[10],int *variavelAcionada_Ponteiro);