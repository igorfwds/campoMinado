CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: campo_minado

campo_minado: main.o campo_minado.o
	$(CC) $(CFLAGS) -o campo_minado main.o campo_minado.o -lncurses

main.o: main.c campo_minado.h
	$(CC) $(CFLAGS) -c main.c -lncurses

campo_minado.o: campo_minado.c campo_minado.h
	$(CC) $(CFLAGS) -c campo_minado.c -lncurses

clean:
	rm -f *.o campo_minado
