#ifndef SALACOMPARTILHADA_H
#define SALACOMPARTILHADA_H

#include "sala.h"

/**
 * @brief Classe que representa uma sala compartilhada.
 * 
 * A sala compartilhada possui estações de trabalho e calcula o preço 
 * com base na quantidade de estações.
 */
class SalaCompartilhada : public Sala {
private:
    int numero_de_estacoes_de_trabalho_disponiveis; /**< Número de estações de trabalho */

public:
    /**
     * @brief Construtor que inicializa a sala compartilhada.
     * 
     * @param numero Número da sala.
     * @param andar Andar da sala.
     * @param estacoes Número de estações de trabalho disponíveis.
     */
    SalaCompartilhada(int numero, int andar, int estacoes);

    /**
     * @brief Calcula o preço da sala com base nas estações de trabalho.
     * 
     * Sobrescreve o método `calcula_preco` para salas compartilhadas.
     * @return double Preço da sala.
     */
    double calcula_preco() const override;
};

#endif // SALACOMPARTILHADA_H
