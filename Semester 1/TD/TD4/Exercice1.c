#include <stdio.h>

void Remplir(int * Tab , int Size){
    for(int i = 0; i < Size ; i++){
        do{
            printf("Donner T[%d]:",i);
            scanf("%d",Tab+i);
        }while(Tab[i] < 0);
    }
}   

int NbOcc(int * Tab , int Size , int nbCher){
    int nb = 0;
    for(int i = 0 ; i < Size ; i++){
        if(nbCher == Tab[i]) nb++;
    }
    return nb;
}
int main(){
    int n;
    do{

        printf("Donner le Taille de Tableau : ");
        scanf("%d",&n);

    }while(n < 1);

    int Tab[n];
    int TabRes[n];
    int j = 0;
    Remplir(Tab,n);
    printf("Votre Tablaux Tab={ ");
    for(int i = 0; i < n ; i++){
        if((NbOcc(Tab,n,Tab[i])) == 1) {
            printf("%d ",Tab[i]);
            TabRes[j] = Tab[i];
            j++;
        }
    }
    printf("}\n");
    return 0;
}