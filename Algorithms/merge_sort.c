#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  long long TAM_MAX = rand() % 50;

  long long array[TAM_MAX];
  for (long long i = 0; i < TAM_MAX; i++) {
    array[i] = rand() % 100000;
  }

  long long *array_aux;
  array_aux = malloc((TAM_MAX) * sizeof(long long));

  time_t inicio, fim;
  double t_total;

  long long ini = 0, meio_v = (double)(TAM_MAX - ini / 2), fim_v = (int)TAM_MAX;
  long long i = ini, j = meio_v;
  long long k = 0;

  /*===============VETOR ANTES DO ALGORITMO DE ORDENAÇÃO===============*/
  for (int k = 0; k < TAM_MAX; k++) {
    printf("%lld ", array[k]);
  }
  /*==================================================================*/

  inicio = clock();
  while (i < meio_v && j < fim_v) {
    if (i < j)
      array_aux[k++] = array[i++];
    else
      array_aux[k++] = array[j++];
  }
  while (i < j)
    array_aux[k++] = array[i++];
  while (j < i)
    array_aux[k++] = array[j++];

  for (i = ini; i < fim_v; ++i) {
    array[i] = array_aux[i - ini];
  }
  fim = clock();
  t_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

  printf(
      "\n\nO tempo para organizar um vetor de tamanho %lld usando o algoritmo "
      "merge sort foi de %fs\n\n",
      TAM_MAX, t_total);
  /*ARRAY DEPOIS DO ALGORITMO DE ORDENAÇÃO*/
  printf("Vetor ordenado:\n");
  for (int k = 0; k < TAM_MAX; k++) {
    printf("%lld ", array[k]);
  }

  return EXIT_SUCCESS;
}
