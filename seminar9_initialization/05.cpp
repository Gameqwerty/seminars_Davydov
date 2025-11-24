#include <iostream>
#include <string>
#include <new>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1 = "Cat";

    string* ps = new string("Dog");

    alignas(string) char x[sizeof(string)];
    string* pe = new (x) string("Elephant");

    cout << s1 << endl;
    cout << *ps << endl;
    cout << *pe << endl;

    delete ps;
    pe->~string();
}
