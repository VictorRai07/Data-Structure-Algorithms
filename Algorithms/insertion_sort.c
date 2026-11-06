#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  long long MAX_SIZE = rand() % 100;
  long long array[MAX_SIZE];

  /*=========ATRIBUIÇÃO DE VALORES "ALEATÓRIOS" PARA O ARRAY==========*/
  for (long long i = 0; i < MAX_SIZE; i++) {
    array[i] = rand() % 100000;
  }
  /*=================================================================*/
  printf("Array antes da organização:\n");
  for (long long i = 0; i < MAX_SIZE; i++) {
    printf("%lld ", array[i]);
  }

  /* ORDENAÇÃO COM INSERTION SORT*/
  for (long long i = 1; i < MAX_SIZE; i++) {
    long long j = i;
    long long aux = array[j];

    while (j > 0 && aux < array[j - 1]) {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = aux;
  }
  /*=================================*/
  printf("\n\nArray após a organização:\n");

  for (int i = 0; i < MAX_SIZE; i++) {
    printf("%lld ", array[i]);
  }
  return EXIT_SUCCESS;
}
