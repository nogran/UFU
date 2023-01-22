/*

************** Exercicio 02 **************

Escreva um programa que tenha uma função que 
calcule e retorne a soma dos primeiros n números 
inteiros elevados a sí próprios:

S = 1*1 + 2*2 + 3*3 + 4*4 + ... + n*n

*/

#include <stdio.h>

int soma(int n) {
    int i, soma = 0;
    for (i = 1; i <= n; i++) {
        soma += i * i;
    }
    return soma;
}

int main() {
    int n = 5;
    printf("Soma dos primeiros %d números inteiros elevados a si próprios: %d", n, soma(n));
    return 0;
}
