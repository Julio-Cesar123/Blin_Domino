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
que leva a vantagem durante a partida.Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas, de forma que os pontos de um dos lados
coincidamcom os pontos da extremidade onde está  sendo  colocada.  As  dobradas  são  colocadas  de  maneira  transversal  para  facilitar  sua localização. Quando o jogador
coloca sua peça sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador.Se um jogador não puder jogar, deverá “comprar” do monte tantas peças como forem necessárias. Se
não houver peças no monte, passará o turno ao seguinte jogador.A partida continua com os jogadores colocando suas peças sobre a mesa até que se apresente alguma das seguintes
situações:

  - Quando um jogador coloca sua última pedra na mesa, essa ação é chamada de bater. Quando joga-se sozinho, o jogador que ganhou a partida soma os pontos de todos os seus 
adversários. Jogando em dupla, somam-se os pontos de todos os jogadores incluindo os do seu companheiro.
  - Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o número das extremidades saiu 7 vezes antes. Nesse momento se diz que a partida está 
fechada. Os jogadores contarão os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se os pontos da maneira habitual.

O projeto foi dividido em 4 módulos:
  - Model;
  - View;
  - Data;
  - Controller;

O módulo "Model" é onde estão localizadas as funções relacionadas com a lógica do jogo, veja abaixo um trecho de exemplo, uma função qe embaralha as 28 peças do domino:
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
