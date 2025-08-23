#include<stdio.h>

int main(){
	int notas[80], i, j;
	float freq[11]={0}, freqrel[11]={0};
	printf("Insira as notas:\n\n");
	for(i=0;i<80;++i){
		printf("Aluno %i:\n", i+1);
		scanf("%i", &notas[i]);
		while(notas[i]>10||notas[i]<0){
			printf("Numero invalido tente novamente\n");
			printf("Aluno %i:\n", i+1);
			scanf("%i", &notas[i]);
		}
	}
	for(i=0;i<11;++i){
		for(j=0;j<80;++j){
			if(i==notas[j]){
				freq[i]+=1;
			}
		}
	}
	for(i=0;i<11;++i){
		freqrel[i]=freq[i]/80;
	}
	printf("Notas\tFrequencia Absoluta\tFrequencia Relativa\n");
	for(i=0;i<11;++i){
		printf("%i\t%.0f\t\t\t%.3f\n", i, freq[i], freqrel[i]);
	}
  return 0;
}
