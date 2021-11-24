/*15.  Utilize a ideia do ponteiro para fun��o pela fun��o qsort() para implementar sua pr�pria fun��o de ordena��o. Para isso, sua fun��o dever� receber, entre outros argumentos, um ponteiro para a fun��o de compara��o.*/ 

#include <stdio.h>
#include <stdlib.h>
 
void ordenar(float  (*pf)(float, float), float *vet, int tam){
float aux;
for(int i = 0; i<tam; i++){
  for(int j = i+1; j<tam; j++){
      if(pf(vet[i], vet[j])> 0){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
  }
}
}
 
float comparar(float x, float y){
   return (x - y);
}
 
int main(){
   int tam; //  declara��o do tamanho do vetor
   float *vet; // declara��o do ponteiro que ser� o vetor
 
   printf("Digite o tamanho do vetor: ");
   scanf("%d", &tam); // recebendo a entrada do tamanho
 
   vet = malloc(tam * sizeof(float)); // alocando a mem�ria de vet
 
   if(vet){
       for(int i = 0; i < tam; i++){
          printf("Digite n�mero: ");
           scanf("%f", (vet + i)); // preenchendo as posi��es do vetor
       }
 
       ordenar(comparar, vet, tam); // chamando a fun��o ordenar 
 
       for(int i = 0; i < tam; i++){
           printf("%f ", *(vet + i)); //imprimindo os valores do vetor em ordem
       }
     
   } 
   free(vet);
   return 0;
}

