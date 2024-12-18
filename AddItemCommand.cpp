// AddItemCommand.cpp
#include "AddItemCommand.h"
#include "Editor.h"

void AddItemCommand::execute(Editor& editor) {
    Slide* slide = editor.getDocument().getSlide(slideIndex);
    if (slide) {
        slide->addItem(std::move(item));
        itemIndex = static_cast<int>(slide->getItems().size()) - 1;
        std::cout << "Item added to slide " << slideIndex << " at position " << itemIndex << ".\n";
    }
}

void AddItemCommand::undo(Editor& editor) {
    Slide* slide = editor.getDocument().getSlide(slideIndex);
    if (slide && itemIndex != -1) {
        slide->deleteItem(itemIndex);
        std::cout << "Item at position " << itemIndex << " removed from slide " << slideIndex << ".\n";
    }
}
