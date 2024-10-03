#include <iostream>
#include <string>

#include "tecnico.h"
#include "jogador.h"
#include "tecnico_jogador.h"

using std::string;
using std::cout;
using std::endl;
using std::ostream;

/**
 * @brief Construtor que inicializa um técnico_jogador com nome, idade, salário, experiência, posição e gols marcados.
 * 
 * @param n Nome do técnico_jogador.
 * @param i Idade do técnico_jogador.
 * @param s Salário do técnico_jogador.
 * @param e Anos de experiência como técnico.
 * @param pos Posição do jogador.
 * @param gm Número de gols marcados pelo jogador.
 */
tecnico_jogador::tecnico_jogador(const string& n, int i, double s, int e, string pos, int gm, double b)
    : membro_clube(n, i, s), tecnico(n, i, s, e), jogador(n, i, s, pos, gm), bonus_duplo_papel(b) {}

/**
 * @brief Construtor que inicializa um técnico_jogador com nome, idade, experiência, posição e gols marcados, com salário padrão de 0.
 * 
 * @param n Nome do técnico_jogador.
 * @param i Idade do técnico_jogador.
 * @param e Anos de experiência como técnico.
 * @param pos Posição do jogador.
 * @param gm Número de gols marcados pelo jogador.
 */
tecnico_jogador::tecnico_jogador(const string& n, int i, int e, string pos, int gm, double b)
    : membro_clube(n, i), tecnico(n, i, e), jogador(n, i, pos, gm), bonus_duplo_papel(b) {}

/**
 * @brief Retorna o bônus por atuar como técnico e jogador.
 * 
 * @return double O valor do bônus.
 */
double tecnico_jogador::get_bonus_duplo_papel() const { return bonus_duplo_papel; }

/**
 * @brief Define o valor do bônus por atuar como técnico e jogador.
 * 
 * @param bdp O novo valor do bônus.
 */
void tecnico_jogador::set_bonus_duplo_papel(double bdp) { bonus_duplo_papel = bdp; }

/**
 * @brief Calcula o salário total do técnico_jogador com base no bônus e nos salários como técnico e jogador.
 * 
 * @return double O valor do salário total.
 */
double tecnico_jogador::calcular_salario() const {
    return jogador::calcular_salario() + tecnico::calcular_salario() + bonus_duplo_papel;
}

void tecnico_jogador::exibir_informacoes() {
    cout << "Nome: " << get_nome() << "\n"
         << "Idade: " << get_idade() << "\n"
         << "Posição: " << get_posicao() << "\n"
         << "Gols Marcados: " << get_gols_marcados() << "\n"
         << "Experiência: " << get_experiencia() << " anos\n"
         << "Salário Total: " << calcular_salario() << "\n";
}

/**
 * @brief Sobrecarga do operador << para exibir as informações do técnico_jogador.
 * 
 * Exibe o nome, idade, posição, gols marcados, experiência e salário total.
 * 
 * @param out Stream de saída.
 * @param tj Referência constante para o técnico_jogador.
 * @return ostream& Referência para o stream de saída.
 */
ostream& operator<<(ostream& out, const tecnico_jogador& tj) {
    out << "tecnico_jogador(" << tj.get_nome() << ", " << tj.get_idade() << ", " << tj.get_gols_marcados() 
        << ", " << tj.get_posicao() << ", " << tj.get_experiencia() << ", " << tj.calcular_salario() << ")" << endl;
    return out;
}