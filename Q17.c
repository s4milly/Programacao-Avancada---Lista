/*17. Escreva uma fun��o em c que escreva em um vetor a soma dos elementos correspondentes de outros dois vetores (os tamanhos dos vetores devem ser fornecidos pelo usu�rio). Por exemplo, se o primeiro vetor contiver os elementos 1, 3, 0 e -2, e o segundo vetor contiver os elementos 3, 5, -3 e 1, o vetor de soma ter� valores resultantes iguais a 4, 8, -3 e -1. A fun��o deve receber 4 argumentos: os nomes dos tr�s vetores e o n�mero de elementos presentes em cada vetor.*/
 
 #include <stdio.h>
#include <stdlib.h>
 
void somaVetores(int *pa, int *pb, int *pc, int tam){
 for(int i=0; i<tam; i++){
   pc[i] = pa[i]+ pb[i];
 }
}
int main() {
 int *vetA, *vetB, *vetC, tam;
 
 printf("Digite o tamanho dos vetores: ");
 scanf("%d", &tam);
 
 vetA = malloc(tam * sizeof(int));
 vetB = malloc(tam * sizeof(int));
 vetC = malloc(tam * sizeof(int));
 
 for(int i=0; i<tam; i++){
   printf("Digite um n�mero para posi��o %d do vetor A: ", i+1);
   scanf("%d", vetA+i);
 }
  printf("\n");
 for(int i=0; i<tam; i++){
   printf("Digite um n�mero para posi��o %d do vetor B: ", i+1);
   scanf("%d", vetB+i);
 }
 
 somaVetores(vetA, vetB, vetC, tam);
 
 printf("\nVetor Soma: \n");
 for(int i=0; i<tam; i++){
   printf("%d\n", *(vetC+i));
 }
 free(vetC);
 free(vetB);
 free(vetA);
 return 0;
}
