// BoundingBox.hpp
#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

#include "Point.h"
#include <iostream>

class BoundingBox {
public:
    BoundingBox(int x, int y, int width, int height)
        : position(x, y), size(width, height) {}

    // Copy constructor
    BoundingBox(const BoundingBox& other)
        : position(other.position), size(other.size) {}

    // Copy assignment operator
    BoundingBox& operator=(const BoundingBox& other) {
        if (this != &other) {
            position = other.position;
            size = other.size;
        }
        return *this;
    }

    void print() const {
        std::cout << "BoundingBox(Position: (" << position.x << ", " << position.y << "), Size: ("
                  << size.width << "x" << size.height << "))\n";
    }

    Point getPosition() const { return position; }
    void setPosition(const Point& pos) { position = pos; }

    Size getSize() const { return size; }
    void setSize(const Size& sz) { size = sz; }

private:
    Point position;
    Size size;
};

#endif // BOUNDINGBOX_HPP
