#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %c ", 'A' + j); // Colunas com letras A–J
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Linhas continuam numeradas (0–9)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        if (tabuleiro[linha][coluna + j] != 0) {
            return 0;
        }
    }
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][coluna + j] = 3;
    }
    return 1;
}

int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0;
        }
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    int linhaNavio1 = 2, colunaNavio1 = 3;
    int linhaNavio2 = 5, colunaNavio2 = 6;

    if (!posicionarNavioHorizontal(tabuleiro, linhaNavio1, colunaNavio1)) {
        printf("Erro ao posicionar o navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaNavio2, colunaNavio2)) {
        printf("Erro ao posicionar o navio vertical!\n");
    }

    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}