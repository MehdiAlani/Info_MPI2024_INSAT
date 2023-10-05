#include <stdio.h>
int main(){
    float Tgr1[]={5.4,8.5,9.15,9.95,10.05,10.50,11.4,12.50,13.4,13.5,14.5,14.98,15.5};
    int N= sizeof(Tgr1)/sizeof(float); 
    float Tgr2[]={4,4.8,5.6,9.6,9.8,10.11,10.7,11.5,12.01,12.9,13.5,13.6,14.8};
    int M= sizeof(Tgr2)/sizeof(float);
    for (int i =0; i<M;i++){
        TAmphi=Tgr1[i]
    }
    float TAmphi[]= Tgr1 + Tgr2 ;
    printf("%d",sizeof(Tgr2)/sizeof(float));
    return 0;
}