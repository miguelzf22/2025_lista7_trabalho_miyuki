#include<stdio.h>
#include<stdbool.h>


void ordem(int k[10]){
	int t;
	
	for(int i=0; i<10; ++i){
		for(int j=i+1; j<10; ++j){
			if(k[i] > k[j]){
				t = k[i];
				k[i] = k[j];
				k[j] = t;
			}
		}
	}
}

int main(){
	int A[10], B[10], t;
	bool achado;
	char verif;
	
	for(int i=0; i<10; ++i){
		printf("Insira o %d(o) valor: ", i+1);
		scanf("%d", &A[i]);
		
		B[i] = (A[i]*2);
	}
	
	ordem(B);
	
	//exibir os elementos
	for(int h=0; h<10; ++h){
		printf("|| %d ", B[h]);
	}
	
	getchar();
	printf("\n\nDeseja buscar um n�mero?\nQualquer Tecla - Continuar \nS - Sair\n");
	scanf("%c", &verif);
	
	while(verif != 'S' && verif != 's'){
		printf("Qual n�mero voc� deseja buscar? ");
		scanf("%d", &t);
		
		for(int u=0; u<10; ++u){
			if(B[u] == t){
				printf("\nO n�mero foi achado na %d(o) posi��o.\n", u+1);
				achado=true;
			}
			
			if(u == 9 && achado==false){
				printf("\nO n�mero n�o foi achado.\n");
			}
		}
		
		getchar();
		printf("\nDeseja continuar? \n");
		achado=false;
		scanf("%c", &verif);
	}
	
	if(verif == 'S' || verif != 's'){
		printf("\nObrigado por testar nosso c�digo!\n");
	}
	
	return 0;
}
