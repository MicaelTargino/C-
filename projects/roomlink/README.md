
# Sistema de Controle de Locação de Salas em Prédio Comercial

Este projeto implementa um sistema de controle de locação para gerenciar salas comerciais em um prédio, permitindo associar empresas locatárias às salas e organizar as salas por andar. Além disso, permite adicionar e remover empresas e salas, com funcionalidades de ordenação e cálculo de preço das salas, que variam dependendo do tipo de sala.

## Conceitos Estudados

O projeto abrange conceitos fundamentais da Programação Orientada a Objetos (POO), incluindo:

1. **Herança**: Classe `Sala` como base para `SalaPrivativa` e `SalaCompartilhada`.
2. **Composição**: As salas contêm uma lista de `Empresa`, representando as empresas locatárias.
3. **Polimorfismo**: Método virtual `calcula_preco()` em `Sala` é sobrescrito em cada tipo específico de sala (`SalaPrivativa` e `SalaCompartilhada`).
4. **Sobrecarga de Operadores**: Operadores `+` e `-` são sobrecarregados para manipular a adição e remoção de empresas em uma sala e de salas em um prédio.
5. **Tratamento de Exceções**: Classes personalizadas para exceções (`InvalidArgumentException`, `NotFoundException` e `InvalidTypeException`) tratam erros específicos, como idades negativas ou entidades não encontradas.
6. **Uso de STL**: O projeto faz uso de `std::vector` para armazenar empresas e salas.

## Estrutura do Projeto

O projeto está organizado em uma estrutura modular de pastas, conforme descrito abaixo:

```
olimpiadas/
├── include/               # Arquivos de cabeçalho (.h)
│   ├── InvalidArgumentException.h
│   ├── Empresa.h
│   ├── Sala.h
│   ├── SalaPrivativa.h
│   ├── SalaCompartilhada.h
│   └── PredioComercial.h
│
├── src/                   # Arquivos de implementação (.cpp)
│   ├── InvalidArgumentException.cpp
│   ├── Empresa.cpp
│   ├── Sala.cpp
│   ├── SalaPrivativa.cpp
│   ├── SalaCompartilhada.cpp
│   ├── PredioComercial.cpp
│   └── main.cpp           # Contém a função principal e o menu interativo
│
├── obj/                   # Arquivos objeto (.o) gerados na compilação
│
├── full_project.cpp       # Arquivo que contém todo o código em um único arquivo
│
├── Makefile               # Arquivo Makefile para gerenciar a compilação
└── README.md              # Este arquivo README
```

### Detalhes sobre a Estrutura

- **`include/`**: Contém os arquivos de cabeçalho que declaram classes e métodos usados no projeto. A estrutura modular facilita a manutenção e permite reutilização de código.
  
- **`src/`**: Contém os arquivos de implementação onde os métodos das classes são definidos. Cada classe tem seu próprio arquivo `.cpp`, promovendo organização e clareza.
  
- **`full_project.cpp`**: Arquivo opcional que reúne todo o código em um único arquivo `.cpp`, permitindo a compilação sem o Makefile para fins de conveniência.
  
- **`Makefile`**: Facilita o processo de compilação, permitindo que todos os arquivos sejam compilados ao mesmo tempo e vinculados em um executável final. Inclui um comando `clean` para limpar os arquivos `.o` e o executável.

## Compilação e Execução

Para compilar o projeto usando o `Makefile`, basta navegar até o diretório do projeto e executar o comando:

```bash
make
```

Para limpar os arquivos gerados:

```bash
make clean
```

Caso prefira compilar apenas o arquivo `full_project.cpp`, utilize:

```bash
g++ full_project.cpp -o sistema_locacao
```

## Menu Interativo

Ao executar o programa, o usuário terá acesso a um menu interativo que permite:

1. **Adicionar Sala**: Inclui uma nova sala, com escolha entre `SalaPrivativa` e `SalaCompartilhada`.
2. **Remover Sala**: Remove uma sala existente com base no número fornecido.
3. **Adicionar Empresa a uma Sala**: Associa uma empresa a uma sala específica.
4. **Remover Empresa de uma Sala**: Remove uma empresa de uma sala específica.
5. **Listar Salas e Empresas**: Exibe as salas e as empresas associadas, incluindo o preço de cada sala.

---

Este sistema permite um gerenciamento eficiente e estruturado das salas de um prédio comercial, aplicando os princípios de POO para uma solução extensível e de fácil manutenção.
