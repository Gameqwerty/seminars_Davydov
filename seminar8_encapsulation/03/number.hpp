#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

    void normalize()
    {
        while (size > 1 && data[size - 1] == 0)
            --size;
    }

    void ensure_capacity(std::size_t new_cap)
    {
        if (new_cap <= capacity)
            return;
        std::size_t cap = capacity ? capacity : 1;
        while (cap < new_cap)
            cap *= 2;
        char* new_data = new char[cap];
        for (std::size_t i = 0; i < size; ++i)
            new_data[i] = data[i];
        delete [] data;
        data = new_data;
        capacity = cap;
    }

public:
        Number(const char* cstr)
        : Number(std::string(cstr))
    {
    }

    Number()
    {
        capacity = 1;
        size = 1;
        data = new char[capacity];
        data[0] = 0;
    }

    Number(int a) 
    {
        if (a == 0)
        {
            capacity = 1;
            size = 1;
            data = new char[capacity];
            data[0] = 0;
            return;
        }

        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        data = new char[capacity];
        size = capacity;

        for (std::size_t i = 0; i < size; ++i) 
        {
            data[i] = static_cast<char>(a % base);
            a /= base;
        }

        normalize();
    }

    Number(const Number& other)
    {
        capacity = other.capacity;
        size = other.size;
        data = new char[capacity];
        for (std::size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    Number(const std::string& str)
    {
        if (str.empty())
        {
            capacity = 1;
            size = 1;
            data = new char[capacity];
            data[0] = 0;
            return;
        }

        std::size_t len = str.size();
        capacity = (len + 1) / 2;
        size = capacity;
        data = new char[capacity];

        std::size_t pos = len;
        std::size_t idx = 0;
        while (pos > 0)
        {
            char units = str[--pos];
            char tens = '0';
            if (pos > 0)
                tens = str[--pos];

            int digit = (tens - '0') * 10 + (units - '0');
            data[idx++] = static_cast<char>(digit);
        }

        normalize();
    }

    ~Number() 
    {
        delete [] data;
    }

    Number& operator=(const Number& other)
    {
        if (this == &other)
            return *this;

        if (capacity < other.size)
        {
            delete [] data;
            capacity = other.size;
            data = new char[capacity];
        }

        size = other.size;
        for (std::size_t i = 0; i < size; ++i)
            data[i] = other.data[i];

        return *this;
    }

    Number operator+(const Number& other) const
    {
        Number res;
        std::size_t max_size = size > other.size ? size : other.size;

        res.ensure_capacity(max_size + 1);
        res.size = max_size;

        int carry = 0;
        for (std::size_t i = 0; i < max_size; ++i)
        {
            int av = (i < size)  ? static_cast<unsigned char>(data[i])       : 0;
            int bv = (i < other.size) ? static_cast<unsigned char>(other.data[i]) : 0;

            int sum = av + bv + carry;
            res.data[i] = static_cast<char>(sum % base);
            carry = sum / base;
        }

        if (carry)
        {
            res.data[res.size++] = static_cast<char>(carry);
        }

        res.normalize();
        return res;
    }

    Number& operator+=(const Number& other)
    {
        *this = *this + other;
        return *this;
    }

    bool isEven() const
    {
        return (static_cast<unsigned char>(data[0]) % 2) == 0;
    }

    Number operator*(const Number& other) const
    {
        Number res;
        std::size_t n = size;
        std::size_t m = other.size;

        res.ensure_capacity(n + m + 1);
        res.size = n + m + 1;
        for (std::size_t i = 0; i < res.size; ++i)
            res.data[i] = 0;

        for (std::size_t i = 0; i < n; ++i)
        {
            int carry = 0;
            for (std::size_t j = 0; j < m; ++j)
            {
                int cur = static_cast<unsigned char>(res.data[i + j]) +
                          static_cast<unsigned char>(data[i]) *
                          static_cast<unsigned char>(other.data[j]) +
                          carry;

                res.data[i + j] = static_cast<char>(cur % base);
                carry = cur / base;
            }

            std::size_t pos = i + m;
            while (carry)
            {
                int cur = static_cast<unsigned char>(res.data[pos]) + carry;
                res.data[pos] = static_cast<char>(cur % base);
                carry = cur / base;
                ++pos;
            }
        }

        res.normalize();
        return res;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    stream << static_cast<int>(num.data[num.size - 1]);

    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2)
               << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}
