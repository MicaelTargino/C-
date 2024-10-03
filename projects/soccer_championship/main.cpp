#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

/**
 * @brief Classe abstrata que representa uma pessoa.
 * 
 * A classe pessoa mantém informações sobre o nome, idade e um contador estático que
 * rastreia o número total de pessoas criadas.
 * É uma classe base para outras classes como jogador, técnico, etc.
 */
class pessoa {
    string nome; 
    int idade;
    static int contador; /**< Contador estático que rastreia o número total de instâncias de pessoa */
public:
    /**
     * @brief Construtor padrão que inicializa uma pessoa com nome e idade padrão.
     */
    pessoa(): nome(""), idade(0) {
        contador++;
    }

    /**
     * @brief Construtor que inicializa uma pessoa com nome e idade específicos.
     * 
     * @param n Nome da pessoa.
     * @param i Idade da pessoa.
     */
    pessoa(const string& n, int i): nome(n), idade(i) {
        contador++;
    }

    /**
     * @brief destrutor que decrementa o valor do contador de instâncias.
     */
    ~pessoa() {
        if (contador > 0) {
           contador--;
        }
    }


    /**
     * @brief Retorna o nome da pessoa.
     * 
     * @return string Nome da pessoa.
     */
    string get_nome() const { return nome; }

    /**
     * @brief Define o nome da pessoa.
     * 
     * @param n O novo nome da pessoa.
     */
    void set_nome(const string& n) { nome = n; }

    /**
     * @brief Retorna a idade da pessoa.
     * 
     * @return int Idade da pessoa.
     */
    int get_idade() const { return idade; }

    /**
     * @brief Define a idade da pessoa.
     * 
     * @param i A nova idade da pessoa.
     */
    void set_idade(int i) { idade = i; }

    /**
     * @brief Retorna o valor atual do contador estático.
     * 
     * @return int Valor do contador que rastreia o número total de pessoas.
     */
    int get_contador() const { return contador; }

    /**
     * @brief Método virtual puro para exibir informações da pessoa.
     * 
     * Esse método deverá ser implementado pelas classes derivadas para exibir informações
     * específicas de cada tipo de pessoa.
     */
    virtual void exibir_informacoes() = 0; 

    /**
     * @brief Sobrecarga do operador de igualdade para comparar duas pessoas.
     * 
     * Compara pessoas pelo nome e idade.
     * 
     * @param outra Outra pessoa a ser comparada.
     * @return true Se o nome e a idade forem iguais.
     * @return false Caso contrário.
     */
    bool operator==(const pessoa& outra) const {
        return nome == outra.nome && idade == outra.idade;
    }
};

// Inicialização do contador estático
int pessoa::contador = 0;

int main(void) {
    return 0;
}
