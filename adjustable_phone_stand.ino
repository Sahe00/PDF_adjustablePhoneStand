/* 
 * Functionality for Arduino Uno in the adjustable phone stand project.
 * 
 * Axel Wester
 * 
 */

#include <Servo.h>

Servo rightServo;
Servo leftServo;

int rightMovement;
int leftMovement;

int redLedPin = 4;
int yellowLedPin = 3;
int greenLedPin = 2;

int sensorPin = A1;
int potentiometerPin = A0;

int knob;
int light;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  pinMode(potentiometerPin, INPUT);
  pinMode(sensorPin, INPUT);
  
  rightServo.attach(6);
  leftServo.attach(5);
}

void loop() {
  
  light = analogRead(sensorPin);
  knob = analogRead(potentiometerPin);

  if (light > 900) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    
  } else if (light > 500) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    
  } else if (light > 200) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    
  } else {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
  }
  
  rightMovement = map(knob, 0, 1023, 45, 130);
  leftMovement = map(knob, 0, 1023, 130, 45);

  rightServo.write(rightMovement);
  leftServo.write(leftMovement);
  delay(15);
}
