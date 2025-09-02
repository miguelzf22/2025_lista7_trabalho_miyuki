#include <stdio.h>

int a = 1, b=0, quant=0,soma=0,med=0,maior[2]={0}, f[5]={0},ft[5]={0},c[2]={0},par[2]={0};

void calc(){
quant ++;
soma += b;
med = soma/quant;
if(quant == 1) {
    maior[0] = b;
    maior[1] = b;
} else {
    if(b < maior[0]) maior[0] = b;
    if(b > maior[1]) maior[1] = b;
}

if(b < 0){
	f[0]++;
	ft[0]+=b;
}else if(b >= 0 && b < 15){
	f[1]++;
	ft[1]+=b;
}else if(b >= 15 && b < 100 ){
	f[2]++;
	ft[2]+=b;
}else if( b >= 100 && b < 1000){
	f[3]++;
	ft[3]+=b;
}else if(b > 1000){
	f[4]++;
	ft[4]+=b;
}


if(b % 2 == 0){
	c[0]++;
	par[1]+=b;
}else{
	c[1]++;
	par[0]+=b;
}
}

void show(){
    printf("A media dos elementos ate agora e de: %d\n O menor numero ate agora e %d\n O maior numero foi %d\n Foi fornecido %d menores que 0 sendo a soma deles %d\n Foi fornecido %d numeros menores que 15 sendo a soma deles %d\n Foi fornecido %d numeros entre 16 e 100, sendo a soma deles %d\n Foi fornecido %d numeros, entre 101 e 1000 sendo a soma deles %d\n Foi fornecido %d maiores que 1000 sendo a soma deles %d\n Foi fornecido %d numeros pares sendo a soma deles %d\n Foi fornecido %d numeros impares sendo a soma deles %d\n Digite outro numero ou encerre o programa: \n ", med, maior[0], maior[1],f[0],ft[0],f[1],ft[1],f[2],ft[2],f[3],ft[3],f[4],ft[4],c[0],par[1],c[1],par[0]);
};

int main(){
printf("Digite um numero inteiro e de enter, ou (0) para parar\n");
while(a){
scanf("%d", &b);
if(b==0){
	return 0;
}
calc();
show();
b=0;
}
return 0;
}
