#ifndef UTILS_H
#define UTILS_H

// Removes newline from string read by fgets
void trimNewline(char *str);

// Claer Input from Buffers .
void clearInputBuffer();


// Check if name it's valid 
bool isValidName(char *name);

// Check if email it's valid
bool isValidEmail(const char *email);

#endif
