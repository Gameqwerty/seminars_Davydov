#include <stdio.h>
#include <string.h>
#include "list_macro.h"

typedef struct book 
{
    char title[32];
    int pages;
    float price;
} Book;

void print_int(int x)     { printf("%d ", x); }
void print_float(float f) { printf("%g ", f); }
void print_book(Book b)   { printf("%s[%d,%.2f] ", b.title, b.pages, b.price); }

DECLARE_LIST(int)
DECLARE_LIST(float)
DECLARE_LIST(Book)
DECLARE_LIST(List_int)

int main(void) {
    List_int a; list_int_init(&a);
    for (int i = 1; i <= 5; ++i) list_int_push_back(&a, 10*i);
    list_int_print(&a, print_int); // 10 20 30 40 50

    Node_int* p = a.head; list_int_advance(&p, 2); // -> 30
    p = list_int_erase(&a, p);
    list_int_print(&a, print_int);

    List_int b; list_int_init(&b);
    list_int_push_back(&b, 100);
    list_int_push_back(&b, 200);
    list_int_push_back(&b, 300);
    list_int_splice(&a, p, &b);
    list_int_print(&a, print_int);

    List_Book lb; list_Book_init(&lb);
    Book bk;
    strcpy(bk.title,"Don Quixote"); bk.pages=100; bk.price=199.9f; list_Book_push_back(&lb, bk);
    strcpy(bk.title,"Pride");       bk.pages=200; bk.price=299.9f; list_Book_push_back(&lb, bk);
    list_Book_print(&lb, print_book);

    List_List_int big; list_List_int_init(&big);
    list_List_int_push_back(&big, a);
    list_List_int_push_back(&big, a);
    for (Node_List_int* n = big.head; n; n = n->next) printf("[%zu] ", n->value.size);
    putchar('\n');

    list_int_destroy(&a);
    list_int_destroy(&b);
    list_Book_destroy(&lb);
    list_List_int_destroy(&big);
}
