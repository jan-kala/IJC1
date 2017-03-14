//	eratosthenes.c
//	Reseni IJC-DU1, priklad a), 14.3.2017
//	Autor: Jan Kala, FIT
//	Prelozeno: gcc 5.4.0 (Ubuntu 5.4.0-6ubuntu1~16.04.4)
//	
//	Ertosthenovo sito. Funguje tak, ze projizdi pole od 2.pozice (0 a 1 nejsou prvocisla,
//	cislo 2 ale uz ano) a z bitoveho pole "vyjednickuje" vsechny nasobky prvocisla.
//	Pote postupuje dal dokud nenajde dalsi prvocislo (hodnota bitu==0) a znovu vyjednickuje vsechnz jeho nasobky.
//	Takto projde celym polem
//	
#include <stdio.h>
#include <math.h>
#include "bit_array.h"
#include "eratosthenes.h"

void Eratosthenes(bit_array_t array){
	unsigned long i,j;

	for (i = 2; i <= sqrt(ba_size(array)); ++i){
		if ((ba_get_bit(array,i)) == 0){
			for (j = i*2; j < array[0]; j+=i)
			{
				ba_set_bit(array,j,1);
			}
		}
	}
}