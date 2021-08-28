#include "DominoModel.h"
#include "DominoView.h"

void imagem(){ //bolo

printf("\n\t                   ,                    ");
printf("\n\t                  /(                    ");
printf("\n\t                 (  )               ");
printf("\n\t                 ,\\/,                   ");
printf("\n\t                 |--|                   ");
printf("\n\t                 |  |                   ");    
printf("\n\t                 |  |                   ");
printf("\n\t       .-'~--..__|  |                   ");
printf("\n\t      |~-,,__    `..|'--..__         ");
printf("\n\t      |      ~~''--,,__     ~-.      ");
printf("\n\t      |                ~~''--~|      ");
printf("\n\t      |    .                  |      ");
printf("\n\t      |   ' `     _.          |      ");
printf("\n\t      | ,'   \\   /  \\       .-|      ");
printf("\n\t      |'      `-'    \\     /  |      ");
printf("\n\t      |               `._,'   |      ");
printf("\n\t   _-~|                       |      ");
printf("\n\t   -   ~-..__                 |._    ");
printf("\n\t    ~-.__    ~~''--..__       |  -.  ");
printf("\n\t         ~~''--..__    ~~''--'~  ,'  ");
printf("\n\t                   ~~''--....--'~    ");
        
}

void menu()
{ //hub do sistema

    mostraNome();

    printf("\n\t\t    _________________ \t\t      ***********************                    _________________");
    printf("\n\t\t    ||             || \t\t\t     Bem-Vindo                           ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t\t        ao                               ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t\t       Jogo                              ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t      ***********************                    ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t\t  -=--=DOMINO=--=-                       ||             ||");
    printf("\n\t\t    ||  O       O  ||     _________________________________________________      ||  O       O  ||");
    printf("\n\t\t    ||_____________|| \t\t >Pressione  <1> para jogar                      ||_____________||");
    printf("\n\t\t    ||             || \t\t >Pressione  <2> para embaralhar as pecas        ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <3> para organizar as pecas         ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t >Pressione  <4> para mostrar as pecas           ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <5> para mostrar as regras          ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t >Pressione  <6> para sair                       ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t                                                 ||  O       O  ||");
    printf("\n\t\t    ||_____________||    __________________________________________________      ||_____________||");
}                                                                  

void exibicaoPeca(tipo_peca dominoAux[])
{ //mostra as peças
    int k = 0;
    for (int i = 0; i < 28; i++)
    {
        k++;

        printf("peca: %d --> %d | %d\n", k , dominoAux[i].p1, dominoAux[i].p2);
    }
    puts("\n");

    
}


int entraJogador()
{ //detecta a qtd de jogadores

    int quant;
    scanf("%d", &quant);

    return quant;
}


void visualizarPeca(tipo_peca dominoAux[], tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[])
{


    //MOSTRA A PECA DO JOGADOR 1
    if(domino[0].rodadaVez % 2 != 0){
        printf("\n\t\t-=-=-=-=JOGADOR_1-=-=-=-=-\n");
        printf("\n");

        for (int i = 0; i < 21; i++)
        {   
            //Peca foi movida para o tabuleiro
            if( jogador1[i].p1 == -1 && jogador1[i].p2 == -1 || jogador1[i].status != 'U'){
                printf("peca %d:    \t\t VAZIO\n", i+1 );

            }else if( jogador1[i].maiorP == 1){

                printf("peca %d:    \t\t|%d | %d| -> (Maior peca dobrada)\n", i+1 ,  jogador1[i].p1, jogador1[i].p2);

            } else if( jogador1[i].maiorP == 2){

                printf("peca %d:    \t\t|%d | %d| -> (Maior peca normal)\n", i+1 ,  jogador1[i].p1, jogador1[i].p2);

            }else{
                printf("peca %d:    \t\t|%d | %d|\n", i+1 ,  jogador1[i].p1, jogador1[i].p2);
            }
        } 
    } 
    //MOSTRA A PECA DO JOGADOR 2
    if(domino[0].rodadaVez % 2 == 0){
        printf("\n\t\t-=-=-=-=JOGADOR_2-=-=-=-=-\n");
        printf("\n");

        for (int i = 0; i < 21; i++)
        {
             if( jogador2[i].p1 == -1 && jogador2[i].p2 == -1){
                printf("peca %d:    \t\t VAZIO\n", i+1 );

             }else  if( jogador2[i].maiorP == 1){

                printf("peca %d:    \t\t|%d | %d| -> (Maior peca dobrada)\n", i+1 ,  jogador2[i].p1, jogador2[i].p2);

            } else if( jogador2[i].maiorP == 2){

                printf("peca %d:    \t\t|%d | %d| -> (Maior peca normal)\n", i+1 ,  jogador2[i].p1, jogador2[i].p2);

            }else{
                printf("peca %d:    \t\t|%d | %d|\n", i+1 ,  jogador2[i].p1, jogador2[i].p2);
            }
        }
    }

  
}


