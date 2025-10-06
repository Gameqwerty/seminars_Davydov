#include <stdio.h>
#include <string.h>
#include <ctype.h>

void used_chars(const char* str, char* used) 
{
    int s[26] = {0};
    int c = 0;

    while (*str != '\0') 
    {
        if (isalpha(*str)) 
        {
            char lower = tolower(*str);
            s[lower - 'a'] = 1;
        }
        str++;
    }

    for (int i = 0; i < 26; i++) 
    {
        if (s[i]) 
        {
            used[c++] = 'a' + i;
        }
    }
    used[c] = '\0';
}

int main() 
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);
}