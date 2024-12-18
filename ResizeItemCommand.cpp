// ResizeItemCommand.cpp
#include "ResizeItemCommand.h"
#include "Editor.h"

void ResizeItemCommand::execute(Editor& editor) {
    Slide* slide = editor.getDocument().getSlide(slideIndex);
    if (slide) {
        Item* item = slide->getItem(itemIndex);
        if (item) {
            oldSize = item->getSize();
            item->setSize(newSize);
            std::cout << "Item " << itemIndex << " on slide " << slideIndex
                      << " resized from (" << oldSize.width << "x" << oldSize.height
                      << ") to (" << newSize.width << "x" << newSize.height << ").\n";
        } else {
            std::cout << "Invalid item index: " << itemIndex << " on slide " << slideIndex << ".\n";
        }
    } else {
        std::cout << "Invalid slide index: " << slideIndex << ".\n";
    }
}

void ResizeItemCommand::undo(Editor& editor) {
    Slide* slide = editor.getDocument().getSlide(slideIndex);
    if (slide) {
        Item* item = slide->getItem(itemIndex);
        if (item) {
            item->setSize(oldSize);
            std::cout << "Resize undone for item " << itemIndex << " on slide " << slideIndex
                      << ". Size reverted to (" << oldSize.width << "x" << oldSize.height << ").\n";
        }
    }
}
