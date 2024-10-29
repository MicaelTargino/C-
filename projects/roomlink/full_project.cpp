#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>


// ESSE ARQUIVO JÁ TEM TUDO QUE PRECISA PARA QUE O PROJETO RODE. SEM PRECISAR USAR O MAKEFILE

/** 
* @brief Classe que implementa um tratamento de erros personalizado.
**/
class InvalidArgumentException : public std::invalid_argument {
public:
    InvalidArgumentException(const std::string& description) : std::invalid_argument(description) {}
};

/** 
* @brief Classe que implementa um tratamento de erros personalizado.
**/
class NotFoundException : public std::logic_error {
public:
    NotFoundException(const std::string& description) : std::logic_error(description) {}
};

/** 
* @brief Classe que implementa um tratamento de erros personalizado.
**/
class InvalidTypeException : public std::invalid_argument {
public:
    InvalidTypeException(const std::string& description) : std::invalid_argument(description) {}
};

/**
 * @brief Classe que representa uma empresa locatária no sistema.
 * 
 * A classe Empresa armazena o nome e a idade da empresa. Lança exceções
 * caso valores negativos sejam passados para a idade. Implementa a 
 * especificação 1 das especificações detalhadas.
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
    Empresa(const std::string& nome, int idade) : nome_da_empresa(nome), idade_da_empresa(idade) {
        if (idade < 0) {
            throw InvalidArgumentException("Idade da empresa nao pode ser negativa.");
        }
    }

    /**
     * @brief Define o nome da empresa.
     * 
     * @param nome Novo nome da empresa.
     */
    void set_nome(const std::string& nome) { nome_da_empresa = nome; }

    /**
     * @brief Obtém o nome da empresa.
     * 
     * @return string Nome da empresa.
     */
    std::string get_nome() const { return nome_da_empresa; }

    /**
     * @brief Define a idade da empresa.
     * 
     * Lança uma exceção se a idade for negativa.
     * @param idade Idade da empresa em anos.
     */
    void set_idade(int idade) {
        if (idade < 0) {
            throw InvalidArgumentException("Idade da empresa nao pode ser negativa.");
        }
        idade_da_empresa = idade;
    }

    /**
     * @brief Obtém a idade da empresa.
     * 
     * @return int Idade da empresa em anos.
     */
    int get_idade() const { return idade_da_empresa; }

    /**
     * @brief Operador de comparação para ordenação das empresas por idade.
     * 
     * Este operador é sobrecarregado para que empresas mais antigas
     * venham primeiro, conforme especificação 1.
     * @param outra Empresa com a qual será feita a comparação.
     * @return true se a idade da empresa atual é maior que a da outra empresa.
     */
    bool operator<(const Empresa& outra) const {
        return idade_da_empresa > outra.idade_da_empresa;
    }

    /**
     * @brief Operador de igualdade para a classe Empresa.
     * 
     * Necessário para encontrar e remover empresas em listas.
     * @param other Outra empresa para comparação.
     * @return true se o nome e a idade das duas empresas forem iguais.
     */
    bool operator==(const Empresa& other) const {
        return nome_da_empresa == other.nome_da_empresa && idade_da_empresa == other.idade_da_empresa;
    }
};

/**
 * @brief Classe abstrata que representa uma sala em um prédio comercial.
 * 
 * A classe Sala é uma classe base para diferentes tipos de salas.
 * Contém atributos e métodos compartilhados e é referenciada na 
 * especificação 2 das especificações detalhadas.
 */
class Sala {
protected:
    int numero_da_sala;               /**< Número da sala */
    int andar;                        /**< Andar em que a sala está localizada */
    std::vector<Empresa> lista_de_empresas_locatarias;  /**< Empresas locatárias da sala */

public:
    /**
     * @brief Construtor que inicializa o número e o andar da sala.
     * 
     * @param numero Número da sala.
     * @param andar Andar da sala.
     */
    Sala(int numero, int andar) : numero_da_sala(numero), andar(andar) {}

