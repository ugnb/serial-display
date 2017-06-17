#ifndef EXECUTOR_H
#define EXECUTOR_H 1

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#include "StandardCplusplus.h"
#include <map>
#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "Command.h"

class Executor {
public:
    Adafruit_GFX& display;
    int index;
    std::map<int, Command*> commands;
    Executor(Adafruit_GFX&);

    int Add(Command*);
    void Run();
};

#endif