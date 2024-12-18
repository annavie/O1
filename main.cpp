#include <iostream>
#include <string>
#include "Document.h"
#include "CommandFactory.h"
#include "CommandRegistrar.h"
#include "Editor.h"
#include "Controller.h"
#include "CLIController.h"
// #include "QCoreApplication"

int main(int argc, char* argv[]) {

    // QCoreApplication app(argc, argv);

    Document document;
    CommandFactory commandFactory;
    CommandRegistrar::registerAllCommands(commandFactory);
    Editor editor(document);
    Controller controller(document, commandFactory);
    CLIController cliController(controller);
    cliController.start();

    return 0;
}
