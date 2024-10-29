#include "predio_comercial.h"
#include <algorithm>
#include <iostream>

PredioComercial::~PredioComercial() {
    for (auto sala : lista_de_salas) {
        delete sala;
    }
}

const std::vector<Sala*>& PredioComercial::get_salas() const {
    return lista_de_salas;
}

PredioComercial& PredioComercial::operator+(Sala* sala) {
    lista_de_salas.push_back(sala);
    ordenar_salas();
    return *this;
}

PredioComercial& PredioComercial::operator-(Sala* sala) {
    auto it = std::find(lista_de_salas.begin(), lista_de_salas.end(), sala);
    if (it != lista_de_salas.end()) {
        lista_de_salas.erase(it);
    } else {
        throw NotFoundException("Sala nao encontrada.");
    }
    return *this;
}

void PredioComercial::ordenar_salas() {
    std::sort(lista_de_salas.begin(), lista_de_salas.end(), [](Sala* a, Sala* b) {
        return *a < *b;
    });
}

void PredioComercial::listar_salas() const {
    for (const auto& sala : lista_de_salas) {
        std::cout << "Sala " << sala->get_numero() << " no andar " << sala->get_andar() << ":\n";
        for (const auto& empresa : sala->get_empresas()) {
            std::cout << "  - Empresa: " << empresa.get_nome() << ", Idade: " << empresa.get_idade() << " anos\n";
        }
        std::cout << "Preco da sala: " << sala->calcula_preco() << "\n";
    }
}
