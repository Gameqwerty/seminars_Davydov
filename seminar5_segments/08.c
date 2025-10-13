#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y) { return x + y; }
int diff(int x, int y) { return x - y; }
int mult(int x, int y) { return x * y; }
int sqdiff(int x, int y) { return x * x - y * y; }
int lin(int x, int y) { return 5 * x - y; }

typedef int (*FuncPtr)(int, int);

void print_func_name(FuncPtr p)
{
    if (p == sum)
        printf("sum\n");
    else if (p == diff)
        printf("diff\n");
    else if (p == mult)
        printf("mult\n");
    else if (p == sqdiff)
        printf("sqdiff\n");
    else if (p == lin)
        printf("lin\n");
    else
        printf("other\n");
}

void print_array_names(FuncPtr* array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        print_func_name(array[i]);
}

void sort_funcs(FuncPtr* a, size_t n, int x, int y)
{
    for (size_t j = 0; j < n; ++j)
    {
        size_t mi = j;
        for (size_t i = j + 1; i < n; ++i)
        {
            if (a[i](x, y) < a[mi](x, y))
                mi = i;
        }

        FuncPtr temp = a[j];
        a[j] = a[mi];
        a[mi] = temp;
    }
}

int main()
{
    FuncPtr array[5] = {sum, diff, mult, sqdiff, lin};

    print_array_names(array, 5);
    sort_funcs(array, 5, 2, 2);
    print_array_names(array, 5);
    sort_funcs(array, 5, 8, 1);
    print_array_names(array, 5);
}