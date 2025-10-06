#include <stdio.h>
#include <stdlib.h>
float* get_geometric_progression(float a, float r, int n)
{
	float* p = (float*)malloc(sizeof(float) * n);
	p[0] = a;
	for (size_t i = 1; i < n; ++i)
		p[i] = r * p[i-1];
	return p;

}
int main()
{
	float a = 1;
	float r = 3;
	float n = 10;
	float* p = get_geometric_progression(a, r, n);
	for (size_t i = 0; i < n; ++i)
		printf("%f ", p[i]);
		printf("\n");
	free(p);

}