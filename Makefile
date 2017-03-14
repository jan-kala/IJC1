
CC=gcc

CFLAGS=-g -std=c99 -pedantic -Wall -Wextra

all: primes primes-i

primes: eratosthenes.o primes.o
	$(CC) $(CFLAGS) eratosthenes.o primes.o -lm -o primes
eratosthenes.o: bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -c eratosthenes.c -lm -o eratosthenes.o
primes.o: bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -c primes.c -o primes.o

primes-i: eratosthenes-i.o primes-i.o
	$(CC) $(CFLAGS) primes-i.o eratosthenes-i.o -lm -o primes-i
eratosthenes-i.o: bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -c eratosthenes.c -DUSE_INLINE -o eratosthenes-i.o
primes-i.o: bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -c primes.c -DUSE_INLINE -o primes-i.o


.PHONY:
	clean

clean:
	rm -f *.o

run:
	time ./primes
	time ./primes-i