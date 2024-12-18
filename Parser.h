#ifndef PARSER_HPP
#define PARSER_HPP

#include "ParsedCommand.h"
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

/**
 * @brief Defines the various states of the parser's state machine.
 */
enum class ParserState {
    Start,      ///< Initial state before parsing begins.
    Command,    ///< Parsing the command name.
    Option,     ///< Parsing an option name (e.g., -id).
    Value,      ///< Parsing the value(s) for the current option.
    Error,      ///< An error has been encountered.
    End         ///< Parsing has completed successfully.
};

/**
 * @brief Responsible for parsing raw command lines into structured ParsedCommand objects using a state machine.
 */
class Parser {
public:
    /**
     * @brief Parses a raw command line into a ParsedCommand structure.
     *
     * @param commandLine The raw command line string entered by the user.
     * @return ParsedCommand representing the parsed command and its components.
     */
    ParsedCommand parseLine(const std::string& commandLine) const;

private:
    /**
     * @brief Splits the input string into tokens based on whitespace, respecting quoted strings.
     *
     * @param input The input command line string.
     * @return A vector of tokens extracted from the input.
     */
    std::vector<std::string> tokenize(const std::string& input) const;

    /**
     * @brief Checks if a given token is an option (starts with '-').
     *
     * @param token The token to check.
     * @return true if the token is an option; false otherwise.
     */
    bool isOption(const std::string& token) const {
        return !token.empty() && token[0] == '-';
    }
};

#endif // PARSER_HPP
