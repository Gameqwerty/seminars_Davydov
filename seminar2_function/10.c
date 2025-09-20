#include <stdio.h>

#define MAX 10

void assign(float A[MAX][MAX], float B[MAX][MAX], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            A[i][j] = B[i][j];
        }
    }
}

int main() 
{
    float mA[MAX][MAX];
    float mB[MAX][MAX] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    int n = 3;

    assign(mA, mB, n);

    printf("\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%.1f ", mA[i][j]);
        }
        printf("\n");
    }
}