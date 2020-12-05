#include <stdio.h>
#include <cs50.h>

int count(int n);

int main(void)
{
    long num = get_long("Number: ");
    long number = num;
    int cnt = 0;

    while (num != 0)
    {
        num /= 10;
        ++cnt;
    }

    num = number;

    if (cnt >= 13 && cnt <= 16)
    {
        int j = 0;
        int k = 0;
        int array[(cnt / 2) + 1];
        int arr[cnt / 2];
        for (int i = 0; i < cnt / 2; i++)
        {
            while (num > 0)
            {
                num /= 10;
                arr[j] = (num % 10) * 2;
                num /= 10;
                j++;
            }
        }

        num = number;
        int sum1 = 0;

        for (int i = 0; i < (cnt / 2) + 1; i++)
        {
            while (num > 0)
            {
                array[k] = num % 10;
                num = num / 100;
                sum1 += array[k];
                k++;
            }
        }

        int m = 0;
        int n = 0;
        int sum = 0;
        for (int i = 0; i < cnt / 2; i++)
        {
            while (arr[i] > 0)
            {
                m = arr[i] % 10;
                sum = sum + m;
                arr[i] /= 10;
            }
        }

        sum = sum + sum1;
        num = number;
        if (sum % 10 == 0)
        {
            while (num > 10)
            {
                num = num / 10;
            }

            while (number > 100)
            {
                number /= 10;
            }
            if (num == 4)
            {
                printf("VISA\n");
            }
            else if (number == 34 || number == 37)
            {
                printf("AMEX\n");
            }
            else if (number == 51 || number == 52 || number == 53 || number == 54 || number == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


