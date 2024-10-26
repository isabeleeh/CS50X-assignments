#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string("before: \n");

    printf("after: ");
    for (int i = 0, length = strlen(name); i < length; i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            printf("%c", name[i] - 32);
        }
        else
        {
            printf("%c", name[i]);
        }
    }
    printf("\n");
}