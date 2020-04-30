//CS50 Problem Set 1, 2020: Cash
//Author: ArkadiiMV
#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_float_restricted(string prompt);

int main(void)
{
//just to initialize the variable that holds the result i.e.
//the final quantity of the coins
    int iCoins = 0;    
    //Здесь получаем сумму с форматированным выводом на экран
    float fInput = get_float_restricted("How much change is owed? ");
//printf("Float number: %.2f\n", fInput);  
//округляем до целого сдачу, которую мы должны покупателю
//получаем величину сдачи ы центах, которую надо обрабатывать
// здесь надо будет отрезать числа больше 2 147 483 648 (оверфлов)
// iSum - сумма сдачи в виде целого числа
    int iSum = round(fInput * 100);
//printf("Целое число: %i\n",iSum);

//начинаем обработку инпута юзера, стартуем с монет 0,25
//Определяем количество 25 центовых монет
    for (iCoins = 0; iSum >= 25; iCoins++) 
    {
        iSum -= 25;
    }
//теперь количество уже набранных .25 содержится в переменной iCoins
//остаток суммы, на который мы должны набрать .10 монеты находится в iSum
// считаем .10 монеты
    for (; iSum >= 10 ; iCoins++) 
    {
        iSum -= 10;
    }
//теперь количество уже набранных .25 .10 и .5 содержится в переменной iCoins
//остаток суммы, на который мы должны набрать .05 монеты находится в iSum
// считаем .05 монеты
    for (; iSum >= 5; iCoins++) 
    {
        iSum -= 5;
    }

//теперь количество уже набранных .25 .10 и .5 и .1 содержится в переменной iCoins
//остаток суммы, на который мы должны набрать .01 монеты находится в iSum
// считаем .01 монеты
    for (; iSum >= 1 ; iCoins++) 
    {
        iSum -= 1;
    }

// printing out the quantity of 25, 10 and 5 cents coins
    printf("We need coins: %i,\n Remainder is %i cents\n", iCoins, iSum);
}






// Prompt user for required input
float get_float_restricted(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);
    }
    while (n <= 0);
    return n;
}
