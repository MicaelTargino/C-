#include <iostream>
#include <string>

#include "tecnico.h"

using std::string;
using std::cout;
using std::endl;

/**
 * @brief Construtor que inicializa um técnico com nome, idade, salário e experiência.
 * 
 * @param n Nome do técnico.
 * @param i Idade do técnico.
 * @param s Salário do técnico.
 * @param e Anos de experiência do técnico.
 */
tecnico::tecnico(const string& n, int i, double s, int e): membro_clube(n, i, s), experiencia(e) {}

/**
 * @brief Construtor que inicializa um técnico com nome, idade e experiência, com salário padrão de 0.
 * 
 * @param n Nome do técnico.
 * @param i Idade do técnico.
 * @param e Anos de experiência do técnico.
 */
tecnico::tecnico(const string& n, int i, int e): membro_clube(n, i), experiencia(e) {}

/**
 * @brief Retorna os anos de experiência do técnico.
 * 
 * @return int Anos de experiência.
 */
int tecnico::get_experiencia() const { return experiencia; }

/**
 * @brief Define os anos de experiência do técnico.
 * 
 * @param e Novo valor de anos de experiência.
 */
void tecnico::set_experiencia(int e) { experiencia = e; }

/**
 * @brief Calcula o salário total do técnico com base nos anos de experiência.
 * 
 * O salário total é o salário base mais um bônus de 200 unidades para cada ano de experiência.
 * 
 * @return double Salário total calculado.
 */
double tecnico::calcular_salario() const {
    return get_salario() + (experiencia * 200);
}

void tecnico::exibir_informacoes() {
    cout << "Técnico: " << get_nome() << ", Idade: " << get_idade()
         << ", Experiência: " << get_experiencia() << " anos, Salário: " << calcular_salario() << endl;
}