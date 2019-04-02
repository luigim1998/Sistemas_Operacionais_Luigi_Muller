#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE * fff = fopen("Betinho.txt", "r");
	FILE * ggg = fopen("Betinho_lido.txt","w");
	char *texto;
	fscanf(fff, "%s\n", texto);
	printf("%s\n", texto);
	fprintf(ggg, "%s\n", texto);
	return 0;
}