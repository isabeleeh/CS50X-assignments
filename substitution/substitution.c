#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //exit if no or more than one command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY.\n");
        return 1;
    }
    //exit if length of the second command-line argument is not 26
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //exit if key contains non-alphabetic character
    for (int i = 0; i < 26; i++)
    {
        if ((islower(argv[1][i]) || isupper(argv[1][i])) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    //exit if there is duplicated characters
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    //ask for plaintext
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int length = strlen(plaintext);
    //substitute, case-sensitive
    for (int i = 0; i < length; i++)
    {
        int index = 0;
        if (islower(plaintext[i]))
        {
            index = plaintext[i] - 97;
            ciphertext[i] = tolower(argv[1][index]);
        }
        else if (isupper(plaintext[i]))
        {
            index = plaintext[i] - 65;
            ciphertext[i] = toupper(argv[1][index]);
        }
    }

    printf("ciphertext: %s\n", ciphertext);

}