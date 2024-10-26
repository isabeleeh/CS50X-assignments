#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    float length1 = get_float("The length of the first side:\n");
    float length2 = get_float("The length of the second side:\n");
    float length3 = get_float("The length of the third side:\n");

    if (valid_triangle(length1, length2, length3) == false)
    {
        printf("Not a valid triangle\n");
    }
    else
    {
        printf("It is a valid triangle\n");
    }
}
bool valid_triangle(float a, float b, float c)
{
    if ((a <= 0) || (b <= 0) || (c <= 0))
    {
        return false;
    }

    if (((a + b) <= c) || ((a + c) <= b) || ((b + c) <= a))
    {
        return false;
    }

    return true;
}