# Sistema de Gerenciamento de Campeonato de Futebol

## Descrição do Projeto

Este projeto é um sistema de gerenciamento de um campeonato de futebol, que permite a criação de times, jogadores, técnicos, juízes e a realização de jogos. Além disso, o sistema calcula a pontuação dos times com base nos resultados dos jogos e exibe a classificação final do campeonato.

### Assuntos Praticados

- **Programação Orientada a Objetos (POO)**: O projeto faz uso extensivo de herança, polimorfismo e classes abstratas para representar os diferentes papéis (pessoa, jogador, técnico, juiz, etc.) no sistema.
- **Estrutura de Projeto em C++**: Organização de código com arquivos de cabeçalho (.h) e arquivos de implementação (.cpp) separados.
- **Manipulação de Ponteiros Inteligentes**: Uso de `std::shared_ptr` para gerenciamento de memória automática e evitar vazamentos.
- **Makefile**: Utilização de um Makefile para automatizar o processo de compilação do projeto.
- **Execução em Docker**: Uso de Docker e Docker Compose para configurar o ambiente de desenvolvimento e executar o projeto em um container isolado.

## Estrutura do Projeto

```bash
campeonato_futebol/
├── include/ # Arquivos de cabeçalho (.h)
│   ├── pessoa.h
│   ├── membro_clube.h
│   ├── jogador.h
│   ├── tecnico.h
│   ├── tecnico_jogador.h
│   ├── juiz.h
│   ├── time.h
│   ├── jogo.h
│   └── campeonato.h
├── src/ # Arquivos de implementação (.cpp)
│   ├── pessoa.cpp
│   ├── membro_clube.cpp
│   ├── jogador.cpp
│   ├── tecnico.cpp
│   ├── tecnico_jogador.cpp
│   ├── juiz.cpp
│   ├── time.cpp
│   ├── jogo.cpp
│   ├── campeonato.cpp
│   └── main.cpp
├── Dockerfile
├── docker-compose.yml
└── Makefile
```

## Como Rodar o Projeto

### Usando Docker Compose

1. Certifique-se de ter o Docker e o Docker Compose instalados em sua máquina.
2. No diretório do projeto, execute o comando:

```bash
docker-compose up --build
```

### Usando Makefile

1. Certifique-se de ter o g++ instalado.
2. No diretório do projeto, execute o comando:
```bash
make
``` 