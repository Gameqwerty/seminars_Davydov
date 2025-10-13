#include <stdio.h>

int adder(int x)
{
    static int t = 0;
    t += x;
    return t;
}

int main()
{
    printf("%i\n", adder(10));
    printf("%i\n", adder(15));
    printf("%i\n", adder(70));
}