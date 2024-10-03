#include <iostream>
#include <string>

#include "jogador.h"

using std::string;
using std::cout;
using std::endl;


/**
 * @brief Construtor que inicializa um jogador com nome, idade, salário, posição e gols marcados.
 * 
 * @param n Nome do jogador.
 * @param i Idade do jogador.
 * @param s Salário do jogador.
 * @param p Posição do jogador.
 * @param gm Número de gols marcados pelo jogador.
 */
jogador::jogador(string n, int i, double s, string p, int gm): membro_clube(n,i,s), posicao(p), gols_marcados(gm) {}

/**
 * @brief Construtor que inicializa um jogador com nome, idade, posição e gols marcados, com salário padrão de 0.
 * 
 * @param n Nome do jogador.
 * @param i Idade do jogador.
 * @param p Posição do jogador.
 * @param gm Número de gols marcados pelo jogador.
 */
jogador::jogador(string n, int i, string p, int gm): membro_clube(n,i), posicao(p), gols_marcados(gm) {}

/**
 * @brief Retorna a posição do jogador.
 * 
 * @return string Posição do jogador.
 */
string jogador::get_posicao() const { return posicao; }

/**
 * @brief Define a posição do jogador.
 * 
 * @param p Nova posição do jogador.
 */
void jogador::set_posicao(const string& p) { posicao = p; }

/**
 * @brief Retorna o número total de gols marcados pelo jogador.
 * 
 * @return int Número de gols marcados.
 */
int jogador::get_gols_marcados() const { return gols_marcados; }

/**
 * @brief Define o número de gols marcados pelo jogador.
 * 
 * @param gm Novo número de gols marcados.
 */
void jogador::set_gols_marcados(int gm) { gols_marcados = gm; }

/**
 * @brief Calcula o salário total do jogador com base no número de gols.
 * 
 * O salário total é o salário base mais um bônus de 100 unidades por cada gol marcado.
 * 
 * @return double Salário total calculado.
 */
double jogador::calcular_salario() const {
    return get_salario() + (gols_marcados * 100);
}

/**
 * @brief Sobrecarga do operador < para comparar jogadores pelo número de gols.
 * 
 * @param outro Outro jogador a ser comparado.
 * @return true Se o jogador atual tiver menos gols marcados que o outro jogador.
 * @return false Caso contrário.
 */
bool jogador::operator<(const jogador& outro) const {
    return gols_marcados < outro.gols_marcados;
}

void jogador::exibir_informacoes() {
    cout << "Jogador: " << get_nome() << ", Idade: " << get_idade()
         << ", Posição: " << get_posicao() << ", Gols Marcados: " << get_gols_marcados()
         << ", Salário: " << calcular_salario() << endl;
}