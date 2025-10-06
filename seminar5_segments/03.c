#include <stdio.h>
#include <stdlib.h>
char* concat(const char* a, const char* b)
{
	t = a + b;
	char* p = (char*)malloc(sizeof(a) + sizeof(b));
	strcpy(p, t);
	return p;

}
int main()
{
	char a[3] = "abc";
    char b[3] = "sed";
	
	char* p = concat(a, b);
	printf("%s\n", p);
	free(p);
}