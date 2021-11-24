/*19. Pesquise na Internet sobre o uso da biblioteca libGC, que implementa um coletor de lixo em C. O processo de instala��o dessa biblioteca em sistemas Windows pode ser um pouco trabalhoso. Entretanto, em sistemas Unix, a instala��o � bem simples, de sorte que se recomenda a resolu��o desta quest�o em uma m�quina, por exemplo, com Linux instalado. Caso seja usu�rio Windows e n�o queira instalar sistemas alternativos em seu computador, use uma ferramenta de virtualiza��o (ex: VirtualBox) para instalar e executar o Linux sem alterar a instala��o original de seu computador. Prepare um pequeno programa-exemplo demonstrando como usar a biblioteca.*/

#include "gc.h" // necess�rio utilizar em todos os programs q possuem GC
#include <stdio.h>

int main(){
    int tam, *x, *y;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    GC_INIT(); 
    x = (int*) GET_malloc(tam * sizeof(int)); // GET_MALLOC tem //como fun��o alocar a mem�ria, mas diferente do malloc ele //limpar os espa�o reservado antes da utiliza��o 

    if(x){
          for(int i = 0; i < tam; i++){
            printf("Digite n�mero: ");
              scanf("%d", (x + i));
          }

          for(int i = 0; i < tam; i++){
              printf("%d ", *(x + i));
          }
        
      }
      
      y = (int*) GET_malloc_atomic(sizeof(int)); //Aloca um objeto de um determinado tamanho que n�o cont�m ponteiros.
      if(y){
        printf("Mem�ria alocada com sucesso");
      }
      else{
        printf("Erro na aloca��o de mem�ria");
      }
    
    return 0;
}