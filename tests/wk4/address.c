#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);

    string s = "hi!";
    char *pp = &s[0];
    printf("%p\n", pp);
    printf("%p\n", s);
    printf("%s\n", s);
    printf("%c\n", *s);
    printf("%i\n", *s);

}