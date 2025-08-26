#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 3

/* Exercicio 7 -
Desenvolver um algoritmo que controle as idades de 50 administrativos de uma
escola e que efetue a exibição dos aposentados e ativos. O algoritmo em questão
deverá executar as seguintes rotinas:
a-cadastrar os 50 administrativos e suas idades
b-classificar os administrativos cadastrados
c-corrigir administrativos e/ou idades que tenham sido cadastrados com erros
d-pesquisar administrativos por nome e por idade
e-listar administrativos aposentados (>=60 anos)
f-listar administrativos ativos 
*/

typedef struct{
	char nome[255];
	int idade;
} Cadastro;
Cadastro cad[MAX];
Cadastro aux[MAX];
bool cadastrado;

void cadastro(){
	for(int i=0;i<MAX;++i){
		printf("\n\033[7m Administrativo #%i \033[0m\n", i+1);
		printf("\nNome:\n");
		fflsuh(stdin);
		fgets(cad[i].nome, 255, stdin);
		cad[i].nome[strcspn(cad[i].nome,"\n")]="\0";
		printf("\nIdade:\n");
		scanf("%i", &cad[i].idade);
		printf("\n");
	}
	cadastrado = true;	
}

void classificar(){
	int escolha;
	printf("Como deseja classificar?\n\n");
	while(escolha!=5){
		printf("1 - Nomes A-Z\t3- Idades crescentes\n");
		printf("2 - Nomes Z-A\t4- Idades decrescentes\n");
		printf("5 - Sair\n\n");
		scanf("%i", &escolha);
		switch(escolha){
			case 1:
				
				break;
			
			case 2:
				
				break;
			
			case 3:
				for(int i=0;i<MAX-1;++i){
					for(int j=MAX+1;j<MAX;++j){
						if(cad[i].idade>cad[j].idade){
							aux[i] = cad[i];
							cad[i] = cad[j];
							cad[j] = aux[i];	
						}
					}
				}
				break;
			case 4:
				for(int i=0;i<MAX-1;++i){
					for(int j=MAX+1;j<MAX;++j){
						if(cad[i].idade<cad[j].idade){
							aux[i] = cad[i];
							cad[i] = cad[j];
							cad[j] = aux[i];	
						}
					}
				}
				break;		
			case 5:
				printf("\n\033[31mSaindo...\033[0m\n");
				break;
			
			default:
				printf("\n\033[31mOpcao invalida, escolha novamente\033[0m\n\n");
				break;
		}
		if(escolha<5 || escolha>0){
			printf("N\tNome\tIdade\n\n");
			for(int i=0;i<MAX;i++){
				printf("\n%i\t%s\t%i\n", i+1, cad[i].nome, cad[i].idade);
			}
		}
	}
}

void corrigir(){
	
}

void pesquisa_nome(){
	
}

void pesquisa_idade(){
	
}

void aposentados(){
	
}

void ativos(){
	
}

int cadastro_check(){
	if(cadastrado){
		return 1;
	}
	else{
		printf("\n\033[31mNao ha cadastros, cadastre-se apertando 1\033[0m\n\n");
		return 0;
	}
}

int main(){
	int escolha;
	while(escolha!=8){
		printf("\033[30;43m Menu \033[0m\n\n");
		printf("1 - Cadastre os 50 administrativos\t"); printf("5 - Pesquisa por idade\n");
		printf("2 - Classificar os administrativos\t"); printf("6 - Listar aposentados\n");
		printf("3 - Correcao de erros no cadastro\t"); printf("7 - Listar ativos\n");
		printf("4 - Pesquisa por nome\t\t\t"); printf("8 - Sair\n\n");
		printf("Escolha uma opcao:\n\n");
		scanf("%i", &escolha);
		switch(escolha){
			case 1:
				cadastro();
				break;
			
			case 2:
				if(cadastro_check() == 1){
					classificar();
				}
				break;
				
			case 8:
				printf("\n\033[31mSaindo...\033[0m\n");
				break;
			
			default:
				printf("\n\033[31mOpcao invalida, escolha novamente\033[0m\n\n");
				break;
		}	
	}
	
	return 0;
}
