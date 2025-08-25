#include<stdio.h>


int main()
{
	int A[50], i, j, contador = 0;
    int B[60][60];
    int encontrado = 0;
    int valor_diagonal;
    
    // Preenche matriz B
    for(i = 0; i < 60; ++i){
        for(j = 0; j < 60; ++j){
            B[i][j] = i + 1;
        }
    }
    
    // Preenche array A
    for(i = 0; i < 50; ++i){
        A[i] = i + 1;
    }
	
	
	
	//transporta os numeros da diagonal principal para a variavel "valor diagonal"
	printf("\nQuantidade de numeros da diagonal principal da matriz 2D que coincidem com os da matriz 1D:\n");
    for (int i = 0; i < 50; i++) {
        valor_diagonal = B[i][i];
   
        if (valor_diagonal == A[i]) {     //if usado para aumentar +1 o contador cada vez que o numeros da diagonal é igual aos presentes na matriz 1D
        	contador++;
        }
	}
	//exibe o contador
	printf("%i", contador);
	
	return 0;
}
