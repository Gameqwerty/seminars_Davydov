#include <stdio.h>

#define MAX 10

void assign(int A[MAX][MAX], int B[MAX][MAX], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            A[i][j] = B[i][j];
        }
    }
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            long long sum = 0;
            for (int k = 0; k < n; k++) 
            {
                sum += (long long)A[i][k] * B[k][j];
            }
            C[i][j] = (int)sum;
        }
    }
}

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k) 
{
    int b[MAX][MAX], res[MAX][MAX], t[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) 
            {
                res[i][j] = 1;
            } else 
            {
                res[i][j] = 0;
            }
        }
    }
    
    assign(b, A, n);

    while (k > 0) 
    {
        if (k % 2 == 1) 
        {
            multiply(res, b, t, n);
            assign(res, t, n);
        }
        multiply(b, b, t, n);
        assign(b, t, n);
        k /= 2;
    }
    
    assign(C, res, n);
}

void print_matrix(int A[MAX][MAX], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int n = 3;

    int A1[MAX][MAX] = {{7, 7, 2}, {1, 8, 3}, {2, 1, 6}};
    int C1[MAX][MAX];
    power(A1, C1, n, 4);
    printf("A^4\n");
    print_matrix(C1, n);
    printf("\n");
    
    int A2[MAX][MAX] = {{0, 1, 0}, {1, 0, 1}, {1, 0, 0}};
    int C2[MAX][MAX];
    power(A2, C2, n, 70);
    printf("B^70\n");
    print_matrix(C2, n);
    printf("\n");
    
    int A3[MAX][MAX] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    int C3[MAX][MAX];
    power(A3, C3, n, 1000);
    printf("C^1000\n");
    print_matrix(C3, n);
}