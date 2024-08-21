#ifndef ATLETA_H
#define ATLETA_H

#include <iostream>
#include <string>
#include <memory>
#include "pais.h"
#include "modalidade.h"

#define MAX_MODALIDADES_POR_ATLETA 3

class atleta {
    std::string nome;
    std::shared_ptr<pais> pais_origem;
    std::shared_ptr<modalidade> modalidades[MAX_MODALIDADES_POR_ATLETA];
    int num_modalidades;
public:
    atleta(std::string n);
    ~atleta();
    
    std::string get_nome() const;
    void set_nome(const std::string& n);
    
    std::string get_pais() const;
    void set_pais(std::shared_ptr<pais> p);
    
    std::string get_modalidade(int i) const;
    void get_modalidades() const;
    void add_modalidade(std::shared_ptr<modalidade> mod);
    
    void print_info() const;
};

#endif // ATLETA_H
