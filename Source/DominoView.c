#include "DominoModel.h"
#include "DominoView.h"
#include "DominoData.h"
//#include "DominoData.h"

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
printf("\n\t      | ,'   \\   /\\       .-|      ");
printf("\n\t      |'      `-'   \\     /  |      ");
printf("\n\t      |               `._,'   |      ");
printf("\n\t   _-~|                       |      ");
printf("\n\t   -   ~-..__                 |._    ");
printf("\n\t    ~-.__    ~~''--..__       |  -.  ");
printf("\n\t         ~~''--..__    ~~''--'~  ,'  ");
printf("\n\t                   ~~''--....--'~    ");
        
}

//hub do sistema
void menu()
{ 

    mostrarNome();

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

//mostra as peças
void exibirPeca(tipo_peca dominoAux[])
{ 
    int k = 0;
    for (int i = 0; i < 28; i++)
    {
        k++;

        printf("peca: %d --> %d | %d\n", k , dominoAux[i].p1, dominoAux[i].p2);
    }
    puts("\n");

    
}


int entrarJogador()
{ //detecta a qtd de jogadores

    int quant;
    scanf("%d", &quant);

    return quant;
}

//mostra as peças do jogador 1 e jogador 2
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

//função para mostrar a mesa
void mostrarMesa(tipo_mesa tabuleiro[])

{                                                   
    int i, j, k;
    
    printf("\n\n\t\t\t\t\t\t                 -=-=-=-=-=DOMINO=-=-=-=-=-\n\n");
    
    printf("\n");
    printf("======================================================================================================================================================\n");   

    for (i =  tabuleiro[0].h_esq; i <=  tabuleiro[0].h_dir; i++){
        if( tabuleiro[0].mapa[i] != -1){
            if(i % 2 == 0){
                printf("|%d-",  tabuleiro[0].mapa[i]);

            }else {
                 printf("-%d|",  tabuleiro[0].mapa[i]);
            }                     
        
        }else if(tabuleiro[0].mapa[i] == -1){
            printf("      ");
        }                 
    }
    printf("\n______________________________________________________________________________________________________________________________________________________");   
    printf("\n======================================================================================================================================================");
    mostrarMesa2();    
}

//Opçao do menu
char opcao()
{
    char op;
    op = getchar();
    flush_in();

    return op;
}

// menu dentro do jogo
char menuJogo()
{ 
    int escolha;
    printf("\n\n\t\t/===============================\\");
    printf("\n\t\t   Digite <1> para jogar");
    printf("\n\t\t   Digite <2> para comprar");
    printf("\n\t\t   Digite <3> para ver as pecas");
    printf("\n\t\t   Digite <4> para mover a tela");
    printf("\n\t\t   Digite <5> para terminar a jogada");
    printf("\n\t\t   Digite <6> para salvar o jogo");
    printf("\n\t\t   Digite <7> para carregar o jogo");
    printf("\n\t\t   Digite <8> para finalizar o jogo (caso ele esteja fechado)");
    printf("\n\t\t   Digite <9> para sair do jogo");
    printf("\n\t\t\\===============================/");
   
    printf("\nOpcao: ");
    scanf("%d", &escolha);
    

    return escolha;
}

//move a a mesa para direita e esquerda
int moverTela(int quant)
{
    char op;
    //char escolha;
    int escolha;
    printf("\n\n         \t\t\t\t\t-=-=-=-=-=-=-=-=DIRECAO=-=-=-=-=-=-=-=-");
    printf("\n                \t\t\t\t\tPressinoe <1> para ----->");
    printf("\n                \t\t\t\t\tPressinoe <2> para <-----");
    printf("\n         \t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    printf("\n\t\tOpcao: ");
    //escolha = opcao();
    scanf("%d", &escolha);

    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &quant);

    if (escolha == 2)
    {
        return quant;
    }

    if (escolha == 1)
    {
        quant = quant * -1;
        return quant;
    }
}

// hub dos dois jogadores
void jogodeDois(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[])
{
    domino[0].jogou = 0;
    //h_esq -> horizontal esquerda [50] 
    //h_dir -> horizontal direita  [50]
    //quant -> quantidade de colunas no sentido da esquerda 
    //         ou no sentido da direita 
    int   i = 0, aux, quant, cont = 0, cont_1 = 7, cont_2 = 7, posicao, vitoria;

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
    posicao = acharMaior(domino, jogador1, jogador2);
    tabuleiro[0].mapa[50] = domino[0].j_maiorP1;
    tabuleiro[0].mapa[51] = domino[0].j_maiorP2;

    //se for a vez do 1 jogador 
    if(domino[0].jogaPrimeiro % 2 != 0){

        //peca foi para mesa | -1 = peca foi movida 
        jogador1[posicao].status = 'M';
        jogador1[posicao].p1 = -1;
        jogador1[posicao].p2 = -1;

        domino[0].quantJ1 = 6;
        domino[0].quantJ2 = 7;
    }

    if(domino[0].jogaPrimeiro % 2 == 0){

        jogador2[posicao].status = 'M';
        jogador2[posicao].p1 = -1;
        jogador2[posicao].p2 = -1;

        domino[0].quantJ1 = 7;
        domino[0].quantJ2 = 6;
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

    cont = 0;
    domino[0].rodadaVez++;

    do{ 
        mostrarMenu();
        escolha = menuJogo();

        switch (escolha)
        {
            case 1: //jogar a peça

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

                    //Colocamos definirMaior para ele atualizar constantemente quem é a maior
                    //peca dobrada e a maior peca normal
                    definirMaior(domino, jogador1, jogador2, monte);
                    mostrarMesa(tabuleiro);
                    visualizarPeca(dominoAux, domino, jogador1, jogador2, monte);
                    alocarPeca(domino, jogador1 , jogador2, tabuleiro);


                } else{
                    printf("\n\tVoce ja jogou sua peca!");
                }

                limparInterface();
                break;

                case 2: //comprar uma peça
                    comprarPeca(domino, jogador1, jogador2, monte, tabuleiro, &cont, &cont_1, &cont_2);

                    limparInterface();
                break;

            case 4:
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
    
            
    
            case 3:
                mostrarMesa(tabuleiro);
                definirMaior(domino, jogador1, jogador2, monte);
                visualizarPeca(dominoAux, domino, jogador1, jogador2, monte);
                limparInterface();
                break;
            
            case 5: //terminar rodada

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
            
            case 8://finalizar o jogo (caso fechado)

                contarPontos(domino, jogador1, jogador2);

                if(domino[0].pontosJ1 <  domino[0].pontosJ2){

                    mostrarJ1();
                    printf("\n\n\n\t\t\t-------------GANHOU-------------");

                }else if(domino[0].pontosJ2 <  domino[0].pontosJ1){
                    mostrarJ2();
                    printf("\n\n\n\t\t\t-------------GANHOU-------------");

                }else{
                    printf("empate");

                }
                sair = true;
                limparInterface();
                break;

            case 9: //sair do jogo
                sair = true;
                limparInterface();
                break;
    
            case 6:
                salvarArquivo(domino, jogador1, jogador2, tabuleiro, monte);
                break;
            
            case 7:
                carregarArquivo(domino,jogador1,jogador2, tabuleiro,  monte);
                break;
    
            default: //opção inválida >:(
                mostrarErro();
                printf("Opcao invalida!! >:(");
                limparInterface();
                break;
    
        }
    } while (sair == false);

}

//limpa o sistema
void limparInterface()
{ 
    char op;
    printf("\n\n................Pressione <ENTER> para continuar...................");
    getchar();
    flush_in();
    system("cls"); //("clear") para Linux
}

//opção de seleção de jogadores
void hubJogador(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_peca bot[])
{ 

    int quant;
    
    tabuleiro[0].ext_dir = 2;
    tabuleiro[0].ext_esq = 2;

    printf("\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=(HUB)=-=-=-=-=-=-=-=-=-=--=-=-");
    printf("\n\n\t\t\t    Digite a quantidade de jogadores: ");
    quant = entrarJogador();

    if (quant == 1)
    { // jogo com 1 jogador
        printf("\n\t\t\t\t  /===================================\\");
        printf("\n\t\t\t\t               JOGO COM BOT");
        printf("\n\t\t\t\t  \\===================================/");
        printf("\n\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        limparInterface();

        //Setup do jogo
        distribuirpecas(dominoAux, domino, jogador1, bot, monte);
        definirStatus(jogador1, bot, monte);
        definirTipo(domino, jogador1, bot, monte);
        definirMaior(domino, jogador1, bot, monte);
        inicializaMesa(tabuleiro);

        
    
        jogoAUTO(dominoAux, domino, tabuleiro, jogador1,  bot,  monte);

    }

    if (quant == 2)
    { // jogo com 2 jogadores

        printf("\n\t\t\t\t  /===================================\\");
        printf("\n\t\t\t\t              JOGO DE DOIS");
        printf("\n\t\t\t\t  \\===================================/");
        printf("\n\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        limparInterface();

        //Setup do jogo
        distribuirpecas(dominoAux, domino, jogador1, jogador2, monte);
        definirStatus(jogador1, jogador2, monte);
        definirTipo(domino, jogador1, jogador2, monte);
        definirMaior(domino, jogador1, jogador2, monte);
        inicializaMesa(tabuleiro);

        jogodeDois(dominoAux, domino, tabuleiro, jogador1, jogador2, monte);
    }

    while (quant > 2 || quant < 1)
    {
        printf("\nOps voce deve ter digitado algo errado!!");
        printf("\nDigite a quantidade de jogadores:");
        quant = entrarJogador();
    }
    
}

//coloca as peças na mesa
void alocarPeca(tipo_jogo domino[],tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa tabuleiro[]){

    char escolha;
    int pecaAux, peca;

    escolha = escolherDirecao();
    
    printf("\nDigite sua peca: ");
    scanf("%d", &pecaAux);

    peca = pecaAux -1;

    if(domino[0].rodadaVez %2 != 0){
        verificarJog1(domino, jogador1, tabuleiro, escolha, peca);
        

    } else if(domino[0].rodadaVez %2 == 0){
        verificarJog2(domino, jogador2, tabuleiro, escolha, peca);
        
    }

}

//Mostra as regras do jogo
void mostrarRegras(){
    
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

//Menu ilustrativo
void mostrarNome(){
                                                                                                                                 
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

//menu dentro do jogo ilustrativo
void mostrarMenu(){

 printf("\n\t\t __  __                           "); 
 printf("\n\t\t|  \\/  |   ___   _ __    _   _   ");
 printf("\n\t\t| |\\/| |  / _ \\ | '_ \\  | | | |  ");
 printf("\n\t\t| |  | | |  __/ | | | | | |_| |  ");
 printf("\n\t\t|_|  |_|  |___| |_| |_|  |__,_|  \n\n");
                                
                                         
}

void mostrarErro(){
    
    printf("\n\t\t\t\t_______ ");
    printf("\n\t\t\t\t|  ___|                   ");
    printf("\n\t\t\t\t| |__ _ __ _ __ ___  _ __ ");
    printf("\n\t\t\t\t|  __| '__| '__/ _ \\| '__|");
    printf("\n\t\t\t\t| |__| |  | | | (_) | |   ");
    printf("\n\t\t\t\t|____/_|  |_|  \\___/|_|   \n");
                         
}



void mostrarMesa2(){

    printf("\n\t\t\t\t\t\t         \\ \\  / /   / /             \\ \\     \\ \\  / /       ");
    printf("\n\t\t\t\t\t\t          \\ \\/ /   /_/               \\_\\     \\ \\/ /        ");
    printf("\n\t\t\t\t\t\t          _\\/ /_______________________________\\ \\/_        ");    
    printf("\n\t\t\t\t\t\t         [_/o/_________________________________\\o\\_]       ");    
    printf("\n\t\t\t\t\t\t          / /\\ \\                             / /\\ \\        ");    
    printf("\n\t\t\t\t\t\t         /_/  \\_\\                           /_/  \\_\\       ");
}

void mostrarJ1(){

    printf("\n\n\t\t   _                       _                 __    ");
    printf("\n\t\t  (_)                     | |               /  |  ");
    printf("\n\t\t   _  ___   __ _  __ _  __| | ___  _ __     `| |  ");
    printf("\n\t\t  | |/ _ \\ / _` |/ _` |/ _` |/ _ \\| '__      | |  ");
    printf("\n\t\t  | | (_) | (_| | (_| | (_| | (_) | |     _  | |_ ");
    printf("\n\t\t  | |\\___/ \\__, |\\__,_|\\__,_|\\___/|_|    \\___/ ");
    printf("\n\t\t _/ |       __/ |                              ");
    printf("\n\t\t|__/       |___/                               ");
}

void mostrarJ2(){

    printf("\n\n\t    _                       _              ___   ");
    printf("\n\t\t   (_)                     | |            |__ \\  ");
    printf("\n\t\t    _  ___   __ _  __ _  __| | ___  _ __     ) | ");
    printf("\n\t\t   | |/ _ \\ / _` |/ _` |/ _` |/ _ \\| '__|   / /  ");
    printf("\n\t\t   | | (_) | (_| | (_| | (_| | (_) | |     / /_  ");
    printf("\n\t\t   | |\\___/ \\__, |\\__,_|\\__,_|\\___/|_|    |____| ");
    printf("\n\t\t  _/ |       __/ |                               ");
    printf("\n\t\t |__/       |___/  ");


}

void mostrarComp(){
    
printf("\n\n\t _________                              __              .___");            
printf("\n\n\t\\_   ___ \\  ____   _____ ______  __ ___/  |______     __| _/___________"); 
printf("\n\n\t/    \\  \\/ /  _ \\ /     \\____ \\|  |  \\   __\\__  \\   / __ |/  _ \\_  __ \\ ");
printf("\n\n\t\\     \\___(  <_> )  Y Y  \\  |_> >  |  /|  |  / __ \\_/ /_/ (  <_> )  | \\/");
printf("\n\n\t \\______  /\\____/|__|_|  /   __/|____/ |__| (____  /\\____ |\\____/|__|   ");
printf("\n\n\t        \\/             \\/|__|                    \\/      \\/             ");
}

void jogoAUTO(tipo_peca dominoAux[], tipo_jogo domino[], tipo_mesa tabuleiro[], tipo_peca jogador1[], tipo_peca bot[], tipo_peca monte[]){
    //h_esq -> horizontal esquerda [50] 
    //h_dir -> horizontal direita  [50]
    //quant -> quantidade de colunas no sentido da esquerda 
    //         ou no sentido da direita 
    int   i = 0, aux, quant, cont = 0, cont_1 = 7, cont_2 = 7, posicao, vitoria;

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
    posicao = acharMaior(domino, jogador1, bot);
    tabuleiro[0].mapa[50] = domino[0].j_maiorP1;
    tabuleiro[0].mapa[51] = domino[0].j_maiorP2;

    //se for a vez do 1 jogador 
    if(domino[0].jogaPrimeiro % 2 != 0){

        //peca foi para mesa | -1 = peca foi movida 
        jogador1[posicao].status = 'M';
        jogador1[posicao].p1 = -1;
        jogador1[posicao].p2 = -1;

        domino[0].quantJ1 = 6;
        domino[0].quantJ2 = 7;
    }

    if(domino[0].jogaPrimeiro % 2 == 0){

        bot[posicao].status = 'M';
        bot[posicao].p1 = -1;
        bot[posicao].p2 = -1;

        domino[0].quantJ1 = 7;
        domino[0].quantJ2 = 6;
    }

    

    if(domino[0].jogaPrimeiro % 2 != 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t   JOGADOR 1 JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n\n");

    }
    
    if(domino[0].jogaPrimeiro % 2 == 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t       BOT JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n");
    }

    cont = 0;
    domino[0].rodadaVez++;
    domino[0]. jogou = 0;

    do{ 
        mostrarMenu();
        if(domino[0].rodadaVez % 2 != 0){
            escolha = menuJogo();
        }
        if(domino[0].rodadaVez % 2 == 0){
            escolha = 1;
        }

        switch (escolha){

            case 1: //jogar a peça

                if(domino[0].rodadaVez % 2 != 0) {
                    
                    if(domino[0]. jogou == 0){
                        
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    JOGADOR 1 IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n\n");
                        definirMaior(domino, jogador1, bot, monte);
                        mostrarMesa(tabuleiro);
                        visualizarPeca(dominoAux, domino, jogador1, bot, monte);
                        alocarPeca(domino, jogador1 , bot, tabuleiro);
                        mostrarMesa(tabuleiro);
                        system("cls");
                    } else{
                        printf("\n\tVoce ja jogou sua peca!");
                    }

                }
                if(domino[0].rodadaVez % 2 == 0) {
                    printf("\n\t\t/================================\\");
                    printf("\n\t\t      BOT JOGOU A PECA !!");
                    printf("\n\t\t\\================================/\n");
                    definirMaior(domino, jogador1, bot, monte);
                    jogarPecaBOT(domino, jogador1, bot, monte, tabuleiro, &cont, &cont_1, &cont_2);
                    mostrarMesa(tabuleiro);
                    domino[0].rodadaVez ++;
                }

                
            break;

            case 2: //comprar uma peça
                if(domino[0].rodadaVez % 2 != 0){
                    comprarPeca(domino, jogador1, bot, monte, tabuleiro, &cont, &cont_1, &cont_2);
                }
                limparInterface();
            break;

            case 4:
                //Quando ele digita <E> o aux ja é convetido para negativo
                // por isso: h_esq + aux = h_esq - aux
                if(domino[0].rodadaVez % 2 != 0) {
                    aux = moverTela(quant);

                    while (( tabuleiro[0].h_esq + aux) <= veri || ( tabuleiro[0].h_dir + aux) >= veri1)
                    {
                        
                        printf("\nOPPS!");
                        printf("Sua escolha de colunas ultapassou o limite!!");

                        aux = moverTela(quant);
                    }

                    tabuleiro[0].h_esq = aux +  tabuleiro[0].h_esq;
                    tabuleiro[0].h_dir = aux + tabuleiro[0].h_dir;

                    mostrarMesa(tabuleiro);
                    limparInterface();
                }
                break;
    
            
    
            case 3:
                
                if(domino[0].rodadaVez % 2 != 0) {
                    mostrarMesa(tabuleiro);
                    definirMaior(domino, jogador1, bot, monte);
                    visualizarPeca(dominoAux, domino, jogador1, bot, monte);
                    limparInterface();
                }
                
                break;
            
            case 5: //terminar rodada

                if(domino[0].rodadaVez % 2 != 0) {
                    domino[0].rodadaVez++;

                    
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    BOT IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n\n");
                    


                    domino[0].jogou = 0;

                    mostrarMesa(tabuleiro);
                    limparInterface();
                }
                break;
            
            case 8://finalizar o jogo (caso fechado)

                if(domino[0].rodadaVez % 2 != 0) {
                    contarPontos(domino, jogador1, bot);

                    if(domino[0].pontosJ1 <  domino[0].pontosJ2){

                        mostrarJ1();
                        imagem();

                    }else if(domino[0].pontosJ2 <  domino[0].pontosJ1){
                        mostrarComp();
                        imagem();

                    }else{
                        printf("empate");

                    }
                    sair = true;
                    limparInterface();
                }
            break;

            case 9: //sair do jogo
                sair = true;
                
            break;
    
            case 6:

                if(domino[0].rodadaVez % 2 != 0) {
                   
                    salvarArquivo(domino, jogador1, bot, tabuleiro, monte);
                
                }
                
            break;
            
            case 7:

                if(domino[0].rodadaVez % 2 != 0) {
                    
                    carregarArquivo(domino,jogador1,bot, tabuleiro,  monte);
                    
                }

            break;

            default: //opção inválida >:(
                if(domino[0].rodadaVez % 2 != 0) {
                    mostrarErro();
                    printf("Opcao invalida!! >:(");
                    limparInterface();
                }
            break;
        }

    } while(sair == false);

}