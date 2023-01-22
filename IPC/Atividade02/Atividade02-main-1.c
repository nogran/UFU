/*


************** Exercicio 01 **************

Escreva um programa para calcular a multiplicação de uma matriz
MxN por uma matriz NxP alocadas dinamicamente. A matriz
resultado também deve ser alocada dinamicamente.
Imprima as matrizes de entrada e a matriz resultante.
Ao final, desaloque as matrizes

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int M, N, P, i, j, k;

    printf("Digite a quantidade de linhas da matriz M1\n");
    scanf("%d", &M);
    printf("\nDigite a quantidade de colunas da matriz M1\n");
    scanf("%d", &N);

    printf("\n\nAviso: Como voce vai multiplicar as matrizes, sua matriz M2 devera ter %d linhas\n\n", N);

    printf("\nDigite a quantidade de colunas da matriz M2\n");
    scanf("%d", &P);

    printf("\nVamos agora digitar os valores da matriz M1\n");
    int **M1 = (int**) malloc(M*sizeof(int*));
    for ( i=0 ; i<M ; i++){
        M1[i] = (int *)malloc(N * sizeof(int *));
        for (j = 0; j < N; j++){
            printf("Digite o valor de M1[%d][%d] = ", i, j);
            scanf("%d", &M1[i][j]);
        }
    }

    // Alocando e lendo a Matriz M2
    printf("\nVamos agora digitar os valores da matriz M2\n");
    int **M2 = (int**) malloc(N*sizeof(int*));
    for ( i=0 ; i<N ; i++){
        M2[i] = (int *)malloc(P * sizeof(int));
        for (j = 0; j < P; j++){
            printf("Digite o valor de M2[%d][%d] = ", i, j);
            scanf("%d", &M2[i][j]);
        }
    }

    // Alocando e zerando a Matriz M3
    int **M3 = (int**) malloc(M*sizeof(int*));
    for ( i=0 ; i<M ; i++){
        M3[i] = (int *)malloc(P * sizeof(int));
        for (j = 0; j < P; j++){
            M3[i][j] = 0;
        }
    }

    // Multiplicando M1 e M2 e salvando em M3
    for ( i=0; i<M ; i++){
        for (j = 0; j < P; j++){
            for (k = 0; k < N; k++){
                M3[i][j] = M3[i][j] + M1[i][k] * M2[k][j];
            }
        }
     }

    // Escrevendo M1 na tela
    printf("\nSua Matriz M1 eh \n");
    for ( i=0 ; i<M ; i++){
        for (j = 0; j < N; j++){
            printf(" %d ", M1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Escrevendo M2 na tela
    printf("\nSua Matriz M2 eh \n");
    for ( i=0 ; i<N ; i++){
        for (j = 0; j < P; j++){
            printf(" %d ", M2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Escrevendo M3 na tela
    printf("\nSua Matriz resultado eh \n");
    for ( i=0 ; i<M ; i++){
        for (j = 0; j < P; j++){
            printf(" %d ", M3[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Desalocando M1
    for ( i=0 ; i<M ; i++ ){
        free(M1[i]);
    }
    free(M1);

    // Desalocando M2
    for ( i=0 ; i<N ; i++ ){
        free(M2[i]);
    }
    free(M2);

    // Desalocando M3
    for ( i=0 ; i<M ; i++ ){
        free(M3[i]);
    }
    free(M3);

    return 0;

}