void mostrarMesa(tipo_mesa tabuleiro[])
//função para mostrar a mesa
{                                                   
    int i, j, k;
    
    printf("\n\n\t\t\t\t\t\t     -=-=-=-=-=DOMINO=-=-=-=-=-\n\n");
    printf("======================================================================================================================================================\n");
    
    printf("\n");

    for (i =  tabuleiro[0].h_esq; i <=  tabuleiro[0].h_dir; i++){
        if( tabuleiro[0].mapa[i] != -1){
            if(i % 2 == 0){
                printf("|%d-",  tabuleiro[0].mapa[i]);
            }else{
                 printf("-%d|",  tabuleiro[0].mapa[i]);
            }                     
                         
        } else if(tabuleiro[0].mapa[i] == -1){
            printf("      ");
        }
    }
    printf("\n\n======================================================================================================================================================\n");

       
}
char opcao()
{
    char op;
    flush_in();
    op = getchar();
    return op;
}

char menuJogo()
{ // menu dentro do jogo
    char escolha;
    printf("\n\n\t\t/===============================\\");
    printf("\n\t\t   Digite <j> para jogar");
    printf("\n\t\t   Digite <c> para comprar");
    printf("\n\t\t   Digite <v> para ver as pecas");
    printf("\n\t\t   Digite <m> para mover a tela");
     printf("\n\t\t   Digite <t> para terminar a jogada");
    printf("\n\t\t   Digite <s> para sair do jogo");
    printf("\n\t\t\\===============================/");
    printf("\nOpcao: ");
    escolha = opcao();

    return escolha;
}


int moverTela(int quant)
{
    //move a a mesa para direita e esquerda

    char op;
    int escolha;
    printf("\n\n         \t\t\t\t\t-=-=-=-=-=-=-=-=DIRECAO=-=-=-=-=-=-=-=-");
    printf("\n                \t\t\t\t\tPressinoe <E> para <----- ");
    printf("\n                \t\t\t\t\tPressinoe <D> para ----->");
    printf("\n         \t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    printf("\n\t\tOpcao: ");
    escolha = opcao();

    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &quant);

    if (escolha == 'D' || escolha == 'd')
    {
        return quant;
    }

    if (escolha == 'E' || escolha == 'e')
    {
        quant = quant * -1;
        return quant;
    }
}

