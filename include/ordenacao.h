#ifndef _ORDENACAO_H
#define _ORDENACAO_H

/* Armazena elementos de um array de tamanho n em grupos */
typedef struct bucket {
  float num;
  struct bucket *prox;
} bucket;

/*==========protótipo das funções de ordenação==========*/

void boobleSort(int *array, int tam_array);
void insertionSort(int *array, int tam_array);
void selectionSort(int *array, int tam_array);

void mergeSort(int *array, int tam_array);
static void merge_sort_recursivo(int *array, int inicio, int fim);
static void merge(int *array, int inicio_e, int meio, int inicio_d);

void quickSort(int *array, int tam_array);
static void quick_sort_recursivo(int *array, int inicio, int fim);
static int particiona_random(int *array, int inicio, int fim);
static int particiona(int *array, int inicio, int fim);

void heapSort(int *array, int tam_array);
static void executar_heapsort(int *array, int root);
static void heapify(int *array, int fim, int raiz);

/* Função que ordena em ordem crescente um array de inteiros de n elementos
 * usando o algoritmo RADIX SORT */
void radixSort(int *array, int tam_array);
static void countDigit(int *array, int tam_array,
                       int exp); // exp = 10^i => i = index do array

/* Função que ordena em ordem crescente um array de inteiros de n elementos
 * usando o algoritmo COUNTING SORT */
void countingSort(int *array, int tam_array);

/* Função que ordena em ordem crescente um array de inteiros de n elementos
 * usando o algoritmo BUCKET SORT*/
void bucketSort(int *array, int tam_array);
static bucket *InsertionBucket(bucket *grupo, int valor);
#endif // _ORDENACAO_H
