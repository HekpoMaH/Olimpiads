// hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <time.h>

typedef unsigned long uint32_t;
typedef unsigned char uint8_t;
typedef signed long int32_t;

/* Fowler / Noll / Vo (FNV) Hash */
#define FNV_32_PRIME ((uint32_t)0x01000193)

/* ======================================================================== 
 * http://en.wikipedia.org/wiki/Hash_table
 * http://en.wikipedia.org/wiki/Hash_function
 * http://burtleburtle.net/bob/hash/doobs.html
 * http://www.isthe.com/chongo/tech/comp/fnv/
 * http://www.cse.yorku.ca/~oz/hash.html
 * 
 ========================================================================== */


uint32_t
badhash(const char *str, int len)
{
	unsigned int hash = 0;
	int c=0;

	while (c<len)
	{
		hash += str[c];
		c++;
	}

	return hash;
}

/* input string length must be multiply of 4 */
uint32_t FNVHash(char *str, int len)
{
	uint32_t hval=2166136261;
	int pos=0;
	unsigned char *s = (unsigned char *)str;	/* unsigned string */

	/*
	* FNV-1 hash each octet in the buffer
	*/
	while (pos<len) {

		/* multiply by the 32 bit FNV magic prime mod 2^32 */
		hval *= FNV_32_PRIME;
		/* xor the bottom with the current octet */
		hval ^= (uint32_t)*s++;
		pos+=4;
	}

	/* return our new hash value */
	return hval;
}


/* ======================================================================== */

uint32_t oneAtATimeHash (const char * s, int len) {
	int32_t hash;
	int i;

	for (hash = 0, i = 0; i < len; i++) {
		hash += s[i];
		hash += (hash << 10);
		hash ^= (hash >>  6);	/* Non-portable due to ANSI C */
	}
	hash += (hash <<  3);
	hash ^= (hash >> 11);		/* Non-portable due to ANSI C */
	hash += (hash << 15);
	return (uint32_t) hash;
} 


/* ======================================================================== */
uint32_t
djb(const char *str, int len)
{
	unsigned long hash = 5381;
	int c=0;

	while (c<len)
	{
		hash = ((hash << 5) + hash) + str[c]; /*((hash << 5) + hash)*/
		c++;
	}

	return hash;
}

/* ======================================================================== */
uint32_t
sdbm(const char* str, int len)
{
	unsigned long hash = 0;
	int c=0;

	while (c<len)
	{
		hash = str[c] + (hash << 6) + (hash << 16) - hash;
		c++;
	}

	return hash;
}


/* ======================================================================== */

typedef uint32_t (* hashFn) (const char * s, int len);

#define BUFF_SZ (128*2)
#define NTESTS 1000000L

double test (hashFn hash) {
	static char buff[BUFF_SZ];
	clock_t c0, c1;
	int32_t i;

	for (buff[0]=0, i=1; i < BUFF_SZ; i++) buff[i] = (char) (i + buff[i-1]);

	c0 = clock ();
	for (i=0; i < NTESTS; i++) hash (buff, BUFF_SZ);
	c1 = clock ();
	return (c1 - c0)*(1.0 / (double)CLOCKS_PER_SEC);
}

struct tagtest {
	double res;
	char * name;
	hashFn hash;
} tests[] = {

	{ 0.0, "oneAtATimeHash\t", oneAtATimeHash	},
	{ 0.0, "djb\t", djb							},
	{ 0.0, "sdbm\t", sdbm						},
	{ 0.0, "badhash\t", badhash},
	{ 0.0, "FNVHash\t\t", FNVHash				},
	{ 0.0, NULL, NULL                           }
};



int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;

	for (j=0; tests[j].name != NULL; j++) {
		for (i=0; i < 3; i++) {
			double res = test (tests[j].hash);
			if (tests[j].res == 0.0 || tests[j].res > res) tests[j].res = res;
		}
		printf ("%s:%8.4fs\n", tests[j].name, tests[j].res);
	}

	return 0;
}