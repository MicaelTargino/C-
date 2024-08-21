#include "pais.h"

// Construtor da classe 'pais', inicializa o nome e o continente do país
pais::pais(std::string n, std::string c) : nome(n), continente(c) {
    std::cout << "Pais(" << nome << ")" << std::endl;  // Mensagem de depuração indicando a criação de um país
}

// Destrutor da classe 'pais'
pais::~pais() {
    std::cout << "~Pais(" << nome << ")" << std::endl;  // Mensagem de depuração indicando a destruição de um país
}

// Retorna o nome do país
std::string pais::get_nome() const {
    return nome;
}

// Define o nome do país
void pais::set_nome(const std::string& n) {
    nome = n;
}

// Retorna o continente ao qual o país pertence
std::string pais::get_continente() const {
    return continente;
}

// Define o continente ao qual o país pertence
void pais::set_continente(const std::string& c) {
    continente = c;
}

// Imprime as informações detalhadas do país
void pais::print_info() const {
    std::cout << "---------" << std::endl;
    std::cout << "Pais: " << nome << std::endl;  // Exibe o nome do país
    std::cout << "Continente: " << continente << std::endl;  // Exibe o continente ao qual o país pertence
    std::cout << "---------" << std::endl;
}
