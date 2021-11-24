/*14. Reimplemente o programa da questão anterior utilizando a função qsort() do C. Comente o seu código, explicando o que faz cada uma das linhas.*/

#include <stdio.h>
#include <stdlib.h>
 
int comparar(const void *x, const void *y){
   return ( *(int*)x - *(int*)y );
   //essa função foi feita para comparar os valores do vetor
   // se a diferença for positiva, então x é maior que y
  // se for negativa, então y é maior
  // já se for igual a 0, significa que x e y são iguais
}
 
int main(){
   int tam; //  declaração do tamanho do vetor
   float *vet; // declaração do ponteiro que será o vetor
 
   printf("Digite o tamanho do vetor: ");
   scanf("%d", &tam); // recebendo a entrada do tamanho
 
   vet = malloc(tam * sizeof(float)); // alocando a memória de vet
 
   if(vet){
       for(int i = 0; i < tam; i++){
          printf("Digite número: ");
           scanf("%f", (vet + i)); // preenchendo as posições do vetor
       }
 
       qsort(vet, tam, sizeof(float), comparar); // chamando a função qsort que organizará o vetor em ordem crescente. Essa tem como parâmetro o vetor, o tamanho, o sizeof e a função que foi criada para comparação
 
       for(int i = 0; i < tam; i++){
           printf("%f ", *(vet + i)); //imprimindo os valores do vetor em ordem
       }
     
   }
   free(vet);
   return 0;
}
