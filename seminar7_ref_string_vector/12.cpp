#include <iostream>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& v)
{
    std::size_t total = 0;
    for (const auto& s : v) total += s.size();

    std::string res;
    res.reserve(total);
    for (const auto& s : v) res += s;
    return res;
}

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
    std::cout << concatenate(v) << std::endl;
}
