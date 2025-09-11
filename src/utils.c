#include <string.h>
#include <stdio.h>
#include "utils.h"

void trimNewline(char *str){
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
    
}

void clearInputBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
