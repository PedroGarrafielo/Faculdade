/*

Algoritmo de Selection Sort em C

O algoritmo ordena os elementos buscando o maior (ou menor) elemento de um vetor
e trocando-o de lugar com o último elemento, repetindo esse processo sempre excluíndo
o último elemento que já estará ordenado

> É recebido um vetor desordenado
> Itera-se pelo vetor buscando o elemento de valor mais alto
> Ao encontrá-lo, troca-o de lugar pelo elemento na última posição
> Repete o processo, cada vez iterando por um elemento a menos, visto que
o último foi recém ordenado
> Ao final do processo, o vetor estará ordenado


Obs: O algoritmo ordenará o vetor de forma CRESCENTE. Para realizar a ordenação
decrescente, leia os comentários na função selection_sort() e valida_ordenacao().

*/

#include <stdio.h.>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Constante que consiste no tamanho do vetor
#define TAMANHO_VETOR 10

// Declarando funções
void mostra_lista(int vetor[], int tamanho, int ordenada);
void cria_lista(int vetor[], int tamanho);
void selection_sort(int vetor[], int tamanho);
void valida_ordenacao(int vetor[], int tamanho);

int main(void)
{
    // Para que possamos criar valores aleatórios
    srand(time(NULL));

    // Cria uma lista de valores aleatórios e desordenados
    int vetor[TAMANHO_VETOR];
    cria_lista(vetor, TAMANHO_VETOR);

    // Mostramos a lista antes de ordená-la
    mostra_lista(vetor, TAMANHO_VETOR, 0);
    Sleep(1500);

    // Ordenamos a lista
    printf("Ordenando vetor...\n");
    selection_sort(vetor, TAMANHO_VETOR);
    Sleep(1500);

    // Mostramos a lista ordenada
    mostra_lista(vetor, TAMANHO_VETOR, 1);
    Sleep(1500);

    // Avaliamos a ordenação
    valida_ordenacao(vetor, TAMANHO_VETOR);

    return 0;
}

// Função que mostra ao usuário o vetor passado
// ordenada = 1 -> vetor ordenado
// ordenada = 0 -> vetor desordenado
void mostra_lista(int vetor[], int tamanho, int ordenada)
{
    if (ordenada == 1)
        printf("Mostrando vetor ordenado:\n");
    else if (ordenada == 0)
        printf("Mostrando vetor desordenado:\n");
    
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    
    printf("\n");
}

// Preenche vetor com valores aleatórios
void cria_lista(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        vetor[i] = rand() % tamanho;
}

// Algoritmo de ordenação CRESCENTE
void selection_sort(int vetor[], int tamanho)
{
    // armazena o indice do maior elemento da lista
    int i_maior_valor = 0;
    // armazena o valor do maior elemento da lista
    int maior_valor = 0;
    // armazena quantos elementos devem participar da iteração    
    int qtd_elementos = tamanho - 1;

    // a iteração acontecerá enquanto houverem elementos para serem ordenados
    while(qtd_elementos > 1)
    {
        maior_valor = 0;
        // encontra o indice do elemento de maior valor na lista
        for (int i = 0; i <= qtd_elementos; i++)
        {
            
            if (vetor[i] > maior_valor)
            {
                maior_valor = vetor[i];
                i_maior_valor = i;
            }
        }

        // troca o elemento de maior valor de lugar com o último elemento possível
        // caso ele já não esteja lá
        if (i_maior_valor != (qtd_elementos)) 
        {
            vetor[i_maior_valor] = vetor[qtd_elementos];
            vetor[qtd_elementos] = maior_valor;
        }
        
        // reduzimos a quantidade de elementos que participará da próxima iteração
        qtd_elementos--;  
    }
}

// Função simples que valida se o vetor de fato foi ordenado
void valida_ordenacao(int vetor[], int tamanho)
{
    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] < vetor[i - 1])
        {
            printf("O vetor NAO esta ordenado\n");
            return;
        }
    }

    printf("O vetor esta SIM ordenado\n");
}