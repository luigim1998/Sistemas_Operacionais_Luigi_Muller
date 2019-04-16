#include <stdio.h>
#include <pthread.h>

long contador = 0;

void * inc(void * threadid){
	int i = 0;
	for(; i < 1000; i++){
		contador++;
	}
}

void * dec(void * threadid){
	int i = 0;
	for(; i < 1000; i++){
		contador--;
	}
}

int main(){
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, inc, NULL);
	pthread_create(&thread2, NULL, dec, NULL);

	pthread_join(thread1, NULL); //ele só passa para a próxima instrução quando a thread terminar
	pthread_join(thread2, NULL);

	printf("Valor final do contador: %ld \n", contador);

	pthread_exit(NULL);
}