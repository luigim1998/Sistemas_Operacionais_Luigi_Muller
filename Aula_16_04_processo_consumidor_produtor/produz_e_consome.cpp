#include <stdio.h>
#include <pthread.h>
#define TAM 50

long vetor[TAM];
int tamanho = 0;
int start = 0;
int end = 0;

void * produz(void * threadid){
	while(1){
        end = (end+1)%TAM;
        vetor[end] = 1;
		tamanho++;
	}
}

void * consome(void * threadid){
	while(1){
        start = (start+1)%TAM;
        vetor[start] = 0;
		tamanho--;
	}
}

int main(){
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, produz, NULL);
	pthread_create(&thread2, NULL, consome, NULL);

	pthread_join(thread1, NULL); //ele só passa para a próxima instrução quando a thread terminar
	pthread_join(thread2, NULL);

	printf("Valor final do contador: %ld \n", producao - consumo);

	pthread_exit(NULL);
}