#include <iostream>

int& getRefToMax(int& a, int& b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 10;
    int b = 20;

    getRefToMax(a, b) += 1;

    std::cout << a << " " << b << std::endl;
}
