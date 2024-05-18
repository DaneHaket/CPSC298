#include <iostream>
#include <cmath>
#include <string>

class Shape {
protected:
    double m_width;
    double m_height;
    std::string m_strType;

public:
    Shape(double width, double height, std::string type)
        : m_width(width), m_height(height), m_strType(type) {}

    virtual ~Shape() {}

    virtual void scale(double factor) = 0;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    void displayProperties() const {
        std::cout << "Type: " << m_strType << ", Width: " << m_width << ", Height: " << m_height << std::endl;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height)
        : Shape(width, height, "Rectangle") {}

    ~Rectangle() {}

    void scale(double factor) override {
        m_width *= factor;
        m_height *= factor;
    }

    double area() const override {
        return m_width * m_height;
    }

    double perimeter() const override {
        return 2 * (m_width + m_height);
    }
};

class Circle : public Shape {
public:
    Circle(double diameter)
        : Shape(diameter, diameter, "Circle") {}

    ~Circle() {}

    void scale(double factor) override {
        m_width *= factor;
        m_height *= factor;
    }

    double area() const override {
        return M_PI * std::pow((m_width / 2), 2);
    }

    double perimeter() const override {
        return M_PI * m_width;
    }
};

int main() {
    Shape* shapes[2];

    shapes[0] = new Circle(2.0);
    shapes[1] = new Rectangle(3.0, 2.0);

    for (int i = 0; i < 2; ++i) {
        shapes[i]->displayProperties();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        std::cout << "Perimeter: " << shapes[i]->perimeter() << std::endl;

        shapes[i]->scale(2.0);

        shapes[i]->displayProperties();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        std::cout << "Perimeter: " << shapes[i]->perimeter() << std::endl;

        delete shapes[i];
    }

    return 0;
}
