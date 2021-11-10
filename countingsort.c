/*

Implementação de um counting sort em C

> Criam-se dois vetores auxiliares, B e C
> No vetor C, serão inseridos em cada índice a quantidade de números iguais ou menores
que o valor do índice que aparecem no vetor A
> Percorre-se o vetor A, e verifica em cada elemento, qual o valor deste elemento no indice
de mesmo número no vetor C. Este valor será a posição ordenada do elemento do vetor A, que
será inserido no vetor B
> Retorna o vetor B ordenado

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAMANHO_VETOR 10

// função simples que mostra o vetor na tela
void mostra_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void counting_sort(int a[], int tamanho)
{
    int b[tamanho];
    int c[tamanho];

    // inicializa o vetor auxiliar C com valores 0
    for (int i  = 0; i < tamanho; i++)
    {
        c[i] = 0;
    }

    // incrementa o valor de cada indice em C de acordo com sua ocorrencia no vetor A
    for (int j = 0; j < tamanho; j++)
    {
        c[a[j]]++;
    }
    
    /* printf("Vetor C (1): \n");
    mostra_vetor(c, tamanho);
    printf("\n"); */    

    // cada indice de C agr conterá o número de aparições de valores iguais ou menor que ele no vetor A
    for (int k = 1; k < tamanho; k++)
    {
        c[k] += c[k - 1];
    }

    /* printf("Vetor C (2):\n");
    mostra_vetor(c, tamanho);
    printf("\n"); */

    // coloca no vetor B, o valor de cada elemento em A de acordo com seu indice em C
    // e decrementa em um este indice de C cada vez que um elemento for "retirado" de lá
    for (int l = tamanho - 1; l >= 0; l--)
    {
        b[c[a[l]] - 1] = a[l];
        c[a[l]]--;
    }

    // agora, basta passar os valores de B para A
    for (int m = 0; m < tamanho; m++)
    {
        a[m] = b[m];
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
    
    // cria um vetor aleatório desordenado com elementos de 0 a k
    int vetor[TAMANHO_VETOR];
    for(int i = 0; i < TAMANHO_VETOR; i++)
    {
        vetor[i] = rand( ) % TAMANHO_VETOR;
    }

    printf("Mostrando vetor gerado: \n");
    mostra_vetor(vetor, TAMANHO_VETOR);
    printf("\n");
    Sleep(1500);

    printf("Ordenando vetor...\n");
    counting_sort(vetor, TAMANHO_VETOR);
    Sleep(1500);

    printf("Mostrando vetor ordenado: \n");
    mostra_vetor(vetor, TAMANHO_VETOR);
    printf("\n");

    // Sleep(1500);
    // valida_ordenacao(vetor, TAMANHO_VETOR);

    return 0;
}