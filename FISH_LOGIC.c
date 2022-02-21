#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 50

#include "MOVE_FISH.h"
#include "MOVE_HARBOR.h"
#include "MANO.h"
#include "MOVE_BUSY.h"

void logica_dos_portos(int *matrizPointer,char comando[10], char resultadoPorto[10],int *peso_barco_ponteiro, int x, int y, int multa_OUT, int altura, int largura, int * vetorXY, int *vetorLinhaCopy, char *comeback_ponteiro[10], int *variavelAcionada_Ponteiro){
    char *ta_na_linha;
    int saldo;
    int result = detectar_porto_na_linha(altura, largura,matrizPointer,y,x);
    if (result == 1){
       ta_na_linha = esquerda_ou_direita_pro_porto(altura,largura, matrizPointer, y, x);
       if(strcmp(ta_na_linha,"SELL") == 0){
        printf("SELL\n");
        scanf("%i", &saldo);
        *(peso_barco_ponteiro) = 0;
       }else if (strcmp(ta_na_linha,"LEFT") == 0){
         ler_e_executar_comando(ta_na_linha,x,y,altura,largura,vetorXY,matrizPointer, vetorLinhaCopy, comeback_ponteiro,variavelAcionada_Ponteiro);
       }else if (strcmp(ta_na_linha,"RIGHT") == 0){
         ler_e_executar_comando(ta_na_linha,x,y,altura,largura,vetorXY,matrizPointer, vetorLinhaCopy, comeback_ponteiro,variavelAcionada_Ponteiro);
       }
    } else{
      if(x-1 >= 0){ 
        result = detectar_portos_na_linha_de_cima(altura,largura,matrizPointer,y, x);
        }else{
          result = 0;
        }
        if(result == 1){
          ler_e_executar_comando("UP",x,y,altura,largura,vetorXY,matrizPointer,vetorLinhaCopy, comeback_ponteiro, variavelAcionada_Ponteiro);
        }
        if(result == 0){
          result = detectar_portos_na_linha_de_baixo(altura, largura,matrizPointer,y, x+1); 
          if(result == 1){
            ler_e_executar_comando("DOWN",x,y,altura,largura,vetorXY,matrizPointer, vetorLinhaCopy, comeback_ponteiro,variavelAcionada_Ponteiro);
    }
  }
}
  }

bool logica_dos_peixes(int *matrizPointer,char comando[10], char resultadoFish[10],int *peso_barco_ponteiro, int x, int y, int multa_OUT, int altura, int largura, int * vetorXY, int *vetorLinhaCopy, char *comeback_ponteiro[10], int *variavelAcionada_Ponteiro, bool EstouPescando){
   int result;
      char * acao_funcao;
      int peixe;
      int flag = 0;
      result = detectar_peixes_na_linha(altura, largura,matrizPointer,y,x);
      if(result == 1){ 
        if(EstouPescando == true && (*(matrizPointer+(largura*x)+y) >= 12 && *(matrizPointer+(largura*x)+y) <= 19 || *(matrizPointer+(largura*x)+y) >= 22 && *(matrizPointer+(largura*x)+y) <= 29 || *(matrizPointer+(largura*x)+y) >= 32 && *(matrizPointer+(largura*x)+y) <= 39)){ 
        acao_funcao = "FISHING";
        }else{
          acao_funcao = locomove_esquerda_ou_direita(altura,largura, matrizPointer, y, x);
        }
        strcpy(comando, acao_funcao);
        if(strcmp(acao_funcao,"FISHING")==0){
          EstouPescando = true;
          peixe = qual_peixe(altura,largura,matrizPointer,y, x);
          if(peixe == 1 && *(peso_barco_ponteiro) <= 10){
            *(peso_barco_ponteiro) = *(peso_barco_ponteiro) + 1;
            printf("FISH\n");
            scanf("%s",&resultadoFish);
          }else if(peixe == 2 && *(peso_barco_ponteiro) <= 10){
            *(peso_barco_ponteiro) = *(peso_barco_ponteiro) + 1;
            printf("FISH\n");
            scanf("%s",&resultadoFish);
          }else if(peixe == 3 && *(peso_barco_ponteiro) <= 10){
            *(peso_barco_ponteiro) = *(peso_barco_ponteiro) + 1;
            printf("FISH\n");
            scanf("%s",&resultadoFish);
          }else{
            EstouPescando = false;
          }
        }else{ 
          ler_e_executar_comando(comando,x,y,altura,largura, vetorXY,matrizPointer,vetorLinhaCopy,comeback_ponteiro, variavelAcionada_Ponteiro);
        }
      }else{
        if(x-1 >= 0){ 
           result = detectar_peixes_na_linha_de_cima(altura,largura,matrizPointer,y, x);   
        }else{
          result = 0;
        }
      if(result == 0){
        result = detectar_peixes_na_linha_de_baixo(altura, largura,matrizPointer,y, x+1); 
        if(result == 1){
          ler_e_executar_comando("DOWN",x,y,altura,largura,vetorXY,matrizPointer, vetorLinhaCopy,comeback_ponteiro,variavelAcionada_Ponteiro);
        }
      }else if(result == 1){
   ler_e_executar_comando("UP",x,y,altura,largura,vetorXY,matrizPointer,vetorLinhaCopy,comeback_ponteiro, variavelAcionada_Ponteiro);
      }
    }
  return EstouPescando;
}