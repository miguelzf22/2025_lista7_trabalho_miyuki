#include <stdio.h>
int a[2];
int b[2];
int pf =0;

void print(){
	printf("Ola, bem-vindo ao programa de apostas!\nQual e o placar do time A e time B? (Digite n1 n2)\n");
	scanf("%d %d",&a[0],&b[0]);
	printf("Qual e o placar final do jogo? (Digite n1 n2)\n");
	scanf("%d %d",&a[1],&b[1]);
}

void jogo(){
 if(b[0]>a[0]&&b[1]>a[1]){
		pf+=10;
		printf("\nVocê ganhou 10 pontos por acertar o resultado\n");
	}
	else if(a[0]>b[0]&&a[1]>b[1]){
		pf+=10;
	printf("\nVocê ganhou 10 pontos por acertar o resultado\n");
	}
	else if(a[0]==b[0]&&a[1]==b[1]){
		printf("\nVocê ganhou 10 pontos por acertar o resultado\n");
		pf+=10;
	}
	
	if(a[0]==a[1]){
		pf+=5;
		printf("\nVocê ganhou 5 pontos por acertar o placar\n");
	}
	if(b[0]==b[1]){
		pf+=5;
		printf("\nVocê ganhou 5 pontos por acertar o placar\n");
	}
}

int main(){
	print();
	printf("O placar e de %d x %d\n",a[1],b[1]);
   	jogo();
	printf("\nVocê fez %d pontos.",pf);
}
