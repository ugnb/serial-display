#import "TextCommand.h"

void TextCommand::Execute(Adafruit_GFX& display) {
    display.setCursor(X, Y);
    display.setTextSize(FontSize);
    display.println(Text);
}