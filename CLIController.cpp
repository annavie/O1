#include "CLIController.h"
#include <iostream>
#include <algorithm> // For std::transform
#include <sstream>   // For std::istringstream
#include <limits> // For std::numeric_limits

CLIController::CLIController(Controller& controller)
    : controller(controller) {}
void CLIController::start() {
    displayWelcomeMessage();

    std::string inputLine;
    while (true) {
        std::cout << "\n> ";
        if (!std::getline(std::cin, inputLine)) {
            // Handle EOF or input failure
            if (std::cin.eof()) {
                std::cout << "\nEnd of input detected. Exiting application.\n";
                break;
            } else {
                std::cin.clear(); // Clear any error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Error reading input. Please try again.\n";
                continue;
            }
        }

        // Trim leading and trailing whitespace
        inputLine.erase(0, inputLine.find_first_not_of(" \t\n\r"));
        inputLine.erase(inputLine.find_last_not_of(" \t\n\r") + 1);

        if (inputLine.empty()) continue; // Ignore empty input

        std::istringstream iss(inputLine);
        std::string commandName;
        iss >> commandName;

        // Convert commandName to lowercase
        std::transform(commandName.begin(), commandName.end(), commandName.begin(), ::tolower);

        if (commandName == "exit") {
            std::cout << "Exiting application.\n";
            break;
        } else if (commandName == "help") {
            controller.executeCommand(inputLine);
        } else if (commandName == "print") {
            controller.printDocument();
        } else if (commandName == "undo") {
            controller.undo();
        } else if (commandName == "redo") {
            controller.redo();
        } else {
            try {
                controller.executeCommand(inputLine);
            } catch (const std::exception& e) {
                std::cout << "Error executing command: " << e.what() << "\n";
            }
        }
    }
}


void CLIController::displayWelcomeMessage() const {
    std::cout << "=========================================\n"
              << "  Welcome to Simple PowerPoint Console   \n"
              << "=========================================\n"
              << "Type 'help' to see available commands.\n"
              << "Type 'exit' to quit the application.\n";
}

void CLIController::processInput(const std::string& inputLine) {
    controller.executeCommand(inputLine);
}
