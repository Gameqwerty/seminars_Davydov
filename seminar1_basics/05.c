#include <stdio.h>

int main() 
{
    int n;
    scanf("%i", &n); 
    
    int l = 1;
    int max = n; 
    
    printf("%i", n);
    
    while (n != 1) 
    {
        if (n % 2 == 0) 
        {
            n = n / 2;
        } 
        else 
        {
            n = 3 * n + 1;
        }
        
        printf(" %i", n);
        l++;
        
        if (n > max) 
        {
            max = n;
        }
    }
    
    printf("\nLength = %i, Max = %i\n", l, max);

}