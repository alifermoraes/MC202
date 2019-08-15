CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab01 

racional.o: racionais.c racionais.h
	$(CC) -c racional.c $(CFLAGS)

lab01.o: lab01.c
	$(CC) -c lab01.c $(CFLAGS)

lab01: lab01.o racionais.o
	$(CC) lab01.o racionais.o -o lab01 

clean:
	rm -f *.o lab01 
