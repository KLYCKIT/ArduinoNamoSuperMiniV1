/*
  NANO V3.0 / Nano SuperMini Blink_Test

  Blink the Green LED (Arduino Pin 0 -- marked "D3" on the PCB), On for 1/2 sec, Off for 1/2 sec
  Blink the Blue LED (Arduino Pin 1 -- marked "D4" on the PCB), On for 1/2 sec, Off for 1/2 sec
  Blink the Green LED (Arduino Pin 13 -- LED_BUILTIN -- marked "D2" on the PCB), On for 1/2 sec, Off for 1/2 sec
  Light up the 3 NeoPixels connected to Arduino Pin 2 using code from the Adafruit "Simple NeoPixel test" sketch

  Hacked from the Arduino "Blink" example and the Adafruit "Simple NeoPixel test" sketch.

  For this sketch you will need the "Adafruit NeoPixel by Adafruit" Library installed in your Arduino software.

  The NANO V3.0 / Nano SuperMini Blink_Test board is from Aliexpress:
  https://www.aliexpress.com/item/1005006468917096.html
  It works with a CH340 USB-Serial driver.
  The board I tried used "Arduino Nano" with "ATmege328P (Old Bootloader)".
  It has 3 single-color LEDs on the PCB:
     D3 -- Green -- Arduino Pin 0
     D4 -- Blue  -- Arduino Pin 1
     D2 -- Green -- Arduino Pin 13 -- LED_BUILTIN
  It also has 3 NeoPixel LEDs connected to Arduino Pin 2.

  Blink:
  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  NANO V3.0 / Nano SuperMini Blink_Test
  by Mitch Altman

  This example code is in the public domain.
  Blink:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
  Simple NeoPixel test:
  https://learn.adafruit.com/neopixel-painter/test-neopixel-strip
*/

#include <Adafruit_NeoPixel.h>

// define LED names and pins (Green LED on Arduino Pin 0 and Blue LED on Arduino Pin 1)
#define GREEN_LED_0 0
#define BLUE_LED_1  1
// (The Green LED on Arduino Pin 13 is automatically named LED_BUILTIN in the Arduino software)

// define NeoPixel values (3 LEDs connected to Arduino Pin 2)
#define PIN         2
#define N_LEDS      3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital Arduino pins connected to LEDs as outputs.
  pinMode(GREEN_LED_0, OUTPUT);  //  Green LED which is marked "D3" on the PCB -- it is active Low (Output pin Low to turn On)
  pinMode(BLUE_LED_1, OUTPUT);   //  Blue LED which is marked "D4" on the PCB -- it is active Low (Output pin Low to turn On)
  pinMode(LED_BUILTIN, OUTPUT);  //  Green LED which is marked "D2" on the PCB -- it is active High (Output pin High to turn On)

  // initialize the NeoPixels
  strip.begin();
  strip.show();             // Initialize all pixels to 'off'
  strip.setBrightness(64);  // 1/4 of max brightness
  strip.show();             // Initialize pixel brightness
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(GREEN_LED_0, LOW);   // turn On the Green LED at Arduino Pin 0  (active Low -- Output pin Low to turn On)
  delay(500);                       // wait 1/2 second
  digitalWrite(GREEN_LED_0, HIGH);  // turn Off the Green LED at Arduino Pin 0  (active Low)
  delay(500);                       // wait 1/2 second

  digitalWrite(BLUE_LED_1, LOW);    // turn On the Blue LED at Arduino Pin 1  (active Low -- Output pin Low to turn On)
  delay(500);                       // wait 1/2 second
  digitalWrite(BLUE_LED_1, HIGH);   // turn Off the Blue LED at Arduino Pin 1  (active Low)
  delay(500);                       // wait 1/2 second

  digitalWrite(LED_BUILTIN, HIGH);  // turn On the Green LED at Arduino Pin 13, the LED_BUILTIN  (active High -- Output pin High to turn On)
  delay(500);                       // wait 1/2 second
  digitalWrite(LED_BUILTIN, LOW);   // turn Off the Green LED at Arduino Pin 13, the LED_BUILTIN  (active High)
  delay(500);                       // wait 1/2 second

  // Light up the 3 NeoPixels connected to Arduino Pin 2
  chase(strip.Color(255, 0, 0));      // Red
  delay(100);                         // wait 1/10 second
  chase(strip.Color(0, 255, 0));      // Green
  delay(100);                         // wait 1/10 second
  chase(strip.Color(0, 0, 255));      // Blue
  delay(100);                         // wait 1/10 second
  chase(strip.Color(255, 255, 0));    // Yellow
  delay(100);                         // wait 1/10 second
  chase(strip.Color(255, 0, 255));    // Magenta
  delay(100);                         // wait 1/10 second
  chase(strip.Color(0, 255, 255));    // Cyan
  delay(100);                         // wait 1/10 second
  chase(strip.Color(255, 255, 255));  // White
  delay(100);                         // wait 1/10 second
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}
