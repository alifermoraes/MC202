C:= clang

CFLAGS:= -Wall -Werror -pedantic-errors -Wextra -fsanitize=address

OUT_NAME:= main.o

all: main

main: main.c heap.c heap.h Makefile
		scan-build $(CC) $(CFLAGS) main.c heap.c -o $(OUT_NAME)

clean:
		$(RM) $(OUT_NAME)
