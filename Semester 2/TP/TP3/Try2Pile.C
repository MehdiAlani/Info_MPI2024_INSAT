#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pile{
    int val;
    struct pile * suivant;
}pile;

typedef pile * Pile;

Pile cree(int v){
    Pile p = (Pile) malloc(sizeof(pile));
    p -> val = v;
    p -> suivant = NULL;
    return p;
}
int vide(Pile p){
    return (p == NULL);
}
Pile empiler (Pile p,int v){
    Pile p1 = cree(v);
    p1 -> suivant = p;
    return p1; 
}
Pile Depiler(Pile p){
    if(p == NULL) return p ;
    if(p -> suivant == NULL) {
        free(p);
        return NULL;
    }
    Pile move = p -> suivant;
    free(p);
    return move;
}
Pile tete(Pile p){
    return p;
}
int len(Pile p){
    if(p == NULL) return 0;
    Pile move = p;
    int n = 1;
    while (move -> suivant !=  NULL){
        n++;
        move = move -> suivant;
    }
    return n;
}
void Affiche(Pile p){
    if(p == NULL) return;
    if(p -> suivant == NULL){
        printf("%d\n",p -> val);
        return;
    }
    Pile pres = NULL;
    Pile move = p -> suivant;

    printf("%d\n",p -> val);
    while (move != NULL){
        printf("%d\n",move -> val);
        pres = empiler(pres,move -> val);
        move = Depiler(move);
    }
    Pile praz = NULL;
    while(pres != NULL){
        praz = empiler(praz,pres-> val);
        pres = Depiler(pres);
    }
    p -> suivant = praz;
}

void decomposer(Pile p1 ,Pile * p2,Pile * p3){
    *p2 = NULL; *p3 = NULL;  
    if(p1 == NULL) return;
    Pile pres = NULL;
    Pile move = p1 -> suivant;
    while(move != NULL){
        pres = empiler(pres,move -> val);
        if (move -> val % 2) *p3 = empiler(*p3,move -> val);
        else *p2 = empiler(*p2,move -> val);
        move = Depiler(move);
    }
    if (p1-> val % 2) *p3 = empiler(*p3,p1 -> val);
    else *p2 = empiler(*p2,p1 -> val);
    Pile praz = NULL;
    while (pres != NULL){
        praz = empiler(praz, pres-> val);
        pres = Depiler(pres);
    }
    p1 -> suivant = praz;
}
Pile fusion(Pile p1 ,Pile p2 , Pile p3){ 
    if(p1 == NULL && p2 == NULL) return NULL;
    Pile pres = NULL;
    while(p2 != NULL && p1 != NULL){
        if(p2 -> val > p1 -> val) {
            pres = empiler(pres, p1 -> val);
            p1 = Depiler(p1);
        }
        else{
            pres = empiler(pres , p2 -> val);
            p2 = Depiler(p2);
        }
    }
    if(p1 == NULL) p1 = p2;
    while (p1 !=  NULL){
        pres = empiler(pres,p1 -> val);
        p1 = Depiler(p1);
    }
    p3 = NULL;
    while (pres != NULL){
        p3 = empiler(p3,pres -> val);
        pres = Depiler(pres);
    }
    return p3;
}
int main(){
    Pile p1 = NULL, p2 = NULL, p3 = NULL;

    p1 = cree(12);
    p1 = empiler(p1 ,15);
    p1 = empiler(p1 ,2);
    p1 = empiler(p1 ,1);
    p1 = empiler(p1 ,19);
    p1 = empiler(p1 ,0);
    Affiche(p1);
    p1 = Depiler(p1);p1 = Depiler(p1);
    Affiche(p1);

    decomposer(p1,&p2,&p3);
    printf("C'est p1: \n"); Affiche(p1);
    printf("C'est p2: \n"); Affiche(p2);
    printf("C'est p3: \n"); Affiche(p3);

    while(p1 != NULL) p1 = Depiler(p1);
    while(p2 != NULL) p2 = Depiler(p2); 
    p1 = empiler(p1 ,14);
    p1 = empiler(p1 ,2);
    p1 = empiler(p1 ,0);

    p2 = empiler(p2 ,80);
    p2 = empiler(p2 ,40);
    p2 = empiler(p2 ,8);
    p2 = empiler(p2 ,3);
    p2 = empiler(p2 ,1);
    printf("C'est p1: \n"); Affiche(p1);
    printf("C'est p2: \n"); Affiche(p2);

    p3 = fusion(p1,p2,p3);
    printf("C'est la Pile p3\n");
    Affiche(p3);
    return 0;
}