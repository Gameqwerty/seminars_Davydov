#include <stdio.h>
void print_even(int x, int y)
{
	while (x <= y)
	{
		if (x % 2 == 0)
		{
			printf("%i ", x); 
		}
		
		x++; 
	}
}
int main()
{
	int n, m;
    scanf("%i %i", &n, &m);
	print_even(n, m); 
}