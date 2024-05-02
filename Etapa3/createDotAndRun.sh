#!/bin/bash
## Esse script apenas replica o passo a passo, para poupar tempo.
## output2dot.sh
## Apenas copiando essa informação do output2dot.sh, pra lembrar.
## "Este script converte o formato de saída
## da E3 para o formato DOT. Ele lê da
## entrada padrão e escreve na saída padrão.
## Portanto, seu uso se dá da seguinte
## forma, assumindo o desejo de visualizar
## com a ferramenta xdot (não esqueça do "-"):
##
## ./etapa3 | ./output2dot.sh | xdot -
##
## Caso houver o desejo de salvar o DOT:
##
## ./etapa3 | ./output2dot.sh > saida.dot
##
## Caso a entrada esteja em entrada.txt e
## há o desejo de salvar a saída em arquivo
##
## ./output2dot.sh < entrada.txt > saida.dot
##"
##

## Cria arquivo de saída de acordo com E3 e seção 2.4
./etapa3 < teste.c > saida
## Transforma o arquivo saida em saida.dot utilizando output2dot.sh
./output2dot.sh < saida > saida.dot
## Gera a árvore no xdot
xdot saida.dot
