# include <stdio.h>
# include <cc50.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        int l = strlen(key);
        for (int i = 0; i < l; i++)
        {
            // if key[i] is an alphabet character
            if (isalpha(key[i]) != 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        //change charater to number
        int k = atoi(argv[1]);

        //print Plaintext
        string plaintext  = get_string("Plaintext: ");

        int n = strlen(plaintext);

        char ciphertext[n];

        //declare plaintext in ASCII
        int nplaintext[n];

        //Change plaintext to ASCII
        for (int i = 0; i < n; i++)
        {
            nplaintext[i] = (int)plaintext[i];
        }

        //Declare ASCII for ciphertext which we name "plusplaintext"
        int plusnplaintext[n];

        for (int i = 0; i < n; i++)
        {
            //if Capital
            if ((nplaintext[i] < 91) && (nplaintext[i] > 64))
            {
                plusnplaintext[i] = 65 + ((nplaintext[i] + k) - 65) % 26 ;
            }

            //if Lowercase
            else if ((nplaintext[i] < 123) && (nplaintext[i] > 96))
            {
                plusnplaintext[i] = 97 + ((nplaintext[i] + k) - 97) % 26 ;
            }

            //if not character a -> z and A -> Z
            else
            {
                plusnplaintext[i] = nplaintext[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            ciphertext[i] = (char)plusnplaintext[i];
        }

        printf("ciphertext: %s\n", ciphertext);

    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
} 
