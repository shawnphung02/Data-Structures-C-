CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

all: run

clean:
	rm -f *.o run

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o

matrix_main.o: matrix_main.c matrix.h
	$(CC) $(CFLAGS) -c matrix_main.c -o matrix_main.o

run: matrix_main.o
	$(CC) $(CFLAGS) matrix_main.o -o run