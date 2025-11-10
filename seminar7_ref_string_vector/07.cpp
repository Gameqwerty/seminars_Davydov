#include <iostream>
#include <string>

void addBrackets(std::string& s)
{
    s.insert(s.begin(), '[');
    s.push_back(']');
}

int main()
{
    std::string a = "Cat";
    addBrackets(a);
    std::cout << a << std::endl;

    addBrackets(a);
    std::cout << a << std::endl;
}
