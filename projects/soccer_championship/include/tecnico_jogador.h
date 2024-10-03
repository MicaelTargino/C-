#ifndef TECNICO_JOGADOR_H
#define TECNICO_JOGADOR_H

#include <iostream>
#include <string>
#include "tecnico.h"
#include "jogador.h"

using std::string;
using std::ostream;

/**
 * @brief Classe que representa um técnico que também atua como jogador de futebol.
 * 
 * Esta classe possui herança múltipla, herdando de técnico e de jogador ao mesmo tempo. 
 * É utilizada a herança virtual, para evitar o problema da ambiguidade na herança diamante.
 */
class tecnico_jogador : virtual public tecnico, virtual public jogador {
    double bonus_duplo_papel; /**< Bônus por atuar como técnico e jogador ao mesmo tempo */
public:
    /**
     * @brief Construtor que inicializa um técnico_jogador com nome, idade, salário, experiência, posição e gols marcados.
     * 
     * @param n Nome do técnico_jogador.
     * @param i Idade do técnico_jogador.
     * @param s Salário do técnico_jogador.
     * @param e Anos de experiência como técnico.
     * @param pos Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    tecnico_jogador(const string& n, int i, double s, int e, string pos, int gm, double b);

    /**
     * @brief Construtor que inicializa um técnico_jogador com nome, idade, experiência, posição e gols marcados, com salário padrão de 0.
     * 
     * @param n Nome do técnico_jogador.
     * @param i Idade do técnico_jogador.
     * @param e Anos de experiência como técnico.
     * @param pos Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    tecnico_jogador(const string& n, int i, int e, string pos, int gm, double b);

    /**
     * @brief Retorna o bônus por atuar como técnico e jogador.
     * 
     * @return double O valor do bônus.
     */
    double get_bonus_duplo_papel() const;

    /**
     * @brief Define o valor do bônus por atuar como técnico e jogador.
     * 
     * @param bdp O novo valor do bônus.
     */
    void set_bonus_duplo_papel(double bdp);


    /**
     * @brief Calcula o salário total do técnico_jogador com base no bônus e nos salários como técnico e jogador.
     * 
     * @return double O valor do salário total.
     */
    double calcular_salario() const override;

    void exibir_informacoes() override;

    /**
     * @brief Sobrecarga do operador << para exibir as informações do técnico_jogador.
     * 
     * Exibe o nome, idade, posição, gols marcados, experiência e salário total.
     * 
     * @param out Stream de saída.
     * @param tj Referência constante para o técnico_jogador.
     * @return ostream& Referência para o stream de saída.
     */
    friend ostream& operator<<(ostream& out, const tecnico_jogador& tj);
};

#endif
