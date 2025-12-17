#include <iostream>
#include <list>

int main()
{
    int n, m;
    if (!(std::cin >> n >> m))
        return 0;

    std::list<int> soldiers;
    for (int i = 1; i <= n; ++i)
        soldiers.push_back(i);

    auto it = soldiers.begin();

    bool first = true;
    while (!soldiers.empty())
    {
        for (int cnt = 1; cnt < m; ++cnt)
        {
            ++it;
            if (it == soldiers.end())
                it = soldiers.begin();
        }

        if (!first)
            std::cout << ' ';
        first = false;
        std::cout << *it;

        auto to_erase = it++;
        if (it == soldiers.end())
            it = soldiers.begin();
        soldiers.erase(to_erase);

        if (soldiers.empty())
            break;
    }

    std::cout << std::endl;
}
