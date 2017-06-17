#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_ST7735.h>

#include <CommandParser.h>
#include <Executor.h>

#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9

Adafruit_ST7735 display = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
auto initializeDisplay = [] () { display.initR(INITR_BLACKTAB); };

Executor* executor;
auto parser = CommandParser();

void setup(void) {
  Serial.begin(9600);
  initializeDisplay();
  executor = new Executor((Adafruit_GFX&)display);
  delay(1000);
  Serial.println("Setup done.");
}

void loop() {
    if (Serial.available() > 0) {
        auto incomingByte = Serial.read();
        if (incomingByte == '>') {
            auto command = parser.ParseInput(Serial);
            if (command != NULL) {
                Serial.print("Got command: ");
                auto id = executor->Add(command);
                Serial.println(id);
            }
            else {
                Serial.println("Could not parse command");
            }
        }
    }
}