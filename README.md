# NANO V3.0 / Nano SuperMini Blink_Test  
  
The NANO V3.0 / Nano SuperMini Blink_Test board is from Aliexpress:  
https://www.aliexpress.com/item/1005006468917096.html  
It works with a CH340 USB-Serial driver.  
The board I tried used "Arduino Nano" with "ATmege328P (Old Bootloader)".  
![Nano SuperMini](https://github.com/user-attachments/assets/f04cb68f-99c4-4ba4-b45e-f3d4c473631b)  
  
It has 3 single-color LEDs on the PCB:  
* D3 -- Green -- Arduino Pin 0 (active Low)  
* D4 -- Blue  -- Arduino Pin 1 (active Low)  
* D2 -- Green -- Arduino Pin 13 -- LED_BUILTIN (active High)  
It also has 3 NeoPixel LEDs connected to Arduino Pin 2.  
  
This example code is in the public domain.  
I hacked the code by combining "Blink" and "Simple NeoPixel test" sketches:  
* Blink:  
https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink  
* Simple NeoPixel test:  
https://learn.adafruit.com/neopixel-painter/test-neopixel-strip  
  
This test sketch does the following:  
* Blink the Green LED (Arduino Pin 0 -- marked "D3" on the PCB), On for 1/2 sec, Off for 1/2 sec  
* Blink the Blue LED (Arduino Pin 1 -- marked "D4" on the PCB), On for 1/2 sec, Off for 1/2 sec  
* Blink the Green LED (Arduino Pin 13 -- LED_BUILTIN -- marked "D2" on the PCB), On for 1/2 sec, Off for 1/2 sec  
* Light up the 3 NeoPixels connected to Arduino Pin 2 using code from the Adafruit "Simple NeoPixel test" sketch  
  
