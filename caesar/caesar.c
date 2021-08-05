#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


//Get the key
int main(int argc, string argv[])
{
    int i, len, key;


    if (argc == 2)
    {
      for (i = 0, len = strlen(argv[1]); i < len; i++)
      {
          if (isdigit(argv[1][i]))
       {
        key = atoi(argv[1]);
            }
            else
            {
            printf("Usage: ./caesar key\n");
            return 1;
            }

        }
        //printf("Success\n");
        //printf("%i\n", key);

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//Get plaintext

    string code = get_string("plaintext: ");

//Encipher

    printf("ciphertext: ");

    char c;
    for (i = 0, len = strlen(code); i < len; i++)
    {
        if isupper(code[i])
        {
            printf("%c", ((code[i] + key - 65) % 26) + 65);
        }
        else if islower(code[i])
        {

            printf("%c", ((code[i] + key - 97) % 26) + 97);
        }
        else
        {
            printf("%c", code[i]);
        }

    }
//Print ciphertext
    printf("\n");
    return 0;

}

