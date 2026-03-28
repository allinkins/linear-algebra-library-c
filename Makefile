CC = clang
CFLAGS = -Iinclude -Wall -Wextra -std=c11
LDFLAGS = -lm

SRC = src/vector.c src/matrix.c src/slae.c
TESTS = tests/tests.c
MAIN = main.c

all: main tests

main:
	$(CC) $(CFLAGS) $(SRC) $(MAIN) -o main $(LDFLAGS)

tests:
	$(CC) $(CFLAGS) $(SRC) $(TESTS) -o tests_run $(LDFLAGS)

run: main
	./main

test: tests
	./tests_run

clean:
	rm -f main tests_run *.o