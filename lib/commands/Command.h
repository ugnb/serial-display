#ifndef COMMAND_H
#define COMMAND_H 1

#include <Arduino.h>
#include <Adafruit_GFX.h>


class Command {
public:
    int index = -1;
    virtual void Execute(Adafruit_GFX&);
};

#endif