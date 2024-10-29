#include "sala_compartilhada.h"

/**
 * @brief Construtor que inicializa a sala compartilhada.
 */
SalaCompartilhada::SalaCompartilhada(int numero, int andar, int estacoes)
    : Sala(numero, andar), numero_de_estacoes_de_trabalho_disponiveis(estacoes) {}

/**
 * @brief Calcula o preço da sala com base no número de estações.
 * 
 * Retorna o número de estações de trabalho multiplicado por 75.
 */
double SalaCompartilhada::calcula_preco() const {
    return numero_de_estacoes_de_trabalho_disponiveis * 75.0;
}
