#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "jogo.h"
#include "time_futebol.h"

using std::string;
using std::vector;
using std::shared_ptr;


/**
 * @brief Classe que representa um campeonato de futebol.
 * 
 * A classe campeonato gerencia os times que participam do campeonato, 
 * os jogos que ocorrem durante o campeonato, e exibe a classificação 
 * dos times de acordo com suas pontuações.
 */
class campeonato {
private:
    std::string nome_campeonato;  /**< Nome do campeonato */
    std::vector<shared_ptr<time_futebol>> lista_times; /**< Lista de times participantes do campeonato */
    std::vector<shared_ptr<jogo>> lista_jogos;  /**< Lista de jogos que ocorrem no campeonato */

public:
    /**
     * @brief Construtor que inicializa o nome do campeonato.
     * 
     * @param nome Nome do campeonato.
     */
    campeonato(const string& nome);

    /**
     * @brief Retorna o nome do campeonato.
     * 
     * @return string Nome do campeonato.
     */
    string get_nome_campeonato() const;

    /**
     * @brief Define o nome do campeonato.
     * 
     * @param nome Novo nome para o campeonato.
     */
    void set_nome_campeonato(const string& nome);

    /**
     * @brief Adiciona um time ao campeonato.
     * 
     * @param t Referência constante para o time a ser adicionado ao campeonato.
     */
    void adicionar_time(shared_ptr<time_futebol> t);

    /**
     * @brief Adiciona um jogo ao campeonato.
     * 
     * @param j Referência constante para o jogo a ser adicionado ao campeonato.
     */
    void adicionar_jogo(shared_ptr<jogo> j);

    /**
     * @brief Exibe a tabela de classificação dos times ordenados por pontuação.
     */
    void exibir_classificacao() const;

    /**
     * @brief Exibe a lista de jogos do campeonato.
     */
    void exibir_jogos() const;  
};

#endif
