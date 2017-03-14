#
# Subor:       makefile
# Datum:       24.03.2014
# Autor:       Martin Hučko, xhucko00@stud.fit.vutbr.cz (FIT VUT)
# Projekt:     IJC-DU1 a)
# Prekladac:   gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
# Popis:       Makefile pre IJC-DU1
#

# Prekladac
CC=gcc

# Parametre prekladu
CFLAGS=-O2 -std=c99 -Wall -Wextra -pedantic -lm

# Vytvori vsetky potrebne subory
all: primes primes-i

# Zavislosti pre program primes
primes: primes.o eratosthenes.o
	$(CC) $(CFLAGS) primes.o eratosthenes.o -lm -o $@
primes.o: primes.c bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -c primes.c -o $@
eratosthenes.o: eratosthenes.c bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o $@

# Zavislosti pre inline verziu programu primes
primes-i: primes-i.o eratosthenes-i.o
	$(CC) $(CFLAGS) primes-i.o eratosthenes-i.o -lm -o $@
primes-i.o: primes.c bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o $@
eratosthenes-i.o: eratosthenes.c bit_array.h eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o $@

.PHONY:
	clean clean-all

# Odstrani vygenerovane objekty
clean:
	rm -f *.o

# Odstrani vygenerovane objekty a subory
clean-all:
	rm -f *.o primes 