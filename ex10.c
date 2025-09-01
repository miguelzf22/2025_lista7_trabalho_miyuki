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
	printf("\n\nDeseja buscar um número?\nQualquer Tecla - Continuar \nS - Sair\n");
	scanf("%c", &verif);
	
	while(verif != 'S' && verif != 's'){
		printf("Qual número você deseja buscar? ");
		scanf("%d", &t);
		
		for(int u=0; u<10; ++u){
			if(B[u] == t){
				printf("\nO número foi achado na %d(o) posição.\n", u+1);
				achado=true;
			}
			
			if(u == 9 && achado==false){
				printf("\nO número não foi achado.\n");
			}
		}
		
		getchar();
		printf("\nDeseja continuar? \n");
		achado=false;
		scanf("%c", &verif);
	}
	
	if(verif == 'S' || verif != 's'){
		printf("\nObrigado por testar nosso código!\n");
	}
	
	return 0;
}
