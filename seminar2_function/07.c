#include <stdio.h>

int count_even(int array[], int size) 
{
    int с = 0;
    for (int i = 0; i < size; i++) 
    {
        if (array[i] % 2 == 0) 
        {
            с++;
        }
    }
    return с;
}

int main() 
{
    int t1[] = {1, 2, 3, 4, 5};
    int s1 = 5;
    printf("%i\n", count_even(t1, s1)); 

    int t2[] = {10, 20, 30, 40};
    int s2 = 4;
    printf("%i\n", count_even(t2, s2)); 
    int t3[] = {10, 1};
    int s3 = 2;
    printf("%i\n", count_even(t3, s3)); 
}