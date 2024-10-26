#include <stdio.h>

int main(void)
{
    unsigned int hash = 99;
    unsigned int hashmove = hash << 2;
    unsigned int sum = hashmove ^ 97;
    printf("hashed value is %i\n", sum);

}