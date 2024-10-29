#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "custom_exceptions.h"

/**
 * @brief Classe que representa uma empresa locatária.
 * 
 * Armazena o nome e a idade da empresa, e lança exceções caso valores inválidos sejam passados.
 */
class Empresa {
private:
    std::string nome_da_empresa;  /**< Nome da empresa */
    int idade_da_empresa;         /**< Idade da empresa em anos de mercado */

public:
    /**
     * @brief Construtor que inicializa o nome e a idade da empresa.
     * 
     * @param nome Nome da empresa.
     * @param idade Idade da empresa em anos. Lança exceção se negativa.
     */
    Empresa(const std::string& nome, int idade);

    /**
     * @brief Define o nome da empresa.
     * 
     * @param nome Novo nome da empresa.
     */
    void set_nome(const std::string& nome);

    /**
     * @brief Obtém o nome da empresa.
     * 
     * @return string Nome da empresa.
     */
    std::string get_nome() const;

    /**
     * @brief Define a idade da empresa.
     * 
     * Lança uma exceção se a idade for negativa.
     * @param idade Idade da empresa em anos.
     */
    void set_idade(int idade);

    /**
     * @brief Obtém a idade da empresa.
     * 
     * @return int Idade da empresa em anos.
     */
    int get_idade() const;

    /**
     * @brief Operador de comparação para ordenação das empresas por idade.
     * 
     * Este operador é sobrecarregado para que empresas mais antigas
     * venham primeiro.
     * @param outra Empresa com a qual será feita a comparação.
     * @return true se a idade da empresa atual é maior que a da outra empresa.
     */
    bool operator<(const Empresa& outra) const;

    /**
     * @brief Operador de igualdade para a classe Empresa.
     * 
     * Necessário para encontrar e remover empresas em listas.
     * @param other Outra empresa para comparação.
     * @return true se o nome e a idade das duas empresas forem iguais.
     */
    bool operator==(const Empresa& outra) const;
};

#endif // EMPRESA_H
