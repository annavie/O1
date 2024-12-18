// Circle.hpp
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(int id, const std::string& color, int radius, const Point& pos)
        : id(id), color(color), radius(radius) {
        boundingBox = std::make_unique<BoundingBox>(pos.x, pos.y, radius * 2, radius * 2);
    }

    void draw() const override {
        std::cout << "Circle(ID: " << id << ", Color: " << color << ", Radius: " << radius << ") ";
        boundingBox->print();
    }

    std::string info() const override {
        return "Circle(ID: " + std::to_string(id) + ", Color: " + color + ", Radius: " + std::to_string(radius) + ")";
    }

    Point getPosition() const override {
        return boundingBox->getPosition();
    }

    void setPosition(const Point& pos) override {
        boundingBox->setPosition(pos);
    }

    Size getSize() const override {
        return boundingBox->getSize();
    }

    void setSize(const Size& sz) override {
        if (sz.width != sz.height) {
            std::cout << "Warning: For circles, width and height should be equal. Adjusting to make them equal.\n";
            int minSize = std::min(sz.width, sz.height);
            boundingBox->setSize(Size(minSize, minSize));
            radius = minSize / 2;
        } else {
            boundingBox->setSize(sz);
            radius = sz.width / 2;
        }
    }

    void setColor(const std::string& newColor) override {
        color = newColor;
    }

    std::string getColor() const override {
        return color;
    }
    std::unique_ptr<Item> clone() const override {
        return std::make_unique<Circle>(*this);
    }

private:
    int id;
    std::string color;
    int radius;
};

#endif // CIRCLE_HPP
