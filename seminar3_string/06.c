#include <stdio.h>
#include <string.h>

int is_palindrom(char *str) 
{
    int len = strlen(str);
    int l = 0;
    int r = len - 1;

    while (l < r) 
    {
        if (str[l] != str[r]) 
        {
            return 0;
        }
        l++;
        r--;
    }

    return 1;
}
int main() 
{
    char test1[] = "abba";
    char test2[] = "ab";
    char test3[] = "abcxedcba";

    printf("%s -> ", test1);
    if (is_palindrom(test1)) 
    {
        printf("Yes\n");
    } else 
    {
        printf("No\n");
    }

    printf("%s -> ", test2);
    if (is_palindrom(test2)) 
    {
        printf("Yes\n");
    } else 
    {
        printf("No\n");
    }

    printf("%s -> ", test3);
    if (is_palindrom(test3)) 
    {
        printf("Yes\n");
    } else 
    {
        printf("No\n");
    }
;
}