#include "atleta.h"

// Construtor da classe 'atleta' que inicializa o nome e define o número de modalidades para 0
atleta::atleta(std::string n) : nome(n), num_modalidades(0) {
    std::cout << "Atleta(" << nome << ")" << std::endl;  // Mensagem de depuração para indicar a criação do objeto
}

// Destrutor da classe 'atleta'
atleta::~atleta() {
    std::cout << "~Atleta(" << nome << ")" << std::endl;  // Mensagem de depuração para indicar a destruição do objeto
}

// Retorna o nome do atleta
std::string atleta::get_nome() const {
    return nome;
}

// Define o nome do atleta
void atleta::set_nome(const std::string& n) {
    nome = n;
}

// Retorna o nome do país de origem do atleta, ou "Desconhecido" se não definido
std::string atleta::get_pais() const {
    return pais_origem ? pais_origem->get_nome() : "Desconhecido";
}

// Define o país de origem do atleta usando um shared_ptr
void atleta::set_pais(std::shared_ptr<pais> p) {
    pais_origem = std::move(p);  // O uso de std::move aqui é adequado, transferindo a propriedade do ponteiro
}

// Retorna o nome da modalidade na posição 'i' ou "Invalida" se 'i' for um índice inválido
std::string atleta::get_modalidade(int i) const {
    if (i >= 0 && i < num_modalidades) {
        return modalidades[i]->get_nome();
    }
    return "Invalida";  
}

// Imprime todas as modalidades do atleta
void atleta::get_modalidades() const {
    std::cout << "Modalidades: ";
    for (int i = 0; i < num_modalidades; i++) {
        if (modalidades[i]) {
            std::cout << modalidades[i]->get_nome() << ", ";
        }
    }
    std::cout << std::endl;
}

// Adiciona uma nova modalidade ao atleta, verificando se o número máximo foi atingido
void atleta::add_modalidade(std::shared_ptr<modalidade> mod) {
    if (num_modalidades >= MAX_MODALIDADES_POR_ATLETA) {
        std::cout << "Máximo de modalidades atingido" << std::endl;  // Mensagem de erro caso o limite seja alcançado
        return;
    }
    modalidades[num_modalidades++] = mod;  // Adiciona a modalidade e incrementa o contador
}

// Imprime todas as informações do atleta
void atleta::print_info() const {
    std::cout << "---------" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Pais de origem: " << (pais_origem ? pais_origem->get_nome() : "Desconhecido") << std::endl;
    std::cout << "Modalidades: " << std::endl;
    for (int i = 0; i < num_modalidades; i++) {
        modalidades[i]->print_info(); 
    }
    std::cout << "---------" << std::endl;
}
