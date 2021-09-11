CC=gcc
CFLAGS=-W -Wall -pedantic -std=c17
LDFLAGS=
EXEC=sujet.elf
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

sujet.elf: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

sujet.o: sujet.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)