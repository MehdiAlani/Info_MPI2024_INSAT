#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLEMAXI 100
int Chercher(char * S,int N,int * i){
    int Nbmots = 1;
    int Taille = strlen(S);
    if(S[0] == ' ') Nbmots=0;
    for (*i = 0; (*i < Taille-1) && Nbmots != N; *i += 1){
        if(S[*i] == ' ' && S[*i +1] != ' ') Nbmots++; 
    }
    if (Nbmots != N) return 0;
    else return 1; 
}
int main(){
    int N; 
    int i;
    char * S = (char *) malloc(TAILLEMAXI);
    printf("Donner une Chaine: ");
    fgets(S,TAILLEMAXI,stdin);
    fflush(stdin);
    printf("Donner Le Nieme mot de Selectioner: ");
    scanf("%d",&N);
    if(Chercher(S,N,&i) == 1){
        printf("Le mot %dieme exicte d'addresse de Debut 0x%p\n",N,S + i);
    }
    else printf("Le mot %dieme n'exicte pas\n");
    free(S);
    return 0;
}