CC=gcc
CFLAGS =-I.

DEPS = parser.tab.h valor_lexico.h arvore.h tabela_simbolo.h
OBJ = main.o lex.yy.o parser.tab.o arvore.o valor_lexico.o tabela_simbolo.o pilha_tabelas.o 

etapa4: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

main.o lex.yy.o parser.tab.o arvore.o valor_lexico.o: $(DEPS)

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: scanner.l
	flex scanner.l

.PHONY: clean
clean:
	rm *.o *.yy.c *.tab.* etapa*

