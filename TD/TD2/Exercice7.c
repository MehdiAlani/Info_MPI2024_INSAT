#include <stdio.h>
#include <stdlib.h>
int main(){
    int N;
    char Texte[512];
    short int Valid = 1;
    int nbchar = 0, nbmots=0;
    do{
        printf("Donner Le nombre de mots a compter: ");
        scanf("%d",&N);
        printf("\n");
    }while(N < 0);
    for(int i=0;i<512;i++){
        Texte[i]='#';
    } 
    do{
        printf("Donner Vortre Texte :");
        scanf("%s",&Texte);
        for(int i=0; Texte[i]!='#'; i++){
            if('A'>Texte[i] && Texte[i]!=' '|| 'Z'<Texte[i] && 'a'>Texte[i] || 'z'<Texte[i] && Texte[i]!='\n') Valid = 0;
        } 
    }while(Valid==0);
    for(int i =0; i != '#'; i++){
        if(Texte[i]==' '){
            if(nbchar == N){
                nbmots++;
            }
            nbchar=0;
        }
        else{
            nbchar++;
        }
    }
    printf("Le Nombre de mots Avec %d caracteres sont %d\n",N,nbchar);

    return 0;
}