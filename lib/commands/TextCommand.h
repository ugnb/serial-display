#ifndef TEXTCOMMAND_H
#define TEXTCOMMAND_H 1

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include "Command.h"

class TextCommand : public Command {
public:
    int X;
    int Y;
    int FontSize;
    String Text;

    void Execute(Adafruit_GFX&);
};

#endif