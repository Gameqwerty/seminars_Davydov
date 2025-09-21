#include <stdio.h>
int main()
{
	char i = 32;
	while (i <= 126)
	{
		printf("Symbol = %c, Code = %i\n", i, i);
		i++;
	}
}