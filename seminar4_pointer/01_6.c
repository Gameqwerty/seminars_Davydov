#include <stdio.h>

int main()
{
	int a = 10;
	int* p = &a;
	*p *= 2;
	printf("%i\n", a);
}