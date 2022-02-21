#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR 50

#include "MOVE_FISH.h"
#include "MOVE_HARBOR.h"
#include "FISH_LOGIC.h"
#include "MOVE_BUSY.h"

void *readData(int h, int w, char IdBOT[MAX_STR], int *vetorXY, int *matrizPointer, int flag){
  char id[MAX_STR];
  int v, n, x, y;
  int matriz[h][w];
  for (int i = 0; i < h; i++) {   
    for (int j = 0; j < w; j++) {
      scanf("%i", &v);
      matriz[i][j] = v;
      *(matrizPointer+flag) = matriz[i][j];
      flag++;
    }
  }
  scanf(" BOTS %i", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %i %i", id, &x, &y);
    if(strcmp(IdBOT, id)==0){
      *(vetorXY+0) = x;
      *(vetorXY+1) = y;
    }
  }
}

int qual_peixe(int altura, int largura, int * matrizPointer, int y, int x){
    int conta_peixe = 1;
    if(*(matrizPointer+(largura*x)+y) - 10 < 10 && *(matrizPointer+(largura*x)+y) - 10 > 1 ){
        return conta_peixe;
    }
    else if(*(matrizPointer+(largura*x)+y)- 20 < 10 && *(matrizPointer+(largura*x)+y) - 20 > 1 ){
        return conta_peixe+1;
    }else if(*(matrizPointer+(largura*x)+y)  - 30 < 10 && *(matrizPointer+(largura*x)+y) - 30 > 1 ){
        return conta_peixe+2;
    }else{
      return 0;
    }
}

void ler_e_executar_comando(char comando[], int x, int y, int altura, int largura, int *vetorXY, int *matrizPointer,int *vetorLinhaCopy, char *comeback_ponteiro[10],int *variavelAcionada_Ponteiro){
  char comeback[10];
  int num_resultado; 
  if(strcmp(comando, "LEFT") == 0){
      y = y - 1;
      *(vetorXY+1) = y;
      printf("LEFT\n");
      scanf("%s",&comeback);
      if(strcmp(comeback,"BUSY") == 0){
        *(variavelAcionada_Ponteiro) = 1;
      }
      
  }else if(strcmp(comando, "RIGHT") == 0){
    y = y + 1;
    *(vetorXY+1) = y;
      printf("RIGHT\n");
      scanf("%s",&comeback);
      if(strcmp(comeback,"BUSY") == 0){
        *(variavelAcionada_Ponteiro) = 1;
      }
      
  }else if(strcmp(comando, "UP") == 0){
      x = x -1;
      *(vetorXY+0) = x;
      printf("UP\n");
      scanf("%s",&comeback);
      if(strcmp(comeback,"BUSY") == 0){
        *(variavelAcionada_Ponteiro) = 1;
      }
      
  }else if(strcmp(comando, "DOWN") == 0){
      x = x + 1;
      *(vetorXY+0) = x;
      printf("DOWN\n");
      scanf("%s",&comeback);
      if(strcmp(comeback,"BUSY") == 0){
        *(variavelAcionada_Ponteiro) = 1;
      }
      
  }

}