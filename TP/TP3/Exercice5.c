#include <stdio.h>


int main(){
    int Matrice[4][4];
    int nb , i = 0 , j , k , z , min , max;

    for(i=0 ; i < 4;i++){
        for(j=0 ; j < 4;j++){
            fflush(stdin);
            printf("Donner Matrice[%d][%d]:",i,j);
            scanf("%d",&nb);
            Matrice[i][j] = nb;
        }
    }
    for(i=0 ; i < 4;i++){
        for(j=0 ; j < 4;j++){
            printf("%d ",Matrice[i][j]);
        }
        printf("\n");
    }
    for(i=0 ; i < 4;i++){
        for(j=0 ; j < 4;j++){
            max = 0;
            min = 0;
            for(k = 0 ; k < 4 ; k++){
                if(Matrice[i][k] > Matrice[i][max]) max = k;
            }
            for(k = 0 ; k < 4 ; k++){
                if(Matrice[k][j] < Matrice[min][j]) min = k;
            }
            if (max == j && min == i) printf("%d\n",Matrice[i][j]);
        }
    }



    return 0;
}
