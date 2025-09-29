#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_integer(const char *str) 
{
    if (str == NULL || *str == '\0') return 0;
    int i = 0;
    if (str[0] == '-' || str[0] == '+') i++;
    for (; str[i] != '\0'; i++) 
    {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 4) 
    {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: ./calc <number> <operator> <number>\n");
        return 1;
    }

    char *op1_str = argv[1];
    char *op2_str = argv[3];
    char op = argv[2][0];

    if (!is_integer(op1_str) || !is_integer(op2_str)) 
    {
        printf("Error: Operands should be integers!\n");
        return 1;
    }

    int a = atoi(op1_str);
    int b = atoi(op2_str);

    if (argv[2][1] != '\0') {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    int result;

    if (op == '+') 
    {
        result = a + b;
    } else if (op == '-') 
    {
        result = a - b;
    } else if (op == '*') 
    {
        result = a * b;
    } else if (op == '/') 
    {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        result = a / b;
    } else if (op == '%') {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        result = a % b;
    } else {
        printf("Error: Invalid operator!\n");
        return 1;
    }

    printf("%d\n", result);
}