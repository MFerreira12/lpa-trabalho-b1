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

int validarModalidade(int mod) {
    while (mod < 1 || mod > 3) {
        printf("Modalidade inválida! Escolha de 1 a 3: ");
        scanf("%d", &mod);
    }
    return mod;
}

float calcularValorBase(float dist) {
    if (dist <= 5.0) return 8.00;
    if (dist <= 15.0) return 12.00;
    if (dist <= 30.0) return 18.00;
    return 25.00;
}

float calcularAdicionalPeso(float peso) {
    if (peso <= 2.0) return 0.00;
    if (peso <= 5.0) return 0.05;
    if (peso <= 10.0) return 0.10;
    return 0.15;
}

float calcularAdicionalModalidade(int mod) {
    if (mod == 1) return 0.00;
    if (mod == 2) return 0.20;
    return 0.40;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int continuar = 1;
    int opcaoInformada;
    int modalidade;
    int protecao;
	int totalEntregas = 0;
	
	float distancia;
    float valorBase;
    float subtotalInicial;
    float peso;
    float percentualPeso;
    float subtotalComPeso;
    float percentualModalidade;
    float subtotalComModalidade;
    float valorFinalEntrega;
    float faturamentoTotal = 0.0;
    float maiorValor = 0.0;
    float menorValor = 0.0;
    
    printf("--- Simulador de Entregas Inicializado ---\n");
    
    do {
        printf("\n[Processando nova entrega...]\n");
        
        printf("Digite a distância da entrega em km: ");
        scanf("%f", &distancia);
        while (distancia <= 0) {
            printf("Distância inválida! Deve ser maior que 0. Digite novamente: ");
            scanf("%f", &distancia);
        }
        
        printf("Digite o peso da entrega em kg: ");
        scanf("%f", &peso);
        while (peso <= 0) {
            printf("Peso inválido! Deve ser maior que 0. Digite novamente: ");
            scanf("%f", &peso);
        }
        
        printf("\nEscolha a modalidade de entrega:\n");
        printf("\n 1 - Econômica (Sem adicional)\n");
        printf(" 2 - Expressa (+20%%)\n");
        printf(" 3 - Prioritária (+40%%)\n");
        printf("\nDigite a opção (1-3): ");
        scanf("%d", &modalidade);
        modalidade = validarModalidade(modalidade);
        
        printf("\nDeseja incluir proteção contra danos? (1 - Sim, 0 - Não): ");
        scanf("%d", &protecao);
        protecao = validarOpcao0ou1(protecao);
        
        valorBase = calcularValorBase(distancia);
        subtotalInicial = valorBase + (distancia * 1.20);
        
        percentualPeso = calcularAdicionalPeso(peso);
        subtotalComPeso = subtotalInicial + (subtotalInicial * percentualPeso);
        
        percentualModalidade = calcularAdicionalModalidade(modalidade);
        subtotalComModalidade = subtotalComPeso + (subtotalComPeso * percentualModalidade);
        
        if (protecao == 1) {
            valorFinalEntrega = subtotalComModalidade + 15.00;
        } else {
            valorFinalEntrega = subtotalComModalidade;
        }
        
        printf("\nValor final desta entrega: R$ %.2f\n", valorFinalEntrega);
        
        totalEntregas++;
        faturamentoTotal += valorFinalEntrega;
        
        if (totalEntregas == 1) {
            maiorValor = valorFinalEntrega;
            menorValor = valorFinalEntrega;
        } else {
            if (valorFinalEntrega > maiorValor) {
                maiorValor = valorFinalEntrega;
            }
            if (valorFinalEntrega < menorValor) {
                menorValor = valorFinalEntrega;
            }
        }
        
        printf("\nDeseja processar outra entrega? (1 - Sim, 0 - Não): ");
        scanf("%d", &opcaoInformada);
        continuar = validarOpcao0ou1(opcaoInformada);
        
    } while (continuar == 1);
    
    printf("\n==========RESUMO DA SESSÃO=============\n");
    printf("Total de entregas processadas: %d\n", totalEntregas);
    printf("Faturamento total do período: R$ %.2f\n", faturamentoTotal);
    printf("Maior valor de entrega registrado: R$ %.2f\n", maiorValor);
    printf("Menor valor de entrega registrado: R$ %.2f\n", menorValor);
    printf("=========================================\n");
    
    return 0;
}


