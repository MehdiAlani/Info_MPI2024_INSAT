#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TailleMaxi 100


char * miroir(char * s){
    int N = strlen(s);
    char i , aux;
    for(i = 0; i < N / 2; i++){
        aux = s[i];
        s[i] = s[N-1-i];
        s[N-1-i] = aux;
    }
    return s;
}

int main(){
    char *  S = (char *)malloc(TailleMaxi * sizeof(char));
    printf("Donner Votre Chaine a renverser: ");
    scanf("%s",S);
    S = miroir(S);
    printf("La Chaine Renverser est: %s \n",S);
    free(S);
    return 0;
}