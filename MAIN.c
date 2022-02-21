#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 50

#include "MOVE_FISH.h"
#include "MOVE_HARBOR.h"
#include "MANO.h"
#include "MOVE_BUSY.h"
#include "FISH_LOGIC.h"


char *locomocao[4][10] = {
  "RIGHT",
  "LEFT",
  "UP",
  "DOWN",
};


int main(){
  char IdBOT[MAX_STR]; 
  setbuf(stdin, NULL); 
  setbuf(stdout, NULL); 
  setbuf(stderr, NULL);
  
  int altura, largura;
  scanf("AREA %i %i", &altura, &largura); 
  scanf(" ID %s", IdBOT);   
  int *vetorLinhaCopy = malloc(largura * sizeof(int));
    int *vetorXY = malloc(2 * sizeof(int)); 
    char comando[10];
    char resultadoComando[10];
    char resultadoFish[10];
    int *matrizPointer = malloc((altura*largura) * sizeof(int));
    int x,y;
    int *peso_barco_ponteiro, peso_barco ;
    bool EstouPescando = false;
    peso_barco_ponteiro = &peso_barco;
    int multa_OUT = 0;
    int saldo = 0;
    char *comeback_ponteiro[10], comeback[10];
    *(comeback_ponteiro) = comeback;
    int *variavelAcionada_Ponteiro, variavelAcionada = 0;
    variavelAcionada_Ponteiro = &variavelAcionada;
    int s = 0;
    while(1){
      setbuf(stdin, NULL); 
  setbuf(stdout, NULL); 
  setbuf(stderr, NULL);
      matrizPointer = NULL; 
      matrizPointer = malloc((altura*largura) * sizeof(int));
      vetorXY = malloc(2 * sizeof(int)); 
      readData(altura, largura, IdBOT,vetorXY,matrizPointer,0);
       x = *(vetorXY+0);
      y = *(vetorXY+1);    
      
    if(variavelAcionada == 1){
        funcBUSY(x,y,s,largura,altura,matrizPointer);
        variavelAcionada = 0;
        s++;
      }else{
        if(peso_barco >= 10){ 
          logica_dos_portos(matrizPointer,comando,resultadoFish,peso_barco_ponteiro, x, y,multa_OUT,altura,largura,vetorXY, vetorLinhaCopy, comeback_ponteiro, variavelAcionada_Ponteiro);
        }else{
          EstouPescando = logica_dos_peixes(matrizPointer,comando,resultadoFish,peso_barco_ponteiro, x, y,multa_OUT,altura,largura,vetorXY, vetorLinhaCopy,comeback_ponteiro, variavelAcionada_Ponteiro,EstouPescando);
                
        }
      }
      matrizPointer = NULL; 
      vetorXY = NULL;
  }
  
  free(vetorXY);
  free(vetorLinhaCopy);
  return 0;
}
