#include <stdio.h>
int main()
{
	int a[5] = {10, 20, 30, 40, 50};
	int* p = &a[0];
	*(p + 3) += 1;
	for (int i = 0; i < 5; ++i)
		printf("%i ", a[i]);
}