#include <Adafruit_NeoPixel.h>

#define ADR(x,y) (((y)&0xF)<<4 | ((y)&1? (~(x)&0xF) : (x)&0xF))

int leds= 256;
// create a pixel strand with 2 pixels on pin A3, color sequence GRB
Adafruit_NeoPixel pixels(leds, 3, NEO_GRB);
unsigned long colors[8];
byte offset;

void setup() 
{
  byte brightness= 0x10;
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
  for (unsigned int y= 0; y<16; y++)
    for (unsigned int x= 0; x<16; x++)
    {
      pixels.setPixelColor(ADR(x,y), colors[(y-x+offset)%8]);
    }
  // and write the data
  pixels.show();

  delay(1000);
  
  offset= ++offset % 8;
}