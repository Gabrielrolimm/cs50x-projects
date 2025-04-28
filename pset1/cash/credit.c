#include <cs50.h>
#include <math.h>
#include <stdio.h>
int calculate_check_sum(long cardnumber);
int digit_amount(long cardnumber);
int multiply_sum(int last_digit);
bool isAmex(long cardnumber, int digiti_quantity);
bool isMaster(long cardnumber, int digit_quantity);
bool isVisa(long cardnumber, int digit_quantity);
int main(void)
{
    long cardnumber = get_long("card number: ");
    int check_sum = calculate_check_sum(cardnumber);
    int digit_quantity = digit_amount(cardnumber);
    bool amex = isAmex(cardnumber, digit_quantity);
    bool master = isMaster(cardnumber, digit_quantity);
    bool visa = isVisa(cardnumber, digit_quantity);
    if (check_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
int calculate_check_sum(long cardnumber)
{
    int sum1 = 0;
    int sum2 = 0;
    bool alternate_digit = false;
    while (cardnumber >= 1)
    {
        if (alternate_digit == false)
        {
            int another_digit = cardnumber % 10;
            sum2 = sum2 + another_digit;
        }
        if (alternate_digit == true)
        {
            int last_digit = cardnumber % 10;
            int product = multiply_sum(last_digit);
            sum1 = sum1 + product;
        }
        cardnumber = cardnumber / 10;
        alternate_digit = !alternate_digit;
    }
    int sumtotal = sum1 + sum2;
    return sumtotal;
}
int multiply_sum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int digit_separate = multiply % 10;
        sum = sum + digit_separate;
        multiply = multiply / 10;
    }
    return sum;
}
int digit_amount(long cardnumber)
{
    int amount = 0;
    while (cardnumber >= 1)
    {
        cardnumber = cardnumber / 10;
        amount++;
    }
    return amount;
}
bool isAmex(long cardnumber, int digit_quantity)
{
    int first_digits = cardnumber / pow(10, (digit_quantity - 2));
    if ((digit_quantity == 15) && (first_digits == 34 || first_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isMaster(long cardnumber, int digit_quantity)
{
    int first_digits = cardnumber / pow(10, (digit_quantity - 2));
    if ((digit_quantity == 16) && (first_digits > 50 && first_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isVisa(long cardnumber, int digit_quantity)
{
    int first_digits = cardnumber / pow(10, (digit_quantity - 1));
    if ((digit_quantity == 13 || digit_quantity == 16) && (first_digits == 4))
    {
        return true;
    }
    else
    {
        return false;
    }
}
