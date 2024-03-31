CC=gcc
CFLAGS =-I.

DEPS = tokens.h
OBJ = main.o lex.yy.o

etapa1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

main.o lex.yy.o : $(DEPS)

lex.yy.c: scanner.l
	flex scanner.l

.PHONY: clean
clean:
	rm *.o *.yy.c etapa1
