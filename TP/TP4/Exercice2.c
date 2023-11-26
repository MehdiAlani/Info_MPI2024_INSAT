#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TailleMaxi 100

void Fonction(char * S,int * MajNb,int * MinNb){
    int N = strlen(S) ,i;
    * MajNb = 0,* MinNb = 0;
    for(i = 0; i < N ;i++){
        if( S[i] >= 'A' && S[i] <= 'Z'){
            MajNb++;
            S[i] = S[i] + (char)(32);
        }
        else if (S[i] >= 'a' && S[i] <= 'z'){
            MinNb++;
            S[i] = S[i] - (char)(32);
        }
    }
}

int main(){
    int MajNb , MinNb;
    char *  S = (char *) malloc(TailleMaxi * sizeof(char));
    printf("Donner Votre Chaine a Transformer: ");
    scanf("%s",S);
    Fonction(S,&MajNb,&MajNb);
    printf("La Chaine devient %s de %d Minuscules et %d Majuscules",S,MajNb,MinNb);
    free(S);
    return 0;
}