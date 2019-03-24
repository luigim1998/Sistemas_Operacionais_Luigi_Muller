#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivoA = fopen("arquivoA.txt", "r");
    FILE *arquivoB = fopen("ArquivoB.txt", "w");
    printf("a");
    char aux[30];
    if (arquivoA == NULL) {
        printf("aNao foi possivel abrir o arquivo\n");
    } else {
        printf("b");
        while (fgets(aux, 29,arquivoA) != NULL){
            printf("c");
            fprintf(arquivoB, "%s", aux);
        }
    }
    fclose(arquivoA);
    fclose(arquivoB);
    return 0;
}
