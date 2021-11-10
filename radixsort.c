/*

Implementação de um radix sort em C

> Baseado no counting sort, mas podendo ser usado para vetores com números com grandes
diferenças entre si
> Realiza a ordenação de cada elemento baseado em suas casas decimais
> Ordena primeiro a casa das unidades, então dezenas, e assim sucessivamente
> Ao término da ordenação da última casa decimal, o vetor estará ordenado

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAMANHO_VETOR 10
// o valor a seguir deve ser um número múltiplo de 10
#define VALOR_MAXIMO 1000

// função simples que mostra o vetor na tela
void mostra_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
}

// função de radix sort, baseada no algoritmo de counting sort
void radix_sort(int a[], int tamanho, int divisor)
{
    // vetor auxiliar que conterá os elementos ordenadamente
    int b[tamanho];

    // vetor que auxiliará na contagem
    int c[tamanho];

    // vetor que conterá os valores apenas da casa decimal importante para a operação
    int d[tamanho];

    // variável que guardará em que casa decimal estamos fazendo a iteração
    // ela será multiplicada por 10 a cada execução
    int div = 10;

    int temp;
    // o laço de repetição a seguir implementa o counting sort começando na base 10^0
    // e segue repetindo com bases maiores de 10 até que cheguemos num número maior
    // do que os dos elementos do vetor
    while(div <= divisor)
    {
        // inicializa o vetor C com elementos vazios, e D com o digito referência para esta iteração
        for (int i = 0; i < tamanho; i++)
        {
            temp = a[i] % div;
            temp -= a[i] % (div/10);
            temp = temp/(div/10);
            d[i] = temp;
            c[i] = 0;
        }

        // incrementa os indices de C para cada aparição destes no vetor D
        for (int i = 0; i < tamanho; i++)
        {
            c[d[i]]++;
        }

        // cada índice de C contará a quantidade de vezes que um número menor ou igual a ele
        // apareceu no vetor D
        for (int i = 1; i < tamanho; i++)
        {
            c[i] += c[i - 1];
        }

        // insere em B o elemento em sua posição ordenada
        for (int i = tamanho - 1; i >= 0; i--)
        {
            b[c[d[i]] - 1] = a[i];
            c[d[i]]--;
        }

        // multiplicamos div por 10 para irmos para a próxima casa decimal
        div = div * 10;

        // atribuímos o valor ordenado ao vetor original
        for (int i = 0; i < tamanho; i++)
        {
            a[i] = b[i];
        }
    }        
}

// função simples de validação, que mostra ao usuario que o vetor NAO está ordenado
// caso exista um número maior que seu sucessor
void valida_ordenacao(int vetor[], int tamanho)
{
    for(int i = 0; i < tamanho - 1; i++)
    {
        if (vetor[i] > vetor[i+1])
        {
            printf("O vetor NAO esta ordenado\n");
            return;
        }
    }

    printf("O vetor esta SIM ordenado\n");
}

int main (void)
{

    // para que possamos usar valores aleatórios
    srand(time(NULL));
    
    // cria um vetor aleatório desordenado com elementos com grandes diferenças entre si
    int vetor[TAMANHO_VETOR];
    for(int i = 0; i < TAMANHO_VETOR; i++)
    {
        vetor[i] = rand( ) % VALOR_MAXIMO;
    }

    printf("Mostrando vetor gerado: \n");
    mostra_vetor(vetor, TAMANHO_VETOR);
    printf("\n");
    Sleep(1500);

    printf("Ordenando vetor...\n");
    radix_sort(vetor, TAMANHO_VETOR, VALOR_MAXIMO);
    Sleep(1500);

    printf("Mostrando vetor ordenado: \n");
    mostra_vetor(vetor, TAMANHO_VETOR);
    printf("\n");

    // Sleep(1500);
    // valida_ordenacao(vetor, TAMANHO_VETOR);

    return 0;
}