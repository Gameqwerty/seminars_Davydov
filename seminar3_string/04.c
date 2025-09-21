#include <stdio.h>
int main()
{
	char a[100];
	char b[100];
	scanf("%99s %99s", a, b);
	int i = 0;
	int j = 0;
	while (a[i] || b[j])
	{
		if (a[i] && b[j])
		{
			printf("%c%c", a[i], b[j]);
			i++;
			j++;
		} else if (a[i])
		{
			printf("%c", a[i]);
			i++;
		}else if (b[i])
		{
			printf("%c", b[j]);
			j++;
		}
	}

}