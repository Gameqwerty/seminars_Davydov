#include <stdio.h>
#include <stdlib.h>
int main()
{
	char* q = (char*)malloc(14 * sizeof(char));
	q[0] = 'C';
	q[1] = 'a';
	q[2] = 't';
	q[3] = 's';
	q[4] = ' ';
	q[5] = 'a';
	q[6] = 'n';
	q[7] = 'd';
	q[8] = ' ';
	q[9] = 'D';
	q[10] = 'o';
	q[11] = 'g';
	q[12] = 's';
	q[13] = '\0';
	char* p = (char*)malloc(14 * sizeof(char));
	p = q;
	printf("%s", p);
	free(p);
}