//CS50 Problem Set 2, 2020: Caesar
//Author: ArkadiiMV
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int get_ciphertext(string splaintext, int iKey);

// starting the main module
int main(int argc, string argv[])
{
    //Check if users input 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Convert user input string to int
    int firstArg = atoi(argv[1]);

//sorting letters out
    for (int i = 0, j = strlen(argv[1]); i < j; i++) 
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //Letters out one more time
    if (firstArg == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //To sort out negative input, zero (useless) & text
    if (firstArg <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //plaintext input
        string plainText = get_string("plaintext: ");
        //output preparation
        printf("ciphertext: ");
        get_ciphertext(plainText, firstArg);
        printf("\n");
        return 0;
    }
}


// this function/procedure prints out our cyphertext ************
int get_ciphertext(string splaintext, int iKey)
{
//Just for kicks
    const int AASCII = 65;
    const int aASCII = 97;
    const int TWENTYSIX = 26;

// ok, let's cypher the user's message (plaintext)
    for (int i = 0, n = strlen(splaintext); i < n; i++)
    {

        switch (splaintext[i]) 
        {
//UPPERCASE LETTERS
            case 65 ... 90:
                printf("%c", (((splaintext[i] + iKey) - AASCII) % 26) + AASCII);
                break;
//LOWERCASE LETTER
            case 97 ... 122:
                printf("%c", (((splaintext[i] + iKey) - aASCII) % TWENTYSIX) + aASCII);
                break;
//ANYTHING ELSE
            default:
                printf("%c", splaintext[i]);
                break;
        }

    }
    return 0;
}
