// TextItem.hpp
#ifndef TEXTITEM_HPP
#define TEXTITEM_HPP

#include "Shape.h"
#include <string>
#include <memory>
#include <iostream>

class TextItem : public Shape {
public:
    // Constructor
    TextItem(int id, const std::string& color, const std::string& text, const Point& pos)
        : id(id), color(color), text(text) {
        boundingBox = std::make_unique<BoundingBox>(pos.x, pos.y, calculateWidth(), calculateHeight());
    }

    // Copy Constructor
    TextItem(const TextItem& other)
        : Shape(other), // Calls Shape's copy constructor
        id(other.id),
        color(other.color),
        text(other.text) {
        // boundingBox is already handled by Shape's copy constructor
    }

    // Copy Assignment Operator
    TextItem& operator=(const TextItem& other) {
        if (this != &other) {
            Shape::operator=(other); // Assign base class
            id = other.id;
            color = other.color;
            text = other.text;
            // boundingBox is already handled by Shape's assignment operator
        }
        return *this;
    }

    // Override virtual methods
    void draw() const override {
        std::cout << "TextItem(ID: " << id << ", Color: " << color << ", Text: \"" << text << "\") ";
        boundingBox->print();
    }

    std::string info() const override {
        return "TextItem(ID: " + std::to_string(id) + ", Color: " + color + ", Text: \"" + text + "\")";
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
        return std::make_unique<TextItem>(*this);
    }

private:
    int id;
    std::string color;
    std::string text;

    // Helper methods to calculate size based on text length
    int calculateWidth() const {
        return static_cast<int>(text.length()) * 10; // Example calculation
    }

    int calculateHeight() const {
        return 20; // Example fixed height
    }
};

#endif // TEXTITEM_HPP
