/*
 * Code for the Smart Traffic Light (traffic light parts 2 and 3) Demo.
 * 
 * Uncomment buzzer code and re-upload for part 3.
 */

//LED pins
#define red 7
#define yellow 6
#define green 5

//ultrasonic sensor pins
#define trig 11
#define echo 12

//active buzzer pin
#define buzzer 2

long duration, inches;
bool redLightOn;

void setup() {
  Serial.begin (9600); //uncomment the Serial lines if you need to see the ultrasonic sensor readings for debugging

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);

  redLightOn = false;
}

void loop() {
  // ultrasonic code from http://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);

  // convert the time into a distance
  // note: speed of sound in inches/microseconds is ~0.0135039 in/uS
  //        74 = ~1/0.0135039
  //        dividing by 74 is less messy than multiplying by 0.0135039
  inches = (duration/2) / 74; 

  Serial.print(inches);  //uncomment the Serial lines if you need to see the ultrasonic sensor readings for debugging
  Serial.print(" in \n");

  /* If something is within range of the sensor, this equates to a car coming down the other branch of the intersection.
   *  So play yellow light, red light to stop traffic for this branch.
  */
  if (inches < 6) { //you can play with this number to make it trigger closer or farther
    if (redLightOn == false) { //don't replay the yellow light if it's continuing to be red from the last loop
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
      delay(500); //change this to modify how long the yellow light phase takes
    }
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    redLightOn = true;
    delay(500); //change this to modify how long red will stay on after the "car" is out of range
    
  } 
  else { //no cars coming, allow traffic on this branch to go
    redLightOn = false;
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(500); //change this to modify how long the yellow light phase takes


   // play buzzer while traffic going on this branch to alert pedestrians that they cannot cross 
   tone(buzzer, 1000);
   delay(500);
   noTone(buzzer);

  }
  delay(250); //ultrasonic sensor needs this delay on the main loop
}

