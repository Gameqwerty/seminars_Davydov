#include <stdio.h>

long long trib(int n) 
{
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;
    
    long long a = 0;
    long long b = 0;
    long long c = 1;
    long long nx;
    
    for (int i = 3; i <= n; i++) 
    {
        nx = a + b + c;
        a = b;
        b = c;
        c = nx;
    }
    return c;
}
int main()
{
    int n;
    scanf("%i", &n);
	printf("%i\n", trib(n)); 
}