//	primes.c
//	Reseni IJC-DU1, priklad a), 14.3.2017
//	Autor: Jan Kala, FIT
//	Prelozeno: gcc 5.4.0 (Ubuntu 5.4.0-6ubuntu1~16.04.4)
//	
//	Program pro vypsani poslednich PRINT prvocisel z celkoveho postu N cisel
//	K nalezeni prvocisel pouziva Eratostenovo sito.

#include <stdio.h>
#include "bit_array.h"
#include "eratosthenes.h"

#define N 303000000
#define PRINT 10

int main(){
	unsigned long i; 
	int count=PRINT-1;
	unsigned long lastNumbers[PRINT]={0};

	ba_create(array,N);

	Eratosthenes(array);

	for (i = N; count >= 0; i--){
		if(ba_get_bit(array,i)==0){
			lastNumbers[count]=i;
			count--;
		}
	}

	for (i = 0; i < PRINT; ++i)
	{
		printf("%lu\n",lastNumbers[i]);
	}

	return 0;
}