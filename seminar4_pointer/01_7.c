#include <stdio.h>
int main()
{
	char a = 't';
	char* p = &a;
	*p -= 32;
	printf("%c\n", a);
}