#include <stdio.h>

int main(){
	int a;
	int b;
	int a2 = 3; //Você pode alterar o placar modificando as variáveis a2 e b2.
	int b2 = 4;
	int pf;
	
	printf( "Ola, bem-vindo ao programa de apostas!\nQual e o placar do time A?\n ");
	scanf("%d",&a);
	printf("E o placar do time B?\n");
	scanf("%d",&b);
	printf("O placar e de %d x %d\n",a2,b2);
	if(a>b&&a2>b2){
		pf+=10;
		printf("\nVocê ganhou 10 pontos por acertar o resultado\n");
	}
	if(b>a&&b2>a2){
		pf+=10;
		printf("\nVocê ganhou 10 pontos por acertar o resultado\n");
	}
	if(a2==b2&&a==b){
		printf("\nVocê ganhou 10 pontos por acertar o resultado\n");
		pf+=10;
	}
	

	
	if(a==a2){
		pf+=5;
		printf("\nVocê ganhou 5 pontos por acertar o placar\n");
	}
	if(b==b2){
		pf+=5;
		printf("\nVocê ganhou 5 pontos por acertar o placar\n");
	}
	
	printf("\nVocê fez %d pontos.",pf);
}


