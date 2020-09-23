
//Caesar code

#include <cc50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
main (int argc, string argv[])
{	//execute the program with the number of args its 2
	if (argc == 2)
	{
		string k = argv[1];
		int l = strlen(k);
		for (int i = 0 ; i < l ; i++)
		{
			//verify if the key is an alphabet character
			if (isalpha(k[i]) != 0)
			{
				printf("Remember to use only numeric characters in key\n");
				printf("Please, whrite the key again:  ");
				k = GetString();
			}
		}
		int key = atoi(k);
		//watch to user the name of .txt archive
		FILE *file;
		printf("Whats the file name?: ");
		string fileName = GetString();
		file = fopen(fileName, "r");
		//veriy with the .txt archive it's valid
		if(file == NULL)
		{
			printf("The file could  not be opened\n");
			exit (0);
		}

		char text[1000];
		string str;
		//places the arguments of the .txt archive in the plain_text variable
		while(fgets(text, 1000, file) != NULL)
			str = text;

		string plain_text = str;

		//turn the text in ascii
		for(int i = 0, len = strlen(plain_text); i < len ; i++ )
		{
			char cha = plain_text[i];
			if(isalpha(cha))
			{
				char n = 'A';
				if(islower(cha))
				{
					n = 'a';
				}
			printf("%c", (cha - n + key) % 26 + n);

			}
			else
				printf("%c", cha);
		}
		printf("\n");
	}
	//if the number of arguments not it's 2, return the program
	else
	{
		printf("Something it's whrong\n");
		return 1;
	}
}
