#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int i = 1;
    int j = 2;

    printf("i = %i, j = %i\n", i, j);
    swap(&i, &j);
    printf("i = %i, j = %i\n", i, j);

}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}