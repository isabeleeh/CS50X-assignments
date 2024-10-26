#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int score1 = 71;
    int score2 = 73;
    int score3 = 40;

    printf("The average score is: %f\n", (score1 + score2 + score3) / 3.0);
    printf("pow(10, 0): %i\n", (int) (pow(10, 1)));
}