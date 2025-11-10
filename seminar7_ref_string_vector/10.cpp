#include <iostream>
#include <string>

bool isDomainName(const std::string& s)
{
    return s.starts_with("www.") && s.ends_with(".com") && s.size() > 8;
}

int main()
{
    std::cout << isDomainName("www.google.com") << std::endl;
    std::cout << isDomainName("abc") << std::endl;
    std::cout << isDomainName("hello.com") << std::endl;
}
