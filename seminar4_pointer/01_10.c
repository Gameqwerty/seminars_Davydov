#include <stdio.h>
int main()
{
	char str[] = "sapere aude";
	char* p = &str[0];
	for (int i = 0; i < 11; ++i)
		if (*(p+i) != ' ') *(p+i) -= 32;
	printf("%s\n", str);
}