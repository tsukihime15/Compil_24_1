DEPS: parser flex etapa2
OBJ: main.o lex.yy.o parser.tab.o

etapa2:: $(OBJ)
	gcc -c parser.tab.c lex.yy.c main.c
	gcc -o etapa2 lex.yy.o parser.tab.o main.o -ly

main.o lex.yy.o parser.tab.o: $(DEPS)

parser: parser.y
	bison -d parser.y

flex: scanner.l
	flex scanner.l

clean:
	rm etapa2 lex.yy.c parser.tab.c parser.tab.h lex.yy.o main.o parser.tab.o
