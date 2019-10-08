CC:= clang

CFLAGS:= -Wall -Werror -pedantic-errors -Wextra -fsanitize=address

OUT_NAME:= main.o

all: main

main: main.c doubly_list.c doubly_list.h Makefile
		scan-build $(CC) $(CFLAGS) main.c doubly_list.c -o $(OUT_NAME)

clean:
		$(RM) $(OUT_NAME)
