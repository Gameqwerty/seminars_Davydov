#include <stdio.h>
#include <ctype.h>

int main() 
{
    int sum = 0;
    int c;

    while ((c = getchar()) != EOF) 
    {
        if (isdigit(c)) 
        {
            sum += c - '0';
        } else 
        {
            break;
        }
    }
    printf("%d\n", sum);
}