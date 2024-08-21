#include "modalidade.h"
#include "pais.h"
#include "atleta.h"
#include "medalha.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Assinatura das funções auxiliares, que serão definidas abaixo do main
shared_ptr<pais> create_pais();
shared_ptr<modalidade> create_modalidade();
shared_ptr<atleta> create_atleta(const vector<shared_ptr<modalidade>>& modalidades_existentes, const vector<shared_ptr<pais>>& paises_existentes);
shared_ptr<medalha> create_medalha(vector<shared_ptr<atleta>>& atletas, vector<shared_ptr<modalidade>>& modalidades);

void display_results(const vector<shared_ptr<atleta>>& atletas, const vector<shared_ptr<modalidade>>& modalidades, const vector<shared_ptr<medalha>>& medalhas);

int main() {
    vector<shared_ptr<modalidade>> modalidades;  // Vetor para armazenar as modalidades
    vector<shared_ptr<pais>> paises;  // Vetor para armazenar os países
    vector<shared_ptr<atleta>> atletas;  // Vetor para armazenar os atletas
    vector<shared_ptr<medalha>> medalhas;  // Vetor para armazenar as medalhas

    int num_atletas, num_modalidades, num_paises, num_medalhas;

    // Coleta de entrada do usuário para a quantidade de modalidades a serem registradas
    cout << "Quantas modalidades serao registradas? ";
    cin >> num_modalidades;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    // Criação das modalidades com base no número informado
    for (int i = 0; i < num_modalidades; i++) {
        modalidades.push_back(create_modalidade());
    }

    // Coleta de entrada do usuário para a quantidade de países a serem registrados
    cout << "Quantos paises serao registrados? ";
    cin >> num_paises;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    // Criação dos países com base no número informado
    for (int i = 0; i < num_paises; i++) {
        paises.push_back(create_pais());
    }

    // Coleta de entrada do usuário para a quantidade de atletas a serem registrados
    cout << "Quantos atletas serao registrados? ";
    cin >> num_atletas;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    // Criação dos atletas com base no número informado
    for (int i = 0; i < num_atletas; i++) {
        atletas.push_back(create_atleta(modalidades, paises));
    }

    // Coleta de entrada do usuário para a quantidade de medalhas a serem registradas
    cout << "Quantas medalhas serao registradas? ";
    cin >> num_medalhas;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    // Criação das medalhas com base no número informado
    for (int i = 0; i < num_medalhas; i++) {
        medalhas.push_back(create_medalha(atletas, modalidades));
    }

    // Exibe os resultados (atletas, modalidades, medalhas)
    display_results(atletas, modalidades, medalhas);

    return 0;
}

// Função auxiliar para criar um novo país
shared_ptr<pais> create_pais() {
    string nome, continente;
    cout << "Digite o nome do pais: ";
    getline(cin, nome);
    cout << "Digite o continente: ";
    getline(cin, continente);
    return make_shared<pais>(nome, continente);  // Cria e retorna um shared_ptr de 'pais'
}

// Função auxiliar para criar uma nova modalidade
shared_ptr<modalidade> create_modalidade() {
    string nome, tipo;
    cout << "Digite o nome da modalidade: ";
    getline(cin, nome);
    cout << "Digite o tipo da modalidade (individual/coletivo): ";
    getline(cin, tipo);
    auto mod = make_shared<modalidade>(nome, tipo);  // Cria e retorna um shared_ptr de 'modalidade'
    return mod;
}

