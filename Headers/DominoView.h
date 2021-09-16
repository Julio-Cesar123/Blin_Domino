#ifndef DOMINOVIEW_H_
#define DOMINOVIEW_H_

#include "DominoModel.h"


void imagem();

void menu();

char menuJogo();

char opcao();

void exibirPeca(tipo_peca dominoAux[]);

int entrarJogador();

void visualizarPeca(tipo_peca dominoAux[], tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void mostrarMesa(tipo_mesa tabuleiro[]);

void mostrarMesa2();

int moverTela(int quant);

void limparInterface();

void hubJogador(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_peca bot[]);

void jogodeDois(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void alocarPeca(tipo_jogo domino[],tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa tabuleiro[]);

void mostrarRegras();

void mostrarNome();

void mostrarMenu();

void mostrarErro();

void mostrarJ1();

void mostrarJ2();

void jogoAUTO(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca bot[], tipo_peca monte[]);

#endif