    virtual ~Sala() = default;

    /**
     * @brief Define o número da sala.
     * 
     * @param numero Novo número para a sala.
     */
    void set_numero(int numero) { numero_da_sala = numero; }

    /**
     * @brief Obtém o número da sala.
     * 
     * @return int Número da sala.
     */
    int get_numero() const { return numero_da_sala; }

    /**
     * @brief Define o andar da sala.
     * 
     * @param andar_novo Novo andar para a sala.
     */
    void set_andar(int andar_novo) { andar = andar_novo; }

    /**
     * @brief Obtém o andar da sala.
     * 
     * @return int Andar da sala.
     */
    int get_andar() const { return andar; }

    /**
     * @brief Retorna a lista de empresas associadas à sala.
     * 
     * Conforme especificado na especificação 2.
     * @return std::vector<Empresa> Lista de empresas na sala.
     */
    std::vector<Empresa> get_empresas() const { return lista_de_empresas_locatarias; }

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
    void ordenar_empresas() {
        std::sort(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end());
    }

    /**
     * @brief Operador de comparação para ordenação das salas por andar.
     * 
     * Salas em andares inferiores vêm primeiro, conforme especificação 2.
     * @param outra Sala a ser comparada.
     * @return true se o andar da sala atual for menor que o da outra sala.
     */
    bool operator<(const Sala& outra) const {
        return andar < outra.andar;
    }

    /**
     * @brief Sobrecarga do operador + para adicionar uma empresa à sala.
     * 
     * Adiciona uma empresa à lista e ordena as empresas.
     * @param empresa Empresa a ser adicionada.
     * @return Sala& Referência para a sala com a nova empresa.
     */
    Sala& operator+(const Empresa& empresa) {
        lista_de_empresas_locatarias.push_back(empresa);
        ordenar_empresas();
        return *this;
    }

    /**
     * @brief Sobrecarga do operador - para remover uma empresa da sala.
     * 
     * Remove uma empresa da lista, se estiver presente.
     * @param empresa Empresa a ser removida.
     * @return Sala& Referência para a sala sem a empresa.
     */
    Sala& operator-(const Empresa& empresa) {
        auto it = std::find(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end(), empresa);
        if (it != lista_de_empresas_locatarias.end()) {
            lista_de_empresas_locatarias.erase(it);
        } else {
            throw NotFoundException("Empresa nao encontrada na sala.");
        }
        return *this;
    }
};

/**
 * @brief Classe que representa uma sala privativa.
 * 
 * A sala privativa possui um limite de pessoas e calcula o preço 
 * baseado na capacidade. Implementa a especificação 3.
 */
class SalaPrivativa : public Sala {
private:
    int capacidade_maxima_de_pessoas; /**< Capacidade máxima de pessoas */

public:
    /**
     * @brief Construtor que inicializa a sala privativa.
     * 
     * @param numero Número da sala.
     * @param andar Andar da sala.
     * @param capacidade Capacidade máxima de pessoas.
     */
    SalaPrivativa(int numero, int andar, int capacidade)
        : Sala(numero, andar), capacidade_maxima_de_pessoas(capacidade) {}

    /**
     * @brief Calcula o preço da sala com base na capacidade.
     * 
     * Sobrescreve o método `calcula_preco` para salas privativas.
     * @return double Preço da sala.
     */
    double calcula_preco() const override {
        return capacidade_maxima_de_pessoas * 100.0;
    }
};

/**
 * @brief Classe que representa uma sala compartilhada.
 * 
 * A sala compartilhada possui estações de trabalho e calcula o preço 
 * baseado na quantidade de estações. Implementa a especificação 3.
 */
class SalaCompartilhada : public Sala {
private:
    int numero_de_estacoes_de_trabalho_disponiveis; /**< Número de estações de trabalho */

public:
    /**
     * @brief Construtor que inicializa a sala compartilhada.
     * 
     * @param numero Número da sala.
     * @param andar Andar da sala.
     * @param estacoes Número de estações de trabalho disponíveis.
     */
    SalaCompartilhada(int numero, int andar, int estacoes)
        : Sala(numero, andar), numero_de_estacoes_de_trabalho_disponiveis(estacoes) {}

