#include <stdio.h>

void mult2(int* p, size_t n)
{
	for (int i = 0; i < n; ++i)
		*(p+i) *= 2;
}
int main()
{
	int x[5] = {10, 20, 30, 40, 50};
	int n = sizeof(x) / sizeof(x[0]);
	mult2(x, n);
	for (int i = 0; i < n; ++i)
		printf("%i ", x[i]);
}
