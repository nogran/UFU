/*

************** Exercicio 05 **************

Escreva uma função iterativa e uma função recursiva que 
receba um número inteiro positivo e retorne o enésimo termo 
da sequência de Fibonacci. Essa sequência começa com os 
termos 0 e 1, e a partir do segundo termo seu valor é dado pela 
soma dos dois termos anteriores. Os primeiros termos da 
sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34.

Utilize o código a seguir para imprimir os 100 primeiros 
termos. Escreva um comentário no programa sobre o 
desempenho das duas funções (tempo de execução).

int main() {
    int i;
    for (i = 1; i < 100; i++){
        printf("\n termo %d: %d", i, FibonacciIterativo(i));
    }
    for (i = 1; i < 100; i++){
        printf("\n termo %d: %d", i, FibonacciRecursivo (i));
    }
    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

int FibonacciIterativo(int n) {
    int i, a = 0, b = 1, c;
    if (n == 0) return 0;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int FibonacciRecursivo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return FibonacciRecursivo(n-1) + FibonacciRecursivo(n-2);
}


int main() {
    int i;
    
    for (i = 1; i < 100; i++){
        printf("\n termo %d: %d", i, fInterativo(i));
    }
    for (i = 1; i < 100; i++){
        printf("\n termo %d: %d", i, fibonacci (i));
    }
    return 0;
}

// Comentário sobre o desempenho:

// A função iterativa é mais eficiente em termos de tempo de execução, pois ela não chama a si mesma
// e evita a criação de várias chamadas recursivas.

// A função recursiva, por outro lado, pode causar uma pilha de chamadas recursivas que podem consumir
// muita memória e causar lentidão no programa. 

// Em particular, o desempenho de função recursiva piora para n grandes.
