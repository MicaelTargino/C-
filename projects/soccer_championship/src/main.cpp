#include <memory>

#include "pessoa.h"
#include "jogador.h"
#include "tecnico.h"
#include "tecnico_jogador.h"
#include "time_futebol.h"
#include "campeonato.h"
#include "jogo.h"

using std::make_shared;

int main() {
    // Criação do campeonato "Campeonato Quadrangular"
    campeonato camp("Campeonato Quadrangular");

    // Criação dos técnicos
    auto tecnico1 = make_shared<tecnico>("Jose Silva", 45, 5000, 20);  // nome, idade, salário, anos de experiência
    auto tecnico2 = make_shared<tecnico>("Carlos Souza", 40, 4800, 18);  // nome, idade, salário, anos de experiência
    auto tecnico3 = make_shared<tecnico>("Ana Lima", 38, 4700, 17);  // nome, idade, salário, anos de experiência
    auto tecnico4 = make_shared<tecnico>("Marcos Azevedo", 50, 5200, 22);  // nome, idade, salário, anos de experiência

    // Criação dos jogadores para cada time
    jogador jogador1("Joao", 28, 3000, "Atacante", 10);  // nome, idade, salário, posição, gols marcados
    jogador jogador2("Pedro", 25, 3200, "Meio-campo", 8);
    jogador jogador3("Lucas", 30, 3500, "Zagueiro", 3);
    jogador jogador4("Andre", 27, 2900, "Goleiro", 0);
    jogador jogador5("Ricardo", 29, 3100, "Atacante", 7);

    jogador jogador6("Paulo", 28, 3200, "Atacante", 9);
    jogador jogador7("Rafael", 23, 3100, "Meio-campo", 6);
    jogador jogador8("Thiago", 26, 3300, "Zagueiro", 4);
    jogador jogador9("Fabio", 30, 3400, "Goleiro", 0);
    jogador jogador10("Sergio", 24, 3000, "Atacante", 8);

    jogador jogador11("Felipe", 29, 3200, "Atacante", 12);
    jogador jogador12("Gustavo", 27, 3150, "Meio-campo", 7);
    jogador jogador13("Matheus", 28, 3300, "Zagueiro", 5);
    jogador jogador14("Vitor", 26, 3400, "Goleiro", 0);
    jogador jogador15("Leandro", 30, 3100, "Atacante", 10);

    jogador jogador16("Igor", 30, 3200, "Atacante", 9);
    jogador jogador17("Jorge", 24, 3050, "Meio-campo", 6);
    jogador jogador18("Ronaldo", 29, 3350, "Zagueiro", 2);
    jogador jogador19("Gabriel", 28, 3250, "Goleiro", 0);
    jogador jogador20("Eduardo", 26, 3150, "Atacante", 11);

    // Criação dos times
    auto time1 = make_shared<time_futebol>("Tigres", tecnico1);  // nome do time, técnico
    auto time2 = make_shared<time_futebol>("Leoes", tecnico2);  // nome do time, técnico
    auto time3 = make_shared<time_futebol>("Aguias", tecnico3);  // nome do time, técnico
    auto time4 = make_shared<time_futebol>("Fenix", tecnico4);  // nome do time, técnico

    // Adicionando jogadores aos times
    time1->adicionar_jogador(jogador1);
    time1->adicionar_jogador(jogador2);
    time1->adicionar_jogador(jogador3);
    time1->adicionar_jogador(jogador4);
    time1->adicionar_jogador(jogador5);

    time2->adicionar_jogador(jogador6);
    time2->adicionar_jogador(jogador7);
    time2->adicionar_jogador(jogador8);
    time2->adicionar_jogador(jogador9);
    time2->adicionar_jogador(jogador10);

    time3->adicionar_jogador(jogador11);
    time3->adicionar_jogador(jogador12);
    time3->adicionar_jogador(jogador13);
    time3->adicionar_jogador(jogador14);
    time3->adicionar_jogador(jogador15);

    time4->adicionar_jogador(jogador16);
    time4->adicionar_jogador(jogador17);
    time4->adicionar_jogador(jogador18);
    time4->adicionar_jogador(jogador19);
    time4->adicionar_jogador(jogador20);

    // Adicionando técnico-jogador ao time 4 (Fênix)
    tecnico_jogador meu_tecnico_jogador("Marcos Azevedo", 50, 5200, 22, "Meio-campo", 5, 1500); // nome, idade, salário, experiência, posição, gols, bônus
    time4->adicionar_jogador(meu_tecnico_jogador);

    // Adicionando times ao campeonato
    camp.adicionar_time(time1);
    camp.adicionar_time(time2);
    camp.adicionar_time(time3);
    camp.adicionar_time(time4);

    // Criação de dois juízes
    auto juiz1 = make_shared<juiz>("Carlos Henrique", 45, 100);  // nome, idade, partidas arbitradas
    auto juiz2 = make_shared<juiz>("Fernando Almeida", 50, 120);  // nome, idade, partidas arbitradas

    // Criação e registro dos jogos
    auto jogo1 = make_shared<jogo>(time1, time2, juiz1);  // time da casa, time visitante, juiz
    jogo1->registrar_resultado(2, 1);  // Gols time1 (casa), Gols time2 (visitante)

    auto jogo2 = make_shared<jogo>(time3, time4, juiz2);  // time da casa, time visitante, juiz
    jogo2->registrar_resultado(3, 3);  // Gols time3 (casa), Gols time4 (visitante)

    auto jogo3 = make_shared<jogo>(time1, time3, juiz1);
    jogo3->registrar_resultado(1, 2);  // Gols time1 (casa), Gols time3 (visitante)

    auto jogo4 = make_shared<jogo>(time2, time4, juiz2);
    jogo4->registrar_resultado(0, 2);  // Gols time2 (casa), Gols time4 (visitante)

    auto jogo5 = make_shared<jogo>(time1, time4, juiz1);
    jogo5->registrar_resultado(3, 2);  // Gols time1 (casa), Gols time4 (visitante)

    auto jogo6 = make_shared<jogo>(time2, time3, juiz2);
    jogo6->registrar_resultado(1, 1);  // Gols time2 (casa), Gols time3 (visitante)

    // Adicionando os jogos ao campeonato
    camp.adicionar_jogo(jogo1);
    camp.adicionar_jogo(jogo2);
    camp.adicionar_jogo(jogo3);
    camp.adicionar_jogo(jogo4);
    camp.adicionar_jogo(jogo5);
    camp.adicionar_jogo(jogo6);

    // Exibe a tabela de classificação final
    camp.exibir_classificacao();

    return 0;
}