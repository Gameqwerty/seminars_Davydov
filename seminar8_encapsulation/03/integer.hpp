#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>

class Integer
{
private:
    static const int base = 100;
    std::vector<unsigned char> data;

    void normalize();

public:
    Integer();
    Integer(int a);
    Integer(const std::string& s);
    Integer(const char* cstr);
    Integer(const Integer& other) = default;
    ~Integer() = default;

    Integer& operator=(const Integer& other) = default;

    bool isEven() const;

    Integer operator+(const Integer& other) const;
    Integer& operator+=(const Integer& other);
    Integer operator*(const Integer& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Integer& n);
    friend std::istream& operator>>(std::istream& is, Integer& n);
};
