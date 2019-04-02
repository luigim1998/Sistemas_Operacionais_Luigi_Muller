#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 9

void * printHello(void * threadid){
	long tid;
	tid = (long) threadid;
	printf("Estou na thread #%ld\n", tid);
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[NUM_THREADS];

	int rc; 
	long t; //contador de thread

	for(t = 0; t < NUM_THREADS; t++){
		printf("Estou na main, criando t %ld\n", t);
		rc = pthread_create(&threads[t], NULL, printHello, (void*)t); //endereço da thread, Prioridade da thread, nome da função e argumento da função
		if(rc){
			printf("ERROR = %d\n", rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}