    /**
     * @brief Calcula o preço da sala com base nas estações de trabalho.
     * 
     * Sobrescreve o método `calcula_preco` para salas compartilhadas.
     * @return double Preço da sala.
     */
    double calcula_preco() const override {
        return numero_de_estacoes_de_trabalho_disponiveis * 75.0;
    }
};

/**
 * @brief Classe que representa um prédio comercial.
 * 
 * Gerencia as salas do prédio e permite ordenação, adição e remoção.
 * Implementa a especificação 4.
 */
class PredioComercial {
private:
    std::vector<Sala*> lista_de_salas; /**< Lista de salas no prédio */

public:
    /**
     * @brief Destrutor que libera a memória das salas.
     */
    ~PredioComercial() {
        for (auto sala : lista_de_salas) {
            delete sala;
        }
    }

    /**
     * @brief Retorna a lista de salas do prédio.
     * 
     * @return const std::vector<Sala*>& Lista de salas.
     */
    const std::vector<Sala*>& get_salas() const {
        return lista_de_salas;
    }

    /**
     * @brief Adiciona uma sala ao prédio.
     * 
     * Adiciona a sala à lista e ordena pelo andar.
     * @param sala Ponteiro para a sala a ser adicionada.
     * @return PredioComercial& Referência para o prédio atualizado.
     */
    PredioComercial& operator+(Sala* sala) {
        lista_de_salas.push_back(sala);
        ordenar_salas();
        return *this;
    }

    /**
     * @brief Remove uma sala do prédio.
     * 
     * Remove a sala da lista se estiver presente.
     * @param sala Ponteiro para a sala a ser removida.
     * @return PredioComercial& Referência para o prédio atualizado.
     */
    PredioComercial& operator-(Sala* sala) {
        auto it = std::find(lista_de_salas.begin(), lista_de_salas.end(), sala);
        if (it != lista_de_salas.end()) {
            lista_de_salas.erase(it);
        } else {
            throw NotFoundException("Sala nao encontrada.");
        }
        return *this;
    }

    /**
     * @brief Ordena as salas pelo andar.
     * 
     * Salas em andares inferiores aparecem primeiro.
     */
    void ordenar_salas() {
        std::sort(lista_de_salas.begin(), lista_de_salas.end(), [](Sala* a, Sala* b) {
            return *a < *b;
        });
    }

    /**
     * @brief Lista todas as salas e empresas associadas.
     * 
     * Exibe os detalhes das salas e suas empresas locatárias.
     */
    void listar_salas() const {
        for (const auto& sala : lista_de_salas) {
            std::cout << "Sala " << sala->get_numero() << " no andar " << sala->get_andar() << ":\n";
            for (const auto& empresa : sala->get_empresas()) {
                std::cout << "  - Empresa: " << empresa.get_nome() << ", Idade: " << empresa.get_idade() << " anos\n";
            }
            std::cout << "Preco da sala: " << sala->calcula_preco() << "\n";
        }
    }
};

