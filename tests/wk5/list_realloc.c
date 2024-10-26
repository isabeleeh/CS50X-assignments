#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //alloc size of 3
    int *list = malloc(3 * sizeof(int));

    if (list == NULL)
    {
        return 1;
    }

    // Initializing the array
    list[0] = 0;
    list[1] = 1;
    list[2] = 2;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // Now I changed my mind from 3 elements to 4
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        printf("realloc failed");
        free(list);
        return 1;
    }

    list = tmp;
    list[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;

}