#include <stdio.h>

int main() 
{
    int n;
    scanf("%i", &n);
    
    int A[10][10];
    int B[10][10];
    int C[10][10] = {0};
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%i", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%i", &B[i][j]);
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%i ", C[i][j]);
        }
        printf("\n");
    }
}