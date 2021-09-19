# Blin_Domino
Projeto de um jogo de dominó, criado no 2º Semestre de **Ciência da Computação da PUC SP**
  
Nome e RA dos integrantes:  
Julio Cesar Barboza Filho RA: 00297586  
Lucas Costa Pessoa Graziano RA: 00297851  
Mateus Assatli Santana RA: 00301457  
Rafael Calado Moderno de Carvalho RA: 00279983  
  
- Regras do Jogo:
As regras do jogo são bem simples: cada jogador pega sete peças e pode comprar sempre que precisar de uma peça para poder jogar e quantas vezes for necessário. Dá-se início ao
jogo o jogador que tirar a pedra “seis-seis”. Caso ninguém tenha o tirado, inicia-se o jogador que tiver a peça  com  os  números  repetidos  mais  altos,  ou  seja, “cinco
-cinco”,  “quatro-quatro”,  e  assim sucessivamente. O jogo acontece no sentido anti-horário e os jogadores devem colocar peças que tenham os mesmos números das peças que se
encontram na ponta do jogo. O jogador que começa a partida leva vantagem. Este é um conceito importante para a estratégia do dominó, pois o jogador que começa, normalmente, é o
que leva a vantagem durante a partida. Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas, de forma que os pontos de um dos lados
coincidam com os pontos da extremidade onde está  sendo  colocada. Quando o jogador coloca sua peça sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador. Se um 
jogador não puder jogar, deverá “comprar” do monte tantas peças como forem necessárias. Se não houver peças no monte, passará o turno ao seguinte jogador. A partida continua com 
os jogadores colocando suas peças sobre a mesa até que se apresente alguma das seguintes situações:
  
  - Quando um jogador coloca sua última pedra na mesa, essa ação é chamada de bater. Quando joga-se sozinho, o jogador que ganhou a partida soma os pontos de todos os seus 
adversários. Jogando em dupla, somam-se os pontos de todos os jogadores incluindo os do seu companheiro.
  - Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o número das extremidades saiu 7 vezes antes. Nesse momento se diz que a partida está 
fechada. Os jogadores contarão os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se os pontos da maneira habitual.
  - Pode acontecer de você ter os mesmos pontos que o jogador ou a dupla que tem a vantagem, nesse caso, ganha este jogador.
  
  
- O projeto foi dividido em 4 módulos:
  - Model;
  - View;
  - Data;
  - Controller;
  
  
- O módulo "Model" possui  as funções relacionadas com a lógica do jogo (inicialização de peças, jogadas, etc.), veja abaixo um trecho de exemplo, uma função qe embaralha as 28 
peças do domino:

```C
void embaralhar(tipo_peca dominoAux[], int array_tamanho)
{
    srand(time(NULL)); //randomiza as peças
    int r, troca;

    for (int i = array_tamanho - 1; i >0; i--)
    {
        r = rand() % array_tamanho;
        troca = dominoAux[i].p1;
        dominoAux[i].p1 = dominoAux[r].p1;
        dominoAux[r].p1 = troca;
        troca = dominoAux[i].p2;
        dominoAux[i].p2 = dominoAux[r].p2;
        dominoAux[r].p2 = troca;
    }
}
```
  
  
- O módulo "View" possui as funções relacionadas com a interação com o usuário (exibição de menus, textos, etc.), veja abaixo um trecho de exemplo, a função que exibe o menu 
principal:

```C
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
```
  
- O módulo "Data" possui as funções ao salvamento e carregamento do jogo, veja abaixo um trecho de exemplo, a função que realiza o salvamento:
```C
void salvarArquivo(tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa tabuleiro[], tipo_peca monte[]){     
    FILE *DominoS;

    //seleciona um arquivo para abrir
    //wb cria um arquivo binário para escrita, como no modo "w" anterior, só que o arquivo é binário.
    DominoS = fopen("DominoS", "wb");
    //se nao conseguir abrir, irá retornar como NULL
    if (DominoS == NULL) {
        printf("\nArquivo Domino nao pode ser aberto.");
        printf("\nOcorreu um Erro Grave! Use alguma tecla para finalizar!");
        exit(1);
    }
    
        fwrite(jogador1, 1, sizeof(tipo_peca), DominoS);
               
        fwrite(jogador2, 1, sizeof(tipo_peca), DominoS);
            
        fwrite(monte, 1, sizeof(tipo_peca), DominoS);
            
        fwrite(tabuleiro[0].mapa, 1, sizeof(tipo_mesa), DominoS);
            
        fwrite(&domino[0], 1, sizeof(tipo_jogo), DominoS);
                   
    fclose(DominoS);
}
```
  
  
- Por fim, o módulo "Controller", que faz o intermédio entre os demais módulos, veja abaixo um trecho de exemplo, onde temos a declaração das variáveis:
```C
void controller() {

    //declaração das variáveis
    tipo_jogo domino[1];
    tipo_mesa tabuleiro[1];
    
    tipo_peca monte[14];
    tipo_peca jogador1[21];
    tipo_peca jogador2[21];
    tipo_peca computador[21];
    tipo_peca dominoAux[28];
    tipo_peca bot[21];

    bool veri= true;
    int opcao, tamanho = 28;

    tabuleiro[0].ext_dir = 2;
    tabuleiro[0].ext_esq = 2;
...}
```

- Segue abaixo uma sequência de telas da exibição do jogo:  
    ![Screenshot_Menu_Principal](https://github.com/Julio-Cesar123/Blin_Domino/blob/main/images/Screenshot_Menu_Principal.png)  
  Menu Principal   
