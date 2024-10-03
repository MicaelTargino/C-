#ifndef TECNICO_H
#define TECNICO_H

#include <string>
#include "membro_clube.h"

using std::string;

/**
 * @brief Classe que representa um técnico de futebol.
 * 
 * A classe técnico herda de membro_clube e adiciona o atributo de anos de experiência,
 * além de implementar o cálculo de salário com base na experiência.
 */
class tecnico : virtual public membro_clube {
    int experiencia; /**< Anos de experiência do técnico */
public:
    /**
     * @brief Construtor que inicializa um técnico com nome, idade, salário e experiência.
     * 
     * @param n Nome do técnico.
     * @param i Idade do técnico.
     * @param s Salário do técnico.
     * @param e Anos de experiência do técnico.
     */
    tecnico(const string& n, int i, double s, int e);

    /**
     * @brief Construtor que inicializa um técnico com nome, idade e experiência, com salário padrão de 0.
     * 
     * @param n Nome do técnico.
     * @param i Idade do técnico.
     * @param e Anos de experiência do técnico.
     */
    tecnico(const string& n, int i, int e);

    /**
     * @brief Retorna os anos de experiência do técnico.
     * 
     * @return int Anos de experiência.
     */
    int get_experiencia() const;

    /**
     * @brief Define os anos de experiência do técnico.
     * 
     * @param e Novo valor de anos de experiência.
     */
    void set_experiencia(int e);

    /**
     * @brief Calcula o salário total do técnico com base nos anos de experiência.
     * 
     * O salário total é o salário base mais um bônus de 200 unidades para cada ano de experiência.
     * 
     * @return double Salário total calculado.
     */
    double calcular_salario() const override;

    void exibir_informacoes() override;
};

#endif