// Implementa um menu interativo para o usuário usar o sistema via linha de comando.
void menu_interativo(PredioComercial& predio) {
    int opcao;
    do {
        try {
            std::cout << "\n=== Menu de Controle de Locacao ===\n";
            std::cout << "1. Adicionar Sala\n";
            std::cout << "2. Remover Sala\n";
            std::cout << "3. Adicionar Empresa a uma Sala\n";
            std::cout << "4. Remover Empresa de uma Sala\n";
            std::cout << "5. Listar Salas e Empresas\n";
            std::cout << "0. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> opcao;

            switch (opcao) {
                case 1: {
                    int numero, andar, tipo;
                    std::cout << "Digite o numero da sala: ";
                    std::cin >> numero;
                    std::cout << "Digite o andar da sala: ";
                    std::cin >> andar;
                    std::cout << "Escolha o tipo de sala (1 para privativa, 2 para compartilhada): ";
                    std::cin >> tipo;

                    if (tipo == 1) {
                        int capacidade;
                        std::cout << "Digite a capacidade maxima de pessoas: ";
                        std::cin >> capacidade;
                        predio + new SalaPrivativa(numero, andar, capacidade);
                    } else if (tipo == 2) {
                        int estacoes;
                        std::cout << "Digite o numero de estacoes de trabalho disponíveis: ";
                        std::cin >> estacoes;
                        predio + new SalaCompartilhada(numero, andar, estacoes);
                    } else {
                        throw InvalidTypeException("Tipo de sala invalido.");
                    }
                    break;
                }
                case 2: {
                    int numero;
                    std::cout << "Digite o numero da sala a ser removida: ";
                    std::cin >> numero;

                    auto salas = predio.get_salas();
                    auto it = std::find_if(salas.begin(), salas.end(), [numero](Sala* sala) {
                        return sala->get_numero() == numero;
                    });

                    if (it != salas.end()) {
                        predio - *it;
                        delete *it;
                        std::cout << "Sala removida com sucesso.\n";
                    } else {
                        throw NotFoundException("Sala nao encontrada.");
                    }
                    break;
                }
                case 3: {
                    int numero, idade;
                    std::string nome;
                    std::cout << "Digite o numero da sala onde a empresa sera adicionada: ";
                    std::cin >> numero;

                    auto salas = predio.get_salas();
                    auto it = std::find_if(salas.begin(), salas.end(), [numero](Sala* sala) {
                        return sala->get_numero() == numero;
                    });

                    if (it != salas.end()) {
                        std::cout << "Digite o nome da empresa: ";
                        std::cin.ignore();
                        std::getline(std::cin, nome);
                        std::cout << "Digite a idade da empresa (em anos): ";
                        std::cin >> idade;

                        Empresa empresa(nome, idade);
                        **it + empresa;
                        std::cout << "Empresa adicionada com sucesso.\n";
                    } else {
                        throw NotFoundException("Sala nao encontrada.");
                    }
                    break;
                }
                case 4: {
                    int numero;
                    std::string nome;
                    std::cout << "Digite o numero da sala de onde a empresa sera removida: ";
                    std::cin >> numero;

                    auto salas = predio.get_salas();
                    auto it = std::find_if(salas.begin(), salas.end(), [numero](Sala* sala) {
                        return sala->get_numero() == numero;
                    });

                    if (it != salas.end()) {
                        std::cout << "Digite o nome da empresa: ";
                        std::cin.ignore();
                        std::getline(std::cin, nome);

                        auto empresas = (*it)->get_empresas();
                        auto emp_it = std::find_if(empresas.begin(), empresas.end(), [&nome](Empresa& emp) {
                            return emp.get_nome() == nome;
                        });

                        if (emp_it != empresas.end()) {
                            **it - *emp_it;
                            std::cout << "Empresa removida com sucesso.\n";
                        } else {
                            throw NotFoundException("Empresa nao encontrada.");
                        }
                    } else {
                        throw NotFoundException("Sala nao encontrada.");
                    }
                    break;
                }
                case 5:
                    predio.listar_salas();
                    break;
                case 0:
                    std::cout << "Saindo do programa.\n";
                    break;
                default:
                    throw InvalidArgumentException("Opcao invalida. Tente novamente.");
            }
        } catch (const InvalidArgumentException& e) {
            std::cerr << "Erro de argumento invalido: " << e.what() << '\n';
        } catch (const NotFoundException& e) {
            std::cerr << "Erro: " << e.what() << '\n';
        } catch (const InvalidTypeException& e) {
            std::cerr << "Erro de tipo: " << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado: " << e.what() << '\n';
        }
    } while (opcao != 0);
}

int main() {
    PredioComercial predio;
    menu_interativo(predio);
    return 0;
}