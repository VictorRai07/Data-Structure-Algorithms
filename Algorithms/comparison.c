#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void troca(int *array, int i, int j);
double booble_sort(int *array, int tam_array);
double insertion_sort(int *array, int tam_array);

void merge_sort(int *array, int inicio, int fim);
void merge(int *array, int inicio_e, int meio, int inicio_d);

void quick_sort(int *array, int inicio, int fim);
int particiona_random(int vet[], int inicio, int fim);
int particiona(int vet[], int inicio, int fim);

int main() {
  int max_int = INT_MAX;
  clock_t inicio, fim;
  double t_total;

  srand(time(NULL));
  int tamanho_array =
      rand() % 100000 +
      100; // Gera um tamanho aleatório para o array entre 100 e 99999
  int array[tamanho_array];
  for (int i = 0; i < tamanho_array; i++) {
    array[i] = rand() % 100000; // Gera números aleatórios entre 0 e 99999
  }
  int copy[tamanho_array];
  int copy_quick[tamanho_array];
  memcpy(copy, array, sizeof(int) * tamanho_array);
  memcpy(copy_quick, array, sizeof(int) * tamanho_array);
  printf("============TAMANHO DO ARRAY: %d=================\n\n",
         tamanho_array);
  printf("Tempo de execução do Booble Sort: %f segundos\n",
         booble_sort(array, tamanho_array));
  printf("Tempo de execução do Insertion Sort: %f segundos\n",
         insertion_sort(array, tamanho_array));

  inicio = clock();
  merge_sort(copy, 0, tamanho_array - 1);
  fim = clock();
  t_total = difftime(fim, inicio);
  printf("Tempo de execução do Merge Sort: %f segundos\n", t_total);

  inicio = clock();
  quick_sort(copy, 0, tamanho_array - 1);
  fim = clock();
  t_total = difftime(fim, inicio);
  printf("Tempo de execução do Quick Sort: %f segundos\n", t_total);
  return 0;
}

void troca(int *array, int i, int j) {
  int aux = j;
  j = i;
  i = aux;
}

double booble_sort(int *array, int tam_array) {
  int copy[tam_array], n;
  clock_t inicio, fim;
  memcpy(copy, array, sizeof(int) * tam_array);

  inicio = clock();

  for (long long i = 0; i < tam_array; i++) {
    for (long long j = i + 1; j < tam_array; j++) {
      if (copy[i] > copy[j]) {
        troca(copy, copy[i], copy[j]);
      }
    }
  }

  fim = clock();
  double t_total = (double)(fim - inicio) / CLOCKS_PER_SEC;

  return t_total;
}

double insertion_sort(int *array, int tam_array) {
  int copy[tam_array];
  clock_t inicio, fim;
  memcpy(copy, array, sizeof(int) * tam_array);

  inicio = clock();

  for (int i = 1; i < tam_array; i++) {
    int j = i;
    int aux = copy[j];

    while (j > 0 && aux < copy[j - 1]) {
      copy[j] = copy[j - 1];
      j--;
    }
    copy[j] = aux;
  }
  fim = clock();

  double t_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
  return t_total;
}

void merge_sort(int *array, int inicio, int fim) {
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;
    merge_sort(array, inicio,
               meio); // Chamada recursiva para a primeira metade do array
    merge_sort(array, meio + 1,
               fim); // Chamada recursiva para a segunda metade do array

    merge(array, inicio, meio, fim); // Chamada para a função de mesclagem
  }
}

void merge(int *array, int inicio, int meio, int fim) {
  int tam_e = meio - inicio + 1; // Tamanho do subarray esquerdo
  int tam_d = fim - meio;        // Tamanho do subarray direito
  int i, j, k;

  int e[tam_e], d[tam_d]; // Criação dos subarrays esquerdo e direito

  for (i = 0; i < tam_e; i++) {
    e[i] = array[inicio + i];
  }
  for (j = 0; j < tam_d; j++) {
    d[j] = array[meio + 1 + j];
  }

  i = 0;
  j = 0;
  k = inicio;

  while (i < tam_e && j < tam_d) {
    if (e[i] <= d[j]) {
      array[k] = e[i];
      i++;
    } else {
      array[k] = d[j];
      j++;
    }
    k++;
  }

  while (i < tam_e) {
    array[k] = e[i];
    i++;
    k++;
  }

  while (j < tam_d) {
    array[k] = d[j];
    j++;
    k++;
  }
}

/*==================== QUICK SORT ====================*/
int particiona(int vet[], int inicio, int fim) {
  int pivo, pivo_indice, i;

  pivo = vet[fim]; // o pivô é sempre o último elemento
  pivo_indice = inicio;

  for (i = inicio; i < fim; i++) {
    // verifica se o elemento é <= ao pivô
    if (vet[i] <= pivo) {
      // realiza a troca
      troca(vet, i, pivo_indice);
      // incrementa o pivo_indice
      pivo_indice++;
    }
  }

  // troca o pivô
  troca(vet, pivo_indice, fim);

  // retorna o índice do pivô
  return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim) {
  // seleciona um número entre fim (inclusive) e inicio (inclusive)
  int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;

  // faz a troca para colocar o pivô no fim
  troca(vet, pivo_indice, fim);
  // chama a particiona
  return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim) {
  if (inicio < fim) {
    // função particionar retorna o índice do pivô
    int pivo_indice = particiona_random(vet, inicio, fim);

    // chamadas recursivas quick_sort
    quick_sort(vet, inicio, pivo_indice - 1);
    quick_sort(vet, pivo_indice + 1, fim);
  }
}
