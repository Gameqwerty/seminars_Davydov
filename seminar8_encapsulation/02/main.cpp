#include <iostream>
#include "vector2f.hpp"

using std::cout, std::endl;

int main()
{
    Vector2f a = {1.0f, 2.0f};
    Vector2f b = {4.0f, -1.0f};

    cout << "a = " << a << "  b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "-a = " << -a << endl;
    cout << "Scalar product of a and b = " << a * b << endl;

    a *= 5.0f;
    cout << "a after a *= 5: " << a << endl;

    a += b;
    cout << "a after a += b: " << a << endl;
}
