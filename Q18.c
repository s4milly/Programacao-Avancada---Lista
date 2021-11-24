/* 18. Crie uma fun��o capaz de realizar multiplica��o matricial da forma C=A B. A fun��o deve receber 6 argumentos: os ponteiros para as matrizes A, B e C, o n�mero de linhas e colunas de A e o n�mero de colunas de B (assuma que o n�mero de coluna de A � igual ao n�mero de linhas de B). O resultado da multiplica��o deve ficar armazenado em C. Crie um programa para testar sua implementa��o, capaz de utilizar a fun��o de multiplica��o e imprimir as tr�s matrizes. A fun��o criada para multiplica��o n�o deve realizar nenhum tipo de sa�da de dados no terminal.*/

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