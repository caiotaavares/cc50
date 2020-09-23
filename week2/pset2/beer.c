
//beer program

#include <stdio.h>
#include <stdlib.h>
#include <cc50.h>
#include <string.h>

int
main(void)
{
	//ask how many bottles of beer have in the wall
	printf("how many bottles of beer are on the wall?: ");
	int beer_bottles = GetInt();

	if (beer_bottles < 1)
	{
		printf("number of bottles invalid");
		return 1;
	}
	//start the music
	//performs the calculation while the number of bottles is less than 2
	printf("\n");

	/*
	while (beer_bottles)
		chorus(beer_bottles);
	*/

	while (beer_bottles > 0)
	{
		/*
		if (beer_bottles == 1)
			s1 = "bottle";
		else
			s1 = "bottles";
		*/

		//change the string between bottle and bottles, according to the number of bottles
		string s1 = (beer_bottles == 1) ? "bottle": "bottles";
		string s2 = (beer_bottles == 2) ? "bottle": "bottles";

		//the bottles on the wall receive the amount of bottles -  1 bottle
		printf("%i %s of beer on the wall,", beer_bottles, s1);
		printf("i drink one, thow on the trash,");
		prþintf("%i %s of beer on the wall...\n", -- beer_bottles, s2);
		//beer_bottles -= 1;
	}

	/*
	if(beer_bottles == 2)
	{
		printf("2 bottles of beer on the wall,");
                printf(" i drink one, thow on the trash,");
                printf(" 1 bottle on the wall...\n");
		beer_bottles --;
	}
	if(beer_bottles == 1)
	{
		printf("1 bottle of beer on the wall,");
                printf(" i drink one, thow on the trash,");
                printf(" any bottle on the wall...\n");
	}
	*/

	//finish the program
	return 0;
}
