CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab04

lista.o: lista.c lista.h
	$(CC) -c lista.c $(CFLAGS)

lab04.o: lab04.c
	$(CC) -c lab04.c $(CFLAGS)

lab04: lab04.o lista.o
	$(CC) lab04.o lista.o -o lab04 $(CFLAGS)

clean:
	rm -f *.o lab04
