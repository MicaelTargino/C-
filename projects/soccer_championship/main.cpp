#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cctype> // para usar a função toupper(), que converte um caractere para maiúsculo.

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::shared_ptr;

#define PONTUACAO_VITORIA 3
#define PONTUACAO_EMPATE 1
#define PONTUACAO_DERROTA 0

/**
 * @brief Classe abstrata que representa uma pessoa.
 * 
 * A classe pessoa mantém informações sobre o nome, idade e um contador estático que
 * rastreia o número total de pessoas criadas.
 * É uma classe base para outras classes como jogador, técnico, etc.
 */
class pessoa {
    string nome; 
    int idade;
    static int contador; /**< Contador estático que rastreia o número total de instâncias de pessoa */
public:
    /**
     * @brief Construtor padrão que inicializa uma pessoa com nome e idade padrão.
     */
    pessoa(): nome(""), idade(0) {
        contador++;
    }

    /**
     * @brief Construtor que inicializa uma pessoa com nome e idade específicos.
     * 
     * @param n Nome da pessoa.
     * @param i Idade da pessoa.
     */
    pessoa(const string& n, int i): nome(n), idade(i) {
        contador++;
    }

    /**
     * @brief destrutor que decrementa o valor do contador de instâncias.
     */
    ~pessoa() {
        if (contador > 0) {
           contador--;
        }
    }


    /**
     * @brief Retorna o nome da pessoa.
     * 
     * @return string Nome da pessoa.
     */
    string get_nome() const { return nome; }

    /**
     * @brief Define o nome da pessoa.
     * 
     * @param n O novo nome da pessoa.
     */
    void set_nome(const string& n) { nome = n; }

    /**
     * @brief Retorna a idade da pessoa.
     * 
     * @return int Idade da pessoa.
     */
    int get_idade() const { return idade; }

    /**
     * @brief Define a idade da pessoa.
     * 
     * @param i A nova idade da pessoa.
     */
    void set_idade(int i) { idade = i; }

    /**
     * @brief Retorna o valor atual do contador estático.
     * 
     * @return int Valor do contador que rastreia o número total de pessoas.
     */
    int get_contador() const { return contador; }

    /**
     * @brief Método virtual puro para exibir informações da pessoa.
     * 
     * Esse método deverá ser implementado pelas classes derivadas para exibir informações
     * específicas de cada tipo de pessoa.
     */
    virtual void exibir_informacoes() = 0; 

    /**
     * @brief Sobrecarga do operador de igualdade para comparar duas pessoas.
     * 
     * Compara pessoas pelo nome e idade.
     * 
     * @param outra Outra pessoa a ser comparada.
     * @return true Se o nome e a idade forem iguais.
     * @return false Caso contrário.
     */
    bool operator==(const pessoa& outra) const {
        return nome == outra.nome && idade == outra.idade;
    }
};

/**
 * @brief Classe que representa um membro de clube de futebol.
 * 
 * A classe membro_clube é derivada da classe pessoa e adiciona a funcionalidade de
 * gerenciamento de salário. É uma classe base abstrata e requer a implementação de
 * um método puramente virtual para calcular o salário de classes derivadas, como jogadores e técnicos.
 */
class membro_clube: public pessoa {
    double salario; /**< Salário do membro do clube */

public:
    /**
     * @brief Construtor que inicializa um membro do clube com nome, idade e salário.
     * 
     * Inicializa os atributos da classe pessoa (nome e idade) e define o salário do membro.
     * 
     * @param n Nome do membro do clube.
     * @param i Idade do membro.
     * @param s Salário do membro.
     */
    membro_clube(const string& n, int i, double s): pessoa(n, i), salario(s) {}

    /**
     * @brief Construtor que inicializa um membro do clube com nome e idade, com salário padrão de 0.
     * 
     * @param n Nome do membro do clube.
     * @param i Idade do membro.
     */
    membro_clube(const string& n, int i): pessoa(n, i), salario(0) {}

