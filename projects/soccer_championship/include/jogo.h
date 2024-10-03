#ifndef JOGO_H
#define JOGO_H

#include<iostream>
#include<memory>
#include "time_futebol.h"
#include "juiz.h"

using std::shared_ptr;

/**
 * @brief Classe que representa um jogo de futebol.
 * 
 * A classe jogo mantém informações sobre os times que jogam (casa e visitante),
 * o juiz responsável pela partida, e o número de gols de cada time.
 */
class jogo {
    shared_ptr<time_futebol> time_casa; /**< Ponteiro para o time jogando em casa */
    shared_ptr<time_futebol> time_visitante; /**< Ponteiro para o time visitante */
    shared_ptr<juiz> juiz_principal; /**< Ponteiro para o juiz responsável pela partida */
    int gols_time_casa; /**< Gols marcados pelo time da casa */
    int gols_time_visitante; /**< Gols marcados pelo time visitante */

public:
    /**
     * @brief Construtor que inicializa os atributos do jogo.
     * 
     * Inicializa os times e o juiz, e define os gols inicialmente como 0.
     * 
     * @param tc Ponteiro para o time da casa.
     * @param tv Ponteiro para o time visitante.
     * @param j Ponteiro para o juiz responsável pela partida.
     */
    jogo(shared_ptr<time_futebol> tc, shared_ptr<time_futebol> tv, shared_ptr<juiz> j);

    /**
     * @brief Retorna o time da casa.
     * 
     * @return shared_ptr<time_futebol> Ponteiro para o time da casa.
     */
    shared_ptr<time_futebol> get_time_casa() const;

    /**
     * @brief Define o time da casa.
     * 
     * @param t Novo ponteiro para o time da casa.
     */
    void set_time_casa(shared_ptr<time_futebol> t);

    /**
     * @brief Retorna o time visitante.
     * 
     * @return shared_ptr<time_futebol> Ponteiro para o time visitante.
     */
    shared_ptr<time_futebol> get_time_visitante() const;

    /**
     * @brief Define o time visitante.
     * 
     * @param t Novo ponteiro para o time visitante.
     */
    void set_time_visitante(shared_ptr<time_futebol> t);

    /**
     * @brief Retorna o juiz principal da partida.
     * 
     * @return shared_ptr<juiz> Ponteiro para o juiz principal.
     */
    shared_ptr<juiz> get_juiz() const;

    /**
     * @brief Define o juiz principal da partida.
     * 
     * @param jp Novo ponteiro para o juiz principal.
     */
    void set_juiz(shared_ptr<juiz> jp);

    /**
     * @brief Retorna os gols marcados pelo time da casa.
     * 
     * @return int Gols marcados pelo time da casa.
     */
    int get_gols_time_casa();

    /**
     * @brief Define os gols marcados pelo time da casa.
     * 
     * @param g Novo número de gols marcados pelo time da casa.
     */
    void set_gols_time_casa(int g);

    /**
     * @brief Retorna os gols marcados pelo time visitante.
     * 
     * @return int Gols marcados pelo time visitante.
     */
    int get_gols_time_visitante();

    /**
     * @brief Define os gols marcados pelo time visitante.
     * 
     * @param g Novo número de gols marcados pelo time visitante.
     */
    void set_gols_time_visitante(int g);

    /**
     * @brief Registra o resultado do jogo e atualiza a pontuação dos times.
     * 
     * Atualiza os gols de cada time e ajusta a pontuação dos times com base
     * no resultado (vitória, empate, ou derrota).
     * 
     * @param gols_casa Gols marcados pelo time da casa.
     * @param gols_visitante Gols marcados pelo time visitante.
     */
    void registrar_resultado(int gols_casa, int gols_visitante);

    /**
     * @brief Exibe as informações do jogo.
     * 
     * Exibe o nome dos times, o juiz responsável, e o resultado do jogo.
     */
    void exibir_informacoes();

};

#endif
