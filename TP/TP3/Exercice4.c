#include <stdio.h>


int main(){
    int i , N ,M,nb ;
    short int Trie = 0;
    float aux;
    do{
        printf("Donner le nombre des Etudents dans Grp1: ");
        scanf("%d",&N);
    }while(N < 1 || N > 30);
    do{
        printf("Donner le nombre des Etudents dans Grp2: ");
        scanf("%d",&M);
    }while(M < 1 || M > 30);
    float Tgr1[N];
    float Tgr2[M];
    printf("Donner Tgr1[0]: ");
    scanf("%d",&nb);
    Tgr1[0]=nb;
    for(i = 1 ; i < N ; i++){
        do{
            printf("Donner Tgr1[%d]: ",i);
            scanf("%d",&nb);
            Tgr1[i]=nb;
        }while(Tgr1[i - 1] > Tgr1[i]);
    }
    printf("Donner Tgr2[0]: ");
    scanf("%d",&nb);
    Tgr2[0]=nb;
    for(i = 1 ; i < M ; i++){
        do{
            printf("Donner Tgr2[%d]: ",i);
            scanf("%d",&nb);
            Tgr2[i] = nb;
        }while(Tgr2[i - 1] > Tgr2[i]);
    }
    float TAmphi[M+N];
    for( i=0; i < N; i++){
        TAmphi[i]=Tgr1[i];
    }
    for( i=N; i < N+M; i++){
        TAmphi[i]=Tgr2[i-N];
    }
    while (!Trie){
        Trie = 1;
        for( i = 1; i < N+M; i++){
            if(TAmphi[i - 1] > TAmphi[i]){
                Trie = 0;
                aux = TAmphi[i];
                TAmphi[i]=TAmphi[i-1];
                TAmphi[i-1]=aux;
            }
        }
    }
    for( i = 0; i < N+M; i++){
        printf("%0.2f,",TAmphi[i]);
    }
    return 0;
}
