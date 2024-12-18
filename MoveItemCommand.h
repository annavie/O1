// MoveItemCommand.hpp
#ifndef MOVEITEMCOMMAND_HPP
#define MOVEITEMCOMMAND_HPP

#include "Command.h"
#include "Document.h"
#include "Item.h"
#include "Point.h"

class MoveItemCommand : public Command {
public:
    MoveItemCommand(int slideIdx, int itemIdx, const Point& newPos)
        : slideIndex(slideIdx), itemIndex(itemIdx), newPosition(newPos), oldPosition(0, 0) {}

    void execute(Editor& editor) override;
    void undo(Editor& editor) override;

private:
    int slideIndex;
    int itemIndex;
    Point newPosition;
    Point oldPosition;
};

#endif // MOVEITEMCOMMAND_HPP
