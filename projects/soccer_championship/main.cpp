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

/**
 * @brief Classe que representa um membro de clube de futebol.
 * 
 * A classe membro_clube é derivada da classe pessoa e adiciona a funcionalidade de
 * gerenciamento de salário. É uma classe base abstrata e requer a implementação de
 * um método puramente virtual para calcular o salário de classes derivadas, como jogadores e técnicos.
 */
class membro_clube: public pessoa {
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
    membro_clube(const string& n, int i, double s): pessoa(n, i), salario(s) {}

    /**
     * @brief Construtor que inicializa um membro do clube com nome e idade, com salário padrão de 0.
     * 
     * @param n Nome do membro do clube.
     * @param i Idade do membro.
     */
    membro_clube(const string& n, int i): pessoa(n, i), salario(0) {}

    /**
     * @brief Retorna o salário do membro do clube.
     * 
     * @return double O salário atual do membro.
     */
    double get_salario() const { return salario; }

    /**
     * @brief Define o salário do membro do clube.
     * 
     * @param s O novo valor do salário.
     */
    void set_salario(double s) { salario = s; }

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
    friend std::ostream& operator<<(std::ostream& out, const membro_clube& mc) {
        out << "membro_clube(" << mc.get_nome() << ", " << mc.get_idade() << ", " << mc.calcular_salario() << ")" << endl;
        return out;
    }
};

/**
 * @brief Classe que representa um jogador de futebol.
 * 
 * A classe jogador mantém informações sobre a posição, gols marcados
 * e salário do jogador, além de permitir o cálculo do salário total
 * e a comparação de jogadores com base no número de gols.
 */
class jogador: public membro_clube {
    string posicao; /**< Posição do jogador (goleiro, zagueiro, meio-campo, atacante) */
    int gols_marcados; /**< Número total de gols marcados pelo jogador */

public:
    /**
     * @brief Construtor que inicializa um jogador com nome, idade, salário, posição e gols marcados.
     * 
     * @param n Nome do jogador.
     * @param i Idade do jogador.
     * @param s Salário do jogador.
     * @param p Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    jogador(string n, int i, double s, string p, int gm): membro_clube(n,i,s), posicao(p), gols_marcados(gm) {}

    /**
     * @brief Construtor que inicializa um jogador com nome, idade, posição e gols marcados, com salário padrão de 0.
     * 
     * @param n Nome do jogador.
     * @param i Idade do jogador.
     * @param p Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    jogador(string n, int i, string p, int gm): membro_clube(n,i), posicao(p), gols_marcados(gm) {}

    /**
     * @brief Retorna a posição do jogador.
     * 
     * @return string Posição do jogador.
     */
    string get_posicao() const { return posicao; }

    /**
     * @brief Define a posição do jogador.
     * 
     * @param p Nova posição do jogador.
     */
    void set_posicao(const string& p) { posicao = p; }

    /**
     * @brief Retorna o número total de gols marcados pelo jogador.
     * 
     * @return int Número de gols marcados.
     */
    int get_gols_marcados() const { return gols_marcados; }

    /**
     * @brief Define o número de gols marcados pelo jogador.
     * 
     * @param gm Novo número de gols marcados.
     */
    void set_gols_marcados(int gm) { gols_marcados = gm; }

    /**
     * @brief Calcula o salário total do jogador com base no número de gols.
     * 
     * O salário total é o salário base mais um bônus de 100 unidades por cada gol marcado.
     * 
     * @return double Salário total calculado.
     */
    double calcular_salario() const override {
        return get_salario() + (gols_marcados * 100);
    }

    /**
     * @brief Sobrecarga do operador < para comparar jogadores pelo número de gols.
     * 
     * @param outro Outro jogador a ser comparado.
     * @return true Se o jogador atual tiver menos gols marcados que o outro jogador.
     * @return false Caso contrário.
     */
    bool operator<(const jogador& outro) const {
        return gols_marcados < outro.gols_marcados;
    }
};

// Inicialização do contador estático
int pessoa::contador = 0;

int main(void) {
    return 0;
}
