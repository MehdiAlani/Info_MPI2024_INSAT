#include <stdio.h>


int main(){
    float Moy ,N1 , N2 , N3;
    do{
        printf("Donner les notes (N1) (N2) (N3)");
        scanf("%f %f %f",&N1,&N2,&N3);
        printf("\n");
    }while(N1 < 0 || N1 > 20 || N2 < 0 || N2 > 20 || N3 < 0 || N3 > 20);  
    Moy = N1 / 5 + N2 / 3 + N3 / 2;
    if(Moy > 16) printf("Tres Bien");
    else if (Moy > 14) printf("Bien");
    else if(Moy > 12) printf("Assez Bien");
    else if(Moy > 10) printf("Passable");
    else printf("Echec");
    return 0;
}