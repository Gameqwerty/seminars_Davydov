#include <stdio.h>
#include <stdalign.h>

struct cat 
{
    char x;
    size_t y;
};

struct dog 
{
    size_t y;
    char x;
};

struct mouse 
{
    char x;
    char y;
    size_t z;
};

struct rat 
{
    char x;
    size_t z;
    char y;
};

struct fox 
{
    char x;
    struct mouse y;
};

int main() 
{
    printf("1. char:         size = %zu, align = %zu\n", sizeof(char),        alignof(char));
    printf("2. int:          size = %zu, align = %zu\n", sizeof(int),         alignof(int));
    printf("3. size_t:       size = %zu, align = %zu\n", sizeof(size_t),      alignof(size_t));
    printf("4. int[10]:      size = %zu, align = %zu\n", sizeof(int[10]),     alignof(int));
    printf("5. int*:         size = %zu, align = %zu\n", sizeof(int*),        alignof(int*));
    printf("6. struct cat:   size = %zu, align = %zu\n", sizeof(struct cat),  alignof(struct cat));
    printf("7. struct dog:   size = %zu, align = %zu\n", sizeof(struct dog),  alignof(struct dog));
    printf("8. struct mouse: size = %zu, align = %zu\n", sizeof(struct mouse),alignof(struct mouse));
    printf("9. struct rat:   size = %zu, align = %zu\n", sizeof(struct rat),  alignof(struct rat));
    printf("10. struct fox:  size = %zu, align = %zu\n", sizeof(struct fox),  alignof(struct fox));
}