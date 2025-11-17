#include "integer.hpp"
#include <iomanip>
#include <algorithm>

void Integer::normalize()
{
    while (data.size() > 1 && data.back() == 0)
        data.pop_back();
}

Integer::Integer()
    : data(1, 0)
{
}

Integer::Integer(int a)
{
    if (a == 0)
    {
        data.assign(1, 0);
        return;
    }

    while (a != 0)
    {
        int digit = a % base;
        data.push_back(static_cast<unsigned char>(digit));
        a /= base;
    }

    normalize();
}

Integer::Integer(const std::string& s)
{
    if (s.empty())
    {
        data.assign(1, 0);
        return;
    }

    std::size_t len = s.size();
    data.clear();
    data.reserve((len + 1) / 2);

    std::size_t pos = len;
    while (pos > 0)
    {
        char units = s[--pos];
        char tens = '0';
        if (pos > 0)
            tens = s[--pos];

        int digit = (tens - '0') * 10 + (units - '0');
        data.push_back(static_cast<unsigned char>(digit));
    }

    normalize();
}

Integer::Integer(const char* cstr)
    : Integer(std::string(cstr))
{
}

bool Integer::isEven() const
{
    return (data[0] % 2) == 0;
}

Integer Integer::operator+(const Integer& other) const
{
    Integer res;
    res.data.clear();

    std::size_t maxSize = std::max(data.size(), other.data.size());
    res.data.resize(maxSize, 0);

    int carry = 0;
    for (std::size_t i = 0; i < maxSize; ++i)
    {
        int av = (i < data.size()) ? static_cast<unsigned char>(data[i]) : 0;
        int bv = (i < other.data.size()) ? static_cast<unsigned char>(other.data[i]) : 0;

        int sum = av + bv + carry;
        res.data[i] = static_cast<unsigned char>(sum % base);
        carry = sum / base;
    }

    if (carry)
        res.data.push_back(static_cast<unsigned char>(carry));

    res.normalize();
    return res;
}

Integer& Integer::operator+=(const Integer& other)
{
    *this = *this + other;
    return *this;
}

Integer Integer::operator*(const Integer& other) const
{
    Integer res;
    std::size_t n = data.size();
    std::size_t m = other.data.size();

    res.data.assign(n + m + 1, 0);

    for (std::size_t i = 0; i < n; ++i)
    {
        int carry = 0;
        for (std::size_t j = 0; j < m; ++j)
        {
            int cur = static_cast<unsigned char>(res.data[i + j]) +
                      static_cast<unsigned char>(data[i]) *
                      static_cast<unsigned char>(other.data[j]) +
                      carry;

            res.data[i + j] = static_cast<unsigned char>(cur % base);
            carry = cur / base;
        }

        std::size_t pos = i + m;
        while (carry)
        {
            int cur = static_cast<unsigned char>(res.data[pos]) + carry;
            res.data[pos] = static_cast<unsigned char>(cur % base);
            carry = cur / base;
            ++pos;
        }
    }

    res.normalize();
    return res;
}

std::ostream& operator<<(std::ostream& os, const Integer& n)
{
    if (n.data.empty())
    {
        os << 0;
        return os;
    }

    std::size_t i = n.data.size() - 1;
    os << static_cast<int>(n.data[i]);

    for (std::size_t k = 0; k < i; ++k)
    {
        std::size_t idx = i - 1 - k;
        os << std::setfill('0') << std::setw(2)
           << static_cast<int>(n.data[idx]);
    }

    return os;
}

std::istream& operator>>(std::istream& is, Integer& n)
{
    std::string s;
    if (!(is >> s))
        return is;
    n = Integer(s);
    return is;
}
