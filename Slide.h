// Slide.hpp
#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Item.h"
#include <vector>
#include <memory>

class Slide {
public:
    Slide() = default;

    // Copy constructor
    Slide(const Slide& other) {
        items.reserve(other.items.size());
        for (const auto& item : other.items) {
            items.push_back(item->clone());
        }
    }

    // Copy assignment operator
    Slide& operator=(const Slide& other) {
        if (this != &other) {
            items.clear();
            items.reserve(other.items.size());
            for (const auto& item : other.items) {
                items.push_back(item->clone());
            }
        }
        return *this;
    }

    // Methods to manage items
    void addItem(std::unique_ptr<Item> item) {
        items.push_back(std::move(item));
    }
    std::unique_ptr<Slide> clone() const {
        return std::make_unique<Slide>(*this);
    }


    void deleteItem(size_t index) {
        if (index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    void printItems() const {
        for (const auto& item : items) {
            std::cout << item->info() << "\n";
            item->draw();
        }
    }
    const std::vector<std::unique_ptr<Item>>& getItems() const {
        return items;
    }
    Item* getItem(size_t index) const {
        if (index < items.size()) {
            return items[index].get();
        }
        return nullptr;
    }

private:
    std::vector<std::unique_ptr<Item>> items;
};

#endif // SLIDE_HPP
