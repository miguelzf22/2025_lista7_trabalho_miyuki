#include<stdio.h>

typedef struct{
    int x;
    float a;
}numeros;
numeros ordem[4];

int i,j;
void sort(){
    float x;
    int y=0;
    for(int i=0; i<2; ++i){
        for(int j=i+1; j<3; ++j){
            if(ordem[i].a > ordem[j].a){
                x=ordem[i].a;
                ordem[i].a=ordem[j].a;
                ordem[j].a=x;
            }
        }
    }
    printf("Digite como deseja sortar\n1-Crescente\n2-Descresente\n3-Maior  meio\nInput:");
    scanf("%d",&y);
    while(y>3||y<1){
        printf("Número inválido,Digite outro\nInput: ");        scanf("%d",&y);
    }
    printf("__\n");
    if(y==1){
        printf("|\t     Ordem Crescente:\t\t|\n|\t| %.3f | %.3f\t| %.3f \t|", ordem[0].a, ordem[1].a, ordem[2].a);
    }
    else if(y==2){
        printf("|Ordem Decrescente: | %.3f | %.3f  | %.3f |", ordem[2].a, ordem[1].a, ordem[0].a);
    }
    else if(y==3){
        printf("|No meio: %.3f %.3f %.3f|", ordem[0].a, ordem[2].a, ordem[1].a);
    }
    printf("\n__");
}
int main(){
    printf("Digite 3 valores:\n");
    for(i=0;i<3;++i){
        scanf("%f", &ordem[i].a);
    }
    sort();
    return 0;
}
