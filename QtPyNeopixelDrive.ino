#include <Adafruit_NeoPixel.h>

// create a pixel strand with 2 pixels on pin A3, color sequence RGB
Adafruit_NeoPixel pixels(2, 3, NEO_RGB);
byte offset;

void setup() {
    pixels.begin();  // initialize the pixel
    offset= 0;
}

void loop() {
    pixels.setPixelColor(0^offset, 0x402000);
    pixels.setPixelColor(1^offset, 0x002040);
    // and write the data
    pixels.show();
  
    delay(500);
    
    // turn off the pixel
    pixels.clear();
    pixels.show();
  
    delay(500);
    offset= 1-offset;
}