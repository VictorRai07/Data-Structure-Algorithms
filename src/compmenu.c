#include "../include/menu.h"
#include "../include/ordenacao.h"
#include "../include/utils.h"
#include "stdio.h"
#include <stdlib.h>

void freeBuffer(void) {
  int buffer;
  while ((buffer = getchar()) != '\n' && buffer != EOF)
    ;
}

void limparTela() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

/* Necessário para fazer a Opção 10 do menu de escolha */
AlgoritmoInfo algoritmos[] = {
    {"Bubble Sort", boobleSort},       {"Insertion Sort", insertionSort},
    {"Selection Sort", selectionSort}, {"Merge Sort", mergeSort},
    {"Quick Sort", quickSort},         {"Heap Sort", heapSort},
    {"Counting Sort", countingSort},   {"Radix Sort", radixSort},
    {"Bucket Sort", bucketSort}};

void menuOrdenacao(int *array, int tam_array) {
  int escolha;
  while (escolha != 0) {
    printf("\t1- Booble Sort          \n"
           "\t2- Insertion Sort       \n"
           "\t3- Seletion Sort        \n"
           "\t4- Merge Sort           \n"
           "\t5- Quick Sort           \n"
           "\t6- Heap Sort            \n"
           "\t7- Counting Sort        \n"
           "\t8- Radix Sort           \n"
           "\t9- Bucket Sort          \n"
           "\t10- Comparar todos      \n"
           "\t0- ENCERRAR O PROGRAMA  \n"
           "Escolha uma opção[0-10]:");

    while (scanf("%d", &escolha) != 1 || escolha < 0 || escolha > 10) {
      printf("Somente números inteiros entre [0-10] são permitidos!\n");
      freeBuffer();
    }
    if (escolha == 10) {
      limparTela();
      printf("\n\n\t=========================================\n");
      for (int i = 0; i < 9; i++) {
        double tempo = ordenacaoTempo(algoritmos[i].func, array, tam_array);
        printf("\tO algoritmo %s ordenou o vetor em %fs\n", algoritmos[i].nome,
               tempo);
      }
      printf("\t=========================================\n\n");
    }
    if (escolha != 0) {
      limparTela();
      AlgoritmoInfo alg = algoritmos[escolha - 1];
      printf("\n\n\t=========================================\n"
             "\tO algoritmo %s ordenou o vetor em %fs\n\n"
             "\t=============================================\n\n",
             alg.nome, ordenacaoTempo(alg.func, array, tam_array));
    }
    if (escolha == 0)
      printf("PROGRAMA FINALIZADO!\n\n");
  }
}
