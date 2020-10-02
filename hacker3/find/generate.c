/***************************************************************************
 * generate.c
 *
 * CC50
 * Pset 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "helpers.c"
#define LIMIT 65536

int
main(int argc, char *argv[])
{
    	// check if the number of argments its correct
    	if (argc != 2 && argc != 3)
    	{
        	printf("Usage: %s n [s]\n", argv[0]);
        	return 1;
    	}

    	// n receive the value of argument number 1
    	int n = atoi(argv[1]);

    	// uses the argument 2 with seed to rand numbers
    	if (argc == 3)
        	srand((unsigned int) atoi(argv[2]));
    	else
        	srand((unsigned int) time(NULL));

    	// divides the randon number to limit and show the result
	int vet[100];
	int i;
	for (i = 0; i < n; i++)
	{
		vet[i] = rand() % LIMIT;
        	printf("%d\n", vet[i]);
	}

	sort(vet, n);

	// organizing the random numbers in ascending order
	int l;
                for (l = 0; l < n; l ++)
                {
                        printf("%d, ", vet[l]);
                }
         printf("\n");

    	// that's all folks
    return 0;
}
