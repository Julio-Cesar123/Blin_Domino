#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct peca{ //definição da peça (struct)
        int p1;
        int p2;
        int aparicao;//quant. de vezes que a peca apareceu
    } tipo_peca;

void Menu();
void LimparInterface();
void ExibicaoPeca(tipo_peca domino[]);
void embaralhar();
void InicializacaoPeca(tipo_peca domino[]);
void desembaralhar(tipo_peca domino[]);

int main() {

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

    return 0;
}


void Menu() { //hub do sistema
        
    printf("\n    _________________ \t\t      ***********************                   _________________");
    printf("\n    ||             || \t\t\t     Bem-Vindo                          ||             ||");
    printf("\n    ||  O       O  || \t\t\t       ao                               ||  O       O  ||");
    printf("\n    ||             || \t\t\t     Meu Jogo                           ||             ||");
    printf("\n    ||  O       O  || \t\t      ***********************                   ||  O       O  ||");
    printf("\n    ||             || \t\t\t  -=--=DOMINO=--=-                      ||             ||");
    printf("\n    ||  O       O  ||     _________________________________________________     ||  O       O  ||");
    printf("\n    ||_____________|| \t\t >Pressione  <1> para embaralhar as pecas       ||_____________||");
    printf("\n    ||             || \t\t                                                ||             ||");
    printf("\n    ||  O       O  || \t\t >Pressione  <2> para organizar as pecas        ||  O       O  ||");
    printf("\n    ||             || \t\t                                                ||             ||");
    printf("\n    ||  O       O  || \t\t >Pressione  <3> para mostrar as pecas          ||  O       O  ||");
    printf("\n    ||             ||                                                           ||             ||");
    printf("\n    ||  O       O  || \t\t >Pressione  <4> para sair                      ||  O       O  ||");
    printf("\n    ||_____________||     _________________________________________________     ||_____________||");
}

void LimparInterface(){ //limpa o sistema
    char op;
    printf("\n\n................Press <ENTER> to continue...................");
    while( (op = fgetc(stdin)) != EOF && op != '\n') {}
    getchar( );
    system("clear");//("cls") para Windows
}

void InicializacaoPeca(tipo_peca domino[]) {

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

void ExibicaoPeca(tipo_peca domino[]) {
    for(int i=0; i<28; i++){
        printf("peca: %d --> %d | %d\n", i+1, domino[i].p1, domino[i].p2);
    }
}

void embaralhar(tipo_peca domino[], int  array_tamanho) {
    srand(time(NULL));
    int r, troca;

    for(int i= array_tamanho-1; i>=0; i--){
        r=rand() % array_tamanho;
        troca=domino[i].p1;
        domino[i].p1=domino[r].p1;
        domino[r].p1=troca;
        troca=domino[i].p2;
        domino[i].p2=domino[r].p2;
        domino[r].p2=troca;
    }

/*    for(int i= array_tamanho-1; i>=0; i--){
        r=rand() % array_tamanho;
        troca=domino[i].p2;
        domino[i].p2=domino[r].p2;
        domino[r].p2=troca;
    }
*/
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
