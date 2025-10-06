#include <stdio.h>
#include <math.h>

#define EPS 1e-10

int solve_quadratic(double a, double b, double c, double* px1, double* px2) 
{
    if (fabs(a) < EPS) 
    {
        if (fabs(b) < EPS) 
        {
            return 0;
        } else 
        {
            *px1 = -c / b;
            return 1;
        }
    }

    double D = b * b - 4.0 * a * c;

    if (D < -EPS) 
    {
        return 0;
    } else if (D < EPS) 
    {
        *px1 = -b / (2.0 * a);
        return 1;
    } else 
    {
        double sqrtD = sqrt(D);
        *px1 = (-b + sqrtD) / (2.0 * a);
        *px2 = (-b - sqrtD) / (2.0 * a);
        return 2;
    }
}

int main() 
{
    double x1, x2;
    int result;

    result = solve_quadratic(1, -3, 2, &x1, &x2);
    printf("%d\n", result);
    if (result >= 1) printf("x1 = %g\n", x1);
    if (result == 2) printf("x2 = %g\n", x2);
}