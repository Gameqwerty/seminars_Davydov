#include <stdio.h>
int main()
{
	int numbers[6] = {4, 8, 15, 16, 23, 42};
	int* p = &numbers[3];
	printf("%i\n", numbers[5]);
	printf("%i\n", *p);
	printf("%i\n", *(p+1));
	printf("%i\n", *(p-2));
	printf("%i\n", p[0]);
	printf("%i\n", p[1]);
	printf("%i\n", p[-2]);
	printf("%i\n", *numbers);
	printf("%i\n", *(numbers + 5));
	printf("%i\n", p - numbers);
	printf("%i\n", (short*)p - (short*)numbers);
	printf("%i\n", (char*)p - (char*)numbers);

}