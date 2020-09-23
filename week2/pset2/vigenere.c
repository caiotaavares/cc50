
//vigenere code

#include <cc50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main(int argc, string argv[])
{
	//stop the program with the number of arguments on string is different from two
	if (argc != 2)
	{
		printf ("The number of argments it's invalid, remember to use only ./vigenere key\n");
		//finish the program with a error
		return 1;
	}

	string k = argv[1];
	//show the number of characters of the strinf on a int
	int lenk = strlen(k);
	//verify if the all key characters are alphabetic
	for (int i = 0 ; i < lenk ; i ++)
	{
		if (!isalpha(k[i]))
		{
			printf ("remember to use only alphabetic characters in key\n");
			//if somebody character of key not is alphabetic, finish the program with error
			return 1;
		}
	}

	printf ("Please, whrite the text if you want to encrypt: ");
	//asks the code to  be encrypted with the user
	string plaintext = GetString();
	printf ("ciphertext: ");
	//start the process of encription
	for (int i = 0, index = 0, l = strlen(plaintext) ; i < l ; i ++)
	{
		//encript the alphabetic characters
		if (isalpha(plaintext[i]))
		{
			//crypt the lowercase character
			if (islower(plaintext[i]))
				printf ("%c", (plaintext[i] - 97 + toupper(k[index]) - 65) % 26 + 97);
			//crypt the uppercase character
			else if (isupper(plaintext[i]))
				printf ("%c", (plaintext[i] - 65 + toupper(k[index]) - 65) % 26 + 65);
			index = (index + 1) % lenk;
		}
		//if the character not is alphabetic, only show it
		else
			printf ("%c", plaintext[i]);
	}
	printf ("\n");
return 0;
}
