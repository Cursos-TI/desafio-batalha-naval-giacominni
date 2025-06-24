#include <stdio.h>
#include <stdbool.h> // Para usar o tipo booleano

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define TAMANHO_NAVIO 3 // Tamanho fixo dos navios

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  "); // Espaço para alinhar com os números das colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Números das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se a posição está dentro dos limites do tabuleiro
bool ehPosicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO &&
            coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar sobreposição antes de posicionar o navio
bool podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, int tipo) {
    // tipo: 0 para horizontal, 1 para vertical, 2 para diagonal crescente, 3 para diagonal decrescente

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linhaInicial;
        int c = colunaInicial;

        if (tipo == 0) { // Horizontal
            c += i;
        } else if (tipo == 1) { // Vertical
            l += i;
        } else if (tipo == 2) { // Diagonal crescente (linha e coluna aumentam)
            l += i;
            c += i;
        } else if (tipo == 3) { // Diagonal decrescente (linha aumenta, coluna diminui)
            l += i;
            c -= i;
        }

        if (!ehPosicaoValida(l, c) || tabuleiro[l][c] == NAVIO) {
            return false; // Fora dos limites ou sobreposição
        }
    }
    return true;
}


// Função para posicionar um navio no tabuleiro
// tipo: 0 para horizontal, 1 para vertical, 2 para diagonal crescente, 3 para diagonal decrescente
bool posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial, int tipo) {
    if (!podePosicionarNavio(tabuleiro, linhaInicial, colunaInicial, tipo)) {
        return false; // Não foi possível posicionar o navio
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linhaInicial;
        int c = colunaInicial;

        if (tipo == 0) { // Horizontal
            c += i;
        } else if (tipo == 1) { // Vertical
            l += i;
        } else if (tipo == 2) { // Diagonal crescente (linha e coluna aumentam)
            l += i;
            c += i;
        } else if (tipo == 3) { // Diagonal decrescente (linha aumenta, coluna diminui)
            l += i;
            c -= i;
        }
        tabuleiro[l][c] = NAVIO;
    }
    return true; // Navio posicionado com sucesso
}


int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Posicionamento dos quatro navios
    // Dois navios horizontais/verticais
    // Navio 1: Horizontal
    if (!posicionarNavio(tabuleiro, 1, 1, 0)) {
        printf("Erro ao posicionar Navio 1. Verifique as coordenadas ou sobreposição.\n");
    }

    // Navio 2: Vertical
    if (!posicionarNavio(tabuleiro, 5, 8, 1)) {
        printf("Erro ao posicionar Navio 2. Verifique as coordenadas ou sobreposição.\n");
    }

    // Dois navios diagonais
    // Navio 3: Diagonal crescente (linha e coluna aumentam) - ALTERADO PARA (7,0)
    if (!posicionarNavio(tabuleiro, 7, 0, 2)) {
        printf("Erro ao posicionar Navio 3. Verifique as coordenadas ou sobreposição.\n");
    }

    // Navio 4: Diagonal decrescente (linha aumenta, coluna diminui)
    if (!posicionarNavio(tabuleiro, 2, 7, 3)) { // Ex: (2,7), (3,6), (4,5)
        printf("Erro ao posicionar Navio 4. Verifique as coordenadas ou sobreposição.\n");
    }

    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
