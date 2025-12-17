#include <iostream>
#include <set>

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;

    std::multiset<int> ms;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        ms.insert(x);
    }

    bool first = true;
    for (int x : ms)
    {
        if (!first) std::cout << ' ';
        first = false;
        std::cout << x;
    }
    std::cout << std::endl;
}
