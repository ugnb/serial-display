#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H 1

#include "StandardCplusplus.h"

#include <map>
#include <Arduino.h>
#include "Command.h"

class CommandParser {
public:
    std::map<String, Command* (*)(Stream&)> supportedCommands;
    CommandParser();
    Command* ParseInput(Stream&);
    static Command* CommandParser::BuildTextCommand(Stream&);
};

#endif