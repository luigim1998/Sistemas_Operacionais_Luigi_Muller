#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define N 5
#define PENSAR 2
#define FAMINTO 1
#define COMENDO 0

#define LEFT (phnum + 4)%N
#define RIGHT (phnum + 1)%N

int state[N];
int phil[N] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];

void test(int phnum){
    if(state[phnum] == FAMINTO && state[LEFT] != COMENDO && state[RIGHT] != COMENDO){
        state[phnum] = COMENDO;
        sleep(2);
        printf("Filo %d estava com o fork do %d e do %d\n", phnum+1, LEFT+1, phnum+1);
        printf("Filo %d esta comendo \n", phnum+1);
    }
}

void put_fork(int phnum){
    state[phnum] = PENSAR;
    printf("Filo %d devolvendo o fork %d e o %d\n", phnum+1, LEFT+1, phnum+1);
    test(LEFT);
    test(RIGHT);
}

void take_fork(int phnum){
    state[phnum] = FAMINTO;
    printf("Filo %d esta FAMINTO\n", phnum+1);
    test(phnum);
    sleep(1);
}

void * filosofar(void *num){
    while(1){
        int * i = num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }
}

int main(){
    int i;
    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);
    for(i=0; i<N; i++){
        sem_init(&S[i], 0, 1);
    }
    
    for(i = 0; i < N; i++){
        pthread_create(&thread_id[i], NULL,
                        filosofar, &phil[i]);
        printf("Filo %d esta pensando\n", i+1);
    }

    for(i = 0; i < N; i++){
        pthread_join(thread_id[i], NULL);
    }
}