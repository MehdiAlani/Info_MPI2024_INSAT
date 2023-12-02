#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLEMAX 100


void Fonction(char * ch1,char * ch2){
    int i ,j ,k;
    int n1 = strlen(ch1);
    int n2 = strlen(ch2);

    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            if(ch1[i] == ch2[j]){
                for(k = i; k < n1 - 1; k++){
                    ch1[k] = ch1[k+1];
                }
                ch1[n1 - 1] = '\0';
                n1--;
            }
        }
    }

    
}

int main(){
    char * Ch1 = (char *) malloc(sizeof(char) * TAILLEMAX);
    char * Ch2 = (char *) malloc(sizeof(char) * TAILLEMAX);

    printf("Donner Votre Chaine Ch1: ");
    scanf("%s",Ch1);
    fflush(stdin);
    printf("Donner Votre Chaine Ch2: ");
    scanf("%s",Ch2);

    printf("%s ,%s",Ch1,Ch2);
    Fonction(Ch1,Ch2);
    printf(":%s\n",Ch1);

    free(Ch1) , free(Ch2);
    return 0;
}