#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para a carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

int main() {
    // (Código para definição de cartas, embaralho, distribuição, etc.)
    // Exemplo de definição de cartas
    Carta cartas[10];
    strcpy(cartas[0].nome, "Brasil");
    cartas[0].populacao = 210000000;
    cartas[0].area = 8500000.0;
    cartas[0].pib = 2000000000.0;
    cartas[0].pontos_turisticos = 500;

    // (Outros exemplos de cartas)

    // (Código para embaralhar e distribuir)

    // Exemplo de comparação (um jogador escolhe uma carta e uma característica)
    int jogador = 0;
    int carta_escolhida = 0;
    char caracteristica[50];

    printf("Jogador %d, escolha uma carta (0-%d): ", jogador + 1, 9);
    scanf("%d", &carta_escolhida);

    printf("Escolha uma característica para comparar (populacao, area, pib, pontos_turisticos): ");
    scanf("%s", caracteristica);

    // (Código para comparar e determinar o vencedor)

    return 0;
}