# Trabalho Final: Batalha Naval em C 🛳️

Esse é o meu projeto do jogo Batalha Naval, desenvolvido para praticar o uso de matrizes, vetores e loops em C. O código atende a todos os requisitos do trabalho (Níveis Novato, Aventureiro e Mestre).

## 📝 Sobre o Projeto
O objetivo principal foi aplicar lógica de programação para manipular um tabuleiro 10x10. Em vez de apenas posicionar coisas aleatoriamente, usei lógica matemática para validar as posições e criar as áreas de efeito.

**Legenda do Tabuleiro:**
* **0** = Água
* **3** = Navio (Ocupa 3 casas)
* **5** = Área atingida por habilidade

---

## 📸 Exemplo de Saida
O jogo exibe o tabuleiro no terminal desta forma:

```text
TABULEIRO:

0 0 0 5 5 5 5 5 0 0 
0 0 0 5 5 5 3 5 0 0 
0 3 3 3 5 5 5 3 0 0 
0 0 0 0 5 0 0 0 3 0 
0 0 5 5 5 5 5 0 0 0 
0 0 0 0 3 0 0 5 0 0 
0 0 0 0 3 0 5 5 5 0 
0 0 0 0 3 5 5 5 5 5 
0 0 0 0 0 0 5 5 5 0 
0 0 0 0 0 0 0 5 0 0 
```
## 🚀 O que foi implementado
**Nível 1:** Novato
Criei o tabuleiro 10x10.

Posicionei dois navios simples (um na horizontal e um na vertical).

Fiz a verificação para o navio não sair para fora do mapa.

**Nível 2:** Aventureiro
Adicionei navios na diagonal (tanto / quanto \).

Implementei a validação para impedir que um navio fique em cima do outro (sobreposição).

**Nível 3:** Mestre (Habilidades)
Aqui foi a parte mais complexa. As habilidades especiais não são desenhos fixos; elas são geradas pelo código usando loops e condições (if/else):

Cruz: Pinta a linha e a coluna do centro.

Cone: Um triângulo que aumenta a largura conforme desce as linhas.

Octaedro: Um losango feito calculando a distância do centro (usei a função abs).

Detalhe: Quando a habilidade acerta um navio, o código mantém o navio visível (3) e pinta apenas a água de cinza (5).

💻 Como Rodar
Usei o GCC para compilar. Para rodar, é só abrir o terminal na pasta do arquivo e digitar:

Compilar:

Bash

gcc batalhaNaval.c -o jogo
Executar:

Bash

.\jogo.exe
(Ou apenas ./jogo se estiver no Linux/Mac)

Aluno: Pedro Crespo Disciplina: Lógica de Programação / Algoritmos
