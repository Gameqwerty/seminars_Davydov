#include <iostream>
#include <string>

std::string repeat(int n)
{
    if (n <= 0) return {};
    std::string token = std::to_string(n);
    std::string res;
    res.reserve(token.size() * static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) res += token;
    return res;
}

int main()
{
    std::cout << repeat(5)  << std::endl;
    std::cout << repeat(10) << std::endl;
    std::cout << repeat(-1) << std::endl;
}
