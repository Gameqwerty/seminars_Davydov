#include <iostream>
#include <cmath>
#include "point.hpp"
using std::cout, std::endl;

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(const Point& center, float radius)
        : center(center), radius(radius >= 0.f ? radius : 0.f) {}

    Circle() : center{0, 0}, radius(1.f) {}

    Circle(const Circle& c) : center(c.center), radius(c.radius) {}

    Point getCenter() const { return center; }
    float getRadius() const { return radius; }

    void setCenter(const Point& p) { center = p; }
    void setRadius(float r) { radius = r >= 0.f ? r : 0.f; }

    float area() const {
        static constexpr float pi = 3.14159265358979323846f;
        return pi * radius * radius;
    }

    float distance(const Point& p) const {
        float dx = p.getX() - center.getX();
        float dy = p.getY() - center.getY();
        float d = std::sqrt(dx*dx + dy*dy);
        return std::fabs(d - radius);
    }

    bool isColliding(const Circle& c) const {
        float dx = c.center.getX() - center.getX();
        float dy = c.center.getY() - center.getY();
        float d = std::sqrt(dx*dx + dy*dy);
        return d <= (radius + c.radius);
    }

    void move(const Point& p) { center = center + p; }
};


int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;


	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;

}