    /**
     * @brief Retorna o salário do membro do clube.
     * 
     * @return double O salário atual do membro.
     */
    double get_salario() const { return salario; }

    /**
     * @brief Define o salário do membro do clube.
     * 
     * @param s O novo valor do salário.
     */
    void set_salario(double s) { salario = s; }

    /**
     * @brief Função virtual pura para calcular o salário.
     * 
     * Essa função deve ser implementada nas classes derivadas para definir como o
     * salário do membro será calculado.
     * 
     * @return double O valor do salário calculado.
     */
    virtual double calcular_salario() const = 0;  // Função virtual pura const

    /**
     * @brief Sobrecarga do operador << para exibir as informações do membro do clube.
     * 
     * Exibe o nome, idade e salário do membro do clube.
     * 
     * @param out Stream de saída.
     * @param mc Referência constante para o membro_clube.
     * @return ostream& Referência para o stream de saída.
     */
    friend std::ostream& operator<<(std::ostream& out, const membro_clube& mc) {
        out << "membro_clube(" << mc.get_nome() << ", " << mc.get_idade() << ", " << mc.calcular_salario() << ")" << endl;
        return out;
    }
};

/**
 * @brief Classe que representa um jogador de futebol.
 * 
 * A classe jogador mantém informações sobre a posição, gols marcados
 * e salário do jogador, além de permitir o cálculo do salário total
 * e a comparação de jogadores com base no número de gols.
 */
class jogador: virtual public membro_clube {
    string posicao; /**< Posição do jogador (goleiro, zagueiro, meio-campo, atacante) */
    int gols_marcados; /**< Número total de gols marcados pelo jogador */

public:
    /**
     * @brief Construtor que inicializa um jogador com nome, idade, salário, posição e gols marcados.
     * 
     * @param n Nome do jogador.
     * @param i Idade do jogador.
     * @param s Salário do jogador.
     * @param p Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    jogador(string n, int i, double s, string p, int gm): membro_clube(n,i,s), posicao(p), gols_marcados(gm) {}

    /**
     * @brief Construtor que inicializa um jogador com nome, idade, posição e gols marcados, com salário padrão de 0.
     * 
     * @param n Nome do jogador.
     * @param i Idade do jogador.
     * @param p Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    jogador(string n, int i, string p, int gm): membro_clube(n,i), posicao(p), gols_marcados(gm) {}

    /**
     * @brief Retorna a posição do jogador.
     * 
     * @return string Posição do jogador.
     */
    string get_posicao() const { return posicao; }

    /**
     * @brief Define a posição do jogador.
     * 
     * @param p Nova posição do jogador.
     */
    void set_posicao(const string& p) { posicao = p; }

    /**
     * @brief Retorna o número total de gols marcados pelo jogador.
     * 
     * @return int Número de gols marcados.
     */
    int get_gols_marcados() const { return gols_marcados; }

    /**
     * @brief Define o número de gols marcados pelo jogador.
     * 
     * @param gm Novo número de gols marcados.
     */
    void set_gols_marcados(int gm) { gols_marcados = gm; }

    /**
     * @brief Calcula o salário total do jogador com base no número de gols.
     * 
     * O salário total é o salário base mais um bônus de 100 unidades por cada gol marcado.
     * 
     * @return double Salário total calculado.
     */
    double calcular_salario() const override {
        return get_salario() + (gols_marcados * 100);
    }

    /**
     * @brief Sobrecarga do operador < para comparar jogadores pelo número de gols.
     * 
     * @param outro Outro jogador a ser comparado.
     * @return true Se o jogador atual tiver menos gols marcados que o outro jogador.
     * @return false Caso contrário.
     */
    bool operator<(const jogador& outro) const {
        return gols_marcados < outro.gols_marcados;
    }
};

/**
 * @brief Classe que representa um técnico de futebol.
 * 
 * A classe técnico herda de membro_clube e adiciona o atributo de anos de experiência,
 * além de implementar o cálculo de salário com base na experiência.
 */
