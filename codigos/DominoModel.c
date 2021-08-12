#include "DominoModel.h"

void InicializacaoPeca(tipo_peca domino[]) {

    int i;
    int valorp1 = 0;
    int valorp2 = 0;
    int reset = 0;

    //fim da declara��o de vari�veis e struct

    //fun��o de inicializa��o das pe�as (REQ01)

    for(i=0; i<28; i++){
        if (i >= 7 && i < 13) valorp1 = 1;
        if (i >= 13  && i <18) valorp1 = 2;
        if (i >= 18  && i <22) valorp1 = 3;
        if (i >= 22  && i <25) valorp1 = 4;
        if (i >= 25  && i <27) valorp1 = 5;
        if (i == 27) valorp1 = 6;
        domino[i].p1 = valorp1;
    }

    for(i=0; i<28; i++){
        domino[i].p2 = valorp2;
        valorp2++;

        if(i == 6){
            reset = 1;
            valorp2 = reset;
        }
        if(i == 12){
            reset = 2;
            valorp2 = reset;
        }
        if(i == 17){
            reset = 3;
            valorp2 = reset;
        }
        if(i == 21){
            reset = 4;
            valorp2 = reset;
        }
        if(i == 24){
            reset = 5;
            valorp2 = reset;
        }
        if(i == 26){
            reset = 6;
            valorp2 = reset;
        }
    }

}

void desembaralhar(tipo_peca domino[]) {

    int i;
    int valorp1 = 0;
    int valorp2 = 0;
    int reset = 0;

    //fim da declaração de variáveis e struct

    //função de inicialização das peças (REQ01)

    for(i=0; i<28; i++){
        if (i >= 7 && i < 13) valorp1 = 1;
        if (i >= 13  && i <18) valorp1 = 2;
        if (i >= 18  && i <22) valorp1 = 3;
        if (i >= 22  && i <25) valorp1 = 4;
        if (i >= 25  && i <27) valorp1 = 5;
        if (i == 27) valorp1 = 6;
        domino[i].p1 = valorp1;
    }

    for(i=0; i<28; i++){
        domino[i].p2 = valorp2;
        valorp2++;

        if(i == 6){
            reset = 1;
            valorp2 = reset;
        }
        if(i == 12){
            reset = 2;
            valorp2 = reset;
        }
        if(i == 17){
            reset = 3;
            valorp2 = reset;
        }
        if(i == 21){
            reset = 4;
            valorp2 = reset;
        }
        if(i == 24){
            reset = 5;
            valorp2 = reset;
        }
        if(i == 26){
            reset = 6;
            valorp2 = reset;
        }
    }

}

