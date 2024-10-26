#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("which number to countdown with?\n");

    switch (x)
    {
        case 5:
            printf("Five, \n");

        case 4:
            printf("Four, \n");

        case 3:
            printf("Three, \n");

        case 2:
            printf("Two, \n");

        case 1:
            printf("One, \n");

        default:
            printf("Blast-off!\n");
    }
}