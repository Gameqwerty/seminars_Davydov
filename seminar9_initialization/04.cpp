#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

int main()
{
    int* pi = new int(123);
    std::string* ps = new std::string("Cats and Dogs");

    int* iarr = new int[5]{10, 20, 30, 40, 50};

    std::vector<int>* pv = new std::vector<int>{10, 20, 30, 40, 50};

    std::string* sarr = new std::string[3]{"Cat", "Dog", "Mouse"};

    cout << *pi << endl;
    cout << *ps << endl;

    for (int i = 0; i < 5; ++i)
        cout << iarr[i] << " ";
    cout << endl;

    for (int x : *pv)
        cout << x << " ";
    cout << endl;

    for (int i = 0; i < 3; ++i)
        cout << sarr[i] << " ";
    cout << endl;

    delete pi;
    delete ps;
    delete[] iarr;
    delete pv;
    delete[] sarr;
}
