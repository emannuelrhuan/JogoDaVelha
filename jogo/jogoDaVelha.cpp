// Emannuel Rhuan Leandro da Silva 
// Matricula: 201908607149

#include<stdlib.h>
#include<stdio.h>

void tabuleiro (char casas1 [3][3]){  // void criado para demostração do tabuleiro do jogo da velha
    system("cls");
    printf("                      \t COLUNAS            \n");
    printf("                 \t1    2    3         \n\n");
    printf("\t           1     %c | %c | %c\n", casas1[0][0], casas1[0][1], casas1[0][2]);
    printf("\t                ------------\n");
    printf("\t  LINHAS   2     %c | %c | %c\n", casas1[1][0], casas1[1][1], casas1[1][2]);
    printf("\t                ------------\n");
    printf("\t           3     %c | %c | %c\n", casas1[2][0], casas1[2][1], casas1[2][2]);
}

int main(){
    char resposta; int Contagem_jogadas, lin, col, vez_jogador=0, i, j;
    char casas[3][3] = {  {'1','2','3'},
                          {'4','5','6'},
                          {'7','8','9'}, }; // numeração foi de teste inicial

     
   
   do{
        Contagem_jogadas = 1;   //inicializando o jogo em 1
        for(i = 0;i <= 2; i++){
            for(j = 0;j <=2; j++){ // mecanismo para limpar o tabuleiro e nao mostrar os numeros de teste inical!! 
                casas[i][j] = ' ';
            }
        }
          
       do{
          tabuleiro(casas);
          if(vez_jogador%2==0){   // para a indentificação da vez de qual jogador sendo JOGADOR 1 E JOGADOR 2
              printf("\n----------");
              printf("\n|Jogador 1|");
              printf("\n----------\n");
          }else{
              printf("\n----------");
              printf("\n|Jogador 2|");
              printf("\n----------\n");
          }
          printf("Digite a Linha: ");
          scanf("%i",&lin);
          printf("Digite a Coluna: ");
          scanf("%i",&col); // apos isso,// criar a condição
  
           //========== SE A JOGADA FOR EM CASAS QUE NAO EXISTE =========
          if(lin < 1 || col < 1 || lin > 3 || col > 3) {
                lin = 0;
                col = 0;  // dessa forma dizer que a jogada foi invalida
                          // caso tenha colocado as casas que nao tem na matriz

          }else if(casas[lin - 1][col - 1] != ' '){ // CASO A CASA ESTEJA OCUPADA !
                lin = 0;
                col = 0;
          }else{
              if(vez_jogador %2 == 0){   // se o resto da divisão for um numero PAR
                  casas[lin-1][col-1] = 'x'; // sempre usado -1 pq o usuario vai esta colocando 
                                                   // linhas e colunas como se fosse a parte do 1
                 }else{ // SE NÃO SERA IMPAR E LOGO ASSIM A VEZ DO OUTRO JOGADOR!
                     casas[lin-1][col-1] = 'o';
                 }
                 vez_jogador++; // para pula a vez do jogador
                 Contagem_jogadas++; // e para contagem de jogadas
          }
          // =====================VERIFICAÇÃO DE VITORIA DE X =======================================
          //Verificação de linhas
          if(casas[0][0] == 'x' && casas[0][1] == 'x' && casas[0][2] == 'x'){Contagem_jogadas = 11;}
          if(casas[1][0] == 'x' && casas[1][1] == 'x' && casas[1][2] == 'x'){Contagem_jogadas = 11;}
          if(casas[2][0] == 'x' && casas[2][1] == 'x' && casas[2][2] == 'x'){Contagem_jogadas = 11;}
          //Verificação de colunas
          if(casas[0][0] == 'x' && casas[1][0] == 'x' && casas[2][0] == 'x'){Contagem_jogadas = 11;}
          if(casas[0][1] == 'x' && casas[1][1] == 'x' && casas[2][1] == 'x'){Contagem_jogadas = 11;}
          if(casas[0][2] == 'x' && casas[1][2] == 'x' && casas[2][2] == 'x'){Contagem_jogadas = 11;}
          //Verificação de Diagonais
          if(casas[0][2] == 'x' && casas[1][1] == 'x' && casas[2][0] == 'x'){Contagem_jogadas = 11;}
          if(casas[0][0] == 'x' && casas[1][1] == 'x' && casas[2][2] == 'x'){Contagem_jogadas = 11;}


          // =====================VERIFICAÇÃO DE VITORIA DE O =======================================
          //Verificação de linhas
          if(casas[0][0] == 'o' && casas[0][1] == 'o' && casas[0][2] == 'o'){Contagem_jogadas = 12;} // aqui mudamos o valor pq sera com isso que iremos indicar o vencedor
          if(casas[1][0] == 'o' && casas[1][1] == 'o' && casas[1][2] == 'o'){Contagem_jogadas = 12;}
          if(casas[2][0] == 'o' && casas[2][1] == 'o' && casas[2][2] == 'o'){Contagem_jogadas = 12;}
          //Verificação de colunas
          if(casas[0][0] == 'o' && casas[1][0] == 'o' && casas[2][0] == 'o'){Contagem_jogadas = 12;}
          if(casas[0][1] == 'o' && casas[1][1] == 'o' && casas[2][1] == 'o'){Contagem_jogadas = 12;}
          if(casas[0][2] == 'o' && casas[1][2] == 'o' && casas[2][2] == 'o'){Contagem_jogadas = 12;}
          //Verificação de Diagonais
          if(casas[0][2] == 'o' && casas[1][1] == 'o' && casas[2][0] == 'o'){Contagem_jogadas = 12;}
          if(casas[0][0] == 'o' && casas[1][1] == 'o' && casas[2][2] == 'o'){Contagem_jogadas = 12;}
          

       }while (Contagem_jogadas <=9);
       tabuleiro(casas); // para mostrar a marcação da ultima casa!
       if(Contagem_jogadas == 10 ){ // condições para mostrar o vencedor!
           printf("\nDeu Velha!\n");
       } if(Contagem_jogadas == 11){
           printf("\nVitoria do Jogador 1!\n");
       }if(Contagem_jogadas == 12){
           printf("\nVitoria do Jogador 2!\n");
       }
                printf("\nNOME DO(S) ALUNO(S):\n");
           printf("\nEMANNUEL RHUAN LEANDRO DA SILVA\n");
           printf("\nMATRICULA: 201908607149\n");
        printf("\nDeseja jogar novamente ?[S-N]\n"); // sistema de repetição apos o termino de uma partida
        scanf("%s",&resposta);//leitura de resposta
   }while (resposta=='s'||resposta=='S'); //condição para uma nova partida
}