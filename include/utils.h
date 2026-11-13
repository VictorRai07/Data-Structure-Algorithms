#ifndef UTILS_H
#define UTILS_H

/*=============== Declaração de funções de arrray ===============*/
int Get_Random_Array(int *array, int tam_array, int intervalo_limite);
int copy_array(int *origem, int *destino, int tam_array);
void verificar_ordenacao(int *array, int tam_array);

// Função genérica de parametrização de tempo
typedef void (*AlgoritmoOrdenacao)(int *vetor, int tamanho);
double tempoTotal(AlgoritmoOrdenacao algoritmo, int *array, int tam_array);

#endif // UTILS_H
