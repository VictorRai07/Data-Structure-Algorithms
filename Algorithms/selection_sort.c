#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  srand(time(NULL));
  time_t inicio, fim;
  long long TAM_MAX = rand() % 100000;
  long long array[TAM_MAX];

  for (long long i = 0; i < TAM_MAX; i++) {
    array[i] = rand() % 100000;
  }

  /*===============Selection Sort===============*/
  inicio = clock();

  for (long long i = 0; i < TAM_MAX; i++) {
    long long IndiceMinimo = i;

    for (int j = i + 1; j < TAM_MAX; j++) {
      if (array[j] < array[IndiceMinimo]) {
        IndiceMinimo = j;
      }
      if (IndiceMinimo != i) {
        long long temp = array[i];
        array[i] = array[IndiceMinimo];
        array[IndiceMinimo] = temp;
      }
    }
  }
  fim = clock();
  /*==========================================================*/
  double t_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

  printf("O tempo total para organizar um vetor de tamanho %lld foi de %fs",
         TAM_MAX, t_total);
  return EXIT_SUCCESS;
}
