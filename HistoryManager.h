// HistoryManager.hpp
#ifndef HISTORYMANAGER_HPP
#define HISTORYMANAGER_HPP

#include "Command.h"
#include <stack>
#include <memory>
#include <stdexcept>

class HistoryManager {
public:
    HistoryManager() = default;

    /**
     * @brief Executes a command and adds it to the undo stack.
     *
     * @param cmd The command to execute.
     * @param editor The Editor instance.
     */
    void executeCommand(std::unique_ptr<Command> cmd, class Editor& editor) {
        cmd->execute(editor);
        undoStack.push(std::move(cmd));
        // Clear the redo stack on new command
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    /**
     * @brief Undoes the last executed command.
     *
     * @param editor The Editor instance.
     */
    void undo(Editor& editor) {
        if (undoStack.empty()) {
            throw std::runtime_error("Nothing to undo.");
        }
        auto cmd = std::move(undoStack.top());
        undoStack.pop();
        cmd->undo(editor);
        redoStack.push(std::move(cmd));
    }

    /**
     * @brief Redoes the last undone command.
     *
     * @param editor The Editor instance.
     */
    void redo(Editor& editor) {
        if (redoStack.empty()) {
            throw std::runtime_error("Nothing to redo.");
        }
        auto cmd = std::move(redoStack.top());
        redoStack.pop();
        cmd->execute(editor);
        undoStack.push(std::move(cmd));
    }

private:
    std::stack<std::unique_ptr<Command>> undoStack;
    std::stack<std::unique_ptr<Command>> redoStack;
};

#endif // HISTORYMANAGER_HPP
