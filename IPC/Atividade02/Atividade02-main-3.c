/*

************** Exercicio 03 **************

Escreva um programa que leia uma matriz de caracteres 
(um vetor de strings) com nomes e apresente quem seria o 
primeiro da lista (pela ordem alfabética). 
 Não se deve ordenar a lista
 Equivalente a encontrar o menor valor em um vetor 
numérico
 Utilize a função strcmp para comparar strings.
int main() {
char M[20][30];
// leia cada string M[i]
// localize o elemento que seria primeiro 
// de uma lista ordenada
}

*/

#include <stdio.h>
#include <string.h>

int main() {
    char M[20][30];
    int i, n, indice_menor;
    // leitura da quantidade de nomes
    printf("Informe a quantidade de nomes: ");
    scanf("%d", &n);

    // leitura dos nomes
    for(i = 0; i < n; i++) {
        printf("Informe o %do. nome: ", i+1);
        scanf("%s", M[i]);
    }

    indice_menor = 0;
    // localizando o menor valor
    for(i = 1; i < n; i++) {
        if(strcmp(M[i], M[indice_menor]) < 0) {
            indice_menor = i;
        }
    }

    printf("O primeiro nome da lista (pela ordem alfabetica) é: %s\n", M[indice_menor]);

    return 0;
}