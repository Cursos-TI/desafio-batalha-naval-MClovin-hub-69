#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 4

// Inicializa o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro com letras nas colunas e números nas linhas
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        if (tabuleiro[linha][coluna + j] != 0) return 0;
    }
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][coluna + j] = 1;
    }
    return 1;
}

// Posiciona navio vertical
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 2;
    }
    return 1;
}

// Posiciona navio diagonal principal (↘, linha++ e coluna++)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        if (tabuleiro[linha + k][coluna + k] != 0) return 0;
    }
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[linha + k][coluna + k] = 3;
    }
    return 1;
}

// Posiciona navio diagonal secundária (↙, linha++ e coluna--)
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO < -1) return 0;
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        if (tabuleiro[linha + k][coluna - k] != 0) return 0;
    }
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[linha + k][coluna - k] = 3;
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas fixas para os 4 navios
    int linhaH = 2, colunaH = 4; // Horizontal
    int linhaV = 5, colunaV = 6; // Vertical
    int linhaD1 = 1, colunaD1 = 1; // Diagonal principal ↘
    int linhaD2 = 4, colunaD2 = 8; // Diagonal secundária ↙

    if (!posicionarNavioHorizontal(tabuleiro, linhaH, colunaH)) printf("Erro ao posicionar navio horizontal!\n");
    if (!posicionarNavioVertical(tabuleiro, linhaV, colunaV)) printf("Erro ao posicionar navio vertical!\n");
    if (!posicionarNavioDiagonalPrincipal(tabuleiro, linhaD1, colunaD1)) printf("Erro ao posicionar navio diagonal principal!\n");
    if (!posicionarNavioDiagonalSecundaria(tabuleiro, linhaD2, colunaD2)) printf("Erro ao posicionar navio diagonal secundária!\n");

    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}