CC:= clang

CFLAGS:= -Wall -Werror -ansi -pedantic-errors -Wextra -fsanitize=address -fno-omit-frame-pointer

OUT_NAME:= lab04

all: main

main: main.c dlist.c dlist.h Makefile
	scan-build $(CC) $(CFLAGS) main.c dlist.c -o $(OUT_NAME)

clean:
	$(RM) lab04
