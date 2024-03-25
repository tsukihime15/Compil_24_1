DIR =./
CC=gcc
CFLAGS =.I$(IDIR)

_DEPS = tokens.h
DEPS = $(patsubst %, $(DIR)/%,$(_DEPS))

_OBJ = main.o lex.yy.o
OBJ = $(patsubst %,$(DIR)/%,$(_OBJ))

$(DIR)/%.o: %.c $(DEPS)
  $(CC) -c -o $@ $< $(CFLAGS)

all: scanner etapa1

scanner: scanner.l
  flex scanner.l

etapa1: $(OBJ)
  $(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
  rm -f $(DIR)/*.o etapa1
