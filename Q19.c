/*19. Pesquise na Internet sobre o uso da biblioteca libGC, que implementa um coletor de lixo em C. O processo de instalação dessa biblioteca em sistemas Windows pode ser um pouco trabalhoso. Entretanto, em sistemas Unix, a instalação é bem simples, de sorte que se recomenda a resolução desta questão em uma máquina, por exemplo, com Linux instalado. Caso seja usuário Windows e não queira instalar sistemas alternativos em seu computador, use uma ferramenta de virtualização (ex: VirtualBox) para instalar e executar o Linux sem alterar a instalação original de seu computador. Prepare um pequeno programa-exemplo demonstrando como usar a biblioteca.*/

#include "gc.h" // necessário utilizar em todos os programs q possuem GC
#include <stdio.h>

int main(){
    int tam, *x, *y;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    GC_INIT(); 
    x = (int*) GET_malloc(tam * sizeof(int)); // GET_MALLOC tem //como função alocar a memória, mas diferente do malloc ele //limpar os espaço reservado antes da utilização 

    if(x){
          for(int i = 0; i < tam; i++){
            printf("Digite número: ");
              scanf("%d", (x + i));
          }

          for(int i = 0; i < tam; i++){
              printf("%d ", *(x + i));
          }
        
      }
      
      y = (int*) GET_malloc_atomic(sizeof(int)); //Aloca um objeto de um determinado tamanho que não contém ponteiros.
      if(y){
        printf("Memória alocada com sucesso");
      }
      else{
        printf("Erro na alocação de memória");
      }
    
    return 0;
}