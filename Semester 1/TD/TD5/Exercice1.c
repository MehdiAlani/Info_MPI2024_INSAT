#include <stdio.h>
#include <stdlib.h>

#define TAILLEMAX 100

int Fonction(char * S,char c){
    int nbocc = 0;
    char * p;
    for(p = S; *p !='\0' ;p++ ){
        if(*p == c) nbocc++;
    }
    return nbocc;
}

int main(){
    char * S = (char *) malloc(sizeof(char) * TAILLEMAX);
    char c; 
    printf("Donner Votre Chaine: ");
    fgets(S,TAILLEMAX,stdin);
    fflush(stdin);
    printf("Donner Votre Charactere a Chercher: ");
    scanf("%c",&c);
    int nbocc = Fonction(S,c);
    if(nbocc == 0) printf("Il n'ya pas des Nombres Repeters\n");
    else printf("Il y a %d Charcteres Repeters dans Votre Chaine\n",nbocc);
    free(S);
    return 0;
}