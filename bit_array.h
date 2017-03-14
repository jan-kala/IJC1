//	bit_array.h
//	Reseni IJC-DU1, priklad a), 10.3.2017
//	Autor: Jan Kala, FIT
//	Prelozeno: gcc 5.4.0 (Ubuntu 5.4.0-6ubuntu1~16.04.4)
//	
//	Hlavickovy soubor bit_array, ktery obsahuje zakladni makra pro praci 
//	s bitovym polem. Bitove pole je relozovano jako pole datovych typu unsigned
//	long, pricemz v nultem indexu pole je ulozena velikost. 
//	Pokud je definovan symbol USE_INLINE, jsou nahrazeny makra
//	stejnojmennymi inline funkcemi.

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

typedef unsigned long bit_array_t[];

/**
 * @brief      Vrati velikost pole, ktera je potrebna pro pozadovany pocet bitu
 *
 * @param      size  Velikost
 */
#define BitArraySize(size)	\
	(size % BITS_IN_UL==0)	\
	?(size / BITS_IN_UL +1)	\
	:(size / BITS_IN_UL +2)

/**
 * @brief      Vraci index bitu v polozce pole 
 *
 * @param      index  Pozadovany index bitu
 */
#define BIT_INDEX(index)\
	(index % BITS_IN_UL)

/**
 * @brief      Vraci index pole, ve kterem se nachazi pozadovany bit
 *
 * @param      index  Pozadovany index bitu
 */
#define ARRAY_INDEX(index)		\
	((index / BITS_IN_UL) + 1)

/**
 * @brief      Pocet bitu v unsigned longu
 */
#define BITS_IN_UL						\
	(CHAR_BIT * sizeof(unsigned long))

/**
 * @brief      Ziska hodnotu bitu z pozadovaneho indexu
 *
 * @param      array  Jmeno pole
 * @param      index  Index bitu
 * @param      expr   Vyraz
 */
#define BA_SET_BIT_(array,index,expr) 							\
	(expr==0) 													\
	?(array[ARRAY_INDEX(index)] &= ~(1L<<( BIT_INDEX(index) )))	\
	:(array[ARRAY_INDEX(index)] |=   1L<<( BIT_INDEX(index) ))		

/**
 * @brief      Nastavi bit na pozadovany vyraz
 *
 * @param      array  Jmeno pole
 * @param      index  Index bitu
 */
#define BA_GET_BIT_(array,index)						\
	(array[ARRAY_INDEX(index)] & 1L<<(BIT_INDEX(index)))\
	? (1)												\
	: (0)

/**
 * @brief      Vytvoreni binarniho pole. Nemuze byt predelano na inline funkci!
 * 
 *
 * @param      array  Jmeno bitoveho pole, ktere ma byt vytvoreno
 * @param      size   Veliksot pole
 */
#define ba_create(array,size) \
	unsigned long array[BitArraySize(size)]={size+1,0}

#ifndef USE_INLINE

/**
 * @brief      Vraci velikost binarniho pole
 *
 * @param      array  Jmeno bitoveho pole
 */
#define ba_size(array) \
	array[0]

/**
 * @brief      Nastavi pozadovany bit v poli na pozadovanou hodnotu, kontroluje mez pole
 *
 * @param      array  Jmeno bitoveho pole
 * @param      index  Index bitu, ktery bude zmenen
 * @param      expr   Vyraz, ktery bude nastaven na bit (1/0)
 */
#define ba_set_bit(array,index,expr)			\
	do{											\
		if(index > ba_size(array)){				\
			printf("EROOOOOOR");				\
		}										\
		else{									\
			BA_SET_BIT_(array,index,expr);		\
		}										\
	}while(0)


/**
 * @brief      Vraci hodnotu bitu z pozadovane pozice, kontroluje mez pole
 *
 * @param      array  Jmeno bitoveho pole
 * @param      index  Index bitu
 */
#define ba_get_bit(array,index)	\
	(array[0] < index)			\
	?(printf("ERROR ERROR"))	\
	:(BA_GET_BIT_(array,index))
	
#endif

// INLINE funkce, stejna funkcnost jako predchozi makra.

#ifdef USE_INLINE
/*
inline static void ba_create(bit_array_t array,unsigned long size){
	unsigned long array[BitArraySize(size)]={size+1,0};
}
*/
inline static unsigned long ba_size(bit_array_t array){
	return array[0];
}

inline static bool ba_set_bit(bit_array_t array,unsigned long index,int expr){
	if (index>array[0]){
		(printf("ERROR ERROR"));
		return false;
	}
	else{
		BA_SET_BIT_(array,index,expr);
		return true;
	}
}

inline static unsigned long ba_get_bit(bit_array_t array,unsigned long index){
	if (index>array[0]){
		(printf("ERROR ERROR"));
		return 2;
	}
	else{
		return BA_GET_BIT_(array,index);
	}
}

#endif

#endif