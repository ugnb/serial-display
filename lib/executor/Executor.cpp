#include <map>
#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "Executor.h"
#include "Command.h"

Executor::Executor(Adafruit_GFX& display) : display(display) {
    index = 0;
    commands = std::map<int, Command*>();
    
    display.setTextWrap(false);
    display.fillScreen(BLACK);
}

int Executor::Add(Command* command) {
    int indexToReturn;

    if (command->index == -1) {
        commands[index] = command;
        indexToReturn = index++;
    }
    else {
        auto it = commands.find(command->index);
        if (it != commands.end()) {
            delete it->second;
        }

        commands[command->index] = command;
        indexToReturn = command->index;
    }

    Run();
    return indexToReturn;


    // display.fillScreen(BLACK);
    // display.setCursor(command->X, command->Y);
    // display.setTextSize(command->FontSize);
    // display.println(command->Text);
    // String input = Serial.readStringUntil('\n');
    // Serial.print("I received: ");
    // Serial.println(input);

    // tft.setTextWrap(false);
    // tft.fillScreen(ST7735_BLACK);
    // tft.setCursor(5, 5);
    // tft.setTextColor(ST7735_GREEN);
    // tft.setTextSize(2);
    // tft.println(input);
    // tft.drawLine(5, 5, tft.width() - 5, 5, ST7735_GREEN);
    // tft.drawLine(5, 20, tft.width() - 5, 20, ST7735_GREEN);

    // tft.setCursor(5, 25);
    // tft.setTextColor(ST7735_RED);
    // tft.setTextSize(2);
    // tft.println(input);
    // tft.drawLine(5, 25, tft.width() - 5, 25, ST7735_GREEN);
    // tft.drawLine(5, 40, tft.width() - 5, 40, ST7735_GREEN);
}

void Executor::Run() {
    display.fillScreen(BLACK);
    for (std::map<int, Command*>::iterator it = commands.begin(); it != commands.end(); ++it) {
        (it->second)->Execute(display);
    }
}