#ifndef MEMBRO_CLUBE_H
#define MEMBRO_CLUBE_H

#include <iostream>
#include <string>
#include "pessoa.h"

using std::string;
using std::ostream;

/**
 * @brief Classe que representa um membro de clube de futebol.
 * 
 * A classe membro_clube é derivada da classe pessoa e adiciona a funcionalidade de
 * gerenciamento de salário. É uma classe base abstrata e requer a implementação de
 * um método puramente virtual para calcular o salário de classes derivadas, como jogadores e técnicos.
 */
class membro_clube : public pessoa {
    double salario; /**< Salário do membro do clube */
public:
    /**
     * @brief Construtor que inicializa um membro do clube com nome, idade e salário.
     * 
     * Inicializa os atributos da classe pessoa (nome e idade) e define o salário do membro.
     * 
     * @param n Nome do membro do clube.
     * @param i Idade do membro.
     * @param s Salário do membro.
     */
    membro_clube(const string& n, int i, double s);

    /**
     * @brief Construtor que inicializa um membro do clube com nome e idade, com salário padrão de 0.
     * 
     * @param n Nome do membro do clube.
     * @param i Idade do membro.
     */
    membro_clube(const string& n, int i);

    /**
     * @brief Retorna o salário do membro do clube.
     * 
     * @return double O salário atual do membro.
     */
    double get_salario() const;

    /**
     * @brief Define o salário do membro do clube.
     * 
     * @param s O novo valor do salário.
     */
    void set_salario(double s);

    /**
     * @brief Função virtual pura para calcular o salário.
     * 
     * Essa função deve ser implementada nas classes derivadas para definir como o
     * salário do membro será calculado.
     * 
     * @return double O valor do salário calculado.
     */
    virtual double calcular_salario() const = 0;  // Função virtual pura const

    /**
     * @brief Sobrecarga do operador << para exibir as informações do membro do clube.
     * 
     * Exibe o nome, idade e salário do membro do clube.
     * 
     * @param out Stream de saída.
     * @param mc Referência constante para o membro_clube.
     * @return ostream& Referência para o stream de saída.
     */
    friend ostream& operator<<(ostream& out, const membro_clube& mc);
};

#endif
