#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check_ending(char *word, int len)
{
    char *temp = word; 
    printf("temp: %s\n", temp);
    printf("word: %s\n", word);

    const char *ending = &temp[len - 1];
    const char *next = strtok(temp, ending);
    printf("ending: %s\n", ending);
    printf("next: %s\n", next);


    /* vowels */
    const char* a = "a";
    const char* e = "e";
    const char* o = "o";
    const char* u = "u";

    /* sh/ch endings */
    const char *h = "h";
    const char *es = "es";

    /* y endings */
    const char *y = "y";
    const char *ies = "ies";

    if (strcmp(ending, h) == 0)
    {
        word = strncat(word, es, 2);
        return true;
    }
    else if (strcmp(ending, y) == 0)
    {
        if ((strcmp(next, a) == 0) || (strcmp(next, e) == 0) || (strcmp(next, o) == 0) || (strcmp(next, u) == 0)) 
        {
            return false;
        }
        else
        {
            char *tok = strtok(word, y);
            strncat(tok, ies, 3);
            printf("tok: %s\n", tok);
            return true;
        }
    }

    char *ife = "ife";

    char *us = "us";

    return false;
}

void pluralize(int num, char *word)
{

    bool status = check_ending(word, strlen(word));
    printf("word: %s\n", word);

    if ((num > 1 || num == 0) )/* && status == false) */
    {
        const char *s = "s";
        strncat(word, s, 1);
        printf("%d %s\n", num, word);
    }
/*     else if ((num > 1 || num == 0) && status == true)
    {
        printf("%d %s\n", num, word);
    } */
    else
    {
        printf("%d %s\n", num, word);
    }
}

int main()
{
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    char word[20];
    printf("Enter word: ");
    scanf("%s", word);

    pluralize(num, word);

    return 0;
}