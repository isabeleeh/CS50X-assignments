#include <math.h>
#include <stdio.h>

int main(void)
{
    int ave1 = round((27 + 28 + 28) / 3);
    int ave2 = round((27 + 28 + 28) / 3.0);

    printf("ave1: %i\n", ave1);
    printf("ave2: %i\n", ave2);

}