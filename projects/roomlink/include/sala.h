#ifndef SALA_H
#define SALA_H

#include <vector>
#include "Empresa.h"

/**
 * @brief Classe abstrata que representa uma sala em um prédio comercial.
 * 
 * A classe Sala serve como base para diferentes tipos de salas comerciais.
 */
class Sala {
protected:
    int numero_da_sala; /**< Número da sala */
    int andar; /**< Andar em que a sala está localizada */
    std::vector<Empresa> lista_de_empresas_locatarias; /**< Empresas locatárias da sala */

public:
    /**
     * @brief Construtor que inicializa o número e o andar da sala.
     * 
     * @param numero Número da sala.
     * @param andar Andar da sala.
     */
    Sala(int numero, int andar);

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Sala() = default;

    /**
     * @brief Define o número da sala.
     * 
     * @param numero Novo número para a sala.
     */
    void set_numero(int numero);

    /**
     * @brief Obtém o número da sala.
     * 
     * @return int Número da sala.
     */
    int get_numero() const;

    /**
     * @brief Define o andar da sala.
     * 
     * @param andar_novo Novo andar para a sala.
     */
    void set_andar(int andar_novo);

    /**
     * @brief Obtém o andar da sala.
     * 
     * @return int Andar da sala.
     */
    int get_andar() const;

    /**
     * @brief Retorna a lista de empresas associadas à sala.
     * 
     * @return std::vector<Empresa> Lista de empresas na sala.
     */
    std::vector<Empresa> get_empresas() const;

    /**
     * @brief Método virtual puro para cálculo de preço.
     * 
     * Implementado nas subclasses para calcular o preço da sala.
     * @return double Preço da sala.
     */
    virtual double calcula_preco() const = 0;

    /**
     * @brief Ordena as empresas por idade.
     * 
     * Garante que empresas mais antigas apareçam primeiro.
     */
    void ordenar_empresas();

    /**
     * @brief Operador de comparação para ordenação das salas por andar.
     * 
     * Salas em andares inferiores vêm primeiro.
     * @param outra Sala a ser comparada.
     * @return true se o andar da sala atual for menor que o da outra sala.
     */
    bool operator<(const Sala& outra) const;

    /**
     * @brief Sobrecarga do operador + para adicionar uma empresa à sala.
     * 
     * Adiciona uma empresa à lista e ordena as empresas.
     * @param empresa Empresa a ser adicionada.
     * @return Sala& Referência para a sala com a nova empresa.
     */
    Sala& operator+(const Empresa& empresa);

    /**
     * @brief Sobrecarga do operador - para remover uma empresa da sala.
     * 
     * Remove uma empresa da lista, se estiver presente.
     * @param empresa Empresa a ser removida.
     * @return Sala& Referência para a sala sem a empresa.
     */
    Sala& operator-(const Empresa& empresa);
};

#endif // SALA_H
