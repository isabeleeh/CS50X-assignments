#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //ask for card number input. Later to enhance to check valibility
    long number = get_long("Number: ");

    //Algorithm step 1/3
    int total = 0;
    int n = 1;
    long digit;
    do
    {
        digit = (number / pow(10, n));
        digit = (digit % 10) * 2;
        //printf("digit: %i\n", digit);

        total = total + (digit % 10) + (digit / 10);
        //printf("total: %i\n", total);

        n = n + 2;

        digit = (number / pow(10, n));
        //printf("digit = %li\n", digit);
    }
    while (digit != 0);

    //Algorithm 2/3
    int m = 0;
    long digit2;
    do
    {
        digit2 = (number / pow(10, m));
        digit2 = digit2 % 10;
        //printf("digit2 = %li\n", digit2);

        total = total + digit2;

        m = m + 2;

        digit2 = (number / pow(10, m));
    }
    while (digit2 != 0);

    //Algorithm 3/3
    if ((total % 10) == 0)
    {
        //check for card length
        int length = 0;
        int x;
        do
        {
            x = (number / pow(10, (length + 1)));
            length++;
        }
        while (x != 0);

        printf("length: %i\n", length);
        switch (length)
        {
            case 13:
                x = (number / pow(10, (length - 1)));
                if (x == 4)
                {
                    printf("VISA\n");
                    break;
                }

            case 15:
                x = (number / pow(10, (length - 2)));
                if ((x == 34) || (x == 37))
                {
                    printf("AMEX\n");
                    break;
                }

            case 16:
                x = (number / pow(10, (length - 2)));
                if ((x > 50) && (x < 56))
                {
                    printf("MASTERCARD\n");
                    break;
                }
                else
                {
                    x = (number / pow(10, (length - 1)));
                    if (x == 4)
                    {
                        printf("VISA\n");
                        break;
                    }
                }
            default:
                printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}
