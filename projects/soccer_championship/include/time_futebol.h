#ifndef TIME_H
#define TIME_H

#include <vector>
#include <string>
#include <memory>
#include "tecnico.h"
#include "jogador.h"

using std::string;
using std::vector;
using std::shared_ptr;

/**
 * @brief Classe que representa um time de futebol.
 * 
 * A classe time gerencia o nome do time, o técnico, os jogadores e a pontuação total.
 */
class time_futebol {
    string nome; /**< Nome do time */
    shared_ptr<tecnico> tecnico_do_time; /**< Técnico responsável pelo time */
    vector<shared_ptr<jogador>> jogadores; /**< Vetor de jogadores pertencentes ao time */
    int pontuacao; /**< Pontuação total do time */

public:
    /**
     * @brief Construtor que inicializa o nome do time, o técnico e define pontuação inicial como 0.
     * 
     * @param n Nome do time.
     * @param tec Ponteiro compartilhado para o técnico do time.
     */
    time_futebol(const string& n, shared_ptr<tecnico> tec);

    /**
     * @brief Retorna o nome do time.
     * 
     * @return string Nome do time.
     */
    string get_nome() const;

    /**
     * @brief Define o nome do time.
     * 
     * @param n Novo nome para o time.
     */
    void set_nome(const string& n);

    /**
     * @brief Retorna o técnico do time.
     * 
     * @return shared_ptr<tecnico> Ponteiro compartilhado para o técnico do time.
     */
    shared_ptr<tecnico> get_tecnico() const;

    /**
     * @brief Define o técnico do time.
     * 
     * @param tecnico Novo ponteiro compartilhado para o técnico do time.
     */
    void set_tecnico(shared_ptr<tecnico> tecnico);

    /**
     * @brief Retorna o vetor de jogadores do time.
     * 
     * @return vector<shared_ptr<jogador>> Vetor de ponteiros compartilhados de jogadores.
     */
    vector<shared_ptr<jogador>> get_jogadores() const;

    /**
     * @brief Adiciona um jogador ao time sem copiar o objeto.
     * 
     * Recebe uma referência constante para um jogador já existente e
     * armazena no vetor de jogadores como um ponteiro compartilhado.
     * 
     * @param j Referência constante para o jogador a ser adicionado ao time.
     */
    void adicionar_jogador(const jogador& j);

    /**
     * @brief Retorna a pontuação total do time.
     * 
     * @return int Pontuação total do time.
     */
    int get_pontuacao() const;

    /**
     * @brief Define a pontuação total do time.
     * 
     * @param p Nova pontuação do time.
     */
    void set_pontuacao(int p);

    /**
     * @brief Atualiza a pontuação do time com base no resultado do jogo.
     * 
     * @param resultado Resultado da partida ('V' para vitória, 'E' para empate, 'D' para derrota).
     */
    void registrar_resultado(char resultado);

    /**
     * @brief Exibe as informações completas do time, incluindo nome, técnico, jogadores e pontuação.
     */
    void exibir_informacoes();

    /**
     * @brief Sobrecarga do operador < para comparar times pela pontuação total.
     * 
     * @param outro Outro time a ser comparado.
     * @return true Se o time atual tiver pontuação menor que o outro time.
     * @return false Caso contrário.
     */
    bool operator<(const time_futebol& outro) const;
};

#endif