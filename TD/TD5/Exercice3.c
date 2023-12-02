#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TailleGrandeSeq 100
#define TaillePetiteSeq 10
void DecalerDroite(char * S ,int N,int Debut){ 
    for(int i = N;i > Debut; i--){
        S[i] = S[i-1];
    }
    S[Debut] = '\0'; 
}


void DecalerGauche(char * S ,int N,int Debut){ 
    for(int i = Debut;i < N; i++){
        S[i] = S[i+1];
    }
}


void Fonction(char * S,char * w1 ,char *w2){
    int i = 0, j = 0;
    int n1 = strlen(w1);
    int n2 = strlen(w2);
    int N = strlen(S);
    for(i = 0; i < N; i++){
        if(S[i] == ' ' || S[i] == '\n') S[i] ='\0';
    }
    w1[n1-1] = '\0'; 
    char T[n1]; 
    for(i = 0; i < N; i++){
        for(j = i ; j < i + n1; j++){
            T[j - i] = S[j];
        }
        if(strcmp(T,w1) == 0){ 
            if(n2 > n1) DecalerDroite(S,N,i + n1);
            for(j = i; j < i + n2;j++){
                S[j] = w2[j - i];
            }
            i = i + n2;
        }    
    }
}



int main(){
    char * S = (char *) malloc(sizeof(char) * TailleGrandeSeq);
    char * w1 = (char *) malloc(sizeof(char) * TaillePetiteSeq);
    char * w2 = (char *) malloc(sizeof(char) * TaillePetiteSeq);

    printf("Donner S:");
    fgets(S,TailleGrandeSeq,stdin);
    fflush(stdin);
    printf("Donner w1:");
    fgets(w1,TailleGrandeSeq,stdin);
    fflush(stdin);
    printf("Donner w2:");
    fgets(w2,TailleGrandeSeq,stdin);
    Fonction(S,w1,w2);
    printf("Votre Chaine Devint %s\n",S);

    free(S), free(w1) , free(w2);
    return 0;
}

  
