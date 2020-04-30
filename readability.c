//CS50 Problem Set 2, 2020: Readability
//Author: ArkadiiMV
//Perhaps, not up to the point, but it has passed check50 at least :-)) 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
//the function counts letters, words und sentences
int letters_count(string someText, int length, int *iColemanLiau);

int main(void)
{
//declaring array for indices
    int iColemanLiau[3];
    iColemanLiau[0] = 0; //letters
    iColemanLiau[1] = 0; //words
    iColemanLiau[2] = 0;// sentences

    float iResult = 0;

    string sUserInput = get_string("Text: ");
    letters_count(sUserInput, 3, iColemanLiau);

    iResult = (0.0588 * (float) iColemanLiau[0] * 100 / (float) iColemanLiau[1]) - (0.296 * (float) iColemanLiau[2] * 100 /
              (float) iColemanLiau[1]) - 15.8;


    if (iResult < 16 && iResult >= 0)
    {
        printf("Grade %i\n", (int) round(iResult));
    }
    else if (iResult >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
 
}

//the function counts letters, words and sentences *******************************
int letters_count(string someText, int length, int *iColemanLiau)
{
    int iLetters = 0; //for letters
    int iSpaces = 1; // for words (spaces+1)
    int iSentences = 0; //for sentences indeed

//cycle for counting letters
    for (int i = 0, k = strlen(someText); i < k; i++)
    {
// sorting out letters & digits
        if ((someText[i] >= 'A' && someText[i] <= 'Z') || (someText[i] >= 'a' && someText[i] <= 'z') || (someText[i] >= '0' 
                && someText[i] <= '9'))
        {
            ++iLetters;
        }
        // sorting out spaces
        else if (someText[i] == 32)
        {
            ++iSpaces;
        } //and punctuation
        else if (someText[i] == '.' || someText[i] == '!' || someText[i] == '?')
        {
            ++iSentences;
        }

    }
    iColemanLiau[0] = iLetters;
    iColemanLiau[1] = iSpaces;
    iColemanLiau[2] = iSentences;
  
    return 0;
}
//end of letter_count function  *******************************
