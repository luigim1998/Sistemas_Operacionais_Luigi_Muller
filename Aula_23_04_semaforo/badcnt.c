#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int data = 0;

void * inc(){
    int a = data;
    a = a + 1;
    data = a;
}

void * dec(){
    int b = data;
    b = b - 1;
    data = b;
}

int main(){
    pthread_t tid1, tid2;
    if(pthread_create(&tid1, NULL, inc, NULL)){
        exit(1);
    }
    if(pthread_create(&tid2, NULL, dec, NULL)){
        exit(1);
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Data = %d\n", data);
    return 0;
}