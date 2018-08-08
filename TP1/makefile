CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -std=c99 -pedantic
OBJ = main.c graphMatrix.c queue.c maximumFlow.c
DEPS = graphMatrix.h queue.h maximumFlow.h
VFLAGS =

EXEC = ./tp1 < big_4
all: tp1

tp1: $(OBJ)
	$(CC) $(CFLAGS) -lm $^ -o $@ 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

exec: 
	$(EXEC)

clean:
	rm -f *.o tp1

valgrind:
	valgrind $(VFLAGS) $(EXEC)

time:
	time $(EXEC)

testeSaida:
	$(CC) $(CFLAGS) compsaidas.c -o testeSaida