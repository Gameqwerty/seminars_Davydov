#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
	char title[50];
	int pages;
	float price;
};
typedef struct book Book;
void print_book(Book** p)
{
	printf("Book info:\n");
	printf("Book: %s, Pages: %i, Price: %f\n", (**p).title, (**p).pages, (**p).price);

}
int main()
{
	Book a =  {"Don Quixote", 1000, 750.0};
	Book** p = (Book**)malloc(sizeof(Book*));
	*p = &a;
	print_book(p);
	free(p);
}