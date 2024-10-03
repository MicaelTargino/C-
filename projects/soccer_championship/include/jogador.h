#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include "membro_clube.h"

using std::string;

/**
 * @brief Classe que representa um jogador de futebol.
 * 
 * A classe jogador mantém informações sobre a posição, gols marcados
 * e salário do jogador, além de permitir o cálculo do salário total
 * e a comparação de jogadores com base no número de gols.
 */
class jogador : virtual public membro_clube {
private:
    string posicao; /**< Posição do jogador (goleiro, zagueiro, meio-campo, atacante) */
    int gols_marcados; /**< Número total de gols marcados pelo jogador */

public:
    /**
     * @brief Construtor que inicializa um jogador com nome, idade, salário, posição e gols marcados.
     * 
     * @param n Nome do jogador.
     * @param i Idade do jogador.
     * @param s Salário do jogador.
     * @param p Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    jogador(string n, int i, double s, string p, int gm);

    /**
     * @brief Construtor que inicializa um jogador com nome, idade, posição e gols marcados, com salário padrão de 0.
     * 
     * @param n Nome do jogador.
     * @param i Idade do jogador.
     * @param p Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    jogador(string n, int i, string p, int gm);

    /**
     * @brief Retorna a posição do jogador.
     * 
     * @return string Posição do jogador.
     */
    string get_posicao() const;

    /**
     * @brief Define a posição do jogador.
     * 
     * @param p Nova posição do jogador.
     */
    void set_posicao(const string& p);

    /**
     * @brief Retorna o número total de gols marcados pelo jogador.
     * 
     * @return int Número de gols marcados.
     */
    int get_gols_marcados() const;

    /**
     * @brief Define o número de gols marcados pelo jogador.
     * 
     * @param gm Novo número de gols marcados.
     */
    void set_gols_marcados(int gm);

    /**
     * @brief Calcula o salário total do jogador com base no número de gols.
     * 
     * O salário total é o salário base mais um bônus de 100 unidades por cada gol marcado.
     * 
     * @return double Salário total calculado.
     */
    double calcular_salario() const override;

    /**
     * @brief Sobrecarga do operador < para comparar jogadores pelo número de gols.
     * 
     * @param outro Outro jogador a ser comparado.
     * @return true Se o jogador atual tiver menos gols marcados que o outro jogador.
     * @return false Caso contrário.
     */
    bool operator<(const jogador& outro) const;

    void exibir_informacoes() override;
};

#endif
