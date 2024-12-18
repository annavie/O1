#include "Parser.h"

ParsedCommand Parser::parseLine(const std::string& commandLine) const {
    ParsedCommand pc;
    ParserState state = ParserState::Start;
    std::string currentOption;
    std::vector<std::string> tokens = tokenize(commandLine);

    for (size_t i = 0; i < tokens.size(); ++i) {
        const std::string& token = tokens[i];

        switch(state) {
        case ParserState::Start:
            if (isOption(token)) {
                pc.isValid = false;
                pc.errorMessage = "Command name expected but found option: " + token;
                state = ParserState::Error;
            } else {
                pc.commandName = token;
                state = ParserState::Command;
            }
            break;

        case ParserState::Command:
            if (isOption(token)) {
                currentOption = token;
                state = ParserState::Option;
            } else {
                pc.isValid = false;
                pc.errorMessage = "Option expected after command but found: " + token;
                state = ParserState::Error;
            }
            break;

        case ParserState::Option:
            if (isOption(token)) {
                pc.isValid = false;
                pc.errorMessage = "Value expected for option " + currentOption + " but found another option: " + token;
                state = ParserState::Error;
            } else {
                pc.optionValues[currentOption].push_back(token);
                state = ParserState::Value;
            }
            break;

        case ParserState::Value:
            if (isOption(token)) {
                currentOption = token;
                state = ParserState::Option;
            } else {
                // Assuming options can have multiple values
                if (!currentOption.empty()) {
                    pc.optionValues[currentOption].push_back(token);
                } else {
                    pc.isValid = false;
                    pc.errorMessage = "Option not set for value: " + token;
                    state = ParserState::Error;
                }
            }
            break;

        case ParserState::Error:
            // Stop parsing on error
            break;

        case ParserState::End:
            // Do nothing
            break;
        }

        if (state == ParserState::Error) {
            break;
        }
    }

    // Final state checks
    if (state == ParserState::Option) {
        pc.isValid = false;
        pc.errorMessage = "Value expected for option " + currentOption + " but none found.";
    }

    return pc;
}

std::vector<std::string> Parser::tokenize(const std::string& input) const {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    char c;
    bool inQuotes = false;
    std::string currentToken;

    while (iss.get(c)) {
        if (c == '\"') {
            inQuotes = !inQuotes;
            continue;
        }

        if (std::isspace(c) && !inQuotes) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
        } else {
            currentToken += c;
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    return tokens;
}
