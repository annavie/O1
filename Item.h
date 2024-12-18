// Item.hpp
#ifndef ITEM_HPP
#define ITEM_HPP

#include "BoundingBox.h"
#include <string>
#include <memory>

class Item {
public:
    virtual ~Item() = default;

    virtual void draw() const = 0;

    const BoundingBox& getBoundingBox() const {
        return *boundingBox;
    }
    void setBoundingBox(std::unique_ptr<BoundingBox> bbox) {
        boundingBox = std::move(bbox);
    }
    virtual std::string info() const = 0;
    virtual Point getPosition() const = 0;
    virtual void setPosition(const Point& pos) = 0;
    virtual Size getSize() const = 0;
    virtual void setSize(const Size& size) = 0;
    virtual std::unique_ptr<Item> clone() const = 0;


protected:
    std::unique_ptr<BoundingBox> boundingBox;
};

#endif // ITEM_HPP
