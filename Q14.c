/*14. Reimplemente o programa da quest�o anterior utilizando a fun��o qsort() do C. Comente o seu c�digo, explicando o que faz cada uma das linhas.*/

#include <stdio.h>
#include <stdlib.h>
 
int comparar(const void *x, const void *y){
   return ( *(int*)x - *(int*)y );
   //essa fun��o foi feita para comparar os valores do vetor
   // se a diferen�a for positiva, ent�o x � maior que y
  // se for negativa, ent�o y � maior
  // j� se for igual a 0, significa que x e y s�o iguais
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
 
       qsort(vet, tam, sizeof(float), comparar); // chamando a fun��o qsort que organizar� o vetor em ordem crescente. Essa tem como par�metro o vetor, o tamanho, o sizeof e a fun��o que foi criada para compara��o
 
       for(int i = 0; i < tam; i++){
           printf("%f ", *(vet + i)); //imprimindo os valores do vetor em ordem
       }
     
   }
   free(vet);
   return 0;
}
