#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];              // Ex: "SP"
    char codigo[4];              // Ex: "A01"
    char nomeCidade[50];         // Ex: "São Paulo"
    int populacao;               // Ex: 12300000
    float area;                  // Ex: 1521.0
    float pib;                   // Ex: 699.28 (em bilhões, por exemplo)
    int pontosTuristicos;        // Ex: 15
    float densidadePopulacional; // Calculada
    float pibPerCapita;          // Calculado
};

int main() {
    // Cadastro das duas cartas (pré-definidas neste nível)
    struct Carta carta1 = {"SP", "A01", "São Paulo", 12300000, 1521.0, 699280.0, 15};
    struct Carta carta2 = {"RJ", "A02", "Rio de Janeiro", 6748000, 1200.0, 407100.0, 12};

    // Cálculo da densidade populacional e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Escolha do atributo para comparação (feito direto no código)
    // Opções: populacao, area, pib, densidadePopulacional, pibPerCapita
    char atributoEscolhido[] = "População"; 
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2

    // Comparação pelo atributo escolhido (exemplo: população)
    if (carta1.populacao > carta2.populacao) {
        vencedor = 1;
    } else if (carta2.populacao > carta1.populacao) {
        vencedor = 2;
    } else {
        vencedor = 0;
    }

    // Exibição do resultado
    printf("Comparação de cartas (Atributo: %s):\n", atributoEscolhido);
    printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
