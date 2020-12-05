#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);

    int coins = 0;
    int change_owed = cents;
    while (change_owed >= 25)
    {
        coins = coins + 1;
        change_owed = change_owed - 25;
    }
    while (change_owed >= 10)
    {
        coins = coins + 1;
        change_owed = change_owed - 10;
    }
    while (change_owed >= 5)
    {
        coins = coins + 1;
        change_owed = change_owed - 5;
    }
    while (change_owed >= 1)
    {
        coins = coins + 1;
        change_owed = change_owed - 1;
    }

    printf("%i", coins);
}