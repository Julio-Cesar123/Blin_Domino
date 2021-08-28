#ifndef DOMINOMODEL_H_
#define DOMINOMODEL_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

//Essas variaveis representam uma referencia para a locomação das peças na mesa
#define posicaoI 50
#define posicaoF 51

/*  p1 e p2 representa metade da peca 

    maiorP representa a maior peca 

    tipoP = 'D' dobrinha / 'N' "normal"


    status representa a disponibilidade 
    de compra da peca

    h_esq e h_dir representa a quantidade de colunas 
    que o jogador que mover  mapa[50] da mesa para 
    visualicao das pecas 

    -------------------(LEGENDA)------------------
      * maiorP = 1 = representa que essa peca é a maior peca DOBRADA do jogador 
                 2 = representa que essa peca é a maior peca NORMAL do jogador  
                 0 = representa as demais pecas
      
      * status = C = peca disponivel para compra
                 V = peca do monte foi comprada ("Vendida")
                 U = a peca esta sendo usada  
                 M = peca do jogador foi colocada na mesa
                 L  = acontece quando a peça não está disponivel para o jogador | espaço livre

    ----------------------------------------------
*/

typedef struct peca{ 
    int p1;
    int p2;
    int maiorP;
    char tipoP;
    char status;

} tipo_peca;

typedef struct mesa{
    int mapa[100]; 
    //Escopo de visualizacao
    int h_esq;
    int h_dir;
 

    // essas variáveis vão representar o valor das pontas do tabuleiro
    int ext_esq ;
    int ext_dir ; 

} tipo_mesa;

typedef struct jogo{
    int pontosJ1;
    int pontosJ2;

    // Maior peca do jogo 
    // nao dos jogadores

    int j_maiorP1;
    int j_maiorP2;

    int jogaPrimeiro;
    int rodadaVez;

    int jogou;
    
} tipo_jogo;




void inicializacaoPeca(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[]);

void desembaralhar(tipo_peca dominoAux[]);

void embaralhar(tipo_peca dominoAux[], int array_tamanho);

void distribuirpecas(tipo_peca dominoAux[], tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void flush_in();

void trocaPeca(int x, tipo_peca dominoAux[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void defineTipo(tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void define_mPeca(tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void defineStatus(tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

char escDirecao();

int achaMaiorP(tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[] );

void verificaJog_1(tipo_jogo domino[], tipo_peca jogador1[], tipo_mesa tabuleiro[], char escolha, int peca);

void verificaJog_2(tipo_jogo domino[], tipo_peca jogador2[], tipo_mesa tabuleiro[], char escolha, int peca);

void comprarPeca(tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_mesa tabuleiro[]);


#endif