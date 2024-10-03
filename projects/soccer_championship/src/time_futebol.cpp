#include <string>
#include <memory>
#include <vector>

#include "time_futebol.h"
#include "tecnico.h"
#include "jogador.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;

const int PONTUACAO_VITORIA = 3;
const int PONTUACAO_EMPATE = 1;
const int PONTUACAO_DERROTA = 0;

/**
 * @brief Construtor que inicializa o nome do time, o técnico e define pontuação inicial como 0.
 * 
 * @param n Nome do time.
 * @param tec Ponteiro compartilhado para o técnico do time.
 */
time_futebol::time_futebol(const string& n, shared_ptr<tecnico> tec): nome(n), tecnico_do_time(tec), pontuacao(0) {}

/**
 * @brief Retorna o nome do time.
 * 
 * @return string Nome do time.
 */
string time_futebol::get_nome() const { return nome; }

/**
 * @brief Define o nome do time.
 * 
 * @param n Novo nome para o time.
 */
void time_futebol::set_nome(const string& n) { nome = n; }

/**
 * @brief Retorna o técnico do time.
 * 
 * @return shared_ptr<tecnico> Ponteiro compartilhado para o técnico do time.
 */
shared_ptr<tecnico> time_futebol::get_tecnico() const { return tecnico_do_time; }

/**
 * @brief Define o técnico do time.
 * 
 * @param tecnico Novo ponteiro compartilhado para o técnico do time.
 */
void time_futebol::set_tecnico(shared_ptr<tecnico> tecnico) {
    tecnico_do_time = tecnico;
}

/**
 * @brief Retorna o vetor de jogadores do time.
 * 
 * @return vector<shared_ptr<jogador>> Vetor de ponteiros compartilhados de jogadores.
 */
vector<shared_ptr<jogador>> time_futebol::get_jogadores() const { return jogadores; }

/**
 * @brief Adiciona um jogador ao time sem copiar o objeto.
 * 
 * Recebe uma referência constante para um jogador já existente e
 * armazena no vetor de jogadores como um ponteiro compartilhado.
 * 
 * @param j Referência constante para o jogador a ser adicionado ao time.
 */
void time_futebol::adicionar_jogador(const jogador& j) {
    // Criar um shared_ptr sem copiar o jogador
    auto ptr = shared_ptr<jogador>(const_cast<jogador*>(&j));
    jogadores.push_back(ptr);
}

/**
 * @brief Retorna a pontuação total do time.
 * 
 * @return int Pontuação total do time.
 */
int time_futebol::get_pontuacao() const { return pontuacao; }

/**
 * @brief Define a pontuação total do time.
 * 
 * @param p Nova pontuação do time.
 */
void time_futebol::set_pontuacao(int p) { pontuacao = p; }

/**
 * @brief Atualiza a pontuação do time com base no resultado do jogo.
 * 
 * @param resultado Resultado da partida ('V' para vitória, 'E' para empate, 'D' para derrota).
 */
void time_futebol::registrar_resultado(char resultado) {
    resultado = toupper(resultado);
    switch (resultado) {
        case 'V':
            pontuacao += PONTUACAO_VITORIA;
            break;
        case 'E':
            pontuacao += PONTUACAO_EMPATE;
            break;
        case 'D':
            pontuacao += PONTUACAO_DERROTA;
            break;
        default: 
            cout << "Erro ao registrar resultado: código inválido." << endl; 
            return;
    }
}

/**
 * @brief Exibe as informações completas do time, incluindo nome, técnico, jogadores e pontuação.
 */
void time_futebol::exibir_informacoes() {
    cout << "Time: " << nome << endl;
    cout << "Técnico: " << tecnico_do_time->get_nome() << endl;
    cout << "Jogadores:" << endl;
    for (const auto& jogador : jogadores) {
        cout << "\t" << jogador->get_nome() << " - Posição: " << jogador->get_posicao()
             << " - Gols Marcados: " << jogador->get_gols_marcados() << endl;
    }
    cout << "Pontuação Total: " << pontuacao << endl;
}

/**
 * @brief Sobrecarga do operador < para comparar times pela pontuação total.
 * 
 * @param outro Outro time a ser comparado.
 * @return true Se o time atual tiver pontuação menor que o outro time.
 * @return false Caso contrário.
 */
bool time_futebol::operator<(const time_futebol& outro) const {
    return pontuacao < outro.pontuacao;
}