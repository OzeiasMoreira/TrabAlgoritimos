#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar posição aleatoria para busca
int geraPosRandomBusca(int tam)
{
    return (rand() % tam);
}

// Função para preencher vetor 
void preencherVetor(int vetor[],int tam){
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = i;
    }
    
}

int main()
{
    FILE *fpiorcaso = fopen("iteracoesPiorCaso.txt", "w");
    FILE *fcasomedio = fopen("iteracoesCasoMedio.txt", "w");

    //Inicializa p gerador de numeros aleatorios
    srand(time(0));

    //Loop para variar o tamanho do vetor de 5000 a 50000,com incremento de 5000
    for (int tam = 5000; tam <= 50000; tam += 5000)
    {   
        // alocando a memoria para o vetor
        int *vetor = (int*)malloc(tam * sizeof(int));
        preencherVetor(vetor,tam);

        int x = -1;// elemento que não esta no vetor,representa o pior caso
        int iteracoes;

        //Busca sequencial no pior caso
        iteracoes = tam;
        fprintf(fpiorcaso,"Sequencia: %d,%d\n",tam , iteracoes);

        //Busca sequencial ordenada no pior caso
        iteracoes = tam;
        fprintf(fpiorcaso,"Sequencial ordenada: %d,%d\n",tam ,iteracoes);

        //Busca binaria no pior caso
        iteracoes = 0;
        int inicio = 0;
        int fim = tam - 1;
        while (inicio <= fim)
        {
            iteracoes++;
            int meio = inicio + (fim - inicio) / 2;
            if (vetor[meio] < x)
            {
                inicio = meio + 1;
            } else {
                fim = meio - 1;
            }
            
        }

        fprintf(fpiorcaso,"Binaria: %d,%d\n",tam,iteracoes);
        
        // Loop para realizar 30 buscas para o caso medio
        for (int k = 0; k < 30; k++)
        {
            x = geraPosRandomBusca(tam); // Gera um posição aleatoria para busca

            //Busca sequencial no caso medio
            iteracoes = 0;
            for (int i = 0; i < tam; i++)
            {
                iteracoes++;
                if (vetor[i] == x)
                {
                    break;
                }
                
            }
            
            fprintf(fcasomedio,"Sequencia: %d,%d\n",tam ,iteracoes);
        }

        //Busca sequencial ordenada no caso medio
        iteracoes = 0;
        for (int i = 0; i < tam; i++)
        {
            iteracoes++;
            if (vetor[i] == x || vetor[i] > x)
            {
                break;
            }

           fprintf(fcasomedio,"Sequencial ordenado: %d,%d\n",tam,iteracoes); 
        }
        
        //Busca binaria no caso medio
        iteracoes = 0;
        inicio = 0;
        fim = tam - 1;
        while (inicio <= fim)
        {
            iteracoes++; // Incrementa o contador a cada passo do loop
            int meio = inicio + (fim - inicio)/ 2; // calcula a posição do meio do vetor
            if (vetor[meio] == x)
            {
                break;
            }
            // se o valor é menor que x,ajusta o inicio da busca para meio + 1
            if (vetor[meio] < x)
            {
                inicio = meio + 1;
            } else { // Se o valor na posição meio é maior ou igual a x,ajusta o fim da busca para meio - 1
                fim = meio - 1;
            }
            
            fprintf(fcasomedio,"Binaria: %d,%d",tam , iteracoes);
        }
        
        // Libera a memoria alocada pelo vetor
        free(vetor);
    }
    
    fclose(fpiorcaso);
    fclose(fcasomedio);

    return 0;
}