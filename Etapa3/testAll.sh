#!/bin/bash

# Cria o diretório "saidas" se ele não existir
mkdir -p saidas

# Itera sobre todos os arquivos de entrada no diretório atual cujo nome começa com 'z'
for input_file in z*; do
    # Define o nome base do arquivo (o nome completo, já que não tem extensão)
    base_name=$(basename "$input_file")

    # Cria arquivo de saída de acordo com E3 e seção 2.4
    ./etapa3 < "$input_file" > "saidas/${base_name}_saida"

    # Transforma o arquivo de saída em .dot utilizando output2dot.sh
    ./output2dot.sh < "saidas/${base_name}_saida" > "saidas/${base_name}_saida.dot"

    # Gera a árvore no xdot
    xdot "saidas/${base_name}_saida.dot"
done

