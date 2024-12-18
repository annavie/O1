// HelpCommand.hpp
#ifndef HELPCOMMAND_HPP
#define HELPCOMMAND_HPP

#include "Command.h"

class HelpCommand : public Command {
public:
    void execute(Editor& editor) override;
    void undo(Editor& editor) override;
};

#endif // HELPCOMMAND_HPP
