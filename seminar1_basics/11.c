#include <stdio.h>

int cs(int n) 
{
    if (n < 0) n = - n;
    int sum = 0;
    while (n > 0) 
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() 
{
    int count;
    scanf("%i", &count);
    
    int n[10000];
    int s[10000];
    
    for (int i = 0; i < count; i++) 
    {
        scanf("%i", &n[i]);
        s[i]=cs(n[i]);
    }

    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = 0; j < count - i - 1; j++) 
        {
            if (s[j] > s[j+1]) 
            {
                int tn = n[j];
                n[j] = n[j+1];
                n[j+1] = tn;
                int ts = s[j];
                s[j] = s[j+1];
                s[j+1] = ts;
            }
        }
    }
    
    for (int i = 0; i < count; i++) 
    {
        printf("%i ", n[i]);
    }
}