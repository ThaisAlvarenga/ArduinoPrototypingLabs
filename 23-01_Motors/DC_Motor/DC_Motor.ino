// From www.elegoo.com
//2016.12.12

/************************
DC  motor using the L293D chip
Code taken from Elegoo Started Kit Examples

Open the serial monitor to note when the changes in the motor movement happen
************************/

#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*---back and forth example
   * Enables the motor.
   * Alternates the motor's direction 5 times:
   * Runs forward for 500ms.
   * Runs backward for 500ms.
   * Disables the motor and waits for 2 seconds.
  */
  
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH); // enable on
    for (i=0;i<5;i++) {
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    delay(500);
    digitalWrite(DIRA,LOW);  //reverse
    digitalWrite(DIRB,HIGH);
    delay(500);
  }
  digitalWrite(ENABLE,LOW); // disable
  delay(2000);

  Serial.println("fast Slow example");

  /* ---fast/slow stop example
   *  Runs the motor in one direction for 3 seconds.
   *  Demonstrates a slow stop by disabling the motor.
   *  Waits for 1 second.
   *  Runs the motor in the opposite direction for 3 seconds.
   *  Demonstrates a fast stop by changing direction inputs.
   Waits for 2 seconds.
  */ 
  
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(3000);
  digitalWrite(ENABLE,LOW); //slow stop
  delay(1000);
  digitalWrite(ENABLE,HIGH); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  delay(3000);
  digitalWrite(DIRA,LOW); //fast stop
  delay(2000);

  // PWM (Pulse Width Modulation)
  // A PWM signal alternates between fully on (usually 5V or 3.3V) and fully off (0V) states
  
  Serial.println("PWM full then slow");
  /*---PWM example, full speed then slow
   * Starts at full speed (255).
   * Gradually decreases speed: 180, 128, 50.
   * Then increases speed back to full: 128, 180, 255.
   * Each speed is maintained for 2 seconds.
  */
  analogWrite(ENABLE,255); //enable on
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  delay(2000);
  analogWrite(ENABLE,180); //half speed
  delay(2000);
  analogWrite(ENABLE,128); //half speed
  delay(2000);
  analogWrite(ENABLE,50); //half speed
  delay(2000);
  analogWrite(ENABLE,128); //half speed
  delay(2000);
  analogWrite(ENABLE,180); //half speed
  delay(2000);
  analogWrite(ENABLE,255); //half speed
  delay(2000);
  digitalWrite(ENABLE,LOW); //all done
  delay(10000);
}
   
