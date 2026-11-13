#include "../include/ordenacao.h"
#include <stdlib.h>

static void merge_sort_recursivo(int *array, int inicio, int fim);
static void merge(int *array, int inicio, int meio, int fim);

static void heapSort_recursivo(int *array, int fim);
static void heapify(int *array, int fim, int raiz);

static void quick_sort_recursivo(int vet[], int inicio, int fim);
static int particiona(int vet[], int inicio, int fim);
static int particiona_random(int vet[], int inicio, int fim);

static void troca(int *array, int i, int j) {
  int aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}
/*==========================BOOBLE SORT================================*/
void booble_sort(int *array, int tam_array) {
  for (int i = 0; i < tam_array; i++) {
    for (int j = i + 1; j < tam_array; j++) {
      if (array[i] > array[j]) {
        troca(array, i, j);
      }
    }
  }
}

/*=============================================================================================*/
void insertion_sort(int *array, int tam_array) {
  for (int i = 1; i < tam_array; i++) {
    int j = i;
    int aux = array[j];

    while (j > 0 && aux < array[j - 1]) {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = aux;
  }
}

/*==============================================================================================*/
void selection_sort(int *array, int tam_array) {
  for (int i = 0; i < tam_array; i++) {

    int min_indx = 1;

    for (int j = i + 1; j < tam_array; j++) {
      if (array[j] < array[min_indx])
        min_indx = j;
    }
    troca(array, min_indx, i);
  }
}

/*============================================================================================*/
void merge_sort(int *array, int tam_array) {
  if (tam_array > 1)
    merge_sort_recursivo(array, 0, tam_array - 1);
}

static void merge_sort_recursivo(int *array, int inicio, int fim) {
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;
    merge_sort_recursivo(
        array, inicio,
        meio); // Chamada recursiva para a primeira metade do array
    merge_sort_recursivo(
        array, meio + 1,
        fim); // Chamada recursiva para a segunda metade do array

    merge(array, inicio, meio, fim); // Chamada para a função de mesclagem
  }
}

static void merge(int *array, int inicio, int meio, int fim) {
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

/*=======================================================================*/
void quick_sort(int *array, int tam_array) {
  if (tam_array > 1)
    quick_sort_recursivo(array, 0, tam_array - 1);
}

static void quick_sort_recursivo(int vet[], int inicio, int fim) {
  if (inicio < fim) {
    // função particionar retorna o índice do pivô
    int pivo_indice = particiona_random(vet, inicio, fim);

    // chamadas recursivas quick_sort
    quick_sort_recursivo(vet, inicio, pivo_indice - 1);
    quick_sort_recursivo(vet, pivo_indice + 1, fim);
  }
}

static int particiona(int vet[], int inicio, int fim) {
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

static int particiona_random(int vet[], int inicio, int fim) {
  // seleciona um número entre fim (inclusive) e inicio (inclusive)
  int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;

  // faz a troca para colocar o pivô no fim
  troca(vet, pivo_indice, fim);
  // chama a particiona
  return particiona(vet, inicio, fim);
}
/*===========================================================================================*/
void heap_sort(int *array, int tam_array) {
  if (tam_array > 1)
    heapSort_recursivo(array, tam_array - 1);
}

static void heapSort_recursivo(int *array, int fim) {
  for (int i = fim / 2 - 1; i > 0; i--)
    heapify(array, fim, i);

  for (int i = fim - 1; i > 0; i--) {
    troca(array, i, 0);

    heapify(array, i, 0);
  }
}

static void heapify(int *array, int fim, int raiz) {
  int maior = raiz;

  int e = 2 * raiz + 1;
  int d = 2 * raiz + 2;

  if (e < fim && array[e] > array[maior])
    maior = e;

  if (d < fim && array[d] > array[maior])
    maior = d;

  // If largest is not root
  if (maior != raiz) {
    troca(array, raiz, maior);

    heapify(array, raiz, maior);
  }
}
