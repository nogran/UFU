/*

************** Exercicio 04 **************

Escreva laços para obter o mesmo resultado das 
seguintes funções:
 strlen
 strcpy
 strcat
int main() {
char M[100] = "The quick brown fox jumps over the lazy dog";
char N[100] = "A ligeira raposa marrom saltou sobre o cachorro preguicoso";
char R[100];
// 1) imprimir o tamanho das strings M e N
// 2) copiar M para R
// 3) concatenar N em R
}

*/

#include <stdio.h>

int main() {
    char M[100] = "The quick brown fox jumps over the lazy dog";
    char N[100] = "A ligeira raposa marrom saltou sobre o cachorro preguicoso";
    char R[100];
    int i, tamanho_M = 0, tamanho_N = 0;

    // 1) imprimir o tamanho das strings M e N
    for(i = 0; M[i] != '\0'; i++) {
        tamanho_M++;
    }
    printf("Tamanho de M: %d\n", tamanho_M);

    for(i = 0; N[i] != '\0'; i++) {
        tamanho_N++;
    }
    printf("Tamanho de N: %d\n", tamanho_N);

    // 2) copiar M para R
    for(i = 0; M[i] != '\0'; i++) {
        R[i] = M[i];
    }
    R[i] = '\0';

    // 3) concatenar N em R
    int tamanho_R = tamanho_M;
    for(i = 0; N[i] != '\0'; i++) {
        R[tamanho_R + i] = N[i];
    }
    R[tamanho_R + i] = '\0';

    printf("R: %s\n", R);

    return 0;
}
