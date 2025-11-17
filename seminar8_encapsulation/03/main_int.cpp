#include <iostream>
#include "integer.hpp"

using std::cout;
using std::endl;

Integer fib(int n)
{
    if (n == 0) return Integer(0);
    if (n == 1) return Integer(1);

    Integer a(0);
    Integer b(1);
    for (int i = 2; i <= n; ++i)
    {
        Integer c = a + b;
        a = b;
        b = c;
    }
    return b;
}

Integer factorial(int n)
{
    Integer res(1);
    for (int i = 2; i <= n; ++i)
        res = res * Integer(i);
    return res;
}

int main()
{
    Integer a = "12345678";
    Integer b = 42;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "isEven(a) = " << a.isEven() << endl;
    cout << "isEven(a) = " << b.isEven() << endl;
    cout << endl;

    Integer f1000 = fib(1000);
    cout << "F(1000) = " << f1000 << endl << endl;

    Integer fact1000 = factorial(1000);
    cout << "1000! = " << fact1000 << endl;
}
