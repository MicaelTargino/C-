#ifndef JUIZ_H
#define JUIZ_H

#include <iostream>
#include <string>
#include "pessoa.h"

using std::string;

/**
 * @brief Classe que representa um juiz de futebol.
 * 
 * A classe juiz herda da classe pessoa e adiciona o atributo de número de partidas arbitradas.
 * Também fornece métodos para incrementar e acessar esse valor, além de exibir informações do juiz.
 */
class juiz : public pessoa {
    int partidas_arbitradas; /**< Número total de partidas arbitradas pelo juiz */

public:
    /**
     * @brief Construtor que inicializa um juiz com nome, idade e número de partidas arbitradas.
     * 
     * @param n Nome do juiz.
     * @param i Idade do juiz.
     * @param pa Número de partidas arbitradas pelo juiz.
     */
    juiz(const string& n, int i, int pa);

    /**
     * @brief Retorna o número total de partidas arbitradas pelo juiz.
     * 
     * @return int Número de partidas arbitradas.
     */
    int get_partidas_arbitradas() const;

    /**
     * @brief Define o número total de partidas arbitradas pelo juiz.
     * 
     * @param pa Novo valor de partidas arbitradas.
     */
    void set_partidas_arbitradas(int pa);

    /**
     * @brief Incrementa o número de partidas arbitradas pelo juiz.
     */
    void incrementar_partidas_arbitradas();

    /**
     * @brief Exibe as informações do juiz, incluindo nome, idade e número de partidas arbitradas.
     */
    void exibir_informacoes() override;
};

#endif