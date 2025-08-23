#include<stdio.h>
typedef struct{
	int x;
	float a;
	float b;
	float c;
}numeros;
numeros ordem[4];

void crescente(){
	float x, a[3];
	a[0]=ordem[0].a;
	a[1]=ordem[1].b;
	a[2]=ordem[2].c;
	for(int i=0; i<2; ++i){
		for(int j=i+1; j<3; ++j){
			if(a[i] > a[j]){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}
	printf("Ordem Crescente: %.3f %.3f %.3f", a[0], a[1], a[2]);
}

void decrescente(){
	float x, a[3];
	a[0]=ordem[0].a;
	a[1]=ordem[1].b;
	a[2]=ordem[2].c;
	for(int i=0; i<2; ++i){
		for(int j=i+1; j<3; ++j){
			if(a[i] < a[j]){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}
	printf("Ordem Decrescente: %.3f %.3f %.3f", a[0], a[1], a[2]);
}

void meio(){
	float x, a[3];
	a[0]=ordem[0].a;
	a[1]=ordem[1].b;
	a[2]=ordem[2].c;
	if(a[0]>a[1]){
		x=a[0];
		a[0]=a[1];
		a[1]=x;
	}
	if(a[1]<a[2]){
		x=a[1];
		a[1]=a[2];
		a[2]=x;
	}
	printf("Com o maior no meio: %.3f %.3f %.3f", a[0], a[1], a[2]);
}

int main(){
	printf("Digite 3 valores:\n");
	scanf("%f", &ordem[0].a);
	scanf("%f", &ordem[1].b);
	scanf("%f", &ordem[2].c);
	printf("\nValores obtidos: %.3f %.3f %.3f\n", ordem[0].a, ordem[1].b, ordem[2].c);
	printf("\nEscolha uma das tres opcoes abaixo para manipular a ordem dos tres valores:\n\nOrdem Crescente - 1\nOrdem Decrescente - 2\nCom o maior no meio - 3\n");
	scanf("%i", &ordem[3].x);
		switch(ordem[3].x){
			case 1: crescente(); break;
			case 2: decrescente(); break;
			case 3: meio(); break;
			default: printf("Valor Invalido, tente um valor entre 1 e 3 da proxima vez");
		}
	return 0;
}
