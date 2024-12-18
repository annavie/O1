// HelpCommand.cpp
#include "HelpCommand.h"
#include "Editor.h"
#include <iostream>

void HelpCommand::execute(Editor& editor) {
    std::cout << "Available Commands:\n"
              << "1. addSlide\n"
              << "2. deleteSlide -index <index>\n"
              << "3. addShape -id <id> -type <type> -color <color> -width <width> -height <height> -x <x> -y <y> -slideIndex <index>\n"
              << "4. addText -id <id> -text <text> -font <font> -color <color> -x <x> -y <y> -slideIndex <index>\n"
              << "5. addImage -id <id> -path <imagePath> -width <width> -height <height> -x <x> -y <y> -slideIndex <index>\n"
              << "6. moveItem -slideIndex <index> -itemIndex <index> -newX <x> -newY <y>\n"
              << "7. resizeItem -slideIndex <index> -itemIndex <index> -newWidth <width> -newHeight <height>\n"
              << "8. undo\n"
              << "9. redo\n"
              << "10. help\n"
              << "11. exit\n";
}

void HelpCommand::undo(Editor& editor) {
    // No action needed for help command
}
