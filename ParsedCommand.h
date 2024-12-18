#ifndef PARSEDCOMMAND_HPP
#define PARSEDCOMMAND_HPP

#include <string>
#include <map>
#include <vector>

/**
 * @brief Represents a parsed command with its name, options, values, and validation status.
 */
struct ParsedCommand {
    std::string commandName; ///< The primary command name (e.g., addSlide, addShape)

    /**
     * @brief A map of option names to their corresponding values.
     *
     * Each option can have multiple values. For example:
     * "-id": ["1"]
     * "-type": ["rectangle"]
     */
    std::map<std::string, std::vector<std::string>> optionValues;

    bool isValid = true; ///< Indicates whether the parsing was successful.
    std::string errorMessage; ///< Provides details if parsing fails.
};

#endif // PARSEDCOMMAND_HPP
