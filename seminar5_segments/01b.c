#include <stdio.h>
#include <stdlib.h>
int main()
{
	char* p = (char*)malloc(9 * sizeof(char));
	p[0] = 'E';
	p[1] = 'l';
	p[2] = 'e';
	p[3] = 'p';
	p[4] = 'h';
	p[5] = 'a';
	p[6] = 'n';
	p[7] = 't';
	p[8] = '\0';
	printf("%s", p);
	free(p);
}
