#include <iostream>
#include <string>
#include <algorithm>
#include "predio_comercial.h"
#include "sala_privativa.h"
#include "sala_compartilhada.h"
#include "custom_exceptions.h"

// Implementa um menu interativo para o usuário usar o sistema via linha de comando.
void menu_interativo(PredioComercial& predio) {
    int opcao;
    do {
        try {
            std::cout << "\n=== Menu de Controle de Locacao ===\n";
            std::cout << "1. Adicionar Sala\n";
            std::cout << "2. Remover Sala\n";
            std::cout << "3. Adicionar Empresa a uma Sala\n";
            std::cout << "4. Remover Empresa de uma Sala\n";
            std::cout << "5. Listar Salas e Empresas\n";
            std::cout << "0. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> opcao;

            switch (opcao) {
                case 1: {
                    int numero, andar, tipo;
                    std::cout << "Digite o numero da sala: ";
                    std::cin >> numero;
                    std::cout << "Digite o andar da sala: ";
                    std::cin >> andar;
                    std::cout << "Escolha o tipo de sala (1 para privativa, 2 para compartilhada): ";
                    std::cin >> tipo;

                    if (tipo == 1) {
                        int capacidade;
                        std::cout << "Digite a capacidade maxima de pessoas: ";
                        std::cin >> capacidade;
                        predio + new SalaPrivativa(numero, andar, capacidade);
                    } else if (tipo == 2) {
                        int estacoes;
                        std::cout << "Digite o numero de estacoes de trabalho disponíveis: ";
                        std::cin >> estacoes;
                        predio + new SalaCompartilhada(numero, andar, estacoes);
                    } else {
                        throw InvalidTypeException("Tipo de sala invalido.");
                    }
                    break;
                }
                case 2: {
                    int numero;
                    std::cout << "Digite o numero da sala a ser removida: ";
                    std::cin >> numero;

                    auto salas = predio.get_salas();
                    auto it = std::find_if(salas.begin(), salas.end(), [numero](Sala* sala) {
                        return sala->get_numero() == numero;
                    });

                    if (it != salas.end()) {
                        predio - *it;
                        delete *it;
                        std::cout << "Sala removida com sucesso.\n";
                    } else {
                        throw NotFoundException("Sala nao encontrada.");
                    }
                    break;
                }
                case 3: {
                    int numero, idade;
                    std::string nome;
                    std::cout << "Digite o numero da sala onde a empresa sera adicionada: ";
                    std::cin >> numero;

                    auto salas = predio.get_salas();
                    auto it = std::find_if(salas.begin(), salas.end(), [numero](Sala* sala) {
                        return sala->get_numero() == numero;
                    });

                    if (it != salas.end()) {
                        std::cout << "Digite o nome da empresa: ";
                        std::cin.ignore();
                        std::getline(std::cin, nome);
                        std::cout << "Digite a idade da empresa (em anos): ";
                        std::cin >> idade;

                        Empresa empresa(nome, idade);
                        **it + empresa;
                        std::cout << "Empresa adicionada com sucesso.\n";
                    } else {
                        throw NotFoundException("Sala nao encontrada.");
                    }
                    break;
                }
                case 4: {
                    int numero;
                    std::string nome;
                    std::cout << "Digite o numero da sala de onde a empresa sera removida: ";
                    std::cin >> numero;

                    auto salas = predio.get_salas();
                    auto it = std::find_if(salas.begin(), salas.end(), [numero](Sala* sala) {
                        return sala->get_numero() == numero;
                    });

                    if (it != salas.end()) {
                        std::cout << "Digite o nome da empresa: ";
                        std::cin.ignore();
                        std::getline(std::cin, nome);

                        auto empresas = (*it)->get_empresas();
                        auto emp_it = std::find_if(empresas.begin(), empresas.end(), [&nome](Empresa& emp) {
                            return emp.get_nome() == nome;
                        });

                        if (emp_it != empresas.end()) {
                            **it - *emp_it;
                            std::cout << "Empresa removida com sucesso.\n";
                        } else {
                            throw NotFoundException("Empresa nao encontrada.");
                        }
                    } else {
                        throw NotFoundException("Sala nao encontrada.");
                    }
                    break;
                }
                case 5:
                    predio.listar_salas();
                    break;
                case 0:
                    std::cout << "Saindo do programa.\n";
                    break;
                default:
                    throw InvalidArgumentException("Opcao invalida. Tente novamente.");
            }
        } catch (const InvalidArgumentException& e) {
            std::cerr << "Erro de argumento invalido: " << e.what() << '\n';
        } catch (const NotFoundException& e) {
            std::cerr << "Erro: " << e.what() << '\n';
        } catch (const InvalidTypeException& e) {
            std::cerr << "Erro de tipo: " << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado: " << e.what() << '\n';
        }
    } while (opcao != 0);
}

int main() {
    PredioComercial predio;
    menu_interativo(predio);
    return 0;
}