#include <LiquidCrystal.h>

// Define the pins connected to the LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// Initialize the LiquidCrystal object with the pin configuration
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Print an initial message to the serial monitor
  Serial.println("Enter your name.");

  // Set the cursor to the first column of the first row on the LCD
  lcd.setCursor(0, 0);

  // Display a prompt on the LCD asking for the user's name
  lcd.print("Enter Your Name");
}

// Variable to store a single character received from the serial input
char myChar = 0;

// String to accumulate characters from the serial input
String myString = "";

void loop() 
{
  // Check if data is available to read from the serial input
  if (Serial.available()) 
  {    
    // Read the incoming character
    myChar = Serial.read();       
    
    // If the character is not a newline ('\n'), add it to the string
    if (myChar != '\n') 
    {
      myString += myChar;
    }
    else 
    {
      // If a newline is received, treat it as the end of the input
      // Print the received string to the serial monitor
      Serial.println(myString);

      // Display the received string on the second row of the LCD
      lcd.setCursor(0, 1);
      lcd.print(myString);

      // Clear the string variable for the next input
      myString = "";                

      // Print a new prompt to the serial monitor
      Serial.println("");
      Serial.println("Enter your name.");
    }
  }  
}
