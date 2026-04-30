// C++ code
//
#include <Servo.h>

int ketinggianbanjir = 0;

Servo servo_10;

void setup()
{
  servo_10.attach(10, 500, 2500);
  pinMode(4, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(5, OUTPUT);

  servo_10.write(0);
  digitalWrite(4, LOW);
  digitalWrite(A2, HIGH);
  ketinggianbanjir = 0;
}

void loop()
{
  ketinggianbanjir = map(analogRead(A2), 0, 1023, 0, 180);
  if (ketinggianbanjir >= 70) {
    digitalWrite(4, HIGH);
    servo_10.write(90);
    tone(5, 523, 3000); // play tone 60 (C5 = 523 Hz)
    delay(5000); // Wait for 5000 millisecond(s)
    digitalWrite(4, LOW);
    noTone(5);
  } else {
    servo_10.write(0);
    digitalWrite(4, LOW);
    noTone(5);
  }
}

