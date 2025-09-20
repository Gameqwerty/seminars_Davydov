#include <stdio.h>

int main() 
{
    int n;
    scanf("%i", &n);
    int a[n];
    
    for (int i = 0; i < n; i++) 
    {
        scanf("%i", &a[i]);
    }
    
    int j = 0;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] >= 0) 
        {
            a[j] = a[i];
            j++;
        }
    }
    
    for (int i = 0; i < j; i++) 
    {
        printf("%i ", a[i]);
    }
}