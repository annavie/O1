// Shape.hpp
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Item.h"
#include "BoundingBox.h"
#include <memory>

class Shape : public Item {
public:
    Shape() = default;

    // Copy constructor
    Shape(const Shape& other) {
        if (other.boundingBox) {
            boundingBox = std::make_unique<BoundingBox>(*other.boundingBox);
        }
    }

    // Copy assignment operator
    Shape& operator=(const Shape& other) {
        if (this != &other) {
            if (other.boundingBox) {
                boundingBox = std::make_unique<BoundingBox>(*other.boundingBox);
            } else {
                boundingBox.reset();
            }
        }
        return *this;
    }
    virtual std::string getColor() const = 0;
    virtual void setColor(const std::string& ) = 0;

protected:
    std::unique_ptr<BoundingBox> boundingBox;
};

#endif // SHAPE_HPP
