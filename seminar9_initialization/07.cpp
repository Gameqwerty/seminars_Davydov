#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

int sumFromString(const std::string& s)
{
    if (s.size() < 2 || s.front() != '[' || s.back() != ']')
        throw std::invalid_argument("bad format");

    int sum = 0;
    std::size_t i = 1;
    std::size_t end = s.size() - 1;

    bool expectingNumber = true;
    bool hasAny = false;

    while (i < end)
    {
        while (i < end && std::isspace(static_cast<unsigned char>(s[i])))
            ++i;
        if (i >= end)
            break;

        if (expectingNumber)
        {
            if (!std::isdigit(static_cast<unsigned char>(s[i])) &&
                s[i] != '+' && s[i] != '-')
            {
                if (!hasAny)
                    break;
                throw std::invalid_argument("expected number");
            }

            int sign = 1;
            if (s[i] == '+' || s[i] == '-')
            {
                if (s[i] == '-')
                    sign = -1;
                ++i;
                if (i >= end || !std::isdigit(static_cast<unsigned char>(s[i])))
                    throw std::invalid_argument("bad sign/number");
            }

            int value = 0;
            bool hasDigit = false;
            while (i < end && std::isdigit(static_cast<unsigned char>(s[i])))
            {
                hasDigit = true;
                value = value * 10 + (s[i] - '0');
                ++i;
            }
            if (!hasDigit)
                throw std::invalid_argument("no digits");

            sum += sign * value;
            hasAny = true;
            expectingNumber = false;
        }
        else
        {
            if (s[i] == ',')
            {
                expectingNumber = true;
                ++i;
            }
            else
            {
                throw std::invalid_argument("expected comma");
            }
        }
    }

    if (expectingNumber && hasAny)
        throw std::invalid_argument("trailing comma");

    return sum;
}

int main()
{
    const std::string tests[] = {
        "[10, 20, 30, 40, 50]",
        "[4, 8, 15, 16, 23, 42]",
        "[20]",
        "[]",
        "[10, a]"
    };

    for (const auto& s : tests)
    {
        try
        {
            int result = sumFromString(s);
            std::cout << s << " -> " << result << '\n';
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << s << " -> invalid_argument: " << e.what() << '\n';
        }
    }
}

