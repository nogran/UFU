/*

************** Exercicio 04 **************

Leia n valores numéricos e armazene-os no vetor V. O valor de n deve ser lido antes
da leitura do vetor V. Calcule e exiba o valor da variância de uma amostra d e a média m
do vetor V.

*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int i, j;
    float vetor[20], aux;
    printf("Digite os valores do Vetor \n");
    for (i = 0; i < 20; i++){
        scanf("%f", &vetor[i]);
    }

    for (i = 0; i < 20; i++){
        for (j = i + 1; j < 20; j++){
            if (vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("Este eh o seu vetor: \n");
    for (i = 0; i < 20; i++){
        printf("%.0f ", vetor[i]);
    }
}
