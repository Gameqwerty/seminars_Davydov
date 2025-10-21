#include <stdio.h>

int main(void) 
{
#ifndef COUNT
    puts("No count!");
#else
  #if COUNT > 100
    puts("Count is too large!");
  #else
    #ifdef REVERSE
      for (int i = COUNT; i >= 1; --i)
        printf("%d%s", i, (i == 1) ? "" : " ");
    #else
      for (int i = 1; i <= COUNT; ++i)
        printf("%d%s", i, (i == COUNT) ? "" : " ");
    #endif
      putchar('\n');
  #endif
#endif
}
