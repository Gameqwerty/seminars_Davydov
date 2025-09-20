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
    
    for (int i = 0; i < n; i++) 
    {
        printf("%i ", a[i]);
    }
    for (int i = 0; i < n; i++) 
    {
        printf("%i ", a[i]);
    }
}