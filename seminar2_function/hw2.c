/*1
#include <stdio.h>
int cube (int x)
{
	return x*x*x;
}
int main()
{
	printf("%i\n",cube(5));
}
*/
/*2
#include <stdio.h>
int is_even (int x)
{
	if (x%2==0)
	{
		return 1;

	}
	else return 0;
}
int main()
{
	printf("%i\n",is_even(90));
	printf("%i\n",is_even(91));
}
*/
/*3
#include <stdio.h>
void print_even (int x, int y)
{
	while (x<=y)
	{
		if (x%2==0)
		{
			printf("%i ",x);

		}
		
		x++;
	}
}
int main()
{
	print_even(2,15);
}
*/
/*4
#include <stdio.h>
int sum_of_dihits (int x)
{
	int s=0;
	while (x>0)
	{
		s+=x%10;
		x=x/10;
	}
	return s;
}
int main()
{
	printf("%i\n",sum_of_dihits(123));
}
*/
/*5
#include <stdio.h>

void print_binary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    if (n > 1) {
        print_binary(n / 2);
    }
    printf("%i", n % 2);
}
int main()
{
	print_binary(123);
}
*/