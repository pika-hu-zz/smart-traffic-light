/*
 * New code for Traffic Light demo.
 * 
 * Changes: -changed pin numbers to match those needed by the extended demo
 *          -changed light order to green > yellow > red (previously it was backwards)
 */

//LED pin constants
int lRed = 7; //Red light is pin 5
int lYellow = 6; //Yellow light is pin 6
int lGreen = 5; //Green light is pin 7

void setup() {
  //initializes the pins
  pinMode(lRed, OUTPUT);
  pinMode(lYellow, OUTPUT);
  pinMode(lGreen, OUTPUT);
  
  //initially all LEDs are off  
  digitalWrite(lRed, LOW); 
  digitalWrite(lYellow, LOW);
  digitalWrite(lGreen, LOW);  
}

void loop() {

  //To turn Green LED on:
  digitalWrite(lRed, LOW);
  digitalWrite(lYellow, LOW);
  digitalWrite(lGreen, HIGH);

  delay(5000); //This number is a time in milliseconds. Change it to change how long the light is on. For example, this will turn on for 1 second.

 //To turn Yellow LED on:  
  digitalWrite(lRed, LOW);
  digitalWrite(lYellow, HIGH);
  digitalWrite(lGreen, LOW);

  delay(500);
  
  //To turn Red LED on: 
  digitalWrite(lRed, HIGH);
  digitalWrite(lYellow, LOW);
  digitalWrite(lGreen, LOW);

  delay(5000);
}
