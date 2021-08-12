#ifndef DOMINOMODEL_H_
#define DOMINOMODEL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct peca{ //definição da peça (struct)
        int p1;
        int p2;
        int aparicao;//quant. de vezes que a peca apareceu
    } tipo_peca;

void InicializacaoPeca(tipo_peca domino[]);

void desembaralhar(tipo_peca domino[]);

void embaralhar(tipo_peca domino[], int  array_tamanho);

#endif