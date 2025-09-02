#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[100];
    float salarioAtual;
    float novoSalario;
    int aumento;
};

struct Funcionario f;
int opcao;
int resultado_scan;
    
void calcSal(){
    if (f.salarioAtual <= 400) {
        f.aumento = 15;
    } else if (f.salarioAtual <= 700) {
        f.aumento = 12;
    } else if (f.salarioAtual <= 1000) {
        f.aumento = 10;
    } else if (f.salarioAtual <= 1800) {
        f.aumento = 7;
    } else if (f.salarioAtual <= 2500) {
        f.aumento = 4;
    } else {
        f.aumento = 0;
    }
    f.novoSalario = f.salarioAtual + (f.salarioAtual * f.aumento / 100);
}

void exibir(){
    printf("\n--- Resultado ---\n");
    printf("Nome do funcionario: %s\n", f.nome);
    printf("Percentual de aumento: %d%%\n", f.aumento);
    printf("Salario atual: R$ %.2f\n", f.salarioAtual);
    printf("Novo salario: R$ %.2f\n", f.novoSalario);
}

int main() {
    do {
        printf("\nDigite 0 para sair ou 1 para cadastrar um funcionario: ");
        resultado_scan = scanf("%d", &opcao);
        while (getchar() != '\n');
        if (resultado_scan != 1) {
            printf("Entrada invalida! Digite apenas 0 ou 1.\n");
            continue;
        }
        if (opcao == 1) {
            printf("Nome do funcionario: ");
            if (fgets(f.nome, sizeof(f.nome), stdin) == NULL) {
                printf("Erro ao ler o nome.\n");
                continue;
            }
            f.nome[strcspn(f.nome, "\n")] = '\0';
            printf("Salario atual: R$ ");
            resultado_scan = scanf("%f", &f.salarioAtual);
            while (getchar() != '\n');
            if (resultado_scan != 1 || f.salarioAtual < 0) {
                printf("Salario invalido! Digite um valor numerico positivo.\n");
                continue;
            }
            calcSal();
            exibir();
        } else if (opcao != 0) {
            printf("Opcao invalida! Digite apenas 0 ou 1.\n");
        }
    } while (opcao != 0);
    printf("\nPrograma encerrado.\n");
    return 0;
}
