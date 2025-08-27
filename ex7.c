#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 50

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
		fflush(stdin);
		fgets(cad[i].nome, 255, stdin);
		cad[i].nome[strcspn(cad[i].nome,"\n")]='\0';
		printf("\nIdade:\n");
		scanf("%i", &cad[i].idade);
		printf("\n");
	}
	cadastrado = true;	
}

void swap(int i, int j){
	aux[i] = cad[i];
	cad[i] = cad[j];
	cad[j] = aux[i];
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
				for(int i=0;i<MAX-1;++i){
					for(int j=i+1;j<MAX;++j){
						if(strcmp(cad[i].nome, cad[j].nome)>0){
							swap(i, j);	
						}
					}
				}
				break;
			
			case 2:
				for(int i=0;i<MAX-1;++i){
					for(int j=i+1;j<MAX;++j){
						if(strcmp(cad[i].nome, cad[j].nome)<-0){
							swap(i, j);	
						}
					}
				}
				break;
			
			case 3:
				for(int i=0;i<MAX-1;++i){
					for(int j=i+1;j<MAX;++j){
						if(cad[i].idade>cad[j].idade){
							swap(i, j);	
						}
					}
				}
				break;
			case 4:
				for(int i=0;i<MAX-1;++i){
					for(int j=i+1;j<MAX;++j){
						if(cad[i].idade<cad[j].idade){
							swap(i, j);	
						}
					}
				}
				break;		
			case 5:
				printf("\n\033[31mSaindo...\033[0m\n\n");
				break;
			
			default:
				printf("\n\033[31mOpcao invalida, escolha novamente\033[0m\n\n");
				break;
		}
		if(escolha<5 && escolha>0){
			printf("\nN\tNome\tIdade\n\n");
			for(int i=0;i<MAX;i++){
				printf("%i\t%s\t%i\n\n", i+1, cad[i].nome, cad[i].idade);
			}
		}
	}
}

void corrigir(){
	int i, escolha, escolha2;
	printf("\nN\tNome\tIdade\n\n");
	for(i=0;i<MAX;i++){
		printf("%i\t%s\t%i\n\n", i+1, cad[i].nome, cad[i].idade);
	}
	while(escolha<0 || escolha>MAX){
		printf("Escolha uma pessoa da lista (Numero da posicao):\n\n");
		scanf("%i", &escolha);
		if(escolha<0 || escolha>MAX){
			printf("\n\033[31mOpcao invalida, tente novamente\033[0m\n");
		}
	}
	escolha--;
	while(escolha2!= 3){
		printf("\n1 - Nome\t2 - Idade\n");
		printf("3 - Sair\n\n");
		printf("O que deseja alterar?\n\n");
		scanf("%i", &escolha2);
		switch(escolha2){
			case 1:
				printf("\nInsira novo nome:\n\n");
				fflush(stdin);
				fgets(cad[escolha].nome, 255, stdin);
				aux[i].nome[strcspn(aux[i].nome, "\n")]='\0';
				printf("\n\033[92mAlteracao na posicao %i! Novo nome: %s \033[0m\n\n", escolha+1, cad[escolha].nome);
				break;
			
			case 2:
				printf("\nInsira novo idade:\n\n");
				scanf("%i", &cad[escolha].idade);
				printf("\n\033[92mAlteracao na posicao %i! Nova idade: %i \033[0m\n\n", escolha+1, cad[escolha].idade);
				break;
				
			case 3:
				printf("\n\033[31mSaindo...\033[0m\n");
				break;
			
			default:
				printf("\n\033[31mOpcao invalida, escolha novamente\033[0m\n\n");
				break;	
		}	
	}
	
	
}

void pesquisa_nome(){
	int i;
	char pesquisa[255];
	bool flag;
	flag = false;
	printf("\nInsira nome para pesquisa:\n\n");
	fflush(stdin);
	fgets(pesquisa, 255, stdin);
	pesquisa[strcspn(pesquisa, "\n")]='\0';
	for(i=0;i<MAX;++i){
		if(strcmp(pesquisa, cad[i].nome)==0){
			flag = true;
			break;
		}
	}
	flag?printf("\n\033[92mNome encontrado na posicao %i! (%s - %i)\033[0m\n\n", i+1, cad[i].nome, cad[i].idade):printf("\n\033[31mNome nao encontrado\033[0m\n\n");
}

void pesquisa_idade(){
	int pesquisa, i;
	bool flag;
	flag = false;
	printf("\nInsira idade para pesquisa:\n\n");
	scanf("%i", &pesquisa);
	for(i=0;i<MAX;++i){
		if(pesquisa==cad[i].idade){
			flag = true;
			break;
		}
	}
	flag?printf("\n\033[92mIdade encontrado na posicao %i! (%s - %i)\033[0m\n\n", i+1, cad[i].nome, cad[i].idade):printf("\n\033[31mIdade nao encontrado\033[0m\n\n");	
}

void aposentados(){
	bool aposentado;
	for(int i=0;i<MAX;i++){
		if(cad[i].idade>=60){
			aposentado=true;
			break;
		}
	}
	if(aposentado){
		printf("\nN\tNome\tIdade\n\n");
		for(int i=0;i<MAX;i++){
			cad[i].idade>=60?
			printf("%i\t%s\t%i\n\n", i+1, cad[i].nome, cad[i].idade):
			0;
		}
	}
	else{
		printf("\n\033[31mNao ha administrativos aposentados\033[0m\n\n");
	}
}

void ativos(){
	bool ativo;
	for(int i=0;i<MAX;i++){
		if(cad[i].idade<60){
			ativo=true;
			break;
		}
	}
	if(ativo){
		printf("\nN\tNome\t\tIdade\n\n");
		for(int i=0;i<MAX;i++){
			cad[i].idade>=60?
			0:printf("%i\t%s\t\t%i\n\n", i+1, cad[i].nome, cad[i].idade);
		}
	}
	else{
		printf("\n\033[31mNao ha administrativos ativos\033[0m\n\n");
	}
}

bool cadastro_check(){
	if(cadastrado){
		return true;
	}
	else{
		printf("\n\033[31mNao ha cadastros, cadastre-se apertando 1\033[0m\n\n");
		return false;
	}
}

int main(){
	int escolha;
	while(escolha!=8){
		printf("\033[2;30;43m Menu \033[0m\n\n");
		printf("1 - Cadastre os 50 administrativos\t"); printf("5 - Pesquisa por idade\n");
		printf("2 - Classificar os administrativos\t"); printf("6 - Listar aposentados\n");
		printf("3 - Correcao de erros no cadastro\t"); printf("7 - Listar ativos\n");
		printf("4 - Pesquisa por nome\t\t\t"); printf("8 - Sair\n\n");
		printf("Escolha uma opcao:\n\n");
		fflush(stdin);
		scanf("%i", &escolha);
		switch(escolha){
			case 1:
				cadastro();
				break;
			
			case 2:
				cadastro_check()?classificar():0;
				break;
			
			case 3:
				cadastro_check()?corrigir():0;
				break;
				
			case 4:
				cadastro_check()?pesquisa_nome():0;
				break;
				
			case 5:
				cadastro_check()?pesquisa_idade():0;
				break;
				
			case 6:
				cadastro_check()?aposentados():0;
				break;
			
			case 7:
				cadastro_check()?ativos():0;
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
