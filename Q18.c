/* 18. Crie uma função capaz de realizar multiplicação matricial da forma C=A B. A função deve receber 6 argumentos: os ponteiros para as matrizes A, B e C, o número de linhas e colunas de A e o número de colunas de B (assuma que o número de coluna de A é igual ao número de linhas de B). O resultado da multiplicação deve ficar armazenado em C. Crie um programa para testar sua implementação, capaz de utilizar a função de multiplicação e imprimir as três matrizes. A função criada para multiplicação não deve realizar nenhum tipo de saída de dados no terminal.*/

#include <stdio.h>
#include <stdlib.h>

void multiplicarMatriz(int **pa, int **pb, int **pc, int la, int ca,  int cb){
  int elemento = 0; 
    for(int l=0; l<la; l++){
    for(int c=0; c<cb; c++){
      for(int i=0; i<ca; i++){
        elemento = ((pa[l][i])*pb[i][c]) + elemento;
      }
      pc[l][c] = elemento;
      elemento = 0;
   }}
}

void imprimir(int **pa, int **pb, int **pc, int la, int ca, int cb){
  printf("\nMatriz A\n");
  for(int l=0; l<la; l++){
    for(int c=0; c<ca; c++){
      printf("%d ", *(*(pa + l) + c));
      
    }
    printf("\n");
  }
    printf("\nMatriz B\n");
    for(int l=0; l<ca; l++){ // lb = ca
    for(int c=0; c<cb; c++){
      printf("%d ", *(*(pb + l) + c));
    }
    printf("\n");
  }
    printf("\nMatriz C\n");
    for(int l=0; l<la; l++){
    for(int c=0; c<cb; c++){
      printf("%d ", *(*(pc + l) + c));
    }
    printf("\n");
  }
}
int main() {
  int la=2, ca = 3, lb=3, cb = 2; 
  // lc = la , cc = cb
  int **matrizA, **matrizB, **matrizC; 

  matrizA = malloc (la*sizeof(int*));
  matrizB = (int **) malloc (lb*sizeof(int*));
  matrizC = (int **) malloc (la*sizeof(int*));
  
  for(int i=0; i<la; i++){
    matrizA[i] =  malloc (ca*sizeof(int));
  }
  for(int i=0; i<lb; i++){
    matrizB[i] =  malloc (cb*sizeof(int));
  }
  for(int i=0; i<la; i++){
    matrizC[i] =  malloc (cb*sizeof(int));
  }

  for(int l=0; l<la; l++){
    for(int c=0; c<ca; c++){
      printf ("Insira o termo %dx%d da matriz A: ", l,c);
      scanf("%d", *(matrizA + l) + c);
    }
  }
  
  for(int l=0; l<lb; l++){
    for(int c=0; c<cb; c++){
      printf ("Insira o termo %dx%d da matriz B: ", l,c);
      scanf("%d", *(matrizB + l) + c);
    
    }
  }
  multiplicarMatriz(matrizA, matrizB, matrizC, la, ca, cb);
  imprimir(matrizA, matrizB, matrizC, la, ca, cb);
  
  for(int i=0; i<ca; i++){
    free(matrizA[i]);
  }
  for(int i=0; i<cb; i++){
    free(matrizB[i]);
  }
  for(int i=0; i<cb; i++){
   free(matrizC[i]);
  }
  free(matrizA);
  free(matrizB);
  free(matrizC);
  return 0;
}