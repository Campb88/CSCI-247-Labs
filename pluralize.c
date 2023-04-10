#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_ending(char ptr[], int len) {
    
    /* get the last two chars */
    char *ending = &ptr[len - 1];
    char *next = &ptr[len - 2];

    if(strcmp("y", ending) == 0) {  /* looking at Y */
        if (strcmp("ay", next) == 0) {
            return true;
        } else if (strcmp("ey", next) == 0) {
            return true;
        } else if (strcmp("oy", next) == 0) {
            return true;
        } else if (strcmp("uy", next) == 0) {
            return true;
        } else if (strcmp("ly", next) == 0) {  /* when its LY */
            strtok(ptr, &ptr[len - 1]);
            strcat(ptr, "ies");
            return false;
        }
    } else if (strcmp("h", ending) == 0) {  /* looking at H */
        strcat(ptr, "es");
        return false;
    } else if (strcmp("us", next) == 0) {  /* looking at US */
        strtok(ptr, next);
        strcat(ptr, "i");
        return false;
    } else if (strcmp("fe", next) == 0) {  /* looking at FE */
        strtok(ptr, next);
        strcat(ptr, "ves");
        return false;
    } else if (strcmp("s", ending) == 0) {
        return false;
    }

}

int main()
{
    int num;

    /* get the number */
    printf("Enter number: ");
    scanf("%d", &num);

    /* get the word */
    char word[20];
    printf("Enter word: ");
    scanf("%s", word);

    /* ptr to word */
    char *ptr = word;

    /* check the ending */
    bool status = check_ending(ptr, strlen(ptr));

    /* if theres no condtionals */
    if (status == true) {
        strcat(ptr, "s");
    }

    printf("%d %s\n", num, word);
    return 0;
}