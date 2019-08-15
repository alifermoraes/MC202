CC:= clang

CFLAGS:= -Wall -Werror -ansi -pedantic-errors -Wextra -fsanitize=address -fno-omit-frame-pointer

OUT_NAME:= lab03

all: main

main: main.c list.c list.h Makefile
	scan-build $(CC) $(CFLAGS) main.c list.c -o $(OUT_NAME)

clean:
	$(RM) $(OUT_NAME)
