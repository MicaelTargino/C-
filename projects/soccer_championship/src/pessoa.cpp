#include <string>
#include "pessoa.h"

using std::string;

// Initialize static member
int pessoa::contador = 0; 

/**
 * @brief Construtor padrão que inicializa uma pessoa com nome e idade padrão.
 */
pessoa::pessoa(): nome(""), idade(0) {
    pessoa::contador++;
}

/**
 * @brief Construtor que inicializa uma pessoa com nome e idade específicos.
 * 
 * @param n Nome da pessoa.
 * @param i Idade da pessoa.
 */
pessoa::pessoa(const string& n, int i): nome(n), idade(i) {
    pessoa::contador++;
}

/**
 * @brief destrutor que decrementa o valor do contador de instâncias.
 */
pessoa::~pessoa() {
    if (pessoa::contador > 0) {
       pessoa::contador--;
    }
}

/**
 * @brief Retorna o nome da pessoa.
 * 
 * @return string Nome da pessoa.
 */
string pessoa::get_nome() const { return nome; }

/**
 * @brief Define o nome da pessoa.
 * 
 * @param n O novo nome da pessoa.
 */
void pessoa::set_nome(const string& n) { nome = n; }

/**
 * @brief Retorna a idade da pessoa.
 * 
 * @return int Idade da pessoa.
 */
int pessoa::get_idade() const { return idade; }

/**
 * @brief Define a idade da pessoa.
 * 
 * @param i A nova idade da pessoa.
 */
void pessoa::set_idade(int i) { idade = i; }

/**
 * @brief Retorna o valor atual do contador estático.
 * 
 * @return int Valor do contador que rastreia o número total de pessoas.
 */
int pessoa::get_contador() const { return contador; }

/**
 * @brief Sobrecarga do operador de igualdade para comparar duas pessoas.
 * 
 * Compara pessoas pelo nome e idade.
 * 
 * @param outra Outra pessoa a ser comparada.
 * @return true Se o nome e a idade forem iguais.
 * @return false Caso contrário.
 */
bool pessoa::operator==(const pessoa& outra) const {
    return nome == outra.nome && idade == outra.idade;
}