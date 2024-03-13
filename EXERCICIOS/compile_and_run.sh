#!/bin/bash

# Defina o compilador, por exemplo: gcc ou cc
COMPILER=cc

# Defina o nome do arquivo de saída
OUTPUT=out

# Lista de arquivos de código-fonte
SOURCE_FILES="main.c ft_strcpy.c ft_strcmp.c ft_print_menu.c apagarCliente.c"

# Comando de compilação
$COMPILER $SOURCE_FILES -o $OUTPUT

# Verifica se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida. Executando $OUTPUT..."
    ./$OUTPUT
else
    echo "A compilação falhou."
fi
