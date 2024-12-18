// ResizeItemCommand.hpp
#ifndef RESIZEITEMCOMMAND_HPP
#define RESIZEITEMCOMMAND_HPP

#include "Command.h"
#include "Document.h"
#include "Item.h"
#include "Point.h"

class ResizeItemCommand : public Command {
public:
    ResizeItemCommand(int slideIdx, int itemIdx, const Size& newSz)
        : slideIndex(slideIdx), itemIndex(itemIdx), newSize(newSz), oldSize(0, 0) {}

    void execute(Editor& editor) override;
    void undo(Editor& editor) override;

private:
    int slideIndex;
    int itemIndex;
    Size newSize;
    Size oldSize;
};

#endif // RESIZEITEMCOMMAND_HPP
