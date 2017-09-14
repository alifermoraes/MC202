CC:= clang

CFLAGS:= -Wall -Werror -ansi -pedantic-errors -Wextra -fsanitize=address -fno-omit-frame-pointer

OUT_NAME:= lab02

all: main

main: main.c array.c array.h matrix.c matrix.h Makefile
	scan-build $(CC) $(CFLAGS) main.c array.c matrix.c -o $(OUT_NAME)

clean:
	$(RM) lab02
