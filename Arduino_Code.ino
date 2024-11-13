#include <Servo.h>
Servo servoMotor;
int ldrPin1 = A0;
int ldrPin2 = A1;
int ldrValue1;
int ldrValue2;
int threshold = 400; // adjust this value to set the sensitivity of the LDR sensor
int servoMinAngle = 0; // adjust this value to set the minimum angle of the servo
int servoMaxAngle = 30; // adjust this value to set the maximum angle of the servo
int servoCurrentAngle;
int ledPin = 13; // the pin connected to the LED
int ledp1=7;
int ledp2=6;
bool platform1Occupied = false;
bool platform2Occupied = false;
void setup() {
  servoMotor.attach(9);
  pinMode(ledPin, OUTPUT);
  pinMode(ledp1,OUTPUT);
  pinMode(ledp2,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  ldrValue1 = analogRead(ldrPin1);
  ldrValue2 = analogRead(ldrPin2);
  
  // check if both platforms are occupied
  if (ldrValue1 < threshold) {
    platform1Occupied = true;
    Serial.println("Platform 1 Occupied");
    Serial.println(ldrValue1);
  } else {
    platform1Occupied = false;
    Serial.println("Platform 1 Unoccupied");
    Serial.println(ldrValue1);
  }
  if (ldrValue2 < threshold) {
    platform2Occupied = true;
    Serial.println("Platform 2 Occupied");
    Serial.println(ldrValue2);
  } else {
    platform2Occupied = false;
    Serial.println("Platform 2 Unoccupied");
    Serial.println(ldrValue2);
  }
  // set the current angle of the servo motor
  if (platform1Occupied && platform2Occupied) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledp2, LOW);
    digitalWrite(ledp1, LOW);
  } else {
    digitalWrite(ledp2, HIGH);
    digitalWrite(ledp1, HIGH);
    digitalWrite(ledPin, LOW);
      if(platform1Occupied)
    {
      servoCurrentAngle = servoMinAngle;
      digitalWrite(ledp2, HIGH);
      digitalWrite(ledp1, LOW);
    }
    if(platform2Occupied)
    {
      servoCurrentAngle = servoMaxAngle;
      digitalWrite(ledp2, LOW);
      digitalWrite(ledp1, HIGH);
    }
  }
  
  // move the servo motor to the current angle
  servoMotor.write(servoCurrentAngle);
  delay(300);
}