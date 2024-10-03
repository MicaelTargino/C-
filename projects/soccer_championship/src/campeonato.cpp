#include <iostream>
#include <string>
#include <memory> 
#include <vector>
#include <algorithm>

#include "campeonato.h"
#include "time_futebol.h"
#include "jogo.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;

/**
 * @brief Construtor que inicializa o nome do campeonato.
 * 
 * @param nome Nome do campeonato.
 */
campeonato::campeonato(const string& nome): nome_campeonato(nome) {}

/**
 * @brief Retorna o nome do campeonato.
 * 
 * @return string Nome do campeonato.
 */
string campeonato::get_nome_campeonato() const { return nome_campeonato; }

/**
 * @brief Define o nome do campeonato.
 * 
 * @param nome Novo nome para o campeonato.
 */
void campeonato::set_nome_campeonato(const string& nome) { nome_campeonato = nome; }

/**
 * @brief Adiciona um time ao campeonato.
 * 
 * @param t Referência constante para o time a ser adicionado ao campeonato.
 */
void campeonato::adicionar_time(shared_ptr<time_futebol> t) {
    lista_times.push_back(t);
}

/**
 * @brief Adiciona um jogo ao campeonato.
 * 
 * @param j Referência constante para o jogo a ser adicionado ao campeonato.
 */
void campeonato::adicionar_jogo(shared_ptr<jogo> j) {
    lista_jogos.push_back(j);
}

/**
 * @brief Exibe a tabela de classificação dos times ordenados por pontuação.
 */
void campeonato::exibir_classificacao() const {
    // Copia a lista de times para ordenar sem modificar a original
    vector<shared_ptr<time_futebol>> times_ordenados = lista_times;

    // Ordena os times pela pontuação em ordem decrescente
    std::sort(times_ordenados.begin(), times_ordenados.end(), [](const shared_ptr<time_futebol>& a, const shared_ptr<time_futebol>& b) {
        return a->get_pontuacao() > b->get_pontuacao();
    });

    // Exibe a classificação
    cout << "Classificacaoo do Campeonato: " << nome_campeonato << endl;
    for (const auto& t : times_ordenados) {
        cout << "Time: " << t->get_nome() << " - Pontuacao: " << t->get_pontuacao() << endl;
    }
}

/**
 * @brief Exibe a lista de jogos do campeonato.
 */
void campeonato::exibir_jogos() const {
    cout << "Jogos no Campeonato: " << nome_campeonato << endl;
    for (const auto& j : lista_jogos) {
        j->exibir_informacoes();
    }
}