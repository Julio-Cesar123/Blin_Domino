#include "DominoController.h"

//menu de comando principal
void controller() {

    //declaração das variáveis
    tipo_jogo domino[1];
    tipo_mesa tabuleiro[1];

    tipo_peca monte[14];
    tipo_peca jogador1[21];
    tipo_peca jogador2[21];
    tipo_peca dominoAux[28];

    bool veri= true;
    int opcao, tamanho = 28;
    /*int jogador1[28][2], jogador2[28][2], monte[28][2];
    int mesa[20][50];*/

    tabuleiro[0].ext_dir = 2;
    tabuleiro[0].ext_esq = 2;

    inicializarPeca(dominoAux, domino, tabuleiro);

    do {
        menu();

        printf("\n\n\tDigite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1: //começa o jogo
                hubJogador(dominoAux, domino, tabuleiro, jogador1, jogador2, monte);

                break;

            case 2: // embaralha peça
                embaralhar(dominoAux, tamanho);
                limparInterface();
                
                break;

            case 3: //organiza peça
                desembaralhar(dominoAux);
                limparInterface();
                break;

            case 4://mostra peça
                exibirPeca(dominoAux);
                printf("\n");
                limparInterface();
                
                break;
                
            case 5://Regras do jogo
                mostrarRegras();
                limparInterface();
                break;

            case 6:  //sai do terminal
                veri=false;
                break;

            default: //digitou um número invalido
                mostrarErro();
                printf("\nOpps!!! Voce deve ter digitado algo errado!");
                limparInterface();

        }
    }while(veri==true);
}