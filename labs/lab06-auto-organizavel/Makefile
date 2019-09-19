CC:= clang

CFLAGS:= -Wall -Werror -pedantic-errors -Wextra -fsanitize=address

OUT_NAME:= main.o

all: main

main: main.c Makefile
		scan-build $(CC) $(CFLAGS) main.c -o $(OUT_NAME)

clean:
		$(RM) $(OUT_NAME)
