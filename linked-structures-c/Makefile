CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Iinclude

SRC = src/list.c

all: main

main: main.c $(SRC) include/list.h
	$(CC) $(CFLAGS) main.c $(SRC) -o main

test: tests/tests.c $(SRC) include/list.h
	$(CC) $(CFLAGS) tests/tests.c $(SRC) -o tests_run
	./tests_run

run: main
	./main

clean:
	rm -f main tests_run

.PHONY: all test run clean
