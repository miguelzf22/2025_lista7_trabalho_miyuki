#include <stdio.h>

int main(){

int a = 1, b, quant=0,soma=0,med,maior=0, menor=0;
int f1=0, f2=0, f3=0, f4=0, f5=0;
int f1t=0, f2t=0, f3t=0, f4t=0, f5t=0;
int c1 = 0, c2 = 0,par = 0, im = 0;

printf("Digite um numero inteiro e de enter, ou (0) para parar\n");
while(a){
scanf("%d", &b);
if(b ==0){
	return 0;
}
quant ++;
soma += b;
med = soma/quant;
if(quant == 1) {
    menor = b;
    maior = b;
} else {
    if(b < menor) menor = b;
    if(b > maior) maior = b;
}

if(b < 0){
	f1++;
	f1t+=b;
}else if(b >= 0 && b < 15){
	f2++;
	f2t+=b;
}else if(b >= 15 && b < 100 ){
	f3++;
	f3t+=b;
}else if( b >= 100 && b < 1000){
	f4++;
	f4t+=b;
}else if(b > 1000){
	f5++;
	f5t+=b;
}


if(b % 2 == 0){
	c1++;
	par+=b;
}else{
	c2++;
	im+=b;
}

printf("A media dos elementos ate agora e de: %d\n O menor numero ate agora e %d\n O maior numero foi %d\n Foi fornecido %d menores que 0 sendo a soma deles %d\n Foi fornecido %d numeros menores que 15 sendo a soma deles %d\n Foi fornecido %d menores que 100 sendo a soma deles %d\n Foi fornecido %d menores que 1000 sendo a soma deles %d\n Foi fornecido %d maior que 1000 sendo a soma deles %d\n Foi fornecido %d numeros pares sendo a soma deles %d\n Foi fornecido %d numeros impares sendo a soma deles %d\n Digite outro numero ou encerre o programa: \n ", med, menor, maior,f1,f1t,f2,f2t,f3,f3t,f4,f4t,f5,f5t,c1,par,c2,im);

b=0;
}



return 0;
}