class tecnico: virtual public membro_clube {
    int experiencia; /**< Anos de experiência do técnico */

public:
    /**
     * @brief Construtor que inicializa um técnico com nome, idade, salário e experiência.
     * 
     * @param n Nome do técnico.
     * @param i Idade do técnico.
     * @param s Salário do técnico.
     * @param e Anos de experiência do técnico.
     */
    tecnico(const string& n, int i, double s, int e): membro_clube(n, i, s), experiencia(e) {}

    /**
     * @brief Construtor que inicializa um técnico com nome, idade e experiência, com salário padrão de 0.
     * 
     * @param n Nome do técnico.
     * @param i Idade do técnico.
     * @param e Anos de experiência do técnico.
     */
    tecnico(const string& n, int i, int e): membro_clube(n, i), experiencia(e) {}

    /**
     * @brief Retorna os anos de experiência do técnico.
     * 
     * @return int Anos de experiência.
     */
    int get_experiencia() const { return experiencia; }

    /**
     * @brief Define os anos de experiência do técnico.
     * 
     * @param e Novo valor de anos de experiência.
     */
    void set_experiencia(int e) { experiencia = e; }

    /**
     * @brief Calcula o salário total do técnico com base nos anos de experiência.
     * 
     * O salário total é o salário base mais um bônus de 200 unidades para cada ano de experiência.
     * 
     * @return double Salário total calculado.
     */
    double calcular_salario() const override {
        return get_salario() + (experiencia * 200);
    }
};

/**
 * @brief Classe que representa um técnico que também atua como jogador de futebol.
 * 
 * Esta classe possui herança múltipla, herdando de técnico e de jogador ao mesmo tempo. 
 * É utilizada a herança virtual, para evitar o problema da ambiguidade na herança diamante.
 */
class tecnico_jogador: virtual public tecnico, virtual public jogador {
    double bonus_duplo_papel; /**< Bônus por atuar como técnico e jogador ao mesmo tempo */
public:
    /**
     * @brief Construtor que inicializa um técnico_jogador com nome, idade, salário, experiência, posição e gols marcados.
     * 
     * @param n Nome do técnico_jogador.
     * @param i Idade do técnico_jogador.
     * @param s Salário do técnico_jogador.
     * @param e Anos de experiência como técnico.
     * @param pos Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    tecnico_jogador(const string& n, int i, double s, int e, string pos, int gm)
        : membro_clube(n, i, s), tecnico(n, i, s, e), jogador(n, i, s, pos, gm), bonus_duplo_papel(0) {}

    /**
     * @brief Construtor que inicializa um técnico_jogador com nome, idade, experiência, posição e gols marcados, com salário padrão de 0.
     * 
     * @param n Nome do técnico_jogador.
     * @param i Idade do técnico_jogador.
     * @param e Anos de experiência como técnico.
     * @param pos Posição do jogador.
     * @param gm Número de gols marcados pelo jogador.
     */
    tecnico_jogador(const string& n, int i, int e, string pos, int gm)
        : membro_clube(n, i), tecnico(n, i, e), jogador(n, i, pos, gm), bonus_duplo_papel(0) {}

    /**
     * @brief Retorna o bônus por atuar como técnico e jogador.
     * 
     * @return double O valor do bônus.
     */
    double get_bonus_duplo_papel() const { return bonus_duplo_papel; }

    /**
     * @brief Define o valor do bônus por atuar como técnico e jogador.
     * 
     * @param bdp O novo valor do bônus.
     */
    void set_bonus_duplo_papel(double bdp) { bonus_duplo_papel = bdp; }

    /**
     * @brief Calcula o salário total do técnico_jogador com base no bônus e nos salários como técnico e jogador.
     * 
     * @return double O valor do salário total.
     */
    double calcular_salario() const override {
        return jogador::calcular_salario() + tecnico::calcular_salario() + bonus_duplo_papel;
    }

