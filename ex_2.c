/*

2) Relacione o controle do ciclo de vida de threads a partir da API POSIX Threads
(PThreads) com o problema da seção crítica e cite uma forma de usar recursos da 
API PThreads para contornar este problema.

R) O ciclo de vida de uma Thread envolve três estados: Pronto, executando, ou em espera.
Usando a API PTreadh, ao usar a chamada pthread_create(), uma thread já estará 
efetivamente pronta caso não ocorra um erro com a chamada. A chamada pthread_join(), por sua vez,
inicia a execução de uma thread e portanto a leva para o estado em execução. Por fim,
uma chamada pthread_exit() encerrará a execução de uma thread e portanto o ciclo de vida
da thread chega ao fim. O problema deste ciclo, é que no caso de um problema da seção crítica,
precisaremos que a thread passe para o estado de espera antes de entrar numa região crítica da
memória, caso alguma outra thread já esteja a acessando. Para isso, podem ser usados os métodos
pthread_mutex_lock e pthread_mutec_unlock para respectivamente levar uma thread ao estado de
em espera, e retorná-la ao estado de execução antes de entrar na região crítica.

pthread_create() -> Cria uma Thread em estado de "Pronto" 
pthread_join() -> Passa a Thread de estado "Pronto" para "Executando"
pthread_mutex_lock() -> Em aguardo
pthread_mutex_unlock() -> Prosseguir
pthread_exit() -> Passa a Thread para o estado "Finalizado"

*/

#include <stdio.h.>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <windows.h>

#define QTD_THREADS 500
#define QTD_ADD 100

long var_global;
pthread_mutex_t mutex;

void *funcao_thread(void *param)
{
    long id = (long)param;
    printf("[%d] Thread criada!\n", id);

    for (int i = 0; i < QTD_ADD; i++)
    {
        pthread_mutex_lock(&mutex);
        var_global++;
        pthread_mutex_unlock(&mutex);
    }

    printf("[%d] Thread finalizando...\n", id);
    pthread_exit((void *)var_global);
}

int main(void)
{
    pthread_t threads[QTD_THREADS];
    int result[QTD_THREADS];
    pthread_mutex_init(&mutex, NULL);

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

    pthread_mutex_destroy(&mutex);
    printf("[main] Valor final da variavel global = %d\n", var_global);

    return 0;
}