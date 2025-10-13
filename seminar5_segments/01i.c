#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

struct library
{
    Book* books;
    int number_of_books;
};
typedef struct library Library;

void print_book(struct book b)
{
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

void library_create(Library* lib, int count)
{
    lib->number_of_books = count;
    lib->books = (Book*) malloc(count * sizeof(Book));
}

void library_set(Library lib, int i, const char* title, int pages, float price)
{
    lib.books[i].title = (char*) malloc(strlen(title) + 1);
    strcpy(lib.books[i].title, title);
    lib.books[i].pages = pages;
    lib.books[i].price = price;
}

Book* library_get(Library lib, int i)
{
    return &lib.books[i];
}

void library_print(Library lib)
{
    for (int i = 0; i < lib.number_of_books; i++)
    {
        print_book(lib.books[i]);
    }
}

void library_destroy(Library* lib)
{
    for (int i = 0; i < lib->number_of_books; i++)
    {
        free(lib->books[i].title);
    }
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main()
{
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0f);
    library_set(a, 1, "Oblomov", 400, 250.0f);
    library_set(a, 2, "The Odyssey", 500, 500.0f);
    library_print(a);
    print_book(*library_get(a, 1));
    library_destroy(&a);
}