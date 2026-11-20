#ifndef _UTILS_H
#define _UTILS_H

/* Representa os estados de ordenação possíveis de um array */
typedef enum {
  NAO_ORDENADO = 0,
  CRESCENTE,
  DECRESCENTE,
  IGUAIS
} StatusOrdenacao;

static inline const char *status_para_string(StatusOrdenacao status) {
  switch (status) {
  case NAO_ORDENADO:
    return "NAO_ORDENADO";
  case CRESCENTE:
    return "CRESCENTE";
  case DECRESCENTE:
    return "DECRESCENTE";
  case IGUAIS:
    return "IGUAIS";
  default:
    return "DESCONHECIDO";
  }
}
/* Retorna o estado de ordenação de um array */
StatusOrdenacao verificar_ordenacao(int *array, int tam_array);

/* Retorna um array do tipo INT aletório dado um tamanho n e um intervalo de
 * valores */
void Get_Random_Array(int *array, int tam_array, int intervalo_limite);

/* Retorna a cópia de um array do tipo INT */
int *copy_array(int *origem, int tamanho);

/* Retorna o maior valor contido em um array do tipo INT */
int getMaxValue(int *array, int tam_array);

/* Retorna o menor valor contido em um array do tipo INT */
int getMinValue(int *array, int tam_array);

int *getMax_and_MinValues(int *array, int tam_array);
/* Função genérica de parametrização de tempo de algoritmos de ordenação para
 * arrays*/
typedef void (*AlgoritmoOrdenacao)(int *array, int tam_array);
double ordenacaoTempo(AlgoritmoOrdenacao algoritmo, int *array, int tam_array);

#endif // _UTILS_H
