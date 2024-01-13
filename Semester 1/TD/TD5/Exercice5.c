#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TailleMax 100
char * Compresser(char * S1){
    int i , j = 1 ,k = 0;
    char c = S1[0];
    char * S2 = (char * ) malloc(sizeof(char) * TailleMax);
    for(i = 1; S1[i] != '\0'; i++){
        if(c != S1[i] || S1[i+1] == '\n'){
            while(j >= 10){   
                S2[k] = (j / 10) + '0';
                j = j / 10;
                k++;
            }
            S2[k] = (j % 10) + '0';
            k++;
            S2[k] = '\t';
            k++; 
            S2[k] = c;
            k++;
            S2[k] = '#';
            k++;

            c = S1[i];
            j = 1;
        }
        else{
            j++;
        }
    }
    S2[k] = '\0';
    return S2;
}

int main(){
    char * S1 = (char *) malloc(sizeof(char) * TailleMax);
    int i = 0;
    int N;


    do{
        fflush(stdin);
        printf("Donner Un Chaine des Sequences composee Seulement par 0 ET 1: ");        
        scanf("%s",S1);
        N = strlen(S1);
        for(i = 0; i < N - 1 && (S1[i] == '0' || S1[i] == '1') ; i++){}
    }while(S1[i] != '1' && S1[i] != '0' && S1 != "");


    printf("Votre Chaine Compresser est => %s\n",Compresser(S1));
    free(S1);
    return 0;
}