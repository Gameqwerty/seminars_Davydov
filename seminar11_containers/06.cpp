#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

using std::cout;
using std::endl;

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    out << "[";
    for (std::size_t i = 0; i + 1 < v.size(); ++i)
        out << v[i] << ", ";
    if (!v.empty())
        out << v.back();
    out << "]";
    return out;
}

template <typename Container>
auto pairing(const Container& cont)
{
    using T = typename Container::value_type;
    std::vector<std::pair<T, T>> result;

    auto it = cont.begin();
    while (it != cont.end()) {
        T first = *it;
        ++it;

        T second{};
        if (it != cont.end()) {
            second = *it;
            ++it;
        }

        result.emplace_back(std::move(first), std::move(second));
    }

    return result;
}

int main()
{
    std::vector<int> a {10, 20, 30, 40, 50, 60};
    cout << pairing(a) << endl;

    std::list<std::string> b {"cat", "dog", "mouse", "elephant", "tiget", "axolotl", "wolf"};
    cout << pairing(b) << endl;

    std::string c {"Cats and dogs!"};
    cout << pairing(c) << endl;
}


/*
    Программа должна напечатать:

    [(10, 20), (30, 40), (50, 60)]
    [(cat, dog), (mouse, elephant), (tiget, axolotl), (wolf, )]
    [(C, a), (t, s), ( , a), (n, d), ( , d), (o, g), (s, !)]
*/