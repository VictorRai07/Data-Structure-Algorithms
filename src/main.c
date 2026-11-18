#include "../include/menu.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int tam_array, intervalo_limite, menu, tempo;
  printf("Digite o tamanho do vetor: ");
  while (scanf("%d", &tam_array) != 1 || tam_array < 1) {
    printf("Somente números inteiros e maiores do que 0 são permitidos!\n");
    freeBuffer();
  }
  int *array = malloc(tam_array * sizeof(int));

  printf("Digite o limite do intervalo de números contidos no vetor: ");
  while (scanf("%d", &intervalo_limite) != 1 || intervalo_limite < 1) {
    printf("Somente números inteiros e maiores do que 0 são permitidos!\n");
    freeBuffer();
  }
  Get_Random_Array(array, tam_array, intervalo_limite);
  menuOrdenacao(array, tam_array);
  StatusOrdenacao status = verificar_ordenacao(array, tam_array);
}
