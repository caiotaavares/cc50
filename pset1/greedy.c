
//CS50 - greedy program

#include <cc50.h> 	//To use the cc50 function
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	//To use the round function

int main(void)
{
	//Make the variables that will be used
	int 	coin_25 = 25,
		coin_10 = 10,
		coin_05 = 05,
		coin_01 = 01,
		num_total_coin = 0;

	float	money_float = 0;

for(;;){
	//Determine the count variable, ask the user to enter the change value and round it
	float cont;
	printf("Hi, how mutch chenge is owed?: ");
	scanf(" %f", &money_float);
	int money_round = round(money_float * 100);

	//start the while function, to prevent negative values.
	while(money_round <= 0)
		{
		float money_float = 0;
		printf("Hi, how mutch change is owed?: ");
		scanf(" %f", &money_float);
		}

		//If the change owed is greather 25 cents, reduce 25  cents of the  value and add 1 coin t counter
	for(cont = money_round;cont >= coin_25;cont = (cont - coin_25))
		{
		money_round = money_round - coin_25;
		num_total_coin ++;
		}

		//If the change owed is greather 10 cents, reduce 10 cents of the value and add 1 coin to counter
	for(cont = money_round;cont >= coin_10;cont = (cont - coin_10))
		{
		money_round = money_round - coin_10;
		num_total_coin ++;
		}

		//If the change owed is greather 05 cents, reduce 05 cents of the value and add 1 coin to counter
	for(cont = money_round;cont >= coin_05;cont = (cont - coin_25))
		{
		money_round = money_round - coin_05;
		num_total_coin ++;
		}

		//If the  change owed is greather 01 cents, reduce 01 cents of the value and add 1 coin to counter
	for(cont = money_round;cont >= coin_01;cont = (cont - coin_01))
		{
		money_round = money_round - coin_01;
		num_total_coin ++;
		}
	//Print what was left the chenge owed
	printf(" %i of change owed\n", money_round);

	//Print the number of coins
	printf(" %i coins\n", num_total_coin);
	num_total_coin = 0;
	}
}

