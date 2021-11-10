/*

Bubble Sort em C++

O algoritmo baseia-se em comparar elementos adjacentes e mudá-los de posição
caso estejam desordenados

> Recebe-se uma lista desordenada
> O algoritmo percorre toda a lista, comparando elementos adjacentes
> Ao término da iteração, o elemento de maior valor deve estar na última posição
> A iteração continua se repetindo, cada vez excluíndo um elemento do final da
lista, já que este elemento já está ordenado
> Quando só sobrar mais um elemento, ou não for feita mais nenhuma troca, o algoritmo
se encerra
> O resultado será uma lista ordenada

Obs: O algoritmo realiza uma ordenação CRESCENTE. Para que ele realize uma ordenação
decrescente, leia os comentários da função bubble_sort() e valida_ordenacao()

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAMANHO_VETOR 10

// Função simples que percorre um vetor e mostra os elementos na tela
void mostra_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
}

// Função simples que valida se o vetor está de fato ordenado
// Percorrendo o vetor e verificando se algum número está fora do lugar
// Ajuda a validar a ordenação, especialmente em vetores muito grandes
void valida_ordenacao(int vetor[], int tamanho)
{
    for (int i = 1; i < tamanho; i++)
    {
        // Para mudar a validação para uma ordenação DECRESCENTE, muda o sinal de "<" abaixo por um ">"
        if (vetor[i] < vetor[i - 1])
        {
            printf("O vetor NAO esta ordenado\n");
            return;            
        }
    }

    printf("O vetor esta SIM ordenado\n");
}

void bubble_sort(int vetor[], int tamanho)
{
    // Conta quantos elementos do array serão iterados na execução do loop
    int contador = tamanho - 1;
    // Contará quantas trocas ocorrerão em casa execução
    // Se seu valor for zero ao final da execução, o código para
    int trocas = 1;
    // Variável auxilar para troca de elementos
    int temp = 0;

    // A iteração ocorrerá enquanto houverem elementos para serem ordenados
    while(contador > 1 || trocas != 0)
    {
        // Caso todos os elementos estejam ordenados, essa variável permanecerá
        // Sendo igual a zero, e encerrará a execução
        trocas = 0;
        
        // Itera pelos elementos que ainda não foram ordenados
        for (int i = 0; i < tamanho; i ++)
        {
            // Para uma ordenação DECRESCENTE, altere o ">" abaixo por um "<"
            if (vetor[i] > vetor[i + 1])
            {
                // Simples troca de posição, no caso dos elementos comparados estarem desordenados
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                // Aumentamos o valor de trocas para informar que o código ainda deve ser executado
                trocas++;
            }
        }
        // Diminuímos o tamanho de contador, uma vez que o último elemento estará ordenado com certeza
        contador--;
    }
}

// A função main criará um vetor de elementos aleatórios, informará ao usuário o vetor criado
// chamará a ordenação, e então mostrará ao usuário o vetor ordenado
// e por fim, deve validar se a ordenação de fato ocorreu
int main()
{
    srand(time(NULL));
    int vetor[TAMANHO_VETOR];
    
    for(int i = 0 ; i < TAMANHO_VETOR; i++)
        vetor[i] = rand() % TAMANHO_VETOR;

    printf("Vetor originado: \n");
    mostra_vetor(vetor, TAMANHO_VETOR);
    printf("\n");

    Sleep(1500);
    printf("Ordenando vetor...\n");
    bubble_sort(vetor, TAMANHO_VETOR);

    Sleep(1500);
    printf("Vetor ordenado: \n");
    mostra_vetor(vetor, TAMANHO_VETOR);
    printf("\n");

    valida_ordenacao(vetor, TAMANHO_VETOR);

    return 0;
}