void jogodeDois(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[])
{
    //h_esq -> horizontal esquerda [50] 
    //h_dir -> horizontal direita  [50]
    //quant -> quantidade de colunas no sentido da esquerda 
    //         ou no sentido da direita 
    int   i = 0, aux, quant, posicao;

    // veri = verificador para a entrada do usuario nao ultrapasse a borda
    // em ambos sentidos
    int   veri = 0, veri1 = 101;

    // jogador = recebe um valor para demonstrar ao usuario
    //           quem comeca a jogar
    char  escolha;
    bool  sair = false;
    
    //definindo a vez de cada jogador 
    domino[0].rodadaVez = domino[0].jogaPrimeiro;

    //Quando o jogo comeca a maior peca do jogo tem que ter seus status alterado
    posicao = achaMaiorP(domino, jogador1, jogador2);
    tabuleiro[0].mapa[50] = domino[0].j_maiorP1;
    tabuleiro[0].mapa[51] = domino[0].j_maiorP2;

    //se for a vez do 1 jogador 
    if(domino[0].jogaPrimeiro % 2 != 0){

        //peca foi para mesa | -1 = peca foi movida 
        jogador1[posicao].status = 'M';
        jogador1[posicao].p1 = -1;
        jogador1[posicao].p2 = -1;
    }

    if(domino[0].jogaPrimeiro % 2 == 0){

        jogador2[posicao].status = 'M';
        jogador2[posicao].p1 = -1;
        jogador2[posicao].p2 = -1;
    }

    if(domino[0].jogaPrimeiro % 2 != 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t   JOGADOR 1 JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n\n");

    }
    
    if(domino[0].jogaPrimeiro % 2 == 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t   JOGADOR 2 JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n");
    }

    domino[0].rodadaVez++;

    do{ 
        mostraMenu();
        escolha = menuJogo();

        switch (escolha)
        {
            case 'j': //jogar a peça

                if(domino[0]. jogou == 0){

                    if(domino[0].rodadaVez % 2 != 0) {
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    JOGADOR 1 IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n\n");

                    }
                    if(domino[0].rodadaVez % 2 == 0) {
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    JOGADOR 2 IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n");

                    }

                    //Colocamos define_mPeca para ele atualizar constantemente quem é a maior
                    //peca dobrada e a maior peca normal
                    define_mPeca(domino, jogador1, jogador2, monte);
                    mostrarMesa(tabuleiro);
                    alocaPeca(domino, jogador1 , jogador2, tabuleiro);

                    

                } else{
                    printf("\n\tVoce ja jogou sua peca!");
                }

                limparInterface();
                break;

                case 'c': //comprar uma peça
                    comprarPeca(domino, jogador1, jogador2, monte, tabuleiro);

                    limparInterface();
                break;

            case 'm':
                //Quando ele digita <E> o aux ja é convetido para negativo
                // por isso: h_esq + aux = h_esq - aux
                aux = moverTela(quant);

                while (( tabuleiro[0].h_esq + aux) <= veri || ( tabuleiro[0].h_dir + aux) >= veri1)
                {
                        printf("\nOPPS!Sua escolha de colunas ultapassou o limite!!");
                      aux = moverTela(quant);
                }

                tabuleiro[0].h_esq = aux +  tabuleiro[0].h_esq;
                tabuleiro[0].h_dir =  tabuleiro[0].h_dir + aux;
    
                mostrarMesa(tabuleiro);
                limparInterface();
                break;
    
            
    
            case 'v':
                mostrarMesa(tabuleiro);
                define_mPeca(domino, jogador1, jogador2, monte);
                visualizarPeca(dominoAux, domino, jogador1, jogador2, monte);
                limparInterface();
                break;
            
            case 't': //terminar rodada

                domino[0].rodadaVez++;

                if(domino[0].rodadaVez % 2 != 0) {
                    printf("\n\t\t/================================\\");
                    printf("\n\t\t    JOGADOR 1 IRA JOGAR!!");
                    printf("\n\t\t\\================================/\n\n");
                }

                if(domino[0].rodadaVez % 2 == 0) {
                    printf("\n\t\t/================================\\");
                    printf("\n\t\t    JOGADOR 2 IRA JOGAR!!");
                    printf("\n\t\t\\===============================/\n");
                }

                domino[0].jogou = 0;

                mostrarMesa(tabuleiro);
                limparInterface();
                break;
            
            case 's': //sair do jogo
                sair = true;
                limparInterface();
                break;
    
            default: //opção inválida >:(
                printf("Opcao invalida!! >:(");
                limparInterface();
                break;
    
        }
    } while (sair == false);

}

void limparInterface()
{ //limpa o sistema
    char op;
    printf("\n\n................Pressione <ENTER> para continuar...................");
    getchar();
    flush_in();
    system("clear"); //("cls") para Windows
}

