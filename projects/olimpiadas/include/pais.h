#ifndef PAIS_H
#define PAIS_H

#include <iostream>
#include <string>

class pais {
    std::string nome;
    std::string continente;
public:
    pais(std::string n, std::string c);
    ~pais();
    
    std::string get_nome() const;
    void set_nome(const std::string& n);
    
    std::string get_continente() const;
    void set_continente(const std::string& c);
    
    void print_info() const;
};

#endif // PAIS_H
