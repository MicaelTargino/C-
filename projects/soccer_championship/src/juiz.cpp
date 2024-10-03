#include <iostream>
#include <string>

#include "juiz.h"
#include "pessoa.h"

using std::string;
using std::cout;
using std::endl;

/**
 * @brief Construtor que inicializa um juiz com nome, idade e número de partidas arbitradas.
 * 
 * @param n Nome do juiz.
 * @param i Idade do juiz.
 * @param pa Número de partidas arbitradas pelo juiz.
 */
juiz::juiz(const string& n, int i, int pa): pessoa(n, i), partidas_arbitradas(pa) {}

/**
 * @brief Retorna o número total de partidas arbitradas pelo juiz.
 * 
 * @return int Número de partidas arbitradas.
 */
int juiz::get_partidas_arbitradas() const { return partidas_arbitradas; }

/**
 * @brief Define o número total de partidas arbitradas pelo juiz.
 * 
 * @param pa Novo valor de partidas arbitradas.
 */
void juiz::set_partidas_arbitradas(int pa) { partidas_arbitradas = pa; }

/**
 * @brief Incrementa o número de partidas arbitradas pelo juiz.
 */
void juiz::incrementar_partidas_arbitradas() { partidas_arbitradas++; }

/**
 * @brief Exibe as informações do juiz, incluindo nome, idade e número de partidas arbitradas.
 */
void juiz::exibir_informacoes() {
    cout << "Juiz(" << get_nome() << ", " << get_idade() << ", " << get_partidas_arbitradas() << ")" << endl;
}