    /**
     * @brief Sobrecarga do operador << para exibir as informações do técnico_jogador.
     * 
     * Exibe o nome, idade, posição, gols marcados, experiência e salário total.
     * 
     * @param out Stream de saída.
     * @param tj Referência constante para o técnico_jogador.
     * @return ostream& Referência para o stream de saída.
     */
    friend std::ostream& operator<<(std::ostream& out, const tecnico_jogador& tj) {
        out << "tecnico_jogador(" << tj.get_nome() << ", " << tj.get_idade() << ", " << tj.get_gols_marcados() 
            << ", " << tj.get_posicao() << ", " << tj.get_experiencia() << ", " << tj.calcular_salario() << ")" << endl;
        return out;
    }
};

/**
 * @brief Classe que representa um juiz de futebol.
 * 
 * A classe juiz herda da classe pessoa e adiciona o atributo de número de partidas arbitradas.
 * Também fornece métodos para incrementar e acessar esse valor, além de exibir informações do juiz.
 */
class juiz: public pessoa {
    int partidas_arbitradas; /**< Número total de partidas arbitradas pelo juiz */

public:
    /**
     * @brief Construtor que inicializa um juiz com nome, idade e número de partidas arbitradas.
     * 
     * @param n Nome do juiz.
     * @param i Idade do juiz.
     * @param pa Número de partidas arbitradas pelo juiz.
     */
    juiz(const string& n, int i, int pa): pessoa(n, i), partidas_arbitradas(pa) {}

    /**
     * @brief Retorna o número total de partidas arbitradas pelo juiz.
     * 
     * @return int Número de partidas arbitradas.
     */
    int get_partidas_arbitradas() const { return partidas_arbitradas; }

    /**
     * @brief Define o número total de partidas arbitradas pelo juiz.
     * 
     * @param pa Novo valor de partidas arbitradas.
     */
    void set_partidas_arbitradas(int pa) { partidas_arbitradas = pa; }

    /**
     * @brief Incrementa o número de partidas arbitradas pelo juiz.
     */
    void incrementar_partidas_arbitradas() { partidas_arbitradas++; }

    /**
     * @brief Exibe as informações do juiz, incluindo nome, idade e número de partidas arbitradas.
     */
    void exibir_informacoes() override {
        cout << "Juiz(" << get_nome() << ", " << get_idade() << ", " << get_partidas_arbitradas() << ")" << endl;
    }
};


/**
 * @brief Classe que representa um time de futebol.
 * 
 * A classe time gerencia o nome do time, o técnico, os jogadores e a pontuação total.
 */
class time_futebol {
    string nome; /**< Nome do time */
    shared_ptr<tecnico> tecnico_do_time; /**< Técnico responsável pelo time */
    vector<shared_ptr<jogador>> jogadores; /**< Vetor de jogadores pertencentes ao time */
    int pontuacao; /**< Pontuação total do time */

public:
    /**
     * @brief Construtor que inicializa o nome do time, o técnico e define pontuação inicial como 0.
     * 
     * @param n Nome do time.
     * @param tec Ponteiro compartilhado para o técnico do time.
     */
    time_futebol(const string& n, shared_ptr<tecnico> tec): nome(n), tecnico_do_time(tec), pontuacao(0) {}

    /**
     * @brief Retorna o nome do time.
     * 
     * @return string Nome do time.
     */
    string get_nome() const { return nome; }

    /**
     * @brief Define o nome do time.
     * 
     * @param n Novo nome para o time.
     */
    void set_nome(const string& n) { nome = n; }

    /**
     * @brief Retorna o técnico do time.
     * 
     * @return shared_ptr<tecnico> Ponteiro compartilhado para o técnico do time.
     */
    shared_ptr<tecnico> get_tecnico() const { return tecnico_do_time; }

    /**
     * @brief Define o técnico do time.
     * 
     * @param tecnico Novo ponteiro compartilhado para o técnico do time.
     */
    void set_tecnico(shared_ptr<tecnico> tecnico) {
        tecnico_do_time = tecnico;
    }

    /**
     * @brief Retorna o vetor de jogadores do time.
     * 
     * @return vector<shared_ptr<jogador>> Vetor de ponteiros compartilhados de jogadores.
     */
    vector<shared_ptr<jogador>> get_jogadores() const { return jogadores; }

