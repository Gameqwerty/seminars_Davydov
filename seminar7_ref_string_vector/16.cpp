#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& s, char delim)
{
    std::vector<std::string> res;
    std::size_t start = 0;
    while (true) {
        std::size_t pos = s.find(delim, start);
        if (pos == std::string::npos) {
            res.emplace_back(s.substr(start));
            break;
        }
        res.emplace_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    return res;
}

int main()
{
    std::string data = "apple,banana,cherry,durian";
    char delimiter = ',';

    std::vector<std::string> parts = split(data, delimiter);
    for (std::size_t i = 0; i < parts.size(); ++i)
        std::cout << parts.at(i) << std::endl;
}
