#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int validarOpcao0ou1(int valor) {
    while (valor != 0 && valor != 1) {
        printf("Valor inválido! Digite apenas 0 ou 1: ");
        scanf("%d", &valor);
    }
    return valor;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int continuar = 1;
    int opcaoInformada;
    
    printf("--- Simulador de Entregas Inicializado ---\n");
    
    do {
        printf("\n[Processando nova entrega...]\n");
     
        printf("\nDeseja processar outra entrega? (1 - Sim, 0 - Não): ");
        scanf("%d", &opcaoInformada);
        continuar = validarOpcao0ou1(opcaoInformada);
        
    } while (continuar == 1);
    
    printf("\n--- Sessão Encerrada. Exibindo resumo final... ---\n");
    
    return 0;
}