    /**
     * @brief Adiciona um jogador ao time sem copiar o objeto.
     * 
     * Recebe uma referência constante para um jogador já existente e
     * armazena no vetor de jogadores como um ponteiro compartilhado.
     * 
     * @param j Referência constante para o jogador a ser adicionado ao time.
     */
    void adicionar_jogador(const jogador& j) {
        // Criar um shared_ptr sem copiar o jogador
        auto ptr = shared_ptr<jogador>(const_cast<jogador*>(&j));
        jogadores.push_back(ptr);
    }

    /**
     * @brief Retorna a pontuação total do time.
     * 
     * @return int Pontuação total do time.
     */
    int get_pontuacao() const { return pontuacao; }

    /**
     * @brief Define a pontuação total do time.
     * 
     * @param p Nova pontuação do time.
     */
    void set_pontuacao(int p) { pontuacao = p; }

    /**
     * @brief Atualiza a pontuação do time com base no resultado do jogo.
     * 
     * @param resultado Resultado da partida ('V' para vitória, 'E' para empate, 'D' para derrota).
     */
    void registrar_resultado(char resultado) {
        resultado = toupper(resultado);
        switch (resultado) {
            case 'V':
                pontuacao += PONTUACAO_VITORIA;
                break;
            case 'E':
                pontuacao += PONTUACAO_EMPATE;
                break;
            case 'D':
                pontuacao += PONTUACAO_DERROTA;
                break;
            default: 
                cout << "Erro ao registrar resultado: código inválido." << endl; 
                return;
        }
    }

    /**
     * @brief Exibe as informações completas do time, incluindo nome, técnico, jogadores e pontuação.
     */
    void exibir_informacoes() {
        cout << "Time: " << nome << endl;
        cout << "Técnico: " << tecnico_do_time->get_nome() << endl;
        cout << "Jogadores:" << endl;
        for (const auto& jogador : jogadores) {
            cout << "\t" << jogador->get_nome() << " - Posição: " << jogador->get_posicao()
                 << " - Gols Marcados: " << jogador->get_gols_marcados() << endl;
        }
        cout << "Pontuação Total: " << pontuacao << endl;
    }

    /**
     * @brief Sobrecarga do operador < para comparar times pela pontuação total.
     * 
     * @param outro Outro time a ser comparado.
     * @return true Se o time atual tiver pontuação menor que o outro time.
     * @return false Caso contrário.
     */
    bool operator<(const time_futebol& outro) const {
        return pontuacao < outro.pontuacao;
    }
};


/**
 * @brief Classe que representa um jogo de futebol.
 * 
 * A classe jogo mantém informações sobre os times que jogam (casa e visitante),
 * o juiz responsável pela partida, e o número de gols de cada time.
 */
class jogo {
    shared_ptr<time_futebol> time_casa; /**< Ponteiro para o time jogando em casa */
    shared_ptr<time_futebol> time_visitante; /**< Ponteiro para o time visitante */
    shared_ptr<juiz> juiz_principal; /**< Ponteiro para o juiz responsável pela partida */
    int gols_time_casa; /**< Gols marcados pelo time da casa */
    int gols_time_visitante; /**< Gols marcados pelo time visitante */

public:
    /**
     * @brief Construtor que inicializa os atributos do jogo.
     * 
     * Inicializa os times e o juiz, e define os gols inicialmente como 0.
     * 
     * @param tc Ponteiro para o time da casa.
     * @param tv Ponteiro para o time visitante.
     * @param j Ponteiro para o juiz responsável pela partida.
     */
    jogo(shared_ptr<time_futebol> tc, shared_ptr<time_futebol> tv, shared_ptr<juiz> j):
        time_casa(tc), time_visitante(tv), juiz_principal(j), gols_time_casa(0), gols_time_visitante(0) {}

