#include "modalidade.h"

// Construtor da classe 'modalidade', inicializa o nome e o tipo da modalidade
modalidade::modalidade(std::string n, std::string t) : nome(n), tipo(t) {
    std::cout << "Modalidade(" << nome << ")" << std::endl;  // Mensagem de depuração indicando a criação de uma modalidade
}

// Destrutor da classe 'modalidade'
modalidade::~modalidade() {
    std::cout << "~Modalidade(" << nome << ")" << std::endl;  // Mensagem de depuração indicando a destruição de uma modalidade
}

// Retorna o nome da modalidade
std::string modalidade::get_nome() const {
    return nome;
}

// Define o nome da modalidade
void modalidade::set_nome(const std::string& n) {
    nome = n;
}

// Retorna o tipo da modalidade (individual ou coletivo)
std::string modalidade::get_tipo() const {
    return tipo;
}

// Define o tipo da modalidade, validando se é um tipo válido
void modalidade::set_tipo(const std::string& t) {
    if (t != "individual" && t != "coletivo") {  // Verifica se o tipo é válido (individual ou coletivo)
        std::cout << "Tipo invalido" << std::endl;  // Mensagem de erro para tipo inválido
        return;
    }
    tipo = t;
}

// Imprime as informações detalhadas da modalidade
void modalidade::print_info() const {
    std::cout << "---------" << std::endl;
    std::cout << "Modalidade: " << nome << std::endl;  // Exibe o nome da modalidade
    std::cout << "Tipo: " << tipo << std::endl;  // Exibe o tipo da modalidade
    std::cout << "---------" << std::endl;
}
