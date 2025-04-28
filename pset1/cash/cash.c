#include <cs50.h>
#include <stdio.h>
int getcent(void);
int calquarter(int cents);
int caldime(int cents);
int calnickel(int cents);
int calpenny(int cents);
int main(void)
{
    // change owned in cents
    int cents = getcent();
    // calculate the quarters
    int quarter = calquarter(cents);
    cents = cents - quarter * 25;
    // calculate dime
    int dime = caldime(cents);
    cents = cents - dime * 10;
    // calculate nickel
    int nickel = calnickel(cents);
    cents = cents - nickel * 5;
    // calculate penny
    int penny = calpenny(cents);
    cents = cents - penny * 1;
    // sum coins
    int coins = quarter + dime + nickel + penny;
    // print number of coins
    printf("quarters: %i\n", quarter);
    printf("dimes: %i\n", dime);
    printf("nickels: %i\n", nickel);
    printf("pennies: %i\n", penny);
    printf("total coins: %i\n", coins);
}
int getcent(void)
{
    int cents;
    do
    {
        cents = get_int("change owned? ");
    }
    while (cents < 0);
    return cents;
}
int calquarter(int cents)
{
    int quarter = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarter++;
    }
    return quarter;
}
int caldime(int cents)
{
    int dime = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dime++;
    }
    return dime;
}
int calnickel(int cents)
{
    int nickel = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickel++;
    }
    return nickel;
}
int calpenny(int cents)
{
    int penny = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        penny++;
    }
    return penny;
}
