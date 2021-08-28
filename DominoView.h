#ifndef DOMINOVIEW_H_
#define DOMINOVIEW_H_

#include "DominoModel.h"


void imagem();

void menu();

char menuJogo();

char opcao();

void exibicaoPeca(tipo_peca dominoAux[]);

int entraJogador();

void visualizarPeca(tipo_peca dominoAux[], tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void mostrarMesa(tipo_mesa tabuleiro[]);

int moverTela(int quant);

void limparInterface();

void hubJogador(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void jogodeDois(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void alocaPeca(tipo_jogo domino[],tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa tabuleiro[]);

void mostraRegras();

void mostraNome();

void mostraMenu();

#endif