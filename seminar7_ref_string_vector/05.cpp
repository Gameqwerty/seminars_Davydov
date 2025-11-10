#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& b)
{
    return b.price > 1000.0f;
}

int main()
{
    Book a{"a", 1200, 950.0f};
    Book b{"b", 900, 1500.0f};

    std::cout << std::boolalpha << isExpensive(a) << " " << isExpensive(b) << std::endl;
}
