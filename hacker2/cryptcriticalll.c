#include <stdio.h>
#include <cc50.h>
#include <crypt.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int main(int argc, string argv[])
{
//verifica se o código tem necessáriamente dois argumentos
if(argc != 2)
{
    printf("Enter the hash code as a single argument\n");
    return 1;
}
//pergunta para o usuário o valor do salt
string salt = GetString("Imput the salt\n");

//armazena em key, todas as letras do alfabeto em caixa alta e baixa
string key[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Y", "Z", "a",
    "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "x", "y", "z"
};

char temp [40];
//cria uma string hash que recebe a string argv[1]
string hash = strcpy(temp, argv[1]);

	//começa um ciclo for para criptografar a key e o salt
    for(int i=0; i<18; i++)
    {	//usa a função crypt para criar o hash de key e salt
        string cypher = crypt(key[i], salt);

	//compara cypher e o hash do usuário (argumento 1)
        int comp = strcmp(cypher, hash);

	//se a comparação for falsa imprime o valor de key
        if(comp == 0)
        {
            printf("%s\n", key[i]);
            break;
        }

    }
	//gera aleatóriamente um conjunto i e j
    char char_2[7500];
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            sprintf(char_2, "%s%s", key[i], key[j]);
		//cria uma var m para criptografar char_2 e salt
            for(int m = 0; m < strlen(char_2); m++)
            {
                string cypher = crypt(char_2[m], salt);
		//se hash for difente do hash encontrado imprime o valor de key e encerra o programa
                int comp = strcmp(cypher, hash);
                if(comp == 0)
                    {
                        printf("%s\n", key[i]);
                        break;
                    }
            }

        }
