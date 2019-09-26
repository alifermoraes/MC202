CC:= clang

CFLAGS:= -Wall -Werror -pedantic-errors -Wextra -fsanitize=address

OUT_NAME:= main.o

all: main

main: main.c dynamic.c dynamic.h Makefile
		scan-build $(CC) $(CFLAGS) main.c list.c -o $(OUT_NAME)

clean:
		$(RM) $(OUT_NAME)
