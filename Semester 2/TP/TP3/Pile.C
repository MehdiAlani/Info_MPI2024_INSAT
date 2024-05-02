#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 7
#define MAX_NB 20

typedef struct noued{
    int val;
    struct noued * suivant;
}noued;

typedef noued * pile;

pile cree(){
    return NULL;
}
int vide(pile p){
    return (p == NULL);
}
void empiler (pile * p,int v){
    pile P = (pile) malloc(sizeof(pile));
    P -> suivant = *p;
    P -> val = v;
    *p = P;
}
void Depiler(pile * p){
    if(*p == NULL) return;
    pile P = (*p) -> suivant;
    free(*p);
    *p = P;  
}
pile tete(pile p){

    return p;

}
int len(pile * p){
    int n = 0;
    if(*p == NULL) return n;
    pile paux = cree();
    while(*p != NULL){
        empiler(&paux,(*p) -> val);
        Depiler(p);
        n++;
    }
    while(paux != NULL){
        empiler(p,paux -> val);
        Depiler(&paux);
    }
    return n;
}


void Affiche(pile * p){
    pile aux = cree();
    while(*p != NULL){
        empiler(&aux,(*p) -> val);
        printf("%d\n",(*p) -> val);
        Depiler(p);
    }
    while(aux != NULL){
        empiler(p,aux -> val);
        Depiler(&aux);
    }
}
void Decomposer(pile * p1, pile * p2,pile * p3){
    if(*p1 == NULL) return;
    *p3 = *p2 = cree();
    pile aux = cree();
    while(*p1 != NULL){
            if((*p1) -> val % 2) empiler(p3, (*p1) -> val);
            else empiler(p2, (*p1) -> val);
            empiler(&aux, (*p1) -> val);
            Depiler(p1);
    }
    while(aux != NULL){
        empiler(p1, aux -> val);
        Depiler(&aux);
    }
    return;
}

pile fusion(pile *p1 ,pile * p2 , pile * p3){
    pile aux1 = cree(),aux2 = cree();

    while(*p1 != NULL && *p2 != NULL){
        if(((*p1) -> val) < ((*p2) -> val)){
            empiler(p3,(*p1) -> val);
            empiler(&aux1,(*p1) -> val);
            Depiler(p1);
        }
        else{
            empiler(p3,(*p2) -> val);
            empiler(&aux2,(*p2) -> val);
            Depiler(p2);
        }
    } 
    while(*p1 != NULL){
        empiler(p3,(*p1) -> val);
        empiler(&aux1,(*p1) -> val);
        Depiler(p1);
    }
    while(*p2 != NULL){
        empiler(p3,(*p2) -> val);
        empiler(&aux2,(*p2) -> val);
        Depiler(p2);
    }
    while(aux1 != NULL){
        empiler(p1,aux1 -> val);
        Depiler(&aux1);
    }
    while(aux2 != NULL){
        empiler(p2,aux2 -> val);
        Depiler(&aux2);
    }
    pile aux3 =  cree();
    while(*p3 != NULL){
        empiler(&aux3,(*p3) -> val);
        Depiler(p3);
    }
    return (aux3); 

}

void inserer(pile * p ,int n){
    pile aux= cree();
    while(*p != NULL && (*p) -> val < n){
        empiler(&aux, (*p) -> val);
        Depiler(p);
    }
    empiler(p,n);
    while(aux != NULL){
        empiler(p,aux -> val);
        Depiler(&aux);
    }
}

int main(){
    int i  = 0;
    pile p1  = cree() ,p2  = cree(), p3 = cree();
    for(i = 0; i < MAX_SIZE; i++) empiler(&p1,rand() % MAX_NB);
    printf("Cest P1 :\n");
    Affiche(&p1);
    Decomposer(&p1,&p2,&p3);
    printf("Decomposee Cest p1:\n");
    Affiche(&p1);
    printf("Cest p2:\n");
    Affiche(&p2);
    printf("Cest p3:\n");
    Affiche(&p3);    

    //

    while(p1 != NULL) Depiler(&p1);
    while(p2 != NULL) Depiler(&p2);
    while(p3 != NULL) Depiler(&p3);
    // Fusion : 

    empiler(&p1,10);
    empiler(&p1,7);
    empiler(&p1,5);
    empiler(&p1,3);

    empiler(&p2,17);
    empiler(&p2,15);
    empiler(&p2,2);
    
    printf("Fusion C'est p1:\n");
    Affiche(&p1);
    printf("C'est p2:\n");
    Affiche(&p2);


    p3 = fusion(&p1,&p2,(&p3));
    printf("C'est p1:\n");
    Affiche(&p1);
    printf("C'est p2:\n");
    Affiche(&p2);
    printf("C'est p3:\n");
    Affiche(&p3);



    int n;
    printf("Cest P1\n");
    Affiche(&p1);
    printf("Insertion de n en P Donner n\n");
    scanf("%d",&n);
    inserer(&p1,n);
    Affiche(&p1);


}



















