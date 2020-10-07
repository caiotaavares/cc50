#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	//Seed of PRNG, make rand() seed don't repeat
	srand(time(NULL));

	//choose the pseudo-random number in [0,1023]
	int skittles = rand() % 1024;
	int user_number;
	//ask the user to guess the number
	printf("Enter as many skittles as you think have here and i'll helo you get the right amount!\n\n");

	for(;;)
	{
		scanf(" %d", &user_number);
		//compare user_numer and skittles
		if(user_number == skittles)
		{
			printf ("Congratulations, you're right!\n");
			//if user_number =skittles, break the program
			break;
		}
		else if (user_number != skittles)
		{
			//help the user to get the right amount
			if (user_number > skittles)
			{
				printf("try a lower value:\n");
			}
			if (user_number < skittles)
			{
				printf("Try a higher value:\n");
			}
		}
	}
	printf("Tank you, end of program\n");
	return(0);

}
