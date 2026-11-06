
#include <iostream>
using namespace std;

// Abstract Class
class Shape {
public:
    virtual double area() = 0;

    virtual ~Shape() {}
};

// Circle Class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }
};

// Rectangle Class
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() override {
        return length * width;
    }
};

int main() {

    Circle c(5);
    Rectangle r(10, 4);

    cout << "Circle Area: " << c.area() << endl;

    cout << "Rectangle Area: " << r.area() << endl;

    return 0;
}
