#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    char* res = (char*) malloc(len_a + len_b + 1);

    strcpy(res, a);
    strcat(res, b);

    return res;
}

int main()
{
    char* s = concat("Hello, ", "world!");
    printf("%s\n", s);
    free(s);
}