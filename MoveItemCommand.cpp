// MoveItemCommand.cpp
#include "MoveItemCommand.h"
#include "Editor.h"

void MoveItemCommand::execute(Editor& editor) {
    Slide* slide = editor.getDocument().getSlide(slideIndex);
    if (slide) {
        Item* item = slide->getItem(itemIndex);
        if (item) {
            oldPosition = item->getPosition();
            item->setPosition(newPosition);
            std::cout << "Item " << itemIndex << " on slide " << slideIndex
                      << " moved from (" << oldPosition.x << ", " << oldPosition.y
                      << ") to (" << newPosition.x << ", " << newPosition.y << ").\n";
        } else {
            std::cout << "Invalid item index: " << itemIndex << " on slide " << slideIndex << ".\n";
        }
    } else {
        std::cout << "Invalid slide index: " << slideIndex << ".\n";
    }
}

void MoveItemCommand::undo(Editor& editor) {
    Slide* slide = editor.getDocument().getSlide(slideIndex);
    if (slide) {
        Item* item = slide->getItem(itemIndex);
        if (item) {
            item->setPosition(oldPosition);
            std::cout << "Move undone for item " << itemIndex << " on slide " << slideIndex
                      << ". Position reverted to (" << oldPosition.x << ", " << oldPosition.y << ").\n";
        }
    }
}
