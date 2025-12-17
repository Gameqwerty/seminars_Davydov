#include <iostream>
#include <map>

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;

    std::map<long long, long long> cnt;

    for (int i = 0; i < n; ++i)
    {
        long long x;
        std::cin >> x;
        ++cnt[x];
    }

    bool first = true;
    for (const auto& p : cnt)
    {
        if (!first) std::cout << ' ';
        first = false;
        std::cout << p.first;
    }
    std::cout << std::endl;

    first = true;
    for (const auto& p : cnt)
    {
        if (!first) std::cout << ' ';
        first = false;
        std::cout << p.second;
    }
    std::cout << std::endl;
}
