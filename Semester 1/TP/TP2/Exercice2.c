#include <stdio.h>

int main(){
    int N,aux;
    int nb,i,Somme=0,max=0,min=0,max_nb=0,min_nb=-1;
    do{
        printf("Donner un nombre positive de max 50: ");
        scanf("%d",&N);
    }while(N < 1 || N > 50);
    int Tab[N];
    for(i = 0; i < N; i++) {
        printf("Donner Tab[%d]:",i);
        scanf("%d",&nb);
        Tab[i] = nb;
    }
    printf("Tab = {");
    max_nb = Tab[0];
    min_nb = Tab[0];
    for(i = 0; i < N; i++){
        printf("%d,",Tab[i]);
        Somme = Somme + Tab[i];
        if(max_nb < Tab[i]){
            max_nb = Tab[i];
            max = i;
        }
        else if (min_nb > Tab[i]){
            min_nb = Tab[i];
            min = i;
        }
    }
    printf("}");
    printf("\n La Somme de Tab est %d , de position max %d, de position min %d\n",Somme,max,min);
    for( i=0 ; i < N / 2 ; i++){
        aux = Tab[i];
        Tab[i] = Tab[N-1-i];
        Tab[N-1-i] = aux ;
    }
    printf("Le tableau Inverse est :{");
    for( i=0 ; i < N ; i++){
        printf("%d,",Tab[i]);
    }
    printf("}\n");
}
