CC=gcc
CFLAGS=-ansi -Wall -pedantic-errors -g -lm

all: lab02 

vetor.o: vetor.c vetor.h
	$(CC) -c vetor.c $(CFLAGS)

matriz.o: matriz.c matriz.h
	$(CC) -c matriz.c $(CFLAGS)

lab02.o: lab02.c
	$(CC) -c lab02.c $(CFLAGS)

lab02: lab02.o vetor.o matriz.o
	$(CC) lab02.o vetor.o matriz.o -o lab02 $(CFLAGS)


clean:
	rm -f *.o lab02 
