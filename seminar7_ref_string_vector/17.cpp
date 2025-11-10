#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <iostream>

std::vector<std::vector<std::size_t>>
calculate_word_lengths(const std::string& filename)
{
    std::ifstream in(filename);
    std::vector<std::vector<std::size_t>> res;
    if (!in) return res;

    std::string line;
    while (std::getline(in, line)) {
        std::vector<std::size_t> row;
        std::size_t i = 0, n = line.size();
        while (i < n) {
            while (i < n && std::isspace(static_cast<unsigned char>(line[i]))) ++i;
            std::size_t j = i;
            while (j < n && !std::isspace(static_cast<unsigned char>(line[j]))) ++j;
            if (j > i) row.push_back(j - i);
            i = j;
        }
        res.push_back(std::move(row));
    }
    return res;
}

int main()
{
    auto vv = calculate_word_lengths("words.txt");

    std::cout << "{";
    for (std::size_t i = 0; i < vv.size(); ++i) {
        std::cout << "{";
        for (std::size_t j = 0; j < vv[i].size(); ++j) {
            std::cout << vv[i][j];
            if (j + 1 < vv[i].size()) std::cout << ", ";
        }
        std::cout << "}";
        if (i + 1 < vv.size()) std::cout << ", ";
    }
    std::cout << "}\n";
}
