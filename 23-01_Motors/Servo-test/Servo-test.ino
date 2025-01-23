/* LMC 4813 Motors Lab -- Servo Examples
 * TA: Thais Alvarenga
 * 
 * Code samples were taken from this tutorial:
 * https://docs.arduino.cc/learn/electronics/servo-motors/
 * 
 * The examples are also accessible from File > Example > Servo > Knob or Sweep

*/

#include <Servo.h>


// EXAMPLE 0: SWEEP / FROM 0 TO 180 DEGREES -----------------------------------

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}


// EXAMPLE 1: BASIC EXAMPLE WITH KNOB -----------------------------------

//Servo myservo;  // create servo object to control a servo
//
//int potpin = A0;  // analog pin used to connect the potentiometer
//int val;    // variable to read the value from the analog pin
//
//void setup() {
//  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
//  Serial.begin(9600);
//}
//
//void loop() {
//  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
//  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
//  myservo.write(val);                  // sets the servo position according to the scaled value
//  //Serial.println("mapped val: " + String(val));
//  delay(15);                           // waits for the servo to get there
//}



// EXAMPLE 2: CLEANING UP THE VALUE COMING FROM THE POTENTIOMETER -------------


//Servo myservo;  // create servo object to control a servo
//int potpin = A0;  // analog pin used to connect the potentiometer
//int val;    // variable to read the value from the analog pin
//int lastVal = 0;  // variable to store the last stable value
//int threshold = 10;  // threshold for value change
//
//// Low-pass filter variables
//const int numReadings = 10;
//int readings[numReadings];
//int readIndex = 0;
//int total = 0;
//int average = 0;
//
//void setup() {
//  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
//  Serial.begin(9600);
//  
//  // Initialize all readings to 0
//  for (int i = 0; i < numReadings; i++) {
//    readings[i] = 0;
//  }
//}
//
//void loop() {
//  // Subtract the last reading
//  total = total - readings[readIndex];
//  // Read from the sensor
//  readings[readIndex] = analogRead(potpin);
//  // Add the reading to the total
//  total = total + readings[readIndex];
//  // Advance to the next position in the array
//  readIndex = (readIndex + 1) % numReadings;
//
//  // Calculate the average
//  average = total / numReadings;
//
//  // Apply hysteresis
//  if (abs(average - lastVal) > threshold) {
//    val = average;
//    lastVal = val;
//    
//    val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
//    myservo.write(val);                  // sets the servo position according to the scaled value
//    Serial.println("mapped val: " + String(val));
//  }
//
//  delay(15);  // waits for the servo to get there
//}
