#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Yingcheng";
    people[1].name = "Isabel";

    people[0].number = "+8613922114903";
    people[1].number = "+61491028241";

    //Search for Isabel
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "Isabel") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;

}