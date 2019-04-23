#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2];
int counter;

void *trythis(void *arg){
    counter += 1;
    printf("\n Job %d Ini\n", counter);
    //8x F
    for(unsigned long i=0; i<(0xFFFFFFFF); i++);
    
    printf("\n Job %d Fim\n", counter);
    
    return NULL;
}

int main(){
    int i = 0;
    int err;

    while(i < 2){
        err = pthread_create(&tid[i], NULL, &trythis, NULL);
        if(err != 0)
            exit(1);
        i++;
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}