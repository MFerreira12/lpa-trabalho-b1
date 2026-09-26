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

float calcularValorBase(float dist) {
    if (dist <= 5.0) return 8.00;
    if (dist <= 15.0) return 12.00;
    if (dist <= 30.0) return 18.00;
    return 25.00;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int continuar = 1;
    int opcaoInformada;
    float distancia;
    float valorBase;
    float subtotalInicial;
    
    printf("--- Simulador de Entregas Inicializado ---\n");
    
    do {
        printf("\n[Processando nova entrega...]\n");
        
        printf("Digite a distância da entrega em km: ");
        scanf("%f", &distancia);
        while (distancia <= 0) {
            printf("Distância inválida! Deve ser maior que 0. Digite novamente: ");
            scanf("%f", &distancia);
        }
        
        valorBase = calcularValorBase(distancia);
        subtotalInicial = valorBase + (distancia * 1.20);
        
        printf("Subtotal parcial (Distância + Valor-Base): R$ %.2f\n", subtotalInicial);
        
        printf("\nDeseja processar outra entrega? (1 - Sim, 0 - Não): ");
        scanf("%d", &opcaoInformada);
        continuar = validarOpcao0ou1(opcaoInformada);
