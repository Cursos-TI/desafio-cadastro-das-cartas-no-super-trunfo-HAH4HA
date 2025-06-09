#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char estado;                  
    char codigo[4];              
    char nomeCidade[100];        
    unsigned long int populacao; 
    float area;                  
    float pib;                   
    int pontosTuristicos;       
    float densidadePopulacional; 
    float pibPerCapita;          
    float superPoder;            
} Carta;

void lerCarta(Carta *carta, int numero) {
    printf("\nDigite os dados da Carta %d:\n", numero);
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    getchar(); // Consumir '\n' pendente
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    size_t len = strlen(carta->nomeCidade);
    if (len > 0 && carta->nomeCidade[len - 1] == '\n') {
        carta->nomeCidade[len - 1] = '\0';
    }

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    
    carta->densidadePopulacional = carta->area > 0 ? (float)carta->populacao / carta->area : 0;

    
    carta->pibPerCapita = carta->populacao > 0 ? (carta->pib * 1e9f) / carta->populacao : 0;

    
    float inversoDensidade = carta->densidadePopulacional > 0 ? 1.0f / carta->densidadePopulacional : 0;
    carta->superPoder = (float)carta->populacao + carta->area + (carta->pib * 1e9f) +
                        (float)carta->pontosTuristicos + carta->pibPerCapita + inversoDensidade;
}

void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);
}

int main() {
    Carta carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}
