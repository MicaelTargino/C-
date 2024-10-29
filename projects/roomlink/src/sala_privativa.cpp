#include "sala_privativa.h"

/**
 * @brief Construtor que inicializa a sala privativa.
 */
SalaPrivativa::SalaPrivativa(int numero, int andar, int capacidade)
    : Sala(numero, andar), capacidade_maxima_de_pessoas(capacidade) {}

/**
 * @brief Calcula o preço da sala com base na capacidade.
 * 
 * Retorna o valor da capacidade máxima multiplicado por 100.
 */
double SalaPrivativa::calcula_preco() const {
    return capacidade_maxima_de_pessoas * 100.0;
}
