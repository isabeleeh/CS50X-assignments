#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letter_num = count_letters(text);
    int words_num = count_words(text);
    int sentence_num = count_sentences(text);
    float l = (float)letter_num / (float)words_num * 100;
    float s = (float)sentence_num / (float)words_num * 100;
    float subindex = 0.0588 * l - 0.296 * s - 15.8;
    int index = round(subindex);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text)
{
    // To count letters (upper and lower) in the given string
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((('a' <= text[i]) && (text[i] <= 'z')) || (('A' <= text[i]) && (text[i] <= 'Z')))
        {
            count ++;
        }
    }
    return count;
}

int count_words(string text)
{
    // To count the number of words in given string
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count ++;
        }
    }
    return (count + 1);
}

int count_sentences(string text)
{
    // Simplified way to check out the number of sentence by '.', '!' and '?'
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == '.') || (text[i] == '?') || text[i] == '!')
        {
            count ++;
        }
    }
    return count;
}