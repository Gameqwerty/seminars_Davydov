#include <iostream>

template<typename Int, Int MOD>
class Modular
{
private:
    Int value;

    static Int normalize(long long v)
    {
        long long m = MOD;
        v %= m;
        if (v < 0) v += m;
        return static_cast<Int>(v);
    }

public:
    Modular(long long v = 0)
        : value(normalize(v))
    {}

    Modular(const Modular& other) = default;

    template<typename OtherInt, OtherInt OTHER_MOD>
    Modular(const Modular<OtherInt, OTHER_MOD>& other)
        : value(normalize(other.get()))
    {}

    Modular& operator=(const Modular& other) = default;

    Int get() const
    {
        return value;
    }

    Modular operator-() const
    {
        return Modular(-static_cast<long long>(value));
    }

    Modular& operator+=(const Modular& rhs)
    {
        value = normalize(static_cast<long long>(value) + rhs.value);
        return *this;
    }

    Modular& operator-=(const Modular& rhs)
    {
        value = normalize(static_cast<long long>(value) - rhs.value);
        return *this;
    }

    Modular& operator*=(const Modular& rhs)
    {
        value = normalize(static_cast<long long>(value) * rhs.value);
        return *this;
    }

    friend Modular operator+(Modular lhs, const Modular& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    friend Modular operator-(Modular lhs, const Modular& rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    friend Modular operator*(Modular lhs, const Modular& rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    friend std::ostream& operator<<(std::ostream& os, const Modular& x)
    {
        return os << x.value;
    }
};

int main()
{
    Modular<int, 7> a(10);
    std::cout << a << std::endl;
    a = (a + 8) * 4;
    std::cout << a << std::endl;

    Modular<int, 7> b(a);
    b = b + 2;
    a = a - b;
    std::cout << a << std::endl;

    Modular<short, 3> c(a);
    std::cout << c << std::endl;
}
