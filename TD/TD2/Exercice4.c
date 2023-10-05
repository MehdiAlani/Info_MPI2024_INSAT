#include <stdio.h>
#define MAXELEVES 10



int main(){
    float Note , Mnote=0 , Pnote=20, Sum=0;
    for(int i = 1; i<= MAXELEVES; i++){
        do{
        printf("\nDonner La note N°%d : ",i);
        scanf(" %f",&Note);
        }while ( Note < 0 || Note > 20);
        Sum = Sum + Note;
        if(Note > Mnote) Mnote=Note;
        else if(Note < Pnote) Pnote=Note;        
    }
    printf("La Meilleur Note est %0.2f et la Mauvaise est %0.2f de moyenne %0.2f",Mnote,Pnote,Sum/MAXELEVES);
    return 0;
}