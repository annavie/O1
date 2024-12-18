// DeleteSlideCommand.hpp
#ifndef DELETESLIDECOMMAND_HPP
#define DELETESLIDECOMMAND_HPP

#include "Command.h"
#include "Document.h"
#include "Slide.h"
#include <memory>

class DeleteSlideCommand : public Command {
public:
    DeleteSlideCommand(int index)
        : slideIndex(index), deletedSlide(nullptr) {}

    void execute(Editor& editor) override;
    void undo(Editor& editor) override;

private:
    int slideIndex;
    std::unique_ptr<Slide> deletedSlide;
};

#endif // DELETESLIDECOMMAND_HPP
