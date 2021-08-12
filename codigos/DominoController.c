#include "DominoController.h"

void Controller() {

    tipo_peca domino[28]; //declaração das variáveis
    bool veri=true;
    int opcao, tamanho=28;


    InicializacaoPeca(domino);

    do {
        Menu();

        printf("\n\n\tDigite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1: // embaralha peça
                embaralhar(domino, tamanho);
                LimparInterface();
                break;

            case 2: //organiza peça
                desembaralhar(domino);
                LimparInterface();
                break;

            case 3: //mostra peça
                ExibicaoPeca(domino);
                LimparInterface();
                break;

            case 4:
                veri=false;
                break;

            default:
                printf("Opps!!! Voce deve ter digitado algo errado!");

        }
    }while(veri==true);

}


