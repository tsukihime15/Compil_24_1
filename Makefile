CC=gcc
CFLAGS =-I.

DEPS = parser3.tab.h valor_lexico.h arvore.h pilha_tabelas.h tabela_simbolo.h
OBJ = main.o lex.yy.o parser3.tab.o arvore.o valor_lexico.o tabela_simbolo.o pilha_tabelas.o 

etapa4: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

main.o lex.yy.o parser3.tab.o arvore.o valor_lexico.o: $(DEPS)

parser.tab.c parser3.tab.h: parser3.y
	bison -d parser3.y

lex.yy.c: scanner.l
	flex scanner.l

.PHONY: clean
clean:
	rm *.o *.yy.c *.tab.* etapa*

