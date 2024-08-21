#include "medalha.h"

// Construtor da classe 'medalha', inicializa o tipo e o ano da medalha
medalha::medalha(std::string t, int a) : tipo(t), ano(a) {
    std::cout << "Medalha(" << tipo << ", " << ano << ")" << std::endl;  // Mensagem de depuração indicando a criação de uma medalha
}

// Destrutor da classe 'medalha'
medalha::~medalha() {
    std::cout << "~Medalha(" << tipo << ", " << ano << ")" << std::endl;  // Mensagem de depuração indicando a destruição de uma medalha
}

// Retorna o tipo da medalha (ouro, prata, bronze)
std::string medalha::get_tipo() const {
    return tipo;
}

// Define o tipo da medalha, validando se é um tipo válido
void medalha::set_tipo(const std::string& t) {
    if (t != "ouro" && t != "prata" && t != "bronze") {  // Verifica se o tipo é um dos valores válidos
        std::cout << "Tipo de medalha invalido" << std::endl;  // Mensagem de erro para tipo inválido
        return;
    }
    tipo = t;
}

// Retorna o ano em que a medalha foi conquistada
int medalha::get_ano() const {
    return ano;
}

// Define o ano em que a medalha foi conquistada
void medalha::set_ano(int a) {
    ano = a;
}

// Retorna o nome do atleta que ganhou a medalha, ou "Desconhecido" se não definido
std::string medalha::get_atleta() const {
    return atleta_vencedor ? atleta_vencedor->get_nome() : "Desconhecido";
}

// Define o atleta vencedor da medalha
void medalha::set_atleta(std::shared_ptr<atleta> atl) {
    atleta_vencedor = atl;
}

// Retorna o nome da modalidade associada à medalha, ou "Desconhecida" se não definida
std::string medalha::get_modalidade() const {
    return modalidade_medalha ? modalidade_medalha->get_nome() : "Desconhecida";
}

// Define a modalidade associada à medalha
void medalha::set_modalidade(std::shared_ptr<modalidade> mod) {
    modalidade_medalha = mod;
}

// Imprime as informações detalhadas da medalha
void medalha::print_info() const {
    std::cout << "-------" << std::endl;
    std::cout << "Medalha de " << tipo << std::endl;  // Exibe o tipo da medalha
    std::cout << "Ano: " << ano << std::endl;  // Exibe o ano da medalha
    std::cout << "Atleta: " << get_atleta() << std::endl;  // Exibe o nome do atleta vencedor
    std::cout << "Modalidade: " << get_modalidade() << std::endl;  // Exibe o nome da modalidade
    std::cout << "-------" << std::endl;
}
