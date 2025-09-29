#include <stdio.h>
#include <math.h>
#define eps 1e-10
int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
	int D = b * b - 4 * a * c;
	if (D < 0)
	{
		return 0;
	}else if ((D < eps || (D < eps))
	{
		*px1 = -b / (2 * a);
		return 1;
	} else
	{
		*px1 = -b - sqrt(D)/ (2 * a);
		*px2 = -b + sqrt(D)/ (2 * a);
		return 2;
	}
}
int main()
{
	double a = 1.5;
	double b = 6.5;
	double c = 1.5;
	double r1;
	double r2;
	int f;
	f = solve_quadratic(a, b, c, &r1, &r2);
	printf("%.7f\n", r1);
	printf("%.7f\n", r2);

}