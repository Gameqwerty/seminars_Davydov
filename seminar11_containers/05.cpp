#include <iostream>
#include <set>

int main()
{
    long long n;
    int k;
    if (!(std::cin >> n >> k))
        return 0;

    std::set<long long> cuts;
    cuts.insert(0);
    cuts.insert(n);

    std::multiset<long long> segments;
    segments.insert(n);

    for (int i = 0; i < k; ++i)
    {
        long long x;
        std::cin >> x;

        auto itRight = cuts.upper_bound(x);
        auto itLeft  = std::prev(itRight);

        long long oldLen = *itRight - *itLeft;
        auto itSeg = segments.find(oldLen);
        if (itSeg != segments.end())
            segments.erase(itSeg);

        segments.insert(x - *itLeft);
        segments.insert(*itRight - x);
        cuts.insert(x);

        if (i > 0)
            std::cout << ' ';
        std::cout << *segments.rbegin();
    }

    std::cout << std::endl;
}
