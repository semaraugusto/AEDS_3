CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Werror -std=c99 -pedantic
OBJ = main.c stack.c reverse_polish.c
DEPS = stack.h reverse_polish.h
VFLAGS =

EXEC = ./tp0
all: tp0

tp0: $(OBJ)
	$(CC) $(CFLAGS) -lm $^ -o $@ 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

exec: 
	$(EXEC)

clean:
	rm -f *.o tp0

valgrind:
	valgrind $(VFLAGS) $(EXEC)

time:
	time $(EXEC)

testeSaida:
	$(CC) $(CFLAGS) compsaidas.c -o testeSaida