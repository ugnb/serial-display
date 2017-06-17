#include <map>

#include "CommandParser.h"
#include "TextCommand.h"


CommandParser::CommandParser() {
    supportedCommands = std::map<String, Command* (*)(Stream&)>();
    supportedCommands[String("text")] = &CommandParser::BuildTextCommand;
}

static Command* CommandParser::ParseInput(Stream& input) {
    auto commandType = input.readStringUntil('~');
    auto commandId = input.parseInt();
    
    if (input.read() != '=') return NULL;

    auto it = supportedCommands.find(commandType);
    if (it != supportedCommands.end()) {
        auto command = (it->second)(input);
        command->index = commandId;
        return command;
    }
    
    return NULL;
}

static Command* CommandParser::BuildTextCommand(Stream& input) {
    auto command = new TextCommand();

    command->X = input.parseInt();

    if (input.read() != ':') { delete command; return NULL; };

    command->Y = input.parseInt();

    if (input.read() != ',') { delete command; return NULL; };

    command->FontSize = input.parseInt();

    if (input.read() != ',') { delete command; return NULL; };

    command->Text = input.readStringUntil('\n');

    return command;
}