// ImageItem.hpp
#ifndef IMAGEITEM_HPP
#define IMAGEITEM_HPP

#include "Shape.h"
#include <string>
#include <memory>
#include <iostream>

class ImageItem : public Shape {
public:
    // Constructor
    ImageItem(int id, const std::string& color, const std::string& imagePath, const Point& pos)
        : id(id), color(color), imagePath(imagePath) {
        boundingBox = std::make_unique<BoundingBox>(pos.x, pos.y, calculateWidth(), calculateHeight());
    }

    // Copy Constructor
    ImageItem(const ImageItem& other)
        : Shape(other), // Calls Shape's copy constructor
        id(other.id),
        color(other.color),
        imagePath(other.imagePath) {
        // boundingBox is already handled by Shape's copy constructor
    }

    // Copy Assignment Operator
    ImageItem& operator=(const ImageItem& other) {
        if (this != &other) {
            Shape::operator=(other); // Assign base class
            id = other.id;
            color = other.color;
            imagePath = other.imagePath;
            // boundingBox is already handled by Shape's assignment operator
        }
        return *this;
    }

    // Override virtual methods
    void draw() const override {
        std::cout << "ImageItem(ID: " << id << ", Color: " << color << ", ImagePath: \"" << imagePath << "\") ";
        boundingBox->print();
    }

    std::string info() const override {
        return "ImageItem(ID: " + std::to_string(id) + ", Color: " + color + ", ImagePath: \"" + imagePath + "\")";
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

    void setColor(const std::string& newColor) override {
        color = newColor;
    }

    std::string getColor() const override {
        return color;
    }

    // Clone method
    std::unique_ptr<Item> clone() const override {
        return std::make_unique<ImageItem>(*this);
    }

private:
    int id;
    std::string color;
    std::string imagePath;

    // Helper methods to calculate size based on image dimensions
    int calculateWidth() const {
        return 100; // Example fixed width or derived from image metadata
    }

    int calculateHeight() const {
        return 100; // Example fixed height or derived from image metadata
    }
};

#endif // IMAGEITEM_HPP
