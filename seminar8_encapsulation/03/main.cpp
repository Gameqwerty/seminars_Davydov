#include <iostream>
#include "number.hpp"

Number fib(int n)
{
    if (n == 0) return Number(0);
    if (n == 1) return Number(1);

    Number a(0);
    Number b(1);
    for (int i = 2; i <= n; ++i)
    {
        Number c = a + b;
        a = b;
        b = c;
    }
    return b;
}

Number factorial(int n)
{
    Number res(1);
    for (int i = 2; i <= n; ++i)
        res = res * Number(i);
    return res;
}

int main()
{
    Number a = "12345678";
    Number b = 42;
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a * b = " << a * b << "\n";
    std::cout << "isEven(a) = " << a.isEven() << "\n";
    std::cout << "isEven(b) = " << b.isEven() << "\n\n";

    Number f1000 = fib(1000);
    std::cout << "F(1000) = " << f1000 << "\n\n";

    Number fact1000 = factorial(1000);
    std::cout << "1000! = " << fact1000 << "\n";
}

