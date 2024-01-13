#include <stdio.h>


int main(){
    char c , cf = '\0';
    int nb  = 0 , N , i=0;
    printf("Donner Le Nombre de Mots a Selecter: "); 
    scanf("%d",&N);
    while((c = getchar()) != '#'){
        if(c == ' ' && cf != ' ' || c == '\n' && cf != '\n'){
            if(nb==N) i++;
            nb = 0;
        }
        else 
            nb++;
        cf = c;
    }
    printf("il ya  %d mots avec %d Caracteres\n",i,N);
}