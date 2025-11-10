#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits  = 0;

    for (unsigned char ch : str)
    {
        if (std::isalpha(ch)) ++numLetters;
        else if (std::isdigit(ch)) ++numDigits;
    }
}

int main()
{
    std::string s = "88 ergj 00 fg]]-";
    int letters, digits;

    countLetters(s, letters, digits);
    std::cout << letters << " " << digits << std::endl;
}
