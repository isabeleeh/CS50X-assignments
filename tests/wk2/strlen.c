#include <stdio.h>
#include <cs50.h>

int string_length(string s);

int main(void)
{
    string name = get_string("please enter a name.\n");


    printf("output: ");
    for (int i = 0, length = string_length(name); i < length; i++)
    {
        printf("%c", name[i]);
    }

    printf("\n");

}

int string_length(string s)
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}