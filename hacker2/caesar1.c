
//Caesar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//for use strlen
#include <cc50.h>	//for use the cc50 comands
#include <ctype.h>

int n;

int
main(int argc, string argv[])
{
	//get the key in the program call
	if (argc != 2 || atoi(argv[1]) < 0)
	{
		printf("it's whrong\n");
		return 1;
	}

	int key = atoi(argv[1]);
//	printf("Get the key:");
	string caesar_text;
	caesar_text = GetString();

	for (int i = 0 , n = strlen(caesar_text) ; n < i ; i++)
	{
		if (caesar_text[i] >= 'A' && caesar_text[i] <= 'Z')
		{
			caesar_text[i] = (caesar_text[i] - 'A' + key) % 26 + 'A';
		}
	}

	for (int i = 0 , n = strlen(caesar_text) ; n < i ; i++)
	{
		if (caesar_text[i] >= 'A' && caesar_text[i] <= 'Z')
		{
			caesar_text[i] = (caesar_text[i] - 'A' + key) % 26 + 'A';
		}
		else if (caesar_text[i] >= 'a' && caesar_text[i] <= 'z')
		{
			caesar_text[i] = (caesar_text[i] - 'a' + key) % 26 + 'a';
		}
		else
		{
			printf("%c \n", caesar_text[i]);
		}
	}
	return 0;
}
