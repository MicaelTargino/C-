# Nome do executável
TARGET = programa

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Compilador e flags
CC = g++
CFLAGS = -Wall -I$(INCLUDE_DIR)

# Lista de arquivos fonte
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos objeto
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@

# Regra para criar arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Regra para instalar (exemplo: copiar para /usr/local/bin)
install: $(TARGET)
	@echo "Instalando o programa em /usr/local/bin..."
	@cp $(TARGET) /usr/local/bin

# Regra para desinstalar
uninstall:
	@echo "Removendo o programa de /usr/local/bin..."
	@rm -f /usr/local/bin/$(TARGET)

# Declaração de dependências
-include $(OBJ_FILES:.o=.d)

# Regras para gerar arquivos de dependências
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) > $@
