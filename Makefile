# Flags de compilacion
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Constantes
BIN_DIR = bin
NOMBRE_PROGRAMA = practica1

# Entrada
all: $(NOMBRE_PROGRAMA)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Paso 1: convertir cada .c en su .o
$(BIN_DIR)/main.o: main.c include/Controlador.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c main.c -o $(BIN_DIR)/main.o

$(BIN_DIR)/Utils.o: src/Utils.c include/Utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c src/Utils.c -o $(BIN_DIR)/Utils.o

$(BIN_DIR)/Registros.o: src/Registros.c include/Registros.h include/Utils.h include/Bool.h include/Tipos.h include/Resultado.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c src/Registros.c -o $(BIN_DIR)/Registros.o

$(BIN_DIR)/Reporte.o: src/Reporte.c include/Reporte.h include/Utils.h include/Tipos.h include/Mensajes.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c src/Reporte.c -o $(BIN_DIR)/Reporte.o

$(BIN_DIR)/Datos.o: src/Datos.c include/Datos.h include/Tipos.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c src/Datos.c -o $(BIN_DIR)/Datos.o

$(BIN_DIR)/Captura.o: src/Captura.c include/Captura.h include/Tipos.h include/Utils.h include/Datos.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c src/Captura.c -o $(BIN_DIR)/Captura.o

$(BIN_DIR)/Controlador.o: src/Controlador.c include/Controlador.h include/Bool.h include/Tipos.h include/Registros.h include/Reporte.h include/Datos.h include/Captura.h include/Mensajes.h include/Resultado.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c src/Controlador.c -o $(BIN_DIR)/Controlador.o

# Paso 2: unir todos los .o
$(NOMBRE_PROGRAMA): $(BIN_DIR)/main.o $(BIN_DIR)/Utils.o $(BIN_DIR)/Registros.o $(BIN_DIR)/Reporte.o $(BIN_DIR)/Datos.o $(BIN_DIR)/Captura.o $(BIN_DIR)/Controlador.o
	$(CC) $(CFLAGS) -o $(NOMBRE_PROGRAMA) $(BIN_DIR)/main.o $(BIN_DIR)/Utils.o $(BIN_DIR)/Registros.o $(BIN_DIR)/Reporte.o $(BIN_DIR)/Datos.o $(BIN_DIR)/Captura.o $(BIN_DIR)/Controlador.o

# Paso 3: Limpiar
clean:
	rm -rf $(BIN_DIR) $(NOMBRE_PROGRAMA)

# Documento tecnico
DOC_TEX = docs/documentoTecnico.tex
DOC_PDF = docs/documentoTecnico.pdf

doc:
	latexmk -pdf -interaction=nonstopmode -halt-on-error -cd $(DOC_TEX)
	mv $(DOC_PDF) documentoTecnico.pdf

.PHONY: all clean doc
