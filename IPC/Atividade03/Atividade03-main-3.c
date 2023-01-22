/*

************** Exercicio 03 **************

Escreva 2 funções recursivas denominadas crescente e 
decrescente que recebam um número inteiro N e 
imprimam todos os números naturais de 0 até N em 
ordem crescente e decrescente:

int main() {
    printf("\n crescente: ");
    crescente(15);
    printf("\n decrescente: ");
    decrescente(15);
    return 0;
}

Saída:
crescente: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
descrescente: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0

*/

#include <stdio.h>

void crescente(int n) {
    if (n >= 0) {
        crescente(n-1);
        printf("%d ", n);
    }
}

void decrescente(int n) {
    if (n >= 0) {
        printf("%d ", n);
        decrescente(n-1);
    }
}

int main(){
    printf("Crescente: "); crescente(15);
    printf("\nDecresente: "); decrescente(15);
    return 0;
}
