#include <iostream>
#include <set>

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;

    std::set<int> s;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    bool first = true;
    for (int x : s)
    {
        if (!first) std::cout << ' ';
        first = false;
        std::cout << x;
    }
    std::cout << std::endl;
}