// Função auxiliar para criar um novo atleta
shared_ptr<atleta> create_atleta(const vector<shared_ptr<modalidade>>& modalidades_existentes, const vector<shared_ptr<pais>>& paises_existentes) {
    string nome;
    cout << "Digite o nome do atleta: ";
    getline(cin, nome);
    auto atl = make_shared<atleta>(nome);  // Cria um novo atleta

    int num_modalidades;
    cout << "Quantas modalidades o atleta participa? ";
    cin >> num_modalidades;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    // Seleção das modalidades em que o atleta participa
    for (int i = 0; i < num_modalidades; i++) {
        cout << "Modalidades disponíveis:" << endl;
        for (size_t j = 0; j < modalidades_existentes.size(); j++) {
            cout << j << ": " << modalidades_existentes[j]->get_nome() << " (" << modalidades_existentes[j]->get_tipo() << ")" << endl;
        }

        cout << "Selecione a modalidade para o atleta (0 a " << modalidades_existentes.size() - 1 << "): ";
        int indice;
        cin >> indice;
        cin.ignore();  // Ignora o '\n' residual deixado pelo cin

        if (indice >= 0 && indice < modalidades_existentes.size()) {
            atl->add_modalidade(modalidades_existentes[indice]);
        } else {
            cout << "Indice de modalidade invalido!" << endl;
        }
    }

    // Seleção do país de origem do atleta
    cout << "Paises disponiveis:" << endl;
    for (size_t j = 0; j < paises_existentes.size(); j++) {
        cout << j << ": " << paises_existentes[j]->get_nome() << " (" << paises_existentes[j]->get_continente() << ")" << endl;
    }

    cout << "Selecione o pais de origem do atleta (0 a " << paises_existentes.size() - 1 << "): ";
    int indice_pais;
    cin >> indice_pais;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    if (indice_pais >= 0 && indice_pais < paises_existentes.size()) {
        atl->set_pais(make_shared<pais>(*paises_existentes[indice_pais]));  // Clona o país selecionado para garantir que cada atleta tenha seu próprio país
    } else {
        cout << "Índice de pais inválido!" << endl;
    }

    return atl;
}

// Função auxiliar para criar uma nova medalha
shared_ptr<medalha> create_medalha(vector<shared_ptr<atleta>>& atletas, vector<shared_ptr<modalidade>>& modalidades) {
    string tipo;
    int ano;
    cout << "Digite o tipo da medalha (ouro/prata/bronze): ";
    getline(cin, tipo);
    cout << "Digite o ano da medalha: ";
    cin >> ano;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    auto medal = make_shared<medalha>(tipo, ano);  // Cria uma nova medalha

    int atleta_index, modalidade_index;

    // Seleção do atleta que ganhou a medalha
    cout << "Atletas disponiveis:" << endl;
    for (size_t i = 0; i < atletas.size(); i++) {
        cout << i << ": " << atletas[i]->get_nome() << " (País: " << atletas[i]->get_pais() << ")" << endl;
    }

    cout << "Digite o indice do atleta vencedor (0 a " << atletas.size() - 1 << "): ";
    cin >> atleta_index;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    if (atleta_index >= 0 && atleta_index < atletas.size()) {
        medal->set_atleta(atletas[atleta_index]);
    } else {
        cout << "Indice de atleta inválido!" << endl;
    }

    // Seleção da modalidade na qual a medalha foi conquistada
    cout << "Modalidades disponiveis:" << endl;
    for (size_t i = 0; i < modalidades.size(); i++) {
        cout << i << ": " << modalidades[i]->get_nome() << " (" << modalidades[i]->get_tipo() << ")" << endl;
    }

    cout << "Digite o indice da modalidade (0 a " << modalidades.size() - 1 << "): ";
    cin >> modalidade_index;
    cin.ignore();  // Ignora o '\n' residual deixado pelo cin

    if (modalidade_index >= 0 && modalidade_index < modalidades.size()) {
        medal->set_modalidade(modalidades[modalidade_index]);
    } else {
        cout << "Indice de modalidade invalido!" << endl;
    }

    return medal;
}

// Função que exibe os resultados dos atletas, modalidades e medalhas
void display_results(const vector<shared_ptr<atleta>>& atletas, const vector<shared_ptr<modalidade>>& modalidades, const vector<shared_ptr<medalha>>& medalhas) {
    cout << "-------- Resultados das Olimpiadas --------" << endl;

    cout << "Atletas:" << endl;
    for (const auto& atleta : atletas) {
        atleta->print_info();  // Presume-se que 'atleta' tenha um método 'print_info()'
    }

    cout << "Modalidades:" << endl;
    for (const auto& modalidade : modalidades) {
        modalidade->print_info();  // Presume-se que 'modalidade' tenha um método 'print_info()'
    }

    cout << "Medalhas:" << endl;
    for (const auto& medalha : medalhas) {
        medalha->print_info();  // Presume-se que 'medalha' tenha um método 'print_info()'
    }
}
