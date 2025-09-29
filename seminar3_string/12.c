#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3) 
    {
        printf("\n");
        return 1;
    }

    char *word = argv[1];
    int count = atoi(argv[2]);

    if (count <= 0) 
    {
        printf("\n");
        return 1;
    }

    for (int i = 0; i < count; i++) 
    {
        if (i > 0) printf(" ");
        printf("%s", word);
    }
    printf("\n");
}