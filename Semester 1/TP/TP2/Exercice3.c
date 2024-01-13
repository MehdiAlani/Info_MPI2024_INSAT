#include <stdio.h>

int main(){
    int N , i=0;
    char c;
    do{
        printf("Donner le taille de Tableau: ");
        scanf("%d",&N);
    }while(N < 1);
    char Tchar[N];
    for(i=0; i < N ; i++){
        fflush(stdin);
        printf("Donner Tchar[%d]:",i);
        scanf("%c",&c);
        Tchar[i] = c;
    }
    fflush(stdin);
    printf("Donner un caractere: ");
    scanf("%c",&c);
    for(i=0; i < N ; i++){
        if(Tchar[i]==c){
            printf("Le caractere %c exist\n");
            return 1;
        }
    }
    printf("Le caractere %c n'exist pas \n");
    return 0;
}
