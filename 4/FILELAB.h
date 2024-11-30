#include <stddef.h>
#ifndef FILELAB
#define FILELAB
#define PROMPTED "Enter the str >> "
char* format(char* str);
char* myformat(char* str);
char* kav(char* str);
char* mykav(char* str);
char* separ(char* str);
char* mysepar(char* str);
char* mystrcpy(char* s1, const char* s2);
size_t mystrlen(const char* str);
char* mystrcat(char* s1, char* s2);
char* myreadline();
void prog1();
void prog2();
#endif
