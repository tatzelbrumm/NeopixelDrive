#include <Adafruit_NeoPixel.h>

// create a pixel strand with 2 pixels on pin A3, color sequence RGB
Adafruit_NeoPixel pixels(2, 3, NEO_RGB);
unsigned long colors[8];
byte offset;

void setup() 
{
  byte brightness= 0x20;
  pixels.begin();  // initialize the pixels
  for(int c= 0; c<8; c++)
  {
    int g;
    g= c ^ (c>>1);
    unsigned long color= 0;
    for(int rgb= 0; rgb<3; rgb++)
    {
      color |= (((unsigned long)1 & (g >> rgb)) * brightness) << ((2-rgb)<<3); 
    }
    colors[c]= color;
  }
  offset= 0;
}

void loop() 
{
  pixels.setPixelColor(0, colors[offset]);
  pixels.setPixelColor(1, colors[(offset+1)%8]);
  // and write the data
  pixels.show();

  delay(1000);
  
  offset= ++offset % 8;
}