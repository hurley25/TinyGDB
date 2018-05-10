#include "util.h"

#include <string.h>

int string_split(char *str, char *delim, char **result, int length)
{
    int i = 0;
    char *p = NULL;
    do {
        p = strsep(&str, delim);
        if (p && *p != '\0') {
            result[i++] = p;
        }
    } while(p && i < length);

    return i;
}

