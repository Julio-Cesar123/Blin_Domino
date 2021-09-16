#include "DominoData.h"

//Salva um jogo em andamento
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
    //for serve para percorrer todas as posições da variável
        fwrite(jogador1, 1, sizeof(tipo_peca), DominoS);
            //printf("\nErro de gravacao\n\n");   

        fwrite(jogador2, 1, sizeof(tipo_peca), DominoS);
            //printf("\nErro de gravacao\n\n");
        fwrite(monte, 1, sizeof(tipo_peca), DominoS);
            //printf("\nErro de gravacao\n\n");
    
        fwrite(tabuleiro[0].mapa, 1, sizeof(tipo_mesa), DominoS);
            //printf("\nErro de gravacao\n\n"); 

        fwrite(&domino[0], 1, sizeof(tipo_jogo), DominoS);
            //printf("\nErro de gravacao\n\n");       
    
    fclose(DominoS);
}

void carregarArquivo(tipo_jogo domino[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa tabuleiro[], tipo_peca monte[]){
    FILE *DominoS;
    int i;
    //seleciona um arquivo para abrir
    // rb Abre um arquivo binário para leitura. Igual ao modo "r" anterior, só que o arquivo é binário.
    DominoS = fopen("DominoS", "rb");
    //se nao conseguir abrir, irá retornar como NULL
    if (DominoS == NULL) {
        printf("\nArquivo Domino nao pode ser aberto.");
        printf("\nOcorreu um Erro Grave! Use alguma tecla para finalizar!");
        getchar();
    }else{
        
            fread(jogador1, 1, sizeof(tipo_peca), DominoS) ;
                //printf("\nErro de gravacao\n\n");   
  
            fread(jogador2, 1, sizeof(tipo_peca), DominoS); 
                //printf("\nErro de gravacao\n\n");    
   
            fread(monte, 1, sizeof(tipo_peca), DominoS);
                //printf("\nErro de gravacao\n\n");    
  
            fread(tabuleiro[0].mapa, 1, sizeof(tipo_mesa), DominoS);
                //printf("\nErro de gravacao\n\n");

            fread(&domino[0], 1, sizeof(tipo_jogo), DominoS);
    } 
}