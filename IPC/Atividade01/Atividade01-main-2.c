/*

************** Exercicio 02 **************

Faça um programa para ler 10 números diferentes a serem armazenados em um 
vetor. Os números deverão ser armazenados no vetor na ordem em que forem lidos, 
sendo que, caso o usuário digite um número que já foi digitado anteriormente, o 
programa deverá pedir a ele para digitar outro número, até que seja digitado um 
diferente dos anteriores. Note que cada valor digitado pelo usuário deve ser pesquisado 
no vetor, verificando se ele existe entre os números que já foram fornecidos. Exiba na 
tela o vetor final.

*/

#include <stdio.h>

int main() {
    int vetor[10], num, i, j;
    for (i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &num);
        for (j = 0; j < i; j++) {
            if (num == vetor[j]) {
                printf("Numero ja digitado, digite outro: ");
                scanf("%d", &num);
                j = -1;
            }
        }
        vetor[i] = num;
    }
    printf("Vetor final: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}

