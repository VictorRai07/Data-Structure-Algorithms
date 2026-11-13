#ifdef ORDENACAO_H
#define ORDENACAO_H

/*==========protótipo das funções de ordenação==========*/

void booble_sort(int *array, int tam_array);
void insertion_sort(int *array, int tam_array);
void selection_sort(int *array, int tam_array);

void merge_sort(int *array, int tam_array);
static void merge_sort_recursivo(int *array, int inicio, int fim);
static void merge(int *array, int inicio_e, int meio, int inicio_d);

void quickSort(int *array, int tam_array);
static void quick_sort_recursivo(int *array, int inicio, int fim);
static int particiona_random(int *array, int inicio, int fim);
static int particiona(int *array, inicio inicio, int fim);

void heapSort(int *array, int tam_array);
static void heapSort_recursivo(int *array, int root);
static void heapify(int *array, int fim, int raiz);
#endif // ORDENACAO_H
