/* Задача 1
#include <stdio.h>

int main() 
{
    int a;
    scanf("%i", &a);
    printf("%i\n",a+1);
}*/ 
/* Задача 2
#include <stdio.h>
int main() {
    int a;
    scanf("%i",&a);
    
    if(a%2==0 && ((a>=0 && a<=20)||(a>100 && a<200))) {
        printf("Yes");
    } else {
        printf("No");
    }

}*/ 
/* Задача 3
#include <stdio.h>
int main() {
    int n;
    scanf("%i", &n);
    
    for (int i=1; i<=n; i++) {
        printf("%3i -> %3i -> %3i\n", i, i*i, i*i*i);
    }
}*/ 
/* Задача 4
#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int c;
    scanf("%i", &n);
    int max = INT_MIN;
    
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%i", &a);
        if (a > max){
            max = a;
            c = 1;}
        else if (a==max){
            c++;

        }
    }
    
    printf("%i %i\n", max, c);
}*/ 
/* Задача 5
#include <stdio.h>

int main() {
    int n;
    scanf("%i", &n);
    
    int l=1;
    int max=n;
    
    printf("%i", n);
    
    while (n!=1) 
    {
        if (n%2==0) 
        {
            n=n/2;
        } else 
        {
            n=3*n+1;
        }
        
        printf(" %i", n);
        l++;
        
        if (n>max) 
        {
            max=n;
        }
    }
    
    printf("\nLength = %i, Max = %i\n", l, max);

}*/ 
/* Задача 6
#include <stdio.h>

int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    
   int s=0;
    
    for (int i=1; i<=n; i++) 
    {
        for (int j=1; j<=m; j++) 
        {
            if ((i+j)%2==0) 
            {
                s+=i*j;
            } else 
            {
                s-=i*j;
            }
        }
    }
    printf("%i", s);
}*/ 
/* Задача 7
#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    
    if (c==0) {
        return 0;
    }
    
    if (c<0) {
        c=-c;
    }
    
    int r=a%c;
    if (r!=0) {
        if (r<0) {
            a-=r;
        } else {
            a+=c-r;
        }
    }
    
    if (a>b) {
        return 0;
    }
    
    printf("%d", a);
    int cur = a+c;
    while (cur <= b) {
        printf(" %i", cur);
        cur += c;
    }
    
}*/ 
/* Задача 8
#include <stdio.h>

int main() {
    int n;
    scanf("%i", &n);
    int a[n];
    for (int i=0; i<n; i++) 
    {
        scanf("%i", &a[i]);
    }
    
    for (int i=0; i<n; i++) 
    {
        printf("%i ", a[i]);
    }
    for (int i=0; i<n; i++) 
    {
        printf("%i ", a[i]);
    }
}*/ 
/* Задача 9
#include <stdio.h>

int main() 
{
    int n;
    scanf("%i", &n);
    int a[n];
    
    for (int i=0; i<n; i++) 
    {
        scanf("%i", &a[i]);
    }
    
    int j = 0;
    for (int i=0; i<n; i++) 
    {
        if (a[i]>=0) 
        {
            a[j]=a[i];
            j++;
        }
    }
    
    for (int i=0; i<j; i++) 
    {
        printf("%i ", a[i]);
    }
}*/
/* Задача 10
#include <stdio.h>

int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    
    int s[m];
    for (int j=0; j<m; j++) 
    {
        s[j]=0;
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int p;
            scanf("%i", &p);
            s[j]+=p;
        }
    }
    
    for (int j=0; j<m; j++) {
        printf("%i ", s[j]);
    }
}*/
/* Задача 11
#include <stdio.h>

int cs(int n) 
{
    if (n<0) n = -n;
    int sum=0;
    while (n>0) {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main() {
    int count;
    scanf("%i", &count);
    
    int n[10000];
    int s[10000];
    
    for (int i = 0; i < count; i++) 
    {
        scanf("%i", &n[i]);
        s[i]=cs(n[i]);
    }

    for (int i=0; i<count-1; i++) 
    {
        for (int j=0; j<count-i-1; j++) 
        {
            if (s[j]>s[j+1]) 
            {
                int tn = n[j];
                n[j] = n[j+1];
                n[j+1] = tn;
                int ts = s[j];
                s[j] = s[j+1];
                s[j+1] = ts;
            }
        }
    }
    
    for (int i=0; i<count; i++) 
    {
        printf("%i ", n[i]);
    }
}*/
/* Задача 12
#include <stdio.h>

int main() 
{
    int n;
    scanf("%i", &n);
    
    int A[10][10];
    int B[10][10];
    int C[10][10]={0};
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            scanf("%i", &A[i][j]);
        }
    }

    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            scanf("%i", &B[i][j]);
        }
    }
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            for (int k=0; k<n; k++) 
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            printf("%i ", C[i][j]);
        }
        printf("\n");
    }
}*/
