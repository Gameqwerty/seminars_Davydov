#include <stdio.h>

int main(void) 
{
#ifdef DOG
    puts("Dog!");
#else
    puts("No dog!");
#endif
}
