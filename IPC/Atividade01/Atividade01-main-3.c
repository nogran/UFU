/*

************** Exercicio 03 **************

Leia n valores numéricos e os armazene no vetor v. O valor de n também deve ser
lido. Calcule e exiba o valor da série S onde vi é o i-ésimo valor armazenado no vetor v.

*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int N, i;
    float s = 0, somatoria = 0;
    printf("Insira a quantidade de valores que o vetor tera \n");
    scanf("%d", &N);
    float v[N];
    for (i = 0; i < N; i++){
        printf("Insira o %d valor do vetor \n", i + 1);
        scanf("%f", &v[i]);
        somatoria = somatoria + (v[i] / ((i + 1) * (i + 1)));
    }
    s = cbrt(somatoria);
    printf("O valor da serie s eh %f \n", s);
}
