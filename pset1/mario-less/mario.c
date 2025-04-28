#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int x;
    do
    {
        x = get_int("?");
    }
    while (x < 1 || x > 8);
    for (int y = 0; y < x; y++)
    {
        for (int z = 0; z < x - y - 1; z++)
        {
            printf(" ");
        }
        for (int i = 0; i <= y; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z <= y; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
