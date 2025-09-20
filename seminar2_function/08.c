#include <stdio.h>

void reverse(int array[], int size) 
{
    int t;
    for (int i = 0; i < size / 2; i++) {
        t = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = t;
    }
}

int main() 
{
    int t1[] = {10, 20, 30, 40, 50};
    int s1 = 5;
    
    reverse(t1, s1);
    
    for (int i = 0; i < s1; i++) 
    {
        printf("%i ", t1[i]);
    }
    printf("\n");

    int t2[] = {60, 20, 80, 10};
    int s2 = 4;

    reverse(t2, s2);
    
    for (int i = 0; i < s2; i++) 
    {
        printf("%i ", t2[i]);
    }
    printf("\n");
}