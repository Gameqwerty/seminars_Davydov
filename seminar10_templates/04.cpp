#include <iostream>
#include <vector>
#include <string>
#include <array>

template<typename C1, typename C2>
bool hasMoreElements(const C1& a, const C2& b)
{
    return a.size() > b.size();
}

int main()
{
    std::vector<int> a {10, 20, 30, 40, 50};
    std::string b = "Cat";
    std::string c = "Elephant";
    std::array<int, 3> d {10, 20, 30};

    std::cout << hasMoreElements(a, b) << std::endl;
    std::cout << hasMoreElements(a, c) << std::endl;
    std::cout << hasMoreElements(a, d) << std::endl;
}
