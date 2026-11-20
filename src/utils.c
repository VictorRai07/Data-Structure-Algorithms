#include "utils.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Get_Random_Array(int *array, int tam_array, int intervalo_limite) {
  if (array == NULL || tam_array < 1 || intervalo_limite < 1)
    return;

  srand(time(NULL));
  for (int i = 0; i < tam_array; i++) {
    array[i] = rand() % intervalo_limite;
  }
}

int *copy_array(int *origem, int tamanho) {
  int *copy = malloc(tamanho * sizeof(int));
  if (origem == NULL || copy == NULL || tamanho < 1)
    return (int *)1;
  memcpy(copy, origem, tamanho * sizeof(int));
  return copy;
}

int getMaxValue(int *array, int tam_array) {
  if (array == NULL || tam_array < 1)
    return EXIT_FAILURE;
  int MaxValue = array[0];
  for (int i = 0; i < tam_array; i++) {
    if (array[i] > MaxValue)
      MaxValue = array[i];
  }
  return MaxValue;
}

StatusOrdenacao verificar_ordenacao(int *array, int tam_array) {
  bool crescente = true;
  bool decrescente = true;
  if (tam_array == 1)
    return IGUAIS;

  for (int i = 0; i < tam_array - 1; i++) {
    if (array[i + 1] < array[i])
      crescente = false;
    if (array[i + 1] > array[i])
      decrescente = false;
    if (crescente == false && decrescente == false)
      return NAO_ORDENADO;
  }

  if (crescente && decrescente)
    return IGUAIS;
  if (crescente) {
    return CRESCENTE;
  }
  return DECRESCENTE;
}

/*Retorna um dado do tipo DOUBLE representando o tempo gasto para ordenar um
 * array de inteiros de tamanho n em segundos */
double ordenacaoTempo(AlgoritmoOrdenacao algoritmo, int *array, int tam_array) {
  if (array == NULL || tam_array < 1)
    return -1.0; // Retornará esse valor para evitar ser confundida com o tempo
                 // de ordenação.
  int *copy = (int *)malloc(tam_array * sizeof(int));
  if (copy == NULL)
    return -1.0;

  copy = copy_array(array, tam_array);
  clock_t inicio = clock();
  algoritmo(copy, tam_array);
  clock_t fim = clock();
  StatusOrdenacao status = verificar_ordenacao(copy, tam_array);
  printf("O array está %s\n", status_para_string(status));
  free(copy);
  double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
  return tempo_execucao;
}
