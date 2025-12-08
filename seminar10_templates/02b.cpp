#include <iostream>
#include <string>

std::string operator*(int n, const std::string& s)
{
    std::string res;
    if (n <= 0)
        return res;

    res.reserve(s.size() * n);
    for (int i = 0; i < n; ++i)
        res += s;
    return res;
}

template<typename T>
T triple(const T& x)
{
    return 3 * x;
}

int main()
{
    int a = 10;
    std::cout << triple(a) << std::endl;

    std::string b = "Cat";
    std::cout << triple(b) << std::endl;
}
