CC:= clang

CFLAGS:= -Wall -Werror -pedantic-errors -Wextra -fsanitize=address

OUT_NAME:= main.o

all: main

main: main.c binary_search_tree.c binary_search_tree.h Makefile
		scan-build $(CC) $(CFLAGS) main.c binary_search_tree.c -o $(OUT_NAME)

clean:
		$(RM) $(OUT_NAME)
