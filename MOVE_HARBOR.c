#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 50

#include "MOVE_FISH.h"
#include "MOVE_BUSY.h"
#include "MANO.h"
#include "FISH_LOGIC.h"

int detectar_porto_na_linha(int altura, int largura, int *matrizPointer, int y, int x){
  int achou_porto = 0;
  for (int i = 0; i < largura; i++){
    if(*(matrizPointer+(largura*x)+i) == 1 ){
      achou_porto = 1;
    }
  } 
  if (achou_porto == 1){
    return 1;
  }
  return 0;
}

int detectar_portos_na_linha_de_cima(int altura, int largura, int *matrizPointer, int y, int cimas_da_linha){
  int achou_porto = 0;
  int soma_sei_la = cimas_da_linha;
  if(soma_sei_la > altura || soma_sei_la < 0){
    return 0;
  }
  if(cimas_da_linha != 0){
      for (int i = 0; i < largura; i++){
        if (*(matrizPointer+((soma_sei_la-1)*largura)+i) == 1){
          achou_porto = 1;
        }
      } 
      if (achou_porto == 1){
        return 1;
      }
  }else if(cimas_da_linha == 0){ 
      for (int i = 0; i < largura; i++){
        if (*(matrizPointer+((soma_sei_la)*largura)+i) == 1 ){
          achou_porto = 1;
        }
      } 
      if (achou_porto == 1){
        return 1;
      }else{
        return 0;
      }
  }
  cimas_da_linha = cimas_da_linha - 1;
  return detectar_portos_na_linha_de_cima(altura, largura,  matrizPointer, y, cimas_da_linha);
}

int detectar_portos_na_linha_de_baixo(int altura, int largura, int *matrizPointer, int y, int baixo_da_linha){
  int achou_porto = 0;
  int soma_sei_la = baixo_da_linha;
  if(soma_sei_la >= altura || soma_sei_la < 0){
    return 0;
  }
  for (int i = 0; i < largura; i++){
    if (*(matrizPointer+(soma_sei_la*largura)+i) == 1){
      achou_porto = 1;
    }
  } 
  if (achou_porto == 1){
    return 1;
  }
  baixo_da_linha = baixo_da_linha + 1;
  return detectar_portos_na_linha_de_baixo(altura, largura,  matrizPointer, y, baixo_da_linha); 
}

char *esquerda_ou_direita_pro_porto (int linhas, int colunas, int *matrizPointer, int y, int x){
  int retornoFuncao;
  int maior = 0;
  int peixe;
  int saldo = 0;
  
if(*(matrizPointer+(colunas*x)+y) == 1){
    return "SELL";
  }
  if(y!= 0){ 
      for(int i = 0; i <= y-1; i++){
           if(*(matrizPointer+(colunas*x)+i) == 1){ 
                return "LEFT";      
              }
      } 
    }
int casas_antes_do_y = colunas;
for(int i = y + 1; i <= colunas; i++){
    if(*(matrizPointer+(colunas*x)+i) == 1){
        return "RIGHT";       
    }
}
}