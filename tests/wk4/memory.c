# include<stdio.h>
# include<stdlib.h>

int main(void)
{
    int *i = malloc(3 * sizeof(int));

    i[1] = 72;
    i[2] = 73;
    i[0] = 74;

    free(i);
}