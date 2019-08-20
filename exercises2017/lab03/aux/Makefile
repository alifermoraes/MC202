CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab03

lista.o: lista.c lista.h
	$(CC) -c lista.c $(CFLAGS)

lab03.o: lab03.c
	$(CC) -c lab03.c $(CFLAGS)

lab03: lab03.o lista.o
	$(CC) lab03.o lista.o -o lab03 $(CFLAGS)

clean:
	rm -f *.o lab03
