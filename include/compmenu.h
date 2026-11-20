#include "utils.h"

#ifndef _MENU_H_
#define _MENU_H_
/* Exibe um menu com 9 possibilidades de algoritmo de ordenação */
void menuOrdenacao(int *array, int tam_array);

/* Limpa o buffer do teclado se um scanf for mal sucedido */
void freeBuffer();

/* Tebela responsável por atribuir nome e funcão pro algoritmo de ordenação */
typedef struct {
  const char *nome;
  AlgoritmoOrdenacao func;
} AlgoritmoInfo;

/* Limpa a tela do terminal */
void limparTela();
#endif // !__MENU_H_
