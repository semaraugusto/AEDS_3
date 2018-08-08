CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -std=c99 -pedantic
OBJ = main.c dynamic.c quicksort.c bruteForce.c greedy.c list.c
DEPS =	dynamic.h, quicksort.h bruteForce.h greedy.h list.h
VFLAGS =

EXEC = ./tp3 < big_toys_09.txt
all: tp3

tp3: $(OBJ)
	$(CC) $(CFLAGS) -lm $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

exec:
	$(EXEC)

clean:
	rm -f *.o tp3

valgrind:
	valgrind $(VFLAGS) $(EXEC)

time:
	time $(EXEC)

testeSaida:
	$(CC) $(CFLAGS) compsaidas.c -o testeSaida
