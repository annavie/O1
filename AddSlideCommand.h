// AddSlideCommand.hpp
#ifndef ADDSLIDECOMMAND_HPP
#define ADDSLIDECOMMAND_HPP

#include "Command.h"
class Slide;
class Editor;
class AddSlideCommand : public Command {
public:
    AddSlideCommand() = default;

    void execute(Editor& editor) override;
    void undo(Editor& editor) override;
};

#endif // ADDSLIDECOMMAND_HPP
