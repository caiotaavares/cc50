
// Credit-card program

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	long long card_number, numbers;
	 card_number = numbers = 0;

	int  count, j, k, i;

	card_number = 0;
	count = 0;
	j = k = 0;
	i = 0;

	//ask to user the card number.
	printf("Whats the card number?: ");
	card_number = GetLongLong();

	//if the card number is invalid, as again.
	while(card_number <= 0)
		{
		printf("Sorry, whats the card number?: ");
		card_number = GetLongLong();

		}
	numbers = card_number;

	//count the number of digits on the card.
	while(numbers > 0)
		{
		numbers = numbers / 10;
		count ++;
		}

	//Shows INVALID if the card is not 13, 15 or 16 digits.
	if((count != 13) && (count != 15) && (count != 16))
		{
		printf("INVALID\n");
		}

	int nums[count];

	//use cycle for to go throught the card numbers, and save on nums[i]
	for(i = 0; i < count; i++)
		{
		nums[i] = card_number % 10;
		card_number = card_number / 10;
		}


	int num_adjusted[count];

	//Adjust the card number position
	for(i = 1 ; i < count ; i++)
		{
		num_adjusted[i] = nums[i];
		}
	//mutiplies the nums[i] factors to 2
	for(i = 1 ; i < count ; i = (i + 2))
		{
		nums[i] = nums[i] * 2;
		}

	//check the validity and the result of the 13 digit cards
	if(count == 13)
		{


		for(i = 0 ; i < count ; i++)
			{
			k = ((nums[i] % 10) + (nums[i]/10 % 10));
			j = j + k;
			}

		//if the firts digit of the card is 4, and the final digit of Hans Peter Luhn algorithm is 0, whow VISA.
		if(num_adjusted[12] == 4 && j % 10 == 0)
			{
			printf("VISA\n");
			}

		else
		{
		printf("INVALID\n");
		}


	}

	//chech the validity and show the result of the 15 digit cards
	if(count == 15)
		{


		for(i = 0 ; i < count ; i++)
			{
			k = ((nums[i] % 10) + (nums[i]/10 % 10));
			j = j + k;
			}

		//if the card number start with 34 or 35, and the final digit of the Hans Peter Luhn algorithm is 0,show AMERINCAN EXPRESS (AMEX).
		if((num_adjusted[14] == 3 && j % 10 ==0) && (num_adjusted[13] == 4 || num_adjusted[13] == 7))
			{
			printf("AMERICAN EXPRESS\n");
			}

		else
			{
			printf("INVALID\n");
			}
		}

	//check the validity and show the result of the 16 digit cards
	if(count == 16)
		{


		for(i = 0; i < count ; i++)
			{
			k = ((nums[i] % 10) + (nums[i]/10 % 10));
			j = j + k;
			}
		//if the card number start with 4, and the last nuber of the Hans Peter Luhn algorithm is 0, show VISA 
		if((num_adjusted[15] == 4 && j % 10 == 0))
			{
			printf("VISA\n");
			}
		//if the card number start with 51, 52, 53, 54, or 55, and the final number of Hans Peter Luhn algorithm is 0, show MASTERCARD
		else if((num_adjusted[15] == 5 && j % 10 == 0) && (num_adjusted[14] == 1 || num_adjusted[14] == 2 || num_adjusted[14] == 3 || num_adjusted[14] == 4 || num_adjusted[14] == 5))
			{
			printf("MASTERCARD\n");
			}

		else
			{
			printf("INVALID\n");
			}

		}
}
