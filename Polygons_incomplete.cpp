#include <iostream>

// Abstract Base Class: Polygon
class Polygon {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual ~Polygon() {}
};

// Derived Class: Rectangle
class Rectangle : public Polygon {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    virtual double area() const override {
        return width * height;
    }
};

// Derived Class: Triangle
class Triangle : public Polygon {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    virtual double area() const override {
        return 0.5 * base * height;  // Area formula for a triangle
    }
};

int main() {
    Rectangle rect(3, 4);  // Example rectangle
    Triangle tri(3, 4);    // Example triangle

    Polygon* poly1 = &rect;  // Polygon pointer to a rectangle
    Polygon* poly2 = &tri;   // Polygon pointer to a triangle

    std::cout << "Rectangle area: " << poly1->area() << std::endl;  // Output rectangle area
    std::cout << "Triangle area: " << poly2->area() << std::endl;  // Output triangle area

    return 0;
}
