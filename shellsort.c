/*

Implementação de um Shell Sort em C
Obs: O algoritmo retorna um vetor ordenado de forma crescente
Para ordenar de forma decrescente, basta alterar a linha 55
trocando o sinal de > por <.
A mesma troca deve ser feita no validador, na linha 70

> Cria um vetor desordenado com elementos aleatórios
> Mostra o vetor na tela
> Cria uma chave recursivamente usando a seguinte fórmula:
    - h(s) = 3h(s - 1) + 1, para s > 1
    - h(s) = 1, para s = 1
> Compara os elementos do vetor com uma distância igual a h, com o maior h possível
> Compara novamente com valores menores de h, até h = 1
> Devolve o vetor ordenado
> Mostra na tela o vetor ordenado

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAMANHO 15

// Função para mostrar elementos de um array
int mostra_vetor(int vetor[], int v_tamanho)
{    
    for (int i = 0; i < v_tamanho; i++)
        printf("%d ", vetor[i]);
}

// recebe um array desordenado, seu tamanho e uma chave inicial, que é setada como 1
// para então devolver um array ordenado
void shell_sort(int vetor[], int v_tamanho, int chave)
{
    // a execução para quando for encontrada uma chave maior que o vetor
    if (chave < v_tamanho)
    {
        // chama recursivamente a operação, usando uma chave maior
        shell_sort(vetor, v_tamanho, (3 * chave) + 1);
        
        // percorrerá os elementos de um array e fará as comparações com um elemento
        // a uma distância h dele (representado por 'chave' neste código)
        for (int i = chave; i < v_tamanho; i++)
        {
            int indice = i;
            int temp = vetor[i];

            // compara o elemento com todos os elementos anteriores a ele por uma distância h
            // e o leva para a posição mais ao inicio possível, enquanto ainda hoverem elementos
            // maiores que ele antes dele a uma distância h
            while (indice >= chave && temp < vetor[indice - chave])
            {
                vetor[indice] = vetor[indice - chave];
                indice -= chave;
            }
            vetor[indice] = temp;
        }
    }
}

// função que valida a ordenação
void valida_sort(int vetor[], int v_tamanho)
{
    for (int i = 0; i > v_tamanho - 1; i++)
    {
        if (vetor[i] < vetor[i + 1])
        {
            printf("O vetor NAO esta ordenado\n");
            return;
        }
    }

    printf("O vetor esta SIM ordenado\n");
}

int main(void)
{
    // criação de um vetor de elementos aleatórios
    srand(time(NULL));
    int vetor[TAMANHO];
    for (int i = 0; i < TAMANHO; i++)
        vetor[i] = ((rand() % (TAMANHO * 3)) + 1);

    printf("Mostrando vetor criado:\n");
    mostra_vetor(vetor, TAMANHO);


    Sleep(2000);
    printf("\nordenando vetor...\n");
    shell_sort(vetor, TAMANHO, 1);
    Sleep(2000);

    printf("Mostrando vetor ordenado:\n");
    mostra_vetor(vetor, TAMANHO);

    Sleep(1000);
    printf("\n");
    valida_sort(vetor, TAMANHO);

    return 0;
}