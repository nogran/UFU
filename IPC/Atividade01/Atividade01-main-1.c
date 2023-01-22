/*

************** Exercicio 01 **************

Faça um programa que leia um vetor com 20 números de ponto flutuante. Em 
seguida, ordene os elementos desse vetor e imprima o vetor na tela. 

*/

#include <stdio.h>

void bubble_sort(float vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                float temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int main() {
    float vetor[20];
    int i;

    printf("Insira 20 numeros de ponto flutuante:\n");
    for (i = 0; i < 20; i++) {
        scanf("%f", &vetor[i]);
    }

    bubble_sort(vetor, 20);

    printf("Vetor ordenado: \n");
    for (i = 0; i < 20; i++) {
        printf("%.2f ", vetor[i]);
    }
    return 0;
}
