#include <stdio.h>

int main() 
{
    int n;
    scanf("%i", &n);
    
    double s = 0.0;
    int sign = 1;
    
    for (int i = 1; i <= n; i++) 
    {
        double r = sign * (1.0 / (2 * i - 1));
        s += r;
        sign = -sign;
    }
    
    double pi = 4 * s;
    printf("%.10f\n", pi);
}