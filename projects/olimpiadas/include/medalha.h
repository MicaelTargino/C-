#ifndef MEDALHA_H
#define MEDALHA_H

#include <iostream>
#include <string>
#include <memory>
#include "atleta.h"
#include "modalidade.h"

class medalha {
    std::string tipo;
    int ano;
    std::shared_ptr<atleta> atleta_vencedor;
    std::shared_ptr<modalidade> modalidade_medalha;
public:
    medalha(std::string t, int a);
    ~medalha();
    
    std::string get_tipo() const;
    void set_tipo(const std::string& t);
    
    int get_ano() const;
    void set_ano(int a);
    
    std::string get_atleta() const;
    void set_atleta(std::shared_ptr<atleta> atl);
    
    std::string get_modalidade() const;
    void set_modalidade(std::shared_ptr<modalidade> mod);
    
    void print_info() const;
};

#endif // MEDALHA_H
