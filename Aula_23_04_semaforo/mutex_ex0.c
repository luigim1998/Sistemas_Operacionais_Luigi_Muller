#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
int counter;

pthread_mutex_t lock;

void * try(void * arg){
    
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d Ini\n", counter);

    for(i = 0; i < (0xFFFFFFFF); i++);

    printf("\n Job %d Fim\n", counter);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(){
    int i = 0;
    int err;

    if(pthread_mutex_init(&lock, NULL)){ //se voltar algo diferetne disso ele não conseguiu iniciar o semaforo
        return 1;
    }

    while(i < 2){
        err = pthread_create(&tid[i], NULL, &try, NULL);
        if(err != 0)
            return 1;
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    pthread_mutex_unlock(&lock);
}