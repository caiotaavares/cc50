/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cc50.h>

#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int array[], int n)
{
	//value == number with i want search,
	//array[] == elements that contain value
	//n == number os values
    	// TODO: re-implement as binary search
	if (value < 0)
	{
		printf("Value invalid\n");
		return 1;
	}
	int min_num = 0, max_num = n - 1;

	while (n > 0)
	{
		int half_num = (max_num - min_num) / 2 + min_num;

		if (array[half_num] == value)
		{
			printf("Value searched\n");
			return true;
		}

		else if (array[half_num] > value)
		{
			max_num = half_num - 1;
		}

		else if (array[half_num] < value)
		{
			min_num = half_num + 1;
		}

		n = max_num - min_num + 1;
	}
    	return 0;
}


/*
 * Sorts array of n values.
 */

void 
sort(int values[], int n)
{
    // TODO: implement an O(n^2) sort
	//BUBBLE
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j ++)
			if (values[j + 1] < values[j])
			{
				//swap
				int temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
    	return;

	int l;
        	for (l = 0; l < n; l ++)
        	{
                	printf("%d", values[l]);
        	}
       	 printf("\n");

}

