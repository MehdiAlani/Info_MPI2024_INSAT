#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TailleMaxi 100
char * Concatiner(char * ch1 , char * ch2){
    int N1 = strlen(ch1); 
    int N2 = strlen(ch2); 
    if(strcmp(ch1,ch2) == 0){
        char * ch3 = (char * ) malloc(sizeof(char) * (N1));
        strcpy(ch3,ch1);
        return ch3;
    }
    else{
        char * ch3 = (char * ) malloc(sizeof(char) * (N1+N2));
        if(strcmp(ch1,ch2) == -1){
            strcpy(ch3,ch1);
            strcat(ch3,ch2);
        }
        else{
            strcpy(ch3,ch2);
            strcat(ch3,ch1);
        }
        return ch3;
    }
}
int main(){
    char *  ch1 = (char *) malloc(TailleMaxi * sizeof(char));
    char *  ch2 = (char *) malloc(TailleMaxi * sizeof(char));
    printf("Donner Ch1: ");
    scanf("%s",ch1);
    fflush(stdin);
    printf("Donner Ch2: ");
    scanf("%s",ch2);
    char * ch3 =  Concatiner(ch1,ch2);
    printf("Le Resultat est => %s\n",ch3);
    free(ch1),free(ch2),free(ch3);
    return 0;
}