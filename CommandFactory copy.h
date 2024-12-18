// CommandFactory.hpp
#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include "Command.h"
#include "ParsedCommand.h"
#include <functional>
#include <map>
#include <string>
#include <memory>
#include <stdexcept> // Add this line for std::runtime_error


using CommandCreator = std::function<std::unique_ptr<Command>(const ParsedCommand&)>;

class CommandFactory {
public:
    /**
     * @brief Registers a command with a corresponding creator function.
     *
     * @param commandName The name of the command.
     * @param creator The function that creates the command.
     */
    void registerCommand(const std::string& commandName, CommandCreator creator) {
        commandRegistry[commandName] = creator;
    }

    /**
     * @brief Creates a command based on the parsed command.
     *
     * @param pc The parsed command.
     * @return A unique_ptr to the created Command.
     */
    std::unique_ptr<Command> createCommand(const ParsedCommand& pc) const {
        auto it = commandRegistry.find(pc.commandName);
        if (it != commandRegistry.end()) {
            return it->second(pc);
        }
        throw std::runtime_error("Unknown command: " + pc.commandName);
    }

private:
    std::map<std::string, CommandCreator> commandRegistry;
};

#endif // COMMANDFACTORY_HPP
