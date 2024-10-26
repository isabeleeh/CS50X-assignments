#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get height information from customer.
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    // first level of loop for rows
    for (int r = 0; r < height; r++)
    {
        // 1/3 in second level of loop for blanks on the left side
        for (int c = (height - r - 1); c > 0; c--)
        {
            printf(" ");
        }

        // 2/3 in second level of loop for # on the left side
        for (int c = 0; c <= r; c++)
        {
            printf("#");
        }

        printf("  ");

        // 3/3 in second level of loop for # on the right side
        for (int c = 0; c <= r; c++)
        {
            printf("#");
        }

        printf("\n");
    }

}