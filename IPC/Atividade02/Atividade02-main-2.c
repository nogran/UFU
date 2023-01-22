/*

************** Exercicio 02 **************

Escreva um programa que leia um cubo tridimensional com
coordenadas X, Y e Z de números de ponto flutuante alocado
dinamicamente com N posições para cada coordenada. O objetivo é
fazer a agregação dos valores que estão em uma dimensão para
valores específicos das outras duas. Por exemplo, se o usuário
quiser a agregação quando Y = 3 e Z = 4, devem ser somados os
valores das células com X de 1 a N para Y = 3 e Z = 4.

Assim, após a leitura do cubo, em uma repetição devem ser
oferecidas as opções: XY, XZ e YZ, seguido da leitura dos valores
para o par escolhido.


*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, X, Y, Z, i, j, k, opcao;
    float agrega = 0;

    // Definindo a dimensão do cubo
    printf("Defina o tamanho da aresta do cubo");
    scanf("%d", &N);

    // Alocando e lendo o Cubo
    printf("\nVamos agora escrever todos os elementos do cubo\n");
    float ***Cubo = (float ***)malloc(N * sizeof(float **));
    for (i = 0; i < N; i++){
        Cubo[i] = (float **)malloc(N * sizeof(float *));
        for (j = 0; j < N; j++){
            Cubo[i][j] = (float *)malloc(N * sizeof(float));
            for (k = 0; k < N; k++){
                printf("Digite o valor correspondente ao elemento
                Cubo[%d][%d][%d] = ", i, j, k);
                scanf("%f", &Cubo[i][j][k]);
            }
        }
    }
    // Imprimindo o cubo
    for (k = 0; k < N; k++){
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf(" %.2f ", Cubo[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n\n");

    // Escolhendo a agregação
    printf("Digite 1 para fazer a agregação de valores XY\n");
    printf("Digite 2 para fazer a agregação de valores XZ\n");
    printf("Digite 3 para fazer a agregação de valores YZ\n");
    scanf("%d", &opcao);

    // Fazendo a agregação
    switch (opcao){

    // Agregação XY
    case 1:
        printf("Escolha o valor de X\n");
        scanf("%d", &X);
        printf("Escolha o valor de Y\n");
        scanf("%d", &Y);
        for (i = 0; i < N; i++){
            agrega = agrega + Cubo[X][Y][i];
        }
        break;
    // Agregação XZ
    case 2:
        printf("Escolha o valor de X\n");
        scanf("%d", &X);
        printf("Escolha o valor de Z\n");
        scanf("%d", &Z);
        for (i = 0; i < N; i++){
            agrega = agrega + Cubo[X][i][Z];
        }
        break;
    // Agregação YZ
    case 3:
        printf("Escolha o valor de Y\n");
        scanf("%d", &Y);
        printf("Escolha o valor de Z\n");
        scanf("%d", &Z);
        for (i = 0; i < N; i++){
            agrega = agrega + Cubo[i][Y][Z];
        }
        break;
    }
    printf("O valor da agregacao eh: %f", agrega);
    return 0;

}
