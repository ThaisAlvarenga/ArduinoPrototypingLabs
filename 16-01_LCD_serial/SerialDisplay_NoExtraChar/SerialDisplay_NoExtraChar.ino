/*


Based on: 
 http://www.arduino.cc/en/Tutorial/LiquidCrystalSerialDisplay

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // Wait for the entire message to arrive
    delay(100);
    
    // Create a buffer to store the incoming message
    String message = "";
    
    // Read all available characters
    while (Serial.available() > 0) {
      char inChar = Serial.read();
      // Only add printable ASCII characters to the buffer
      if (inChar >= 32 && inChar <= 126) {
        message += inChar;
      }
    }
    
    // Trim leading and trailing whitespace
    message.trim();
    
    // Clear the screen and display the message
    lcd.clear();
    lcd.print(message);
  }
}


//
//void loop() {
//  // when characters arrive over the serial port...
//  if (Serial.available()) {
//    // wait a bit for the entire message to arrive
//    delay(100);
//    // clear the screen
//    lcd.clear();
//    // read all the available characters
//    while (Serial.available() > 0) {
//      // display each character to the LCD
//      lcd.write(Serial.read());
//    }
//  }
//}
