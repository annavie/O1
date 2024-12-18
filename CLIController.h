// CLIController.hpp
#ifndef CLICONTROLLER_HPP
#define CLICONTROLLER_HPP

#include "Controller.h"
#include <string>

/**
 * @brief Handles the Command-Line Interface (CLI) interactions with the user.
 */
class CLIController {
public:
    CLIController(Controller& controller);

    void start();

private:
    Controller& controller;
    void displayWelcomeMessage() const;
    void processInput(const std::string& inputLine);
};

#endif // CLICONTROLLER_HPP
