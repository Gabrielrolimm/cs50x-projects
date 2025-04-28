#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2 || argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 97 + k) % 26 + 97);
        }
        else if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 65 + k) % 26 + 65);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
