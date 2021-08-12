#include "DominoModel.h"
#include "DominoView.h"

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
    printf("\n    _________________     _________________________________________________     _________________");
    }

void ExibicaoPeca(tipo_peca domino[]) {
    for(int i=0; i<28; i++){
        printf("peca: %d --> %d | %d\n", i+1, domino[i].p1, domino[i].p2);
    }
}

void LimparInterface(){ //limpa o sistema
    char op;
    printf("\n\n................Pressione <ENTER> to continue...................");
    while( (op = fgetc(stdin)) != EOF && op != '\n') {}
    getchar( );
    system("cls");//("clear") para Linux
}
