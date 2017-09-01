CC:= clang

CFLAGS:= -ansi -Wall -pedantic-errors -fsanitize=address -fno-omit-frame-pointer

OUT_NAME:= rational

all: main

main: main.c rational.c rational.h Makefile
	scan-build $(CC) $(CFLAGS) main.c rational.c -o $(OUT_NAME)

clean:
	$(RM) rational
