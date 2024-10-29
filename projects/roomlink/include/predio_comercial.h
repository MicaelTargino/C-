#ifndef PREDIOCOMERCIAL_H
#define PREDIOCOMERCIAL_H

#include <vector>
#include "sala.h"

/**
 * @brief Classe que representa um prédio comercial.
 * 
 * Gerencia as salas do prédio e permite ordenação, adição e remoção de salas.
 */
class PredioComercial {
private:
    std::vector<Sala*> lista_de_salas; /**< Lista de salas no prédio */

public:
    /**
     * @brief Destrutor que libera a memória das salas.
     */
    ~PredioComercial();

    /**
     * @brief Retorna a lista de salas do prédio.
     * 
     * @return const std::vector<Sala*>& Lista de salas.
     */
    const std::vector<Sala*>& get_salas() const;

    /**
     * @brief Adiciona uma sala ao prédio.
     * 
     * Adiciona a sala à lista e ordena pelo andar.
     * @param sala Ponteiro para a sala a ser adicionada.
     * @return PredioComercial& Referência para o prédio atualizado.
     */
    PredioComercial& operator+(Sala* sala);

    /**
     * @brief Remove uma sala do prédio.
     * 
     * Remove a sala da lista se estiver presente.
     * @param sala Ponteiro para a sala a ser removida.
     * @return PredioComercial& Referência para o prédio atualizado.
     */
    PredioComercial& operator-(Sala* sala);

    /**
     * @brief Ordena as salas pelo andar.
     * 
     * Salas em andares inferiores aparecem primeiro.
     */
    void ordenar_salas();

    /**
     * @brief Lista todas as salas e empresas associadas.
     * 
     * Exibe os detalhes das salas e suas empresas locatárias.
     */
    void listar_salas() const;
};

#endif // PREDIOCOMERCIAL_H
