/*

************** Exercicio 01 **************

Escreva um programa que tenha uma função que 
receba a massa (kg) e a altura (metros) de uma 
pessoal. Calcule e retorne o IMC (índice de massa 
corporal) definido como:

IMC = peso / (altura * altura)
*/

#include <stdio.h>

float imc(float massa, float altura) {
    return massa / (altura * altura);
}

int main() {
    float massa = 70.0, altura = 1.75;
    printf("IMC: %.2f", imc(massa, altura));
    return 0;
}
