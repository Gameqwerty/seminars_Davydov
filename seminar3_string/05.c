#include <stdio.h>
#include <ctype.h>

int main() 
{
    char c;
    long long s = 0;
    
    while ((c = getchar()) != EOF && c != '\n' && c != '\r') 
    {
        if (isdigit(c)) 
        {
            s += c - '0';
        }
    }
    
    printf("%lld\n", s);
}