#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> prefixes(const std::string& s)
{
    std::vector<std::string> res;
    res.reserve(s.size());
    std::string cur;
    cur.reserve(s.size());
    for (char ch : s) 
    {
        cur.push_back(ch);
        res.push_back(cur);
    }
    return res;
}

int main()
{
    std::vector<std::string> v = prefixes("Mouse");
    print(v);
}
