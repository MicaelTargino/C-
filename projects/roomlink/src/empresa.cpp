#include "empresa.h"

/**
 * @brief Construtor que inicializa o nome e a idade da empresa.
 */
Empresa::Empresa(const std::string& nome, int idade) : nome_da_empresa(nome), idade_da_empresa(idade) {
    if (idade < 0) {
        throw InvalidArgumentException("Idade da empresa nao pode ser negativa.");
    }
}

void Empresa::set_nome(const std::string& nome) { nome_da_empresa = nome; }
std::string Empresa::get_nome() const { return nome_da_empresa; }

void Empresa::set_idade(int idade) {
    if (idade < 0) {
        throw InvalidArgumentException("Idade da empresa nao pode ser negativa.");
    }
    idade_da_empresa = idade;
}

int Empresa::get_idade() const { return idade_da_empresa; }

bool Empresa::operator<(const Empresa& outra) const { return idade_da_empresa > outra.idade_da_empresa; }
bool Empresa::operator==(const Empresa& outra) const {
    return nome_da_empresa == outra.nome_da_empresa && idade_da_empresa == outra.idade_da_empresa;
}
