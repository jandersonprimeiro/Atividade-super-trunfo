#include <stdio.h>

#define TAM 10    // Tamanho fixo do tabuleiro 10x10
#define NAVIO 3   // Valor que representa um navio
#define AGUA 0    // Valor que representa água
#define TAM_NAVIO 3  // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // ========================
    // 1. Inicializa o tabuleiro
    // ========================
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // =====================================
    // 2. Define coordenadas dos dois navios
    // =====================================
    // Navio 1 - horizontal
    int linha_h = 2; // linha inicial
    int coluna_h = 4; // coluna inicial

    // Navio 2 - vertical
    int linha_v = 5;
    int coluna_v = 7;

    // ========================================
    // 3. Valida se estão dentro dos limites
    // ========================================
    if (coluna_h + TAM_NAVIO > TAM || linha_v + TAM_NAVIO > TAM) {
        printf("Erro: coordenadas invalidas! Navio fora do tabuleiro.\n");
        return 1;
    }

    // ==============================================
    // 4. Posiciona os navios (sem sobreposição)
    // ==============================================

    // Posiciona o navio horizontal
    for (j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[linha_h][coluna_h + j] = NAVIO;
    }

    // Verifica sobreposição antes de posicionar o vertical
    int sobreposicao = 0;
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_v + i][coluna_v] == NAVIO) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: navios se sobrepõem!\n");
        return 1;
    }

    // Posiciona o navio vertical
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = NAVIO;
    }

    // ========================
    // 5. Exibe o tabuleiro
    // ========================
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
