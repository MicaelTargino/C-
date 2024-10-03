#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "jogo.h"
#include "juiz.h"
#include "time_futebol.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;

/**
 * @brief Construtor que inicializa os atributos do jogo.
 * 
 * Inicializa os times e o juiz, e define os gols inicialmente como 0.
 * 
 * @param tc Ponteiro para o time da casa.
 * @param tv Ponteiro para o time visitante.
 * @param j Ponteiro para o juiz responsável pela partida.
 */
jogo::jogo(shared_ptr<time_futebol> tc, shared_ptr<time_futebol> tv, shared_ptr<juiz> j):
    time_casa(tc), time_visitante(tv), juiz_principal(j), gols_time_casa(0), gols_time_visitante(0) {}

/**
 * @brief Retorna o time da casa.
 * 
 * @return shared_ptr<time_futebol> Ponteiro para o time da casa.
 */
shared_ptr<time_futebol> jogo::get_time_casa() const { return time_casa; }

/**
 * @brief Define o time da casa.
 * 
 * @param t Novo ponteiro para o time da casa.
 */
void jogo::set_time_casa(shared_ptr<time_futebol> t) { time_casa = t; }

/**
 * @brief Retorna o time visitante.
 * 
 * @return shared_ptr<time_futebol> Ponteiro para o time visitante.
 */
shared_ptr<time_futebol> jogo::get_time_visitante() const { return time_visitante; }

/**
 * @brief Define o time visitante.
 * 
 * @param t Novo ponteiro para o time visitante.
 */
void jogo::set_time_visitante(shared_ptr<time_futebol> t) { time_visitante = t; }

/**
 * @brief Retorna o juiz principal da partida.
 * 
 * @return shared_ptr<juiz> Ponteiro para o juiz principal.
 */
shared_ptr<juiz> jogo::get_juiz() const { return juiz_principal; }

/**
 * @brief Define o juiz principal da partida.
 * 
 * @param jp Novo ponteiro para o juiz principal.
 */
void jogo::set_juiz(shared_ptr<juiz> jp) { juiz_principal = jp; }

/**
 * @brief Retorna os gols marcados pelo time da casa.
 * 
 * @return int Gols marcados pelo time da casa.
 */
int jogo::get_gols_time_casa() { return gols_time_casa; }

/**
 * @brief Define os gols marcados pelo time da casa.
 * 
 * @param g Novo número de gols marcados pelo time da casa.
 */
void jogo::set_gols_time_casa(int g) { gols_time_casa = g; }

/**
 * @brief Retorna os gols marcados pelo time visitante.
 * 
 * @return int Gols marcados pelo time visitante.
 */
int jogo::get_gols_time_visitante() { return gols_time_visitante; }

/**
 * @brief Define os gols marcados pelo time visitante.
 * 
 * @param g Novo número de gols marcados pelo time visitante.
 */
void jogo::set_gols_time_visitante(int g) { gols_time_visitante = g; }

/**
 * @brief Registra o resultado do jogo e atualiza a pontuação dos times.
 * 
 * Atualiza os gols de cada time e ajusta a pontuação dos times com base
 * no resultado (vitória, empate, ou derrota).
 * 
 * @param gols_casa Gols marcados pelo time da casa.
 * @param gols_visitante Gols marcados pelo time visitante.
 */
void jogo::registrar_resultado(int gols_casa, int gols_visitante) {
    gols_time_casa = gols_casa;
    gols_time_visitante = gols_visitante;

    if (gols_casa == gols_visitante) {
        // empate
        time_casa->registrar_resultado('E');
        time_visitante->registrar_resultado('E');
    } else if (gols_casa > gols_visitante) {
        // vitória do time da casa
        time_casa->registrar_resultado('V');
        time_visitante->registrar_resultado('D');
    } else {
        // vitória do time visitante
        time_visitante->registrar_resultado('V');
        time_casa->registrar_resultado('D');
    }
}

/**
 * @brief Exibe as informações do jogo.
 * 
 * Exibe o nome dos times, o juiz responsável, e o resultado do jogo.
 */
void jogo::exibir_informacoes() {
    cout << "Jogo entre: " << endl;
    cout << "Time da casa: " << time_casa->get_nome() << " - Gols: " << gols_time_casa << endl;
    cout << "Time visitante: " << time_visitante->get_nome() << " - Gols: " << gols_time_visitante << endl;
    cout << "Juiz: " << juiz_principal->get_nome() << endl;
    if (gols_time_casa == gols_time_visitante) {
        cout << "Resultado: Empate" << endl;
    } else if (gols_time_casa > gols_time_visitante) {
        cout << "Resultado: Vitória do time da casa" << endl;
    } else {
        cout << "Resultado: Vitória do time visitante" << endl;
    }
}