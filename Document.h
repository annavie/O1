// Document.hpp
#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Slide.h"
#include <vector>
#include <memory>

class Document {
public:
    Document() = default;

    Document(const Document& other) {
        slides.reserve(other.slides.size());
        for (const auto& slide : other.slides) {
            slides.push_back(std::make_unique<Slide>(*slide));
        }
    }

    // Copy assignment operator
    Document& operator=(const Document& other) {
        if (this != &other) {
            slides.clear();
            slides.reserve(other.slides.size());
            for (const auto& slide : other.slides) {
                slides.push_back(std::make_unique<Slide>(*slide));
            }
        }
        return *this;
    }

    // Methods to manage slides
    void addSlide(std::unique_ptr<Slide> slide) {
        slides.push_back(std::move(slide));
    }

    void deleteSlide(size_t index) {
        if (index < slides.size()) {
            slides.erase(slides.begin() + index);
        }
    }

    Slide* getSlide(size_t index) const {
        if (index < slides.size()) {
            return slides[index].get();
        }
        return nullptr;
    }

    size_t getSlideCount() const {
        return slides.size();
    }

    void printDocument() const {
        std::cout << "Document contains " << slides.size() << " slides:\n";
        for (size_t i = 0; i < slides.size(); ++i) {
            std::cout << "Slide " << i << ":\n";
            slides[i]->printItems();
        }
    }

private:
    std::vector<std::unique_ptr<Slide>> slides;
};

#endif // DOCUMENT_HPP
