/*13. Implemente em linguagem C uma função em um programa de computador que leia n valores do tipo float e os apresente em ordem crescente. Utilize alocação dinâmica de memória para realizar a tarefa. */

#include <stdio.h>
#include <stdlib.h>
 
void ordemCrescente(float *p, int tam){
float aux;
for(int i = 0; i<tam; i++){
  for(int j = i+1; j<tam; j++){
      if(p[i]>p[j]){
        aux = p[i];
        p[i] = p[j];
        p[j] = aux;
      }
  }
}
}
 
int main(){
   int tam;
   float *vet;
 
   printf("Digite o tamanho do vetor: ");
   scanf("%d", &tam);
 
   vet = malloc(tam * sizeof(float));
 
   if(vet){
       for(int i = 0; i < tam; i++){
          printf("Digite número: ");
           scanf("%f", (vet + i));
       }
 
       ordemCrescente(vet, tam);
 
       for(int i = 0; i < tam; i++){
           printf("%f ", *(vet + i));
       }
     
   }
   free(vet);
   return 0;
}
