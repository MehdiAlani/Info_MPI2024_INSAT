#include <stdio.h>
#include <string.h>
#define TAILLEMAX 100

int main(){
    // Saisie des Chaines
    char S1[TAILLEMAX];
    char S2[TAILLEMAX];
    int i , j , nbocc_S1 , nbocc_S2;
    printf("Donner S1: ");
    scanf("%s",S1);
    fflush(stdin);
    printf("Donner S2: ");
    scanf("%s",S2);

    // Verfication

    for(i = 0; i < strlen(S1); i++){
        nbocc_S1 = 0;
        nbocc_S2 = 0;
        for(j = 0; j < strlen(S1); j++)    
            if(S1[i] == S1[j]) nbocc_S1++;
        for(j = 0; j < strlen(S2); j++)    
            if(S1[i] == S2[j]) nbocc_S2++;     
        if(nbocc_S1 != nbocc_S2) {
            printf("%s n'est pas anagramme de %s\n",S1,S2);
            return 1;
        }
    }
    printf("%s est anagramme de %s\n",S1,S2);
    return 1;
}