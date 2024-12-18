// CommandRegistrar.hpp
#ifndef COMMANDREGISTRAR_HPP
#define COMMANDREGISTRAR_HPP

#include "CommandFactory.h"
#include "AddSlideCommand.h"
#include "DeleteSlideCommand.h"
#include "AddItemCommand.h"
#include "MoveItemCommand.h"
#include "ResizeItemCommand.h"
#include "HelpCommand.h"
//#include "NoOpCommand.h"
#include "Rectangle.h"
#include "Circle.h"
#include "TextItem.h"
#include "ImageItem.h"
#include "AddItemCommand.h"
#include "MoveItemCommand.h"
#include "ResizeItemCommand.h"
#include "DeleteSlideCommand.h"
#include "AddSlideCommand.h"
#include "HelpCommand.h"
//#include "NoOpCommand.h"
#include "Point.h"
#include "Item.h"
#include "Slide.h"

#include <stdexcept>

class CommandRegistrar {
public:
    /**
     * @brief Registers all available commands with the CommandFactory.
     *
     * @param factory The CommandFactory instance.
     */
    static void registerAllCommands(CommandFactory& factory) {
        // Register addSlide command
        factory.registerCommand("addSlide", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
            return std::make_unique<AddSlideCommand>();
        });

        // Register deleteSlide command
        factory.registerCommand("deleteSlide", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
            if (pc.optionValues.find("-index") == pc.optionValues.end()) {
                throw std::runtime_error("Missing '-index' option for deleteSlide command.");
            }
            int index = std::stoi(pc.optionValues.at("-index").front());
            return std::make_unique<DeleteSlideCommand>(index);
        });

        // Register addShape command
        factory.registerCommand("addShape", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
            // Ensure required options are present
            if (pc.optionValues.find("-id") == pc.optionValues.end() ||
                pc.optionValues.find("-type") == pc.optionValues.end() ||
                pc.optionValues.find("-color") == pc.optionValues.end() ||
                pc.optionValues.find("-slideIndex") == pc.optionValues.end() ||
                pc.optionValues.find("-x") == pc.optionValues.end() ||
                pc.optionValues.find("-y") == pc.optionValues.end()) {
                throw std::runtime_error("Missing required options for addShape command.");
            }

            int id = std::stoi(pc.optionValues.at("-id").front());
            std::string type = pc.optionValues.at("-type").front();
            std::string color = pc.optionValues.at("-color").front();
            int slideIndex = std::stoi(pc.optionValues.at("-slideIndex").front());
            int x = std::stoi(pc.optionValues.at("-x").front());
            int y = std::stoi(pc.optionValues.at("-y").front());

            std::unique_ptr<Item> item;

            if (type == "rectangle") {
                if (pc.optionValues.find("-width") == pc.optionValues.end() ||
                    pc.optionValues.find("-height") == pc.optionValues.end()) {
                    throw std::runtime_error("Missing '-width' or '-height' for rectangle.");
                }
                int width = std::stoi(pc.optionValues.at("-width").front());
                int height = std::stoi(pc.optionValues.at("-height").front());
                item = std::make_unique<Rectangle>(id, color, Size(width, height), Point(x, y));
            }
            else if (type == "circle") {
                if (pc.optionValues.find("-radius") == pc.optionValues.end()) {
                    throw std::runtime_error("Missing '-radius' for circle.");
                }
                int radius = std::stoi(pc.optionValues.at("-radius").front());
                item = std::make_unique<Circle>(id, color, radius, Point(x, y));
            }
            else {
                throw std::runtime_error("Unknown shape type: " + type);
            }

            return std::make_unique<AddItemCommand>(slideIndex, std::move(item));
        });

        // // Register addText command
        // factory.registerCommand("addText", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
        //     if (pc.optionValues.find("-id") == pc.optionValues.end() ||
        //         pc.optionValues.find("-text") == pc.optionValues.end() ||
        //         pc.optionValues.find("-font") == pc.optionValues.end() ||
        //         pc.optionValues.find("-color") == pc.optionValues.end() ||
        //         pc.optionValues.find("-slideIndex") == pc.optionValues.end() ||
        //         pc.optionValues.find("-x") == pc.optionValues.end() ||
        //         pc.optionValues.find("-y") == pc.optionValues.end()) {
        //         throw std::runtime_error("Missing required options for addText command.");
        //     }

        //     int id = std::stoi(pc.optionValues.at("-id").front());
        //     std::string text = pc.optionValues.at("-text").front();
        //     std::string font = pc.optionValues.at("-font").front();
        //     std::string color = pc.optionValues.at("-color").front();
        //     int slideIndex = std::stoi(pc.optionValues.at("-slideIndex").front());
        //     int x = std::stoi(pc.optionValues.at("-x").front());
        //     int y = std::stoi(pc.optionValues.at("-y").front());

        //     auto item = std::make_unique<TextItem>(id, text, font, color, Point(x, y));
        //     return std::make_unique<AddItemCommand>(slideIndex, std::move(item));
        // });

        // // Register addImage command
        // factory.registerCommand("addImage", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
        //     if (pc.optionValues.find("-id") == pc.optionValues.end() ||
        //         pc.optionValues.find("-path") == pc.optionValues.end() ||
        //         pc.optionValues.find("-width") == pc.optionValues.end() ||
        //         pc.optionValues.find("-height") == pc.optionValues.end() ||
        //         pc.optionValues.find("-slideIndex") == pc.optionValues.end() ||
        //         pc.optionValues.find("-x") == pc.optionValues.end() ||
        //         pc.optionValues.find("-y") == pc.optionValues.end()) {
        //         throw std::runtime_error("Missing required options for addImage command.");
        //     }

        //     int id = std::stoi(pc.optionValues.at("-id").front());
        //     std::string path = pc.optionValues.at("-path").front();
        //     int width = std::stoi(pc.optionValues.at("-width").front());
        //     int height = std::stoi(pc.optionValues.at("-height").front());
        //     int slideIndex = std::stoi(pc.optionValues.at("-slideIndex").front());
        //     int x = std::stoi(pc.optionValues.at("-x").front());
        //     int y = std::stoi(pc.optionValues.at("-y").front());

        //     auto item = std::make_unique<ImageItem>(id, path, Size(width, height), Point(x, y));
        //     return std::make_unique<AddItemCommand>(slideIndex, std::move(item));
        // });

        // Register moveItem command
        factory.registerCommand("moveItem", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
            if (pc.optionValues.find("-slideIndex") == pc.optionValues.end() ||
                pc.optionValues.find("-itemIndex") == pc.optionValues.end() ||
                pc.optionValues.find("-newX") == pc.optionValues.end() ||
                pc.optionValues.find("-newY") == pc.optionValues.end()) {
                throw std::runtime_error("Missing required options for moveItem command.");
            }

            int slideIdx = std::stoi(pc.optionValues.at("-slideIndex").front());
            int itemIdx = std::stoi(pc.optionValues.at("-itemIndex").front());
            int newX = std::stoi(pc.optionValues.at("-newX").front());
            int newY = std::stoi(pc.optionValues.at("-newY").front());

            Point newPos(newX, newY);
            return std::make_unique<MoveItemCommand>(slideIdx, itemIdx, newPos);
        });

        // Register resizeItem command
        factory.registerCommand("resizeItem", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
            if (pc.optionValues.find("-slideIndex") == pc.optionValues.end() ||
                pc.optionValues.find("-itemIndex") == pc.optionValues.end() ||
                pc.optionValues.find("-newWidth") == pc.optionValues.end() ||
                pc.optionValues.find("-newHeight") == pc.optionValues.end()) {
                throw std::runtime_error("Missing required options for resizeItem command.");
            }

            int slideIdx = std::stoi(pc.optionValues.at("-slideIndex").front());
            int itemIdx = std::stoi(pc.optionValues.at("-itemIndex").front());
            int newWidth = std::stoi(pc.optionValues.at("-newWidth").front());
            int newHeight = std::stoi(pc.optionValues.at("-newHeight").front());

            Size newSize(newWidth, newHeight);
            return std::make_unique<ResizeItemCommand>(slideIdx, itemIdx, newSize);
        });

        // Register help command
        factory.registerCommand("help", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
            return std::make_unique<HelpCommand>();
        });

        // // Register exit command
        // factory.registerCommand("exit", [](const ParsedCommand& pc) -> std::unique_ptr<Command> {
        //     return std::make_unique<NoOpCommand>();
        // });
    }
};

#endif // COMMANDREGISTRAR_HPP
