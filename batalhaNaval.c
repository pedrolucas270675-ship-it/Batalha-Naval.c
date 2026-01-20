#include <stdio.h>
#include <stdlib.h>

// Definindo constantes para facilitar a mudanca de tamanho depois
#define TAM 10
#define NAVIO 3
#define HAB 5

// ---------------- TABULEIRO ----------------

// Funcao para zerar a matriz (agua = 0)
void inicializarTabuleiro(int t[TAM][TAM]) {
    for(int i = 0; i < TAM; i++)
        for(int j = 0; j < TAM; j++)
            t[i][j] = 0; // 0 representa agua
}

// Mostra o tabuleiro na tela
void exibirTabuleiro(int t[TAM][TAM]) {
    printf("\nTABULEIRO:\n\n");
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

// ---------------- NAVIOS ----------------

// Verifica se o navio cabe no tabuleiro e se nao vai bater em outro
int podePosicionar(int t[TAM][TAM], int l, int c, int dx, int dy) {
    for(int i = 0; i < NAVIO; i++) {
        // Calcula a posicao de cada parte do navio
        int x = l + i * dx;
        int y = c + i * dy;

        // Verifica se saiu do mapa (limites da matriz)
        if(x < 0 || x >= TAM || y < 0 || y >= TAM)
            return 0; // Invalido

        // Verifica sobreposicao (se ja tem navio la)
        if(t[x][y] != 0)
            return 0; // Invalido
    }
    return 1; // Tudo certo, pode colocar
}

// Coloca o navio na matriz (marca com 3)
void posicionarNavio(int t[TAM][TAM], int l, int c, int dx, int dy) {
    for(int i = 0; i < NAVIO; i++)
        t[l + i * dx][c + i * dy] = 3;
}

// ---------------- HABILIDADES (NIVEL MESTRE) ----------------

// Cria a matriz da habilidade CRUZ
void criarCruz(int h[HAB][HAB]) {
    for(int i = 0; i < HAB; i++) {
        for(int j = 0; j < HAB; j++) {
            // Pinta apenas a linha do meio ou a coluna do meio
            if(i == HAB/2 || j == HAB/2)
                h[i][j] = 1;
            else
                h[i][j] = 0;
        }
    }
}

// Cria a matriz da habilidade CONE (Triangulo)
void criarCone(int h[HAB][HAB]) {
    for(int i = 0; i < HAB; i++) {
        for(int j = 0; j < HAB; j++) {
            // Logica do triangulo: a largura aumenta conforme desce a linha (i)
            // Forma um cone apontando para cima
            if(j >= HAB/2 - i && j <= HAB/2 + i)
                h[i][j] = 1;
            else
                h[i][j] = 0;
        }
    }
}

// Cria a matriz da habilidade OCTAEDRO (Losango)
void criarOctaedro(int h[HAB][HAB]) {
    for(int i = 0; i < HAB; i++) {
        for(int j = 0; j < HAB; j++) {
            // Usa a Distancia de Manhattan (soma das diferencas absolutas)
            // Se a distancia ate o centro for menor que o raio, pinta.
            int dist = abs(i - HAB/2) + abs(j - HAB/2);
            if(dist <= HAB/2)
                h[i][j] = 1;
            else
                h[i][j] = 0;
        }
    }
}

// Aplica a matriz de habilidade (5x5) no tabuleiro principal (10x10)
void aplicarHabilidade(int t[TAM][TAM], int h[HAB][HAB], int l, int c) {
    // Centraliza a habilidade na coordenada escolhida
    for(int i = 0; i < HAB; i++) {
        for(int j = 0; j < HAB; j++) {
            if(h[i][j] == 1) {
                // Calcula a posicao real no tabuleiro
                int x = l + i - HAB/2;
                int y = c + j - HAB/2;

                // Verifica se esta dentro do tabuleiro
                if(x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    // So pinta se for agua (0), para nao apagar os navios (3)
                    if(t[x][y] == 0)
                        t[x][y] = 5;
                }
            }
        }
    }
}

// ---------------- MAIN ----------------

int main() {
    int tabuleiro[TAM][TAM];
    // Matrizes para guardar os desenhos das habilidades
    int cruz[HAB][HAB], cone[HAB][HAB], octaedro[HAB][HAB];

    inicializarTabuleiro(tabuleiro);

    // --- NIVEL NOVATO: Navios Horizontais e Verticais ---
    // Posiciona navio horizontal na linha 2, coluna 1
    if(podePosicionar(tabuleiro, 2, 1, 0, 1))
        posicionarNavio(tabuleiro, 2, 1, 0, 1);

    // Posiciona navio vertical na linha 5, coluna 4
    if(podePosicionar(tabuleiro, 5, 4, 1, 0))
        posicionarNavio(tabuleiro, 5, 4, 1, 0);

    // --- NIVEL AVENTUREIRO: Navios Diagonais ---
    // Diagonal principal (\)
    if(podePosicionar(tabuleiro, 1, 6, 1, 1))
        posicionarNavio(tabuleiro, 1, 6, 1, 1);

    // Diagonal secundaria (/)
    if(podePosicionar(tabuleiro, 7, 2, -1, 1))
        posicionarNavio(tabuleiro, 7, 2, -1, 1);

    // --- NIVEL MESTRE: Habilidades Especiais ---
    // Gera as matrizes das habilidades
    criarCruz(cruz);
    criarCone(cone);
    criarOctaedro(octaedro);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cruz, 4, 4);      // Cruz no centro
    aplicarHabilidade(tabuleiro, cone, 0, 5);      // Cone no topo
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro embaixo

    exibirTabuleiro(tabuleiro);

    return 0;
}
