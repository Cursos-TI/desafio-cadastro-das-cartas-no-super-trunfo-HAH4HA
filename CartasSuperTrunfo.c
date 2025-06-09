#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    char estado;                  // Letra de A a H
    char codigo[4];               // Ex: A01, B03
    char nomeCidade[100];        // Nome da cidade
    int populacao;               // População
    float area;                  // Área em km²
    float pib;                   // PIB
    int pontosTuristicos;       // Número de pontos turísticos
} Carta;


void lerCarta(Carta *carta, int numero) {
    printf("\nDigite os dados da Carta %d:\n", numero);
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar(); // Consumir o '\n' pendente
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    
    size_t len = strlen(carta->nomeCidade);
    if (len > 0 && carta->nomeCidade[len - 1] == '\n') {
        carta->nomeCidade[len - 1] = '\0';
    }

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}


void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    Carta carta1, carta2;

    
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
