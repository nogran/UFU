/*

************** Exercicio 05 **************

Jogo da velha: escreva um programa que declare uma matriz de 3 linhas e 3 colunas
de números inteiros. Inicialmente, todas as posições da matriz devem ser zero. Há 2
jogadores, que marcam suas jogadas alternadamente. Ao jogar, armazena-se 1 ou 2 na
posição escolhida, referente aos jogadores 1 ou 2. A cada jogada, verificar a
possibilidade do jogador ter ganhado a partida.

*/

int main(){
    int i, j, v[3][3], c, p1, p2, win = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            v[i][j] = 0;
        }
    }

    // INICIO
    printf("Vamos jogar o jogo da velha? \n \n \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf(" %d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\n \n");

    while (win == 0){
        // JOGADOR1
        printf("Eh a vez do jogador numero 1, primeiro, digite a LINHA onde esta a casa em que voce quer jogar) \n ");
        scanf("%d", &i);
        printf("Otimo, agora digite a COLUNA onde esta a casa em que voce quer jogar) \n ");
        scanf("%d", &j);
        v[i - 1][j - 1] = 1;
        printf("\n \n");
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                printf(" %d ", v[i][j]);
            }
            printf("\n");
        }
        printf("\n \n");

        // CONFERIR SE JOGADOR 1 GANHOU
        if ((v[0][0] == 1 && v[0][1] == 1 && v[0][0] == 1 && v[0][2] == 1) ||
            (v[1][0] == 1 && v[1][1] == 1 && v[1][0] == 1 && v[1][2] == 1) ||
            (v[2][0] == 1 && v[2][1] == 1 && v[2][0] == 1 && v[2][2] == 1) ||
            (v[0][0] == 1 && v[1][0] == 1 && v[0][0] == 1 && v[2][0] == 1) ||
            (v[0][1] == 1 && v[1][1] == 1 && v[0][1] == 1 && v[2][1] == 1) ||
            (v[0][2] == 1 && v[1][2] == 1 && v[0][2] == 1 && v[2][2] == 1) ||
            (v[0][0] == 1 && v[1][1] == 1 && v[0][0] == 1 && v[2][2] == 1) ||
            (v[0][2] == 1 && v[1][1] == 1 && v[0][2] == 1 && v[2][0] == 1)){
            printf("O jogador 1 venceu!! \n \n \n \n");
            win = 1;
        }else{
            // JOGADOR2
            printf("Eh a vez do jogador numero 2, primeiro, digite a LINHA onde esta a casa em que voce quer jogar) \n ");
            scanf("%d", &i);
            printf("Otimo, agora digite a COLUNA onde esta a casa em que voce quer jogar) \n ");
            scanf("%d", &j);
            v[i - 1][j - 1] = 2;
            printf("\n \n");
            for (i = 0; i < 3; i++){
                for (j = 0; j < 3; j++){
                    printf(" %d ", v[i][j]);
                }printf("\n");
            }printf("\n \n");
        }

        // CONFERIR SE JOGADOR 2 GANHOU
        if ((v[0][0] == 2 && v[0][1] == 2 && v[0][0] == 2 && v[0][2] == 2) ||
            (v[1][0] == 2 && v[1][1] == 2 && v[1][0] == 2 && v[1][2] == 2) ||
            (v[2][0] == 2 && v[2][1] == 2 && v[2][0] == 2 && v[2][2] == 2) ||
            (v[0][0] == 2 && v[1][0] == 2 && v[0][0] == 2 && v[2][0] == 2) ||
            (v[0][1] == 2 && v[1][1] == 2 && v[0][1] == 2 && v[2][1] == 2) ||
            (v[0][2] == 2 && v[1][2] == 2 && v[0][2] == 2 && v[2][2] == 2) ||
            (v[0][0] == 2 && v[1][1] == 2 && v[0][0] == 2 && v[2][2] == 2) ||
            (v[0][2] == 2 && v[1][1] == 2 && v[0][2] == 2 && v[2][0] == 2)){
            printf("O jogador 2 venceu!! \n \n \n \n");
            win = 2;
        }
    }
    printf("\n \n \n \n \n");
}