    /**
     * @brief Retorna o time da casa.
     * 
     * @return shared_ptr<time_futebol> Ponteiro para o time da casa.
     */
    shared_ptr<time_futebol> get_time_casa() const { return time_casa; }

    /**
     * @brief Define o time da casa.
     * 
     * @param t Novo ponteiro para o time da casa.
     */
    void set_time_casa(shared_ptr<time_futebol> t) { time_casa = t; }

    /**
     * @brief Retorna o time visitante.
     * 
     * @return shared_ptr<time_futebol> Ponteiro para o time visitante.
     */
    shared_ptr<time_futebol> get_time_visitante() const { return time_visitante; }

    /**
     * @brief Define o time visitante.
     * 
     * @param t Novo ponteiro para o time visitante.
     */
    void set_time_visitante(shared_ptr<time_futebol> t) { time_visitante = t; }

    /**
     * @brief Retorna o juiz principal da partida.
     * 
     * @return shared_ptr<juiz> Ponteiro para o juiz principal.
     */
    shared_ptr<juiz> get_juiz() const { return juiz_principal; }

    /**
     * @brief Define o juiz principal da partida.
     * 
     * @param jp Novo ponteiro para o juiz principal.
     */
    void set_juiz(shared_ptr<juiz> jp) { juiz_principal = jp; }

    /**
     * @brief Retorna os gols marcados pelo time da casa.
     * 
     * @return int Gols marcados pelo time da casa.
     */
    int get_gols_time_casa() { return gols_time_casa; }

    /**
     * @brief Define os gols marcados pelo time da casa.
     * 
     * @param g Novo número de gols marcados pelo time da casa.
     */
    void set_gols_time_casa(int g) { gols_time_casa = g; }

    /**
     * @brief Retorna os gols marcados pelo time visitante.
     * 
     * @return int Gols marcados pelo time visitante.
     */
    int get_gols_time_visitante() { return gols_time_visitante; }

    /**
     * @brief Define os gols marcados pelo time visitante.
     * 
     * @param g Novo número de gols marcados pelo time visitante.
     */
    void set_gols_time_visitante(int g) { gols_time_visitante = g; }

    /**
     * @brief Registra o resultado do jogo e atualiza a pontuação dos times.
     * 
     * Atualiza os gols de cada time e ajusta a pontuação dos times com base
     * no resultado (vitória, empate, ou derrota).
     * 
     * @param gols_casa Gols marcados pelo time da casa.
     * @param gols_visitante Gols marcados pelo time visitante.
     */
    void registrar_resultado(int gols_casa, int gols_visitante) {
        gols_time_casa = gols_casa;
        gols_time_visitante = gols_visitante;

        if (gols_casa == gols_visitante) {
            // empate
            time_casa->registrar_resultado('E');
            time_visitante->registrar_resultado('E');
        } else if (gols_casa > gols_visitante) {
            // vitória do time da casa
            time_casa->registrar_resultado('V');
            time_visitante->registrar_resultado('D');
        } else {
            // vitória do time visitante
            time_visitante->registrar_resultado('V');
            time_casa->registrar_resultado('D');
        }
    }

    /**
     * @brief Exibe as informações do jogo.
     * 
     * Exibe o nome dos times, o juiz responsável, e o resultado do jogo.
     */
    void exibir_informacoes() {
        cout << "Jogo entre: " << endl;
        cout << "Time da casa: " << time_casa->get_nome() << " - Gols: " << gols_time_casa << endl;
        cout << "Time visitante: " << time_visitante->get_nome() << " - Gols: " << gols_time_visitante << endl;
        cout << "Juiz: " << juiz_principal->get_nome() << endl;

        if (gols_time_casa == gols_time_visitante) {
            cout << "Resultado: Empate" << endl;
        } else if (gols_time_casa > gols_time_visitante) {
            cout << "Resultado: Vitória do time da casa" << endl;
        } else {
            cout << "Resultado: Vitória do time visitante" << endl;
        }
    }
};

// Inicialização do contador estático
int pessoa::contador = 0;

int main(void) {
    return 0;
}
