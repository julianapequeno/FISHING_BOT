#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 50

#include "MOVE_FISH.h"
#include "MOVE_HARBOR.h"
#include "MANO.h"
#include "FISH_LOGIC.h"

int esquerda_ou_direita_BUSY(int altura, int largura, int *matrizPointer, int y, int x, int pontodePesca){
  int retornoFuncao = 0;
  int peixe = 0;
  int maior = 0;
  if(y!= 0){ 
      int casas_antes_do_y = 0;
      for(int i = 0; i <= y-1; i++){
           if(*(matrizPointer+(largura*x)+i) == pontodePesca){ 
              casas_antes_do_y = i;
              peixe = qual_peixe(altura,largura,matrizPointer,casas_antes_do_y,x);
              if(peixe > maior){
                maior  = peixe;
                retornoFuncao = (i+1); 
                retornoFuncao = -retornoFuncao;
              }
          } 
        
    } 
  }
int casas_antes_do_y = largura;
for(int substituto_y = largura-1; substituto_y >= y+1; substituto_y--){
    if(*(matrizPointer+(largura*x)+substituto_y) == pontodePesca){
        casas_antes_do_y = substituto_y;
        peixe = qual_peixe(altura,largura,matrizPointer,substituto_y,x);
        if(peixe > maior){
          maior  = peixe;
          retornoFuncao = casas_antes_do_y; 
        }
    }
}
  return retornoFuncao;
}

char * locomove_esquerda_ou_direita_BUSY(int altura, int largura, int *matrizPointer, int y, int x){ 
  int pontodePesca = *(matrizPointer+(largura*x)+y);
  int vetorLinha[largura];
  int retornoFuncao = 0;
  
  for(int j = 0; j < largura; j++){
    vetorLinha[j] = *(matrizPointer+(largura*x)+j);
    if(vetorLinha[j] == 21 || vetorLinha[j] == 11 || vetorLinha[j] == 31 || vetorLinha[j] == 10 || vetorLinha[j] == 20 || vetorLinha[j] == 30 || vetorLinha[j] == 1 || vetorLinha[j] == *(matrizPointer+(largura*x)+(y+1)) || vetorLinha[j] == *(matrizPointer+(largura*x)+(y-1)) ){ 
      vetorLinha[j] = 0;
    }
  }
  for(int j = 0; j < largura; j++){
    if(vetorLinha[j] > pontodePesca){ 
      pontodePesca = vetorLinha[j];
    }
  }
  retornoFuncao = esquerda_ou_direita_BUSY(altura,largura, matrizPointer,y,x, pontodePesca);
  
  if(retornoFuncao == 0){
    return "NOTHING"; 
  }else if(retornoFuncao < 0){
    return "LEFT";
  }else if(retornoFuncao > 0){
    return "RIGHT";
  }
}

void funcBUSY(int x, int y, int s, int largura, int altura, int *matrizPointer){
  int retorno;
  int acoes = 4;
  char result[10];
  char *retornoF;
  srand(s);
  int num = rand()%acoes;
  switch(num){
    case 0:
         
          retornoF = locomove_esquerda_ou_direita_BUSY(altura, largura, matrizPointer, y, x);
          if(strcmp(retornoF,"NOTHING")==0){
            funcBUSY(x,y,s+879,largura,altura,matrizPointer);
          }else{
             printf("%s\n",retornoF);
             scanf("%s",&result); 
          }
  
          break; 
    case 1:
          retornoF = locomove_esquerda_ou_direita_BUSY( altura, largura, matrizPointer, y, x);
          if(strcmp(retornoF,"NOTHING")==0){
            funcBUSY(x,y,s+879,largura,altura,matrizPointer);
          }else{
             printf("%s\n",retornoF);
             scanf("%s",&result); 
          }
     
          break; 
    case 2:
          retorno = detectar_peixes_na_linha_de_cima(altura,  largura, matrizPointer,y, x);
          if(retorno == 0){
            funcBUSY(x,y,s+317,largura,altura,matrizPointer);
          }else{
            printf("UP\n");
            scanf("%s",&result);
          }
          break;
    case 3:
          retorno =  detectar_peixes_na_linha_de_baixo(altura, largura,matrizPointer, y, x);
          if(retorno == 0){  
            funcBUSY(x,y,s+43,largura,altura,matrizPointer);
          }else{  
            printf("DOWN\n");
            scanf("%s",&result);
          }
          break; 
    }

  }
