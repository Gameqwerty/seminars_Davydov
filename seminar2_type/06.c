#include <stdio.h>
#include <math.h>

#define STEP 1e-2
#define EPS 1e-10

double gamma(double x) 
{
    double integral = 0.0;
    double t = 0.0;
    double prev_area = 0.0;

    while (1) 
    {
        double t_next = t + STEP;
        double f_t = pow(t, x - 1) * exp(-t);
        double f_t_next = pow(t_next, x - 1) * exp(-t_next);

        double area = STEP * (f_t + f_t_next) / 2.0;

        if (area < EPS && t > 1.0) 
        {
            break;
        }

        integral += area;
        t = t_next;

        if (t > 500.0) 
        { 
            break;
        }
    }

    return integral;
}

int main() 
{
    printf("%.6f\n", gamma(2));
    printf("%.6f\n", gamma(6));
    printf("%.6f\n", gamma(20));
    printf("%.6f\n", gamma(1.5));
    printf("%.6f\n", gamma(2.5));
    printf("%.6f\n", gamma(4.14159));
}