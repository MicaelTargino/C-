
# Projeto Olímpico

Este projeto é um programa simples em C++ que simula a gestão de modalidades, atletas, países e medalhas em um contexto olímpico. Ele permite que o usuário crie modalidades, registre países, associe modalidades a atletas, e registre medalhas conquistadas em diferentes anos.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:

```
/olimpiadas
│
├── /include           # Diretório para arquivos de cabeçalho (.h)
│   ├── modalidade.h
│   ├── pais.h
│   ├── atleta.h
│   └── medalha.h
│
├── /src               # Diretório para arquivos-fonte (.cpp)
│   ├── modalidade.cpp
│   ├── pais.cpp
│   ├── atleta.cpp
│   ├── medalha.cpp
│   └── main.cpp
│
├── /obj               # Diretório para arquivos objeto (.o), gerados durante a compilação
│   ├── modalidade.o   # (Esses arquivos serão criados durante a compilação)
│   ├── pais.o
│   ├── atleta.o
│   ├── medalha.o
│   └── main.o
│
├── Makefile           # Arquivo Makefile para gerenciar a compilação
└── README.md          # Este arquivo README
```

## Requisitos

Para compilar e executar o projeto, você precisará de:

- GCC (G++), ou outro compilador C++ compatível
- Make (para utilizar o Makefile)

## Compilação e Execução

### 1. Compilação

Para compilar o projeto, basta rodar o comando:

```bash
make
```

Este comando irá:

- Compilar os arquivos `.cpp` no diretório `src/`
- Gerar os arquivos objeto correspondentes no diretório `obj/`
- Linkar os objetos e gerar o executável `programa`

### 2. Execução

Para executar o programa, após a compilação, use:

```bash
./programa
```

### 3. Limpeza

Para remover os arquivos objeto gerados e o executável, utilize:

```bash
make clean
```

### 4. Instalação

Para instalar o programa em `/usr/local/bin`, permitindo que seja executado de qualquer lugar, utilize:

```bash
sudo make install
```

### 5. Desinstalação

Para remover o programa de `/usr/local/bin`, utilize:

```bash
sudo make uninstall
```

## Estrutura do Código

O código fonte está dividido em várias classes, cada uma representando uma entidade:

- `modalidade`: Representa uma modalidade esportiva, como "Futebol" ou "Natação".
- `pais`: Representa um país participante.
- `atleta`: Representa um atleta, associado a um país e até 3 modalidades.
- `medalha`: Representa uma medalha conquistada por um atleta em uma modalidade.
