// Command.hpp
#ifndef COMMAND_HPP
#define COMMAND_HPP

class Editor;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Editor& editor) = 0;

    virtual void undo(Editor& editor) = 0;
};

#endif // COMMAND_HPP
