// Rectangle.hpp
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.h"

class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(int id, const std::string& color, const Size& size, const Point& pos)
        : id(id), color(color) {
        boundingBox = std::make_unique<BoundingBox>(pos.x, pos.y, size.width, size.height);
    }

    // Copy constructor
    Rectangle(const Rectangle& other)
        : Shape(other), // Calls Shape's copy constructor
        id(other.id),
        color(other.color) {
        // `boundingBox` is already handled by Shape's copy constructor
    }

    // Copy assignment operator
    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) {
            Shape::operator=(other); // Assign base class
            id = other.id;
            color = other.color;
            // `boundingBox` is already handled by Shape's assignment operator
        }
        return *this;
    }

    // Override virtual methods
    void draw() const override {
        std::cout << "Rectangle(ID: " << id << ", Color: " << color << ") ";
        boundingBox->print();
    }

    std::string info() const override {
        return "Rectangle(ID: " + std::to_string(id) + ", Color: " + color + ")";
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
        boundingBox->setSize(sz);
    }

    void setColor(const std::string& newColor)  override{
        color = newColor;
    }

    std::string getColor() const override {
        return color;
    }

    // Clone method
    std::unique_ptr<Item> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

private:
    int id;
    std::string color;
};
#endif
