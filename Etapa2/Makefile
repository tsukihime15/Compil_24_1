CC=gcc
CFLAGS =-I.

DEPS = parser.tab.h
OBJ = main.o lex.yy.o

etapa2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

main.o parser.tab.o lex.yy.o: $(DEPS)

parser.tab.c: parser.y
  bison -d parser.y

lex.yy.c: scanner.l
	flex scanner.l

.PHONY: clean
clean:
	rm *.o *.yy.c *.tab.c etapa2
