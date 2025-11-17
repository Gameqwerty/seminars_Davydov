#pragma once

#include <iostream>

class Vector2f
{
private:
    float x;
    float y;

public:
    Vector2f() : x(0.0f), y(0.0f) {}
    Vector2f(float x, float y) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float v) { x = v; }
    void setY(float v) { y = v; }

    Vector2f operator+() const { return *this; }
    Vector2f operator-() const { return Vector2f(-x, -y); }

    Vector2f& operator+=(const Vector2f& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2f& operator-=(const Vector2f& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Vector2f& operator*=(float k)
    {
        x *= k;
        y *= k;
        return *this;
    }

    friend Vector2f operator+(const Vector2f& a, const Vector2f& b)
    {
        return Vector2f(a.x + b.x, a.y + b.y);
    }

    friend Vector2f operator-(const Vector2f& a, const Vector2f& b)
    {
        return Vector2f(a.x - b.x, a.y - b.y);
    }

    friend float operator*(const Vector2f& a, const Vector2f& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    friend Vector2f operator*(const Vector2f& v, float k)
    {
        return Vector2f(v.x * k, v.y * k);
    }

    friend Vector2f operator*(float k, const Vector2f& v)
    {
        return Vector2f(v.x * k, v.y * k);
    }

    friend bool operator==(const Vector2f& a, const Vector2f& b)
    {
        return a.x == b.x && a.y == b.y;
    }

    friend bool operator!=(const Vector2f& a, const Vector2f& b)
    {
        return !(a == b);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2f& v)
    {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector2f& v)
    {
        is >> v.x >> v.y;
        return is;
    }
};
