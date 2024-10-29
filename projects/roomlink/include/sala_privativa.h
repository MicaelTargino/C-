#ifndef SALAPRIVATIVA_H
#define SALAPRIVATIVA_H

#include "sala.h"

/**
 * @brief Classe que representa uma sala privativa.
 * 
 * Esta sala tem um limite de capacidade de pessoas, e o preço
 * é calculado com base na capacidade máxima.
 */
class SalaPrivativa : public Sala {
private:
    int capacidade_maxima_de_pessoas; /**< Capacidade máxima de pessoas */

public:
    /**
     * @brief Construtor que inicializa a sala privativa.
     * 
     * @param numero Número da sala.
     * @param andar Andar da sala.
     * @param capacidade Capacidade máxima de pessoas.
     */
    SalaPrivativa(int numero, int andar, int capacidade);

    /**
     * @brief Calcula o preço da sala com base na capacidade.
     * 
     * Sobrescreve o método `calcula_preco` para salas privativas.
     * @return double Preço da sala.
     */
    double calcula_preco() const override;
};

#endif // SALAPRIVATIVA_H
