#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <iostream>
#include <string>

class modalidade {
    std::string nome;
    std::string tipo;
public:
    modalidade(std::string n, std::string t);
    ~modalidade();
    
    std::string get_nome() const;
    void set_nome(const std::string& n);
    
    std::string get_tipo() const;
    void set_tipo(const std::string& t);
    
    void print_info() const;
};

#endif // MODALIDADE_H
