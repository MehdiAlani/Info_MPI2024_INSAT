#include <stdio.h>
int main(){
    int N;
    char Carctere;
    do{
        printf("Donner La taille du tableau comprise entre 1 et 50: ");
        scanf("%d",&N);
    }while(N<1 || N>50);
    char Tchar[N];
    printf("\n");
    for(int i =0;i<N;i++){
        do{
            printf("Tchar[%d]= ",i);
            scanf("%c",&Carctere);
            printf("\n");
        }while('A'> Carctere || 'z'< Carctere );
        Tchar[i]=Carctere;
    }
    printf("\nTchar={");
    for(int i =0; i < N-1;i++){
        printf("%c,",Tchar[i]);
    }
    printf("%c}\n",Tchar[N-1]);
    printf("Saisir un chartere a chercher: \n");
    scanf("%c",&Carctere);
    for (int i=0; i<N;i++){
        if (Tchar[i]==Carctere){
            printf("Le caractere %c exciste dans le tableau Tchar\n",Carctere);
            return 0;
        }
    }
    printf("Le caractere %c n'exciste pas dans le tableau Tchar\n",Carctere);
    return 0;
}