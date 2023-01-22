/*

************** Exercicio 04 **************

Escreva um programa que faça a leitura de 2 matrizes do tipo float
denominadas A e B e calcule a matriz resultante da multiplicação de A e 
B. As matrizes devem ser alocadas dinamicamente. O programa deve fazer 
uso das seguintes funções:

a) função ALOCA: recebe o número de linhas e o número de colunas 
passados por valor, e retorna um ponteiro para uma matriz alocada 
dinamicamente pela função

b) função LEITURA: recebe um ponteiro para uma matriz, o número de 
linhas e o número de colunas, e faz a leitura da matriz (scanf). O tipo 
do retorno deve ser void.  c) função MULTIPLICA: recebe um ponteiro para a matriz A,
o número de linhas e o número de colunas de A, um ponteiro para a matriz B, o 
número de linhas e o número de colunas de B. A função deve executar 
a função ALOCA para alocar a matriz resultado, calcular a 
multiplicação, e retorná-la.

d) função IMPRIME: recebe um ponteiro para uma matriz, o número 
de linhas e o número de colunas, e faz a impressão (printf)

e) função DESALOCA: recebe um ponteiro para uma matriz e o 
número de linhas, e desaloca a matriz (free)
*/

#include <stdio.h>
#include <stdlib.h>

float **Alocar_matriz_real (int m, int n){
  float **v;  /* ponteiro para a matriz */
  int   i;    /* variavel auxiliar      */

  if (m < 1 || n < 1) { /* verifica parametros recebidos */
    printf ("** Erro: Parametro invalido **\n");
    return (NULL);
  }
  /* aloca as linhas da matriz */
  v = (float **) calloc (m, sizeof(float *));
  if (v == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    return (NULL);
  }
  /* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) {
    v[i] = (float*) calloc (n, sizeof(float));
    if (v[i] == NULL) {
      printf ("** Erro: Memoria Insuficiente **");
      return (NULL);
    }
  }
  return (v); /* retorna o ponteiro para a matriz */
}

float **Liberar_matriz_real (int m, int n, float **v){
  int  i;  /* variavel auxiliar */

  if (v == NULL) return (NULL);
  if (m < 1 || n < 1) {  /* verifica parametros recebidos */
    printf ("** Erro: Parametro invalido **\n");
    return (v);
  }
  for (i=0; i<=m; i++) free (v[i]); /* libera as linhas da matriz */
  free (v);      /* libera a matriz */
  return (NULL); /* retorna um ponteiro nulo */
}

void Le_matriz_real(int linhas, int colunas, float **matriz){
  int i, j;

  for (i = 0; i < linhas; i++){
    printf("\nlinha %d: \n", i+1);
    for (j= 0; j<colunas; j++){
      scanf("%f", &matriz[i][j]);
    }
  }
}

void Multiplica_matriz_real(int linha3, int coluna3, int linha2, float **mat1,float **mat2, float **mat3){
  int i, j, t;

  for(i=0; i< linha3; i++){
    for(j=0; j< coluna3; j++){
      mat3[i][j] = 0;
      for(t=0; t< linha2; t++){   /* linha2, que e igual a coluna1.. */
        mat3[i][j] += mat1[i][t]*mat2[t][j];
      }
    }
  }
}

void Imprime_matriz_real(int linha,int coluna,float **mat){
  int i,j;

  for (i =0; i < linha; i++) {
    for (j=0; j<coluna; j++) {
      printf("%f\t", mat[i][j]);
      printf("\n");
    }
  }
}

void main (void){
  float **mat1, **mat2, **mat3;  /* matrizes a serem alocadas */
  int linha1, coluna1;   /* Dimensoes das matrizes */
  int linha2, coluna2;
  int linha3, coluna3;
  int i, j, t, erro=0;
 
 /* Le e compara as dimensoes das matrizes.
    So abandona o loop se as dimensoes forem validas
    Atencao aa condicao...                           */
  do{
    printf("\nDimensoes da matriz 1 (linhas e colunas): ");
    scanf("%d%d", &linha1, &coluna1);
    printf("\nDimensoes da matriz 2 (linhas e colunas): ");
    scanf("%d%d", &linha2, &coluna2);
    if ( coluna1 != linha2 ){
      printf("\nDimensoes Invalidas! Tente de novo..\n");
    }
  } while ( coluna1 != linha2 );
 
 /* Dimensoes da matriz de resposta: */
  linha3 =  linha1;
  coluna3 =  coluna2;
 
 /* Aloca a memoria para as matrizes: */
  if ((mat1 = Alocar_matriz_real (linha1, coluna1))== NULL) erro = 1;
  if ((mat2 = Alocar_matriz_real (linha2, coluna2))== NULL) erro = 1;
  if ((mat3 = Alocar_matriz_real (linha3, coluna3))== NULL) erro = 1;
  if (erro){
  printf("\n Memoria Insuficiente! Abortando..\n");
  exit(1);
}

/* Le a Matriz 1: */
  printf("\n\nDigite a Matriz 1:\n");

  Le_matriz_real(linha1,coluna1,mat1);

/* Le a Matriz 2: */

  printf("\n\nDigite a Matriz 2:\n");

  Le_matriz_real(linha2,coluna2,mat2);

/* Imprime as matrizes lidas */

  printf ("\n\n==>Matriz 1\n");
  Imprime_matriz_real(linha1,coluna1,mat1);
  printf ("\n\n==>Matriz 2\n");
  Imprime_matriz_real(linha2,coluna2,mat2);

/* --------------------- Multiplicacao..*/

  Multiplica_matriz_real(linha3,coluna3,linha2,mat1,mat2,mat3);

/* ------------- Imprime a Matriz Calculada... */

  printf("\n\n==> Matriz 3 , Resultado da multiplicacao:\n");
  Imprime_matriz_real(linha3,coluna3,mat3);

  Liberar_matriz_real (linha1, coluna1, mat1);
  Liberar_matriz_real (linha2, coluna2, mat2);
  Liberar_matriz_real (linha3, coluna3, mat3);
}