CC:= clang

CFLAGS:= -Wall -Werror -ansi -pedantic-errors -Wextra -fsanitize=address -fno-omit-frame-pointer

OUT_NAME:= derivative

all: main

main: main.c derivative.c derivative.h Makefile
	scan-build $(CC) $(CFLAGS) main.c derivative.c -o $(OUT_NAME)

clean:
	$(RM) $(OUT_NAME)
