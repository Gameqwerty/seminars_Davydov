#include <stdio.h>

float yeard(int y, int d) 
{
    int dy;
    if (y % 4 == 0) 
    {
        dy = 366;
    } else {
        dy = 365;
    }
    return (float)d / dy;
}

int main() 
{
    int y, d;
    scanf("%i %i", &y, &d);
    printf("%.5f\n", yeard(y, d));
}