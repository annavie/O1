// Controller.hpp
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Document.h"
#include "CommandFactory.h"
#include "Parser.h"
#include "Editor.h"
#include "ParsedCommand.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

class Controller {
public:
    Controller(Document& doc, CommandFactory& cmdFactory)
        : editor(doc), commandFactory(cmdFactory), parser() {}

    /**
     * @brief Executes a command based on a command line string.
     *
     * @param commandLine The raw command line string.
     */
    void executeCommand(const std::string& commandLine) {
        try {
            ParsedCommand pc = parser.parseLine(commandLine);
            if (!pc.isValid) {
                throw std::runtime_error(pc.errorMessage);
            }
            std::unique_ptr<Command> cmd = commandFactory.createCommand(pc);
            editor.executeCommand(std::move(cmd));
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    /**
     * @brief Undoes the last command.
     */
    void undo() {
        try {
            editor.undo();
        }
        catch (const std::exception& e) {
            std::cerr << "Undo Error: " << e.what() << "\n";
        }
    }

    /**
     * @brief Redoes the last undone command.
     */
    void redo() {
        try {
            editor.redo();
        }
        catch (const std::exception& e) {
            std::cerr << "Redo Error: " << e.what() << "\n";
        }
    }

    void printDocument() const {
        editor.getDocument().printDocument();
    }

private:
    Editor editor;
    CommandFactory& commandFactory;
    Parser parser;
};

#endif // CONTROLLER_HPP
