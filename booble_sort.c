#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  long long n;
  int max_int = INT_MAX;
  clock_t inicio, fim;
  double t_total;

  srand(time(NULL));
  long long tamanho_array = rand() % 10000;
  long long array[tamanho_array];
  for (long long i = 0; i < tamanho_array; i++) {
    array[i] = rand() % 10000;
  }
  inicio = clock();

  for (long long i = 0; i < tamanho_array; i++) {
    for (long long j = 1 + 1; j < tamanho_array; j++) {
      if (array[i] > array[j]) {
        n = array[i];
        array[i] = array[j];
        array[j] = n;
      }
    }
  }

  fim = clock();

  t_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("O tempo total gasto para organizar em ordem crescente um vetor de "
         "tamanho %lld foi de %fs",
         tamanho_array, t_total);

  return 0;
}
