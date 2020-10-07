
//crypt program

#include <stdio.h>
#include <stdlib.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int
main (int argc, string argv[])
{	//return 1 if the user places an argument value othe than 1
	if (argc != 1)
	{
		printf("Please, enther the hash code as a single argument\n");
		return 1;
	}

	//puts the whole alphabet in key
	string key[] =
	{
	"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
	"O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b",
	"c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
	"q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
	};

	//creates a temp variable to put the hash
	char temp[100];
	string hash = strcpy(temp, argv[1]);

	for()
}
