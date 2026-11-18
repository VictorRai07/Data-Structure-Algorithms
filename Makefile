# Compilador e flags (o -Iinclude resolve o problema de achar os .h sem mexer no código)
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Nome do binário final
TARGET = main

# Arquivos fonte e os respectivos objetos temporários na pasta build/
SRCS = src/main.c src/utils.c src/ordenacao.c src/menu.c
OBJS = build/main.o build/utils.o build/ordenacao.o build/menu.o

# Regra padrão
all: $(TARGET)

# Cria o executável final
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Regra para compilar os .c em .o na pasta build/
build/%.o: src/%.c include/utils.h include/ordenacao.h include/menu.h
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa o binário e a pasta de objetos
clean:
	rm -rf build $(TARGET)

# Declara alvos que não são arquivos físicos
.PHONY: all clean
