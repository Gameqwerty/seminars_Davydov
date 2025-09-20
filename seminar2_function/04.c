#include <stdio.h>
#include <stdio.h>

int sum_of_digits(int n) 
{
    int s = 0;
    while (n > 0) 
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int sum_of_digits_rec(int n) 
{
    if (n < 10) 
    {
        return n;
    }
    return n % 10 + sum_of_digits_rec(n / 10);
}


int main()
{
	int n;
    scanf("%i", &n);
	printf("%i\n", sum_of_digits(n)); 
	printf("%i\n", sum_of_digits_rec(n)); 
}