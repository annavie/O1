// AddItemCommand.hpp
#ifndef ADDITEMCOMMAND_HPP
#define ADDITEMCOMMAND_HPP

#include "Command.h"
#include "Document.h"
#include "Item.h"
#include <memory>

class AddItemCommand : public Command {
public:
    AddItemCommand(int slideIdx, std::unique_ptr<Item> itm)
        : slideIndex(slideIdx), item(std::move(itm)), itemIndex(-1) {}

    void execute(Editor& editor) override;
    void undo(Editor& editor) override;

private:
    int slideIndex;
    std::unique_ptr<Item> item;
    int itemIndex; // Position where the item was added
};

#endif // ADDITEMCOMMAND_HPP