void hubJogador(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[])
{ //opção de seleção de jogadores

    int quant;

    printf("\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=(HUB)=-=-=-=-=-=-=-=-=-=--=-=-");
    printf("\n\n\t\t\t    Digite a quantidade de jogadores: ");
    quant = entraJogador();

    if (quant == 1)
    { // jogo com 1 jogador
        printf("\n\tEM MANUTENCAO!!!!");
    }

    if (quant == 2)
    { // jogo com 2 jogadores

        printf("\n\t\t\t\t  /===================================\\");
        printf("\n\t\t\t\t              JOGO DE DOIS");
        printf("\n\t\t\t\t  \\===================================/");
        printf("\n\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        limparInterface();


        distribuirpecas(dominoAux, domino, jogador1, jogador2, monte);
        defineTipo(domino, jogador1, jogador2, monte);
        define_mPeca(domino, jogador1, jogador2, monte);
        defineStatus(jogador1, jogador2, monte);

        jogodeDois(dominoAux, domino, tabuleiro, jogador1, jogador2, monte);
    }

    while (quant > 2 || quant < 1)
    {
        printf("\nOps voce deve ter digitado algo errado!!");
        printf("\nDigite a quantidade de jogadores:");
        quant = entraJogador();
    }

    
}

void alocaPeca(tipo_jogo domino[],tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa tabuleiro[]){

    char escolha;
    int pecaAux, peca;

    escolha = escDirecao();
    
    printf("\nDigite sua peca: ");
    scanf("%d", &pecaAux);

    peca = pecaAux -1;

    if(domino[0].rodadaVez %2 != 0){
        verificaJog_1(domino, jogador1, tabuleiro, escolha, peca);

    } else if(domino[0].rodadaVez %2 == 0){
        verificaJog_2(domino, jogador2, tabuleiro, escolha, peca);

    }

}

void mostraRegras(){
    printf("\n");
    printf("\nRegras do Jogo \n");
    printf("\nAs regras do jogo sao bem simples: cada jogador pega sete pecas e pode comprar sempre que precisar de");
    printf("\numa peca para poder jogar e quantas vezes for necessario. Da-se inicio ao jogo o jogador que tirar");
    printf("\na pedra seis-seis. Caso ninguem tenha o tirado, inicia-se o jogador que tiver a peca com os numeros");
    printf("\nrepetidos mais altos, ou seja, cinco-cinco, quatro-quatro, e assim sucessivamente. O jogo");
    printf("\nacontece no sentido anti-horario e os jogadores devem colocar pecas que tenham os mesmos numeros das");
    printf("\npecas que se encontram na ponta do jogo. O jogador que comeca a partida leva vantagem. Este e um");
    printf("\nconceito importante para a estrategia do domino, pois o jogador que comeca, normalmente, e o que leva");
    printf("\na vantagem durante a partida. Cada jogador, no seu turno, deve colocar uma das suas pecas em uma das");
    printf("\nduas extremidades abertas, de forma que os pontos de um dos lados coincidam com os pontos da extremidade");
    printf("\nonde esta sendo colocada. As dobradas sao colocadas de maneira transversal para facilitar");
    printf("\nsua localizacao. Quando o jogador coloca sua peca sobre a mesa, seu turno se acaba e passa-se ao");
    printf("\nseguinte jogador. Se um jogador nao puder jogar, devera comprar do monte tantas pecas como forem");
    printf("\nnecessarias. Se nao houver pecas no monte, passara o turno ao seguinte jogador.A partida continua com");
    printf("\nos jogadores colocando suas pecas sobre a mesa ate que se apresente alguma das seguintes situacoes:\n");
    printf("\n- Quando um jogador coloca sua ultima pedra na mesa, essa acao e chamada de bater. Quando joga-se sozinho,");
    printf("\no jogador que ganhou a partida soma os pontos de todos os seus adversarios. Jogando em dupla, somam-se"); 
    printf("\nos pontos de todos os jogadores incluindo os do seu companheiro.\n"); 
    printf("\n- Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o numero das"); 
    printf("\nextremidades saiu 7 vezes antes. Nesse momento se diz que a partida esta fechada. Os jogadores"); 
    printf("\ncontarao os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se");
    printf("\nos pontos da maneira habitual.\n");
    printf("\n- Pode acontecer de voce ter os mesmos pontos que o jogador ou a dupla que tem a vantagem,"); 
    printf("\nnesse caso, ganha este jogador.\n");
    printf("\nPontificia Universidade Catolica de Sao Paulo");
    printf("\nFaculdade de Ciencia Exatas e Tecnologia - Ciencia da Computacao");

}

void mostraNome(){
                                                                                                                                 
printf("\n        ***** **                                                                        ***** **   ***                          ");
printf("\n     ******  ***                                  *                                  ******  ***    ***      *                  ");
printf("\n   **    *  * ***                                ***                                **   *  * **     **     ***                 ");
printf("\n  *     *  *   ***                                *                                *    *  *  **     **      *                  ");
printf("\n       *  *     ***    ****                                             ****           *  *   *      **                         ");
printf("\n      ** **      **   * ***  * *** **** ****    ***     ***  ****      * ***  *       ** **  *       **    ***     ***  ****    ");
printf("\n      ** **      **  *   ****   *** **** ***  *  ***     **** **** *  *   ****        ** ** *        **     ***     **** **** * ");
printf("\n      ** **      ** **    **     **  **** ****    **      **   ****  **    **         ** ***         **      **      **   ****  ");
printf("\n      ** **      ** **    **     **   **   **     **      **    **   **    **         ** ** ***      **      **      **    **   ");
printf("\n      ** **      ** **    **     **   **   **     **      **    **   **    **         ** **   ***    **      **      **    **   ");
printf("\n      *  **      ** **    **     **   **   **     **      **    **   **    **         *  **     **   **      **      **    **   ");
printf("\n         *       *  **    **     **   **   **     **      **    **   **    **            *      **   **      **      **    **   ");
printf("\n    *****       *    ******      **   **   **     **      **    **    ******         ****     ***    **      **      **    **   ");
printf("\n   *   *********      ****       ***  ***  ***    *** *   ***   ***    ****         *  ********      *** *   *** *   ***   ***  ");
printf("\n  *       ****                    ***  ***  ***    ***     ***   ***               *     ****         ***     ***     ***   *** ");
printf("\n  *                                                                                *                                            ");
printf("\n   **                                                                               **                                          \n\n");
}

void mostraMenu(){

 printf("\n\t\t __  __                           "); 
 printf("\n\t\t|  \\/  |   ___   _ __    _   _   ");
 printf("\n\t\t| |\\/| |  / _ \\ | '_ \\  | | | |  ");
 printf("\n\t\t| |  | | |  __/ | | | | | |_| |  ");
 printf("\n\t\t|_|  |_|  |___| |_| |_|  |__,_|  \n\n");
                                
                                         
}


                                