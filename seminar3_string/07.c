#include <stdio.h>

void encrypt(char* str, int k) 
{
    k = k % 26;
    if (k < 0) {
        k += 26;
    }
    
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] = 'A' + (str[i] - 'A' + k) % 26;
        } else if (str[i] >= 'a' && str[i] <= 'z') 
        {
            str[i] = 'a' + (str[i] - 'a' + k) % 26;
        }
    }
}

int main() 
{
    char str1[] = "ABCZ";
    encrypt(str1, 1);
    printf("%s\n", str1);

    char str2[] = "ZzZzZ";
    encrypt(str2, 15);
    printf("%s\n", str2); 

    char str3[] = "The Fox Jumps Over The Dog";
    encrypt(str3, 7);
    printf("%s\n", str3);

    char str4[] = "Green Terra";
    encrypt(str4, 13);
    printf("%s\n", str4); 

}