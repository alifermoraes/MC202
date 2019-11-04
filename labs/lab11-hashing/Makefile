CC:= clang

CFLAGS:= -Wall -Werror -pedantic-errors -Wextra -fsanitize=address

OUT_NAME:= main.o

all: main

main: main.c hashing.c hashing.h Makefile
		scan-build $(CC) $(CFLAGS) main.c hashing.c -o $(OUT_NAME)

clean:
		$(RM) $(OUT_NAME)
