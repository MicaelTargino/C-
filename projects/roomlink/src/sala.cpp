#include "sala.h"
#include <algorithm>

/**
 * @brief Construtor que inicializa o número e o andar da sala.
 */
Sala::Sala(int numero, int andar) : numero_da_sala(numero), andar(andar) {}

void Sala::set_numero(int numero) { numero_da_sala = numero; }
int Sala::get_numero() const { return numero_da_sala; }

void Sala::set_andar(int andar_novo) { andar = andar_novo; }
int Sala::get_andar() const { return andar; }

std::vector<Empresa> Sala::get_empresas() const { return lista_de_empresas_locatarias; }

void Sala::ordenar_empresas() {
    std::sort(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end());
}

bool Sala::operator<(const Sala& outra) const { return andar < outra.andar; }

Sala& Sala::operator+(const Empresa& empresa) {
    lista_de_empresas_locatarias.push_back(empresa);
    ordenar_empresas();
    return *this;
}

Sala& Sala::operator-(const Empresa& empresa) {
    auto it = std::find(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end(), empresa);
    if (it != lista_de_empresas_locatarias.end()) {
        lista_de_empresas_locatarias.erase(it);
    } else {
        throw NotFoundException("Empresa nao encontrada na sala.");
    }
    return *this;
}
