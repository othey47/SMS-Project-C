#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
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


bool isValidName(char *name)
{
    // Helper function to check if name has valid characters only
    for (int i = 0; name[i] != '\0'; i++) {
        char c = name[i];
        
        // Allow: letters, spaces, apostrophes, hyphens
        if (!(isalpha(c) || c == ' ' || c == '\'' || c == '-')) {
            return false;  // Invalid character found
        }
    }
    return true;  // All characters are valid
}



bool isValidEmail(const char *email)
{
    int atCount = 0;
    int atPosition = -1;
    int len = strlen(email);

    // Reject empty input here if you want
    if(len == 0) {
        return false; // invalid
    }

    // Scan characters
    for(int i = 0; i < len; i++) {
        if(email[i] == '@') {
            atCount++;
            atPosition = i;
        }
        if(isspace((unsigned char)email[i])) {
            return false; // invalid: spaces not allowed
        }
    }

    // Must have exactly one '@', not at start or end
    if(atCount != 1 || atPosition == 0 || atPosition == len - 1) {
        return false; // invalid
    }

    // Must have '.' after '@'
    int dotAfterAt = 0;
    for(int i = atPosition + 1; i < len; i++) {
        if(email[i] == '.') {
            dotAfterAt = 1;
            break;
        }
    }

    if(!dotAfterAt) {
        return false; // invalid
    }

    return true; // valid
}
