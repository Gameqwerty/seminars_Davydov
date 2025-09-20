#include <stdio.h>

int main() 
{
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    
    if (c == 0) 
    {
        return 0;
    }
    
    if (c < 0) 
    {
        c =- c;
    }
    
    int r = a % c;
    if (r != 0) 
    {
        if (r < 0) 
        {
            a -= r;
        } else 
        {
            a += c - r;
        }
    }
    
    if (a > b) 
    {
        return 0;
    }
    
    printf("%d", a);
    int cur = a + c;
    while (cur <= b) 
    {
        printf(" %i", cur);
        cur += c;
    }
    
}