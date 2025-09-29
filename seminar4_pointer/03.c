#include <stdio.h>
void cube(float* p)
{
	*p = *p * *p * *p;
}
int main()
{
	float a = 1.5;
	cube(&a);
	printf("%.3f\n", a); 
}
