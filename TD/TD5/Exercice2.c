#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 100

void Remplacer(char * S){
    int i = 0,j,N = strlen(S); 
    while(i < N - 1){
        if(S[i] == S[i+1]){
            for(j = i + 1; j < N - 1;j++){
                S[j] = S[j+1];
            }
            S[N-1] = '\0'; // Not For obligation
            N--;
        }
        else i++;
    }
}

int main(){
    char * S = (char *) malloc(sizeof(char) * TAILLEMAX);
    printf("Donner Votre Chaine: ");
    fgets(S,TAILLEMAX,stdin);

    Remplacer(S);
    printf("La Chaine Devint %s",S);

    free(S);
    return 0;
}