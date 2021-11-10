/*

1) O que é o problema da seção crítica? Dê exemplos de situações onde tal problema
acontece.

O problema de seção crítica é quando mais de uma thread que se executam de maneira síncrona
alteram o valor de uma variável global. Isto ocorre pois os comandos de buscar um conteúdo
na memória principal e alterar seu valor NÃO são atômicos, ou seja, não são executados ao mesmo
tempo. Portanto, o tempo em que uma Thread, que, por exemplo, deseja acrescer em um
o valor de uma variável global por uma quantidade N de vezes, leva entre buscar uma informação na memória
principal (que seria um comando) e sobescrever o valor novo nesse mesmo espaço de memória (que seria
outro comando distinto), uma outra thread pode sobrescrever este valor com a operação que ela mesma
executou, efetivamente anulando a execução recém feita da thread, uma vez q as duas realizaram a
operação de incremento no mesmo valor (em vez de cada uma fazer num valor distinto após receber
o incremento).
Uma forma de evitar esse problema seria usando uma semáforos, que bloqueiam o acesso de uma região
crítica da memória enquanto uma thread a estiver acessando.
O código abaixo representa uma situação em que o problema da seção crítica ocorre.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <time.h>

#define QTD_THREADS 500
#define QTD_ADD 1000

long var_global;

void *funcao_thread(void *param)
{
    long id = (long)param;
    printf("[%d] Thread criada!\n", id);

    for (int i = 0; i < QTD_ADD; i++)
    {
        __sync_fetch_and_add(&var_global, 1);
        var_global++;
        //var_global = var_global + 1;
    }

    printf("[%d] Thread finalizando...\n", id);
    pthread_exit((void *)var_global);
}

int main(void)
{
    pthread_t threads[QTD_THREADS];
    int result[QTD_THREADS];

    var_global = 0;

    for (long i = 0; i < QTD_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, funcao_thread, (void *)i);
    }

    for (int i = 0; i < QTD_THREADS; i++)
    {
        pthread_join(threads[i], (void *)&result[i]);
        printf("[main] resultado recebido da thread %ld: %d\n",
               i, result[i]);
    }

    printf("[main] Valor final da variavel global = %d\n", var_global);

    return 0;
}