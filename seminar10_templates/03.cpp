#include <iostream>
#include <vector>
#include <utility>
#include <string>

template<typename T>
std::pair<T, T> minmax(const std::vector<T>& v)
{
    T mn = v[0];
    T mx = v[0];
    for (std::size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] < mn) mn = v[i];
        if (mx < v[i]) mx = v[i];
    }
    return std::pair<T, T>(mn, mx);
}

int main()
{
    std::vector<int> a {60, 10, 40, 80, 30};
    auto am = minmax(a);
    std::cout << am.first << " " << am.second << std::endl;

    std::vector<std::string> b {"Cat", "Dog", "Mouse", "Camel", "Wolf"};
    auto bm = minmax(b);
    std::cout << bm.first << " " << bm.second << std::endl;

    std::vector<std::pair<int, int>> c {{10, 90}, {30, 10}, {20, 40}, {10, 50}};
    auto cm = minmax(c);
    std::cout << cm.first.first << " " << cm.first.second << std::endl;
    std::cout << cm.second.first << " " << cm.second.second << std::endl;
}
