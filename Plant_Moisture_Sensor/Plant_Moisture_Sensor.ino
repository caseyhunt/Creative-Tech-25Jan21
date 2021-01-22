#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>


//define is for constants
#define LED_PIN    A10
#define ANALOG_INPUT  A9

#define LED_COUNT 5

#define VALUE_MIN     5
#define VALUE_MAX     1000

//variables are for things that might change
byte stepVal = (VALUE_MAX-VALUE_MIN)/LED_COUNT;
byte red = 0;
byte green = 100;
byte blue = 255;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(9600); //confirm this setting

    CircuitPlayground.begin();

    strip.begin();           
    strip.show();            
    strip.setBrightness(100); //255 is maximum

}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t value = analogRead(ANALOG_INPUT);
  Serial.println(value, DEC);
  //Serial.println(stepVal);

  if (value < VALUE_MIN) {
    strip.setPixelColor(0, (red,green,blue));         //  Set pixel's color (in RAM)
    strip.show(); 
  }
  for(int i=0; i<5; i++) {
    if (value> stepVal*i) {
      strip.setPixelColor(i, (red,green,blue));         //  Set pixel's color (in RAM)
    strip.show();
  }}

      delay(5);  
      strip.clear(); 
}
