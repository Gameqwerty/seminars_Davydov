#include <stdio.h>

unsigned long long arr(unsigned int n, unsigned int k) 
{
    unsigned long long result = 1;
    for (unsigned int i = 0; i < k; ++i) 
    {
        result *= (n - i);
    }
    return result;
}

int main() 
{
    unsigned int n, k;
    scanf("%u %u", &n, &k);
    printf("%llu\n", arr(n, k));
}