/*
 The circuit:
 - LCD RS pin to digital pin 12
 - LCD Enable pin to digital pin 11
 - LCD D4 pin to digital pin 5
 - LCD D5 pin to digital pin 4
 - LCD D6 pin to digital pin 3
 - LCD D7 pin to digital pin 2
 - LCD R/W pin to ground
 - 10K resistor:
   * ends to +5V and ground
   * wiper to LCD VO pin (pin 3)
*/

// include the library code
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //Declaring the object LCD

void setup() {
  /* set up the LCD's number of columns and rows: */
  lcd.begin(16, 2);
  /* Print a message to the LCD. */
  lcd.setCursor(0,0);  //Sets the cursor
  lcd.print("Engineer Apex");
}

void loop() {
  /* Turn off the blinking cursor: */
  lcd.setCursor(0,0);
  lcd.noBlink();
  delay(3000);
  /* Turn on the blinking cursor: */
  lcd.blink();
  delay(3000);
}
