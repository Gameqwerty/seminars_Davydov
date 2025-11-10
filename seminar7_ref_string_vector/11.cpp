#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void doubling(std::vector<int>& v)
{
    std::size_t n = v.size();
    v.reserve(2 * n);
    v.insert(v.end(), v.begin(), v.begin() + n);
}

int main()
{
    std::vector<int> v {10, 20, 30};
    doubling(v);
    print(v);
}
