//CS50 Problem Set 1, 2020: Mario_More
//Author: ArkadiiMV
#include <cs50.h>
#include <stdio.h>
int get_int_restricted(string prompt);

int main(void)
{
    int iDimension = get_int_restricted("Pls provide a positive int between 1 & 8, inclusive: ");

//****This code builds up the left side of Mario's pyramid********
    for (int i = 0; i < iDimension; i++)
    {
        for (int k = iDimension - i; k > 1; k = k - 1) 
        {         
            printf(" ");
        }  
      
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
//****** Here we insert two whitespaces that should fit in the middle ******
        printf("  ");
//******* We need a cycle to build up the right side of the pyramid *******
        int l = 0;
// ******* Let's do it with Do-while loop for a change ******************
        do 
        {
            printf("#");
            l++;
        } 
        while (l <= i);

//********** The Final Cut *********************
        printf("\n");
    }

}

// Prompt user for required input
int get_int_restricted(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n > 8 || n < 1);
    return n;
}
