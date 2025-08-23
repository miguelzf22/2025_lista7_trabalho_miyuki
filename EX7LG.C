#include <stdio.h>
#include<stdlib.h>
#define BdOn "\e[1m"
#define BdOff "\e[0m"

int i,j,addCont=1,revCol=6,nIter[4]={0};
float sums[8]={0},matrix[6][6]={0},xDirVal[4]={0};

void printFunc(){
    system("cls");
    system("clear");
    printf("\n\t\t      %s\033[101m \033[32mDados inseridos \033[0m%s\n\n",BdOn,BdOff);
    printf("\033[95m");
    for(i=0;i<6;++i){
	    printf("\t| %d |",i);
	}
	printf("\n");
	printf("     -------------------------------------------------");
	printf("\n");
	for(i=0; i<6; ++i) {
	    printf("  %i |\t",i);
		for(j=0; j<6; ++j) {
			printf("|%.2f|\t",matrix[i][j]);
		}
		printf("\n");
	}
    printf("     -------------------------------------------------\n");
    printf("\n\t\t      %s\033[101m \033[32mIteracoes e soma \033[0m%s\n\n",BdOn,BdOff);
    printf("\033[96m     _________________________________________________\n");
    for(i=0; i<8; ++i) {
		if(i>=4){
		    printf("\t| Iteracoes: %d | \t | Soma: %f |\n",12,sums[i]);
		}
		else{
		    printf("\t| Iteracoes: %d | \t | Soma: %f |\n",nIter[i],sums[i]);
		}
	}
    printf("     _________________________________________________\033[0m\n");
}

void regFunc(){
    for(i=0; i<6; ++i) {
		for(j=0; j<6; ++j) {
			printf("Digite o valor da posicao [%d][%d]\nInput: ",i,j);
			scanf("%f",&matrix[i][j]);
		}
		system("cls");
		system("clear");
	}
}

void calcFunc(){
    //diagonal esq-dir
	for(i=0; i<6; ++i) {
		for(j=0+addCont; j<6; ++j) {
			sums[0]+=matrix[i][j];
			nIter[0]++;
		}
		addCont++;
	}
	addCont=1;
	//diagonal dir-esq
	for(i=0; i<6; i++) {
		for(j=5-addCont; j>=0; --j) {
			sums[1]+=matrix[i][j];
			nIter[1]++;
		}
		addCont++;
	}
	//X top
	addCont=1;
	for(i=0; i<6; ++i) {
		for(j=0+addCont; j<6-addCont; ++j) {
			sums[2]+=matrix[i][j];
			nIter[2]++;
		}
		addCont++;
	}
	xDirVal[0]=sums[2];
	//X bot
	addCont=1;
	for(i=5; i>=0; --i) {
		for(j=0+addCont; j<6-addCont; ++j) {
			xDirVal[1]+=matrix[i][j];
		}
		addCont++;
	}
	//X left
	addCont=6;
	for(i=0; i<6; ++i) {
		if(i<=2) {
			for(j=5-addCont; j>=0; --j) {
                sums[3]+=matrix[i][j];
				nIter[3]++;
			}
			addCont--;
		}
		else {
		    addCont++;
			for(j=5-addCont; j>=0; --j) {
				sums[3]+=matrix[i][j];
				nIter[3]++;
			}
		}
	}
	xDirVal[2]=sums[3];
	//X right
	addCont=6;
	for(i=0; i<6; ++i) {
		if(i<=2) {
			for(j=0+addCont; j<=5; ++j) {
				xDirVal[3]+=matrix[i][j];
			}
			addCont--;
		}
		else {
		    addCont++;
			for(j=0+addCont; j<=5; ++j) {
				xDirVal[3]+=matrix[i][j];
			}
		}
	}
	//xDirVal 0 = top/ 1 = bot/ 2 = left / 3 = right
	sums[4]=xDirVal[2]+xDirVal[3];
	sums[5]=xDirVal[0]+xDirVal[1];
	sums[6]=xDirVal[0]+xDirVal[2];
	sums[7]=xDirVal[1]+xDirVal[2];
}

int main(void) {
	regFunc();
	calcFunc();
    printFunc();
}
//  /|--  \  /          <<>>   _____------_____
// ||:^) ----                 |               |
// \|--  /   \               |________________|