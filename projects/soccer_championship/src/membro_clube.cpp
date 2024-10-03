#include <iostream>
#include <string>

#include "membro_clube.h"

using std::string;
using std::ostream;
using std::endl;

/**
 * @brief Construtor que inicializa um membro do clube com nome, idade e salário.
 * 
 * Inicializa os atributos da classe pessoa (nome e idade) e define o salário do membro.
 * 
 * @param n Nome do membro do clube.
 * @param i Idade do membro.
 * @param s Salário do membro.
 */
membro_clube::membro_clube(const string& n, int i, double s): pessoa(n, i), salario(s) {}

/**
 * @brief Construtor que inicializa um membro do clube com nome e idade, com salário padrão de 0.
 * 
 * @param n Nome do membro do clube.
 * @param i Idade do membro.
 */
membro_clube::membro_clube(const string& n, int i): pessoa(n, i), salario(0) {}

/**
 * @brief Retorna o salário do membro do clube.
 * 
 * @return double O salário atual do membro.
 */
double membro_clube::get_salario() const { return salario; }

/**
 * @brief Define o salário do membro do clube.
 * 
 * @param s O novo valor do salário.
 */
void membro_clube::set_salario(double s) { salario = s; }

/**
 * @brief Sobrecarga do operador << para exibir as informações do membro do clube.
 * 
 * Exibe o nome, idade e salário do membro do clube.
 * 
 * @param out Stream de saída.
 * @param mc Referência constante para o membro_clube.
 * @return ostream& Referência para o stream de saída.
 */

ostream& operator<<(ostream& out, const membro_clube& mc) {
    out << "membro_clube(" << mc.get_nome() << ", " << mc.get_idade() << ", " << mc.calcular_salario() << ")" << endl;
    return out;
}