#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 50

#include "MOVE_BUSY.h"
#include "MOVE_HARBOR.h"
#include "MANO.h"
#include "FISH_LOGIC.h"

int esquerda_ou_direita (int altura, int largura, int *matrizPointer, int y, int x, int pontodePesca){
  int retornoFuncao;
  int maior = 0;
  int peixe;
  
if(*(matrizPointer+(largura*x)+y) == pontodePesca){
    peixe = qual_peixe(altura,largura,matrizPointer,y,x); 
    if(peixe > maior){
      maior = peixe;
      retornoFuncao = 0;
    }
         
}
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

char * locomove_esquerda_ou_direita(int altura, int largura, int *matrizPointer, int y, int x){ 
  int vetorLinha[largura];
  int retornoFuncao = 0;
  
  for(int j = 0; j < largura; j++){
    vetorLinha[j] = *(matrizPointer+(largura*x)+j);
    if(vetorLinha[j] == 21 || vetorLinha[j] == 11 || vetorLinha[j] == 31 || vetorLinha[j] == 10 || vetorLinha[j] == 20 || vetorLinha[j] == 30 || vetorLinha[j] == 1){ 
      vetorLinha[j] = 0;
    }
  }
  int pontodePesca = 0;
  for(int j = 0; j < largura; j++){
    if(vetorLinha[j] > pontodePesca){
      pontodePesca = vetorLinha[j];
      fprintf(stderr,"PontoPesca = %d\n",pontodePesca);
    }
  }
  retornoFuncao = esquerda_ou_direita(altura,largura, matrizPointer,y,x, pontodePesca);
  
  if(retornoFuncao == 0){
    return "FISHING";
  }else if(retornoFuncao < 0){
    return "LEFT";
  }else if(retornoFuncao > 0){
    return "RIGHT";
  }

}

int detectar_peixes_na_linha(int altura, int largura, int *matrizPointer, int y, int x){
  int achou_peixe = 0;
  for (int i = 0; i < largura; i++){
    if(*(matrizPointer+(largura*x)+i) >= 12 && *(matrizPointer+(largura*x)+i) <= 19 || *(matrizPointer+(largura*x)+i) >= 22 && *(matrizPointer+(largura*x)+i) <= 29 || *(matrizPointer+(largura*x)+i) >= 32 && *(matrizPointer+(largura*x)+i) <= 39){
      achou_peixe = 1;
    }
  } 
  if (achou_peixe == 1){
    return 1;
  }
  return 0;
}

int detectar_peixes_na_linha_de_cima(int altura, int largura, int *matrizPointer, int y, int cimas_a_linha){
  int achou_peixe = 0;
  int soma_sei_la = cimas_a_linha; 
  if(soma_sei_la > altura || soma_sei_la < 0){
    return 0;
  }
  if(cimas_a_linha != 0){
      for (int i = 0; i < largura; i++){
        if (*(matrizPointer+((soma_sei_la-1)*largura)+i) >= 12 && *(matrizPointer+((soma_sei_la-1)*largura)+i) <= 19 || *(matrizPointer+((soma_sei_la-1)*largura)+i) >= 22 && *(matrizPointer+((soma_sei_la-1)*largura)+i) <= 29 || *(matrizPointer+((soma_sei_la-1)*largura)+i) >= 32 && *(matrizPointer+((soma_sei_la-1)*largura)+i) <= 39 ){
          achou_peixe = 1;
        }
      } 
      if (achou_peixe == 1){
        return 1;
      }
  }else if(cimas_a_linha == 0){ 
      for (int i = 0; i < largura; i++){
        if (*(matrizPointer+((soma_sei_la)*largura)+i) >= 12 && *(matrizPointer+((soma_sei_la)*largura)+i) <= 19 || *(matrizPointer+((soma_sei_la)*largura)+i) >= 22 && *(matrizPointer+((soma_sei_la)*largura)+i) <= 29 || *(matrizPointer+((soma_sei_la)*largura)+i) >= 32 && *(matrizPointer+((soma_sei_la)*largura)+i) <= 39){
          achou_peixe = 1;
        }
      } 
      if (achou_peixe == 1){
        return 1;
      }else{
        return 0;
      }
  }
  cimas_a_linha = cimas_a_linha - 1;
  return detectar_peixes_na_linha_de_cima(altura, largura,  matrizPointer, y, cimas_a_linha);
}

int detectar_peixes_na_linha_de_baixo(int altura, int largura, int *matrizPointer, int y, int baixo_da_linha){
  int achou_peixe = 0;
  int soma_sei_la = baixo_da_linha;
  if(soma_sei_la >= altura || soma_sei_la < 0){
    return 0;
  }
  for (int i = 0; i < largura; i++){
    if (*(matrizPointer+(soma_sei_la*largura)+i) >= 12 && *(matrizPointer+(soma_sei_la*largura)+i) <= 19 || *(matrizPointer+(soma_sei_la*largura)+i) >= 22 && *(matrizPointer+(soma_sei_la*largura)+i) <= 29  && *(matrizPointer+(soma_sei_la*largura)+i) >= 32 && *(matrizPointer+(soma_sei_la*largura)+i) <= 39){
      achou_peixe = 1;
    }
  } 
  if (achou_peixe == 1){
    return 1;
  }
  baixo_da_linha = baixo_da_linha + 1;
  return detectar_peixes_na_linha_de_baixo(altura, largura,  matrizPointer, y, baixo_da_linha); 
}

