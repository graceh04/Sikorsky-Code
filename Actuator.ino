/*
  Button control Servo
*/

#include <Servo.h>

int pos = 0;

int ButtonState = 0;

int i = 0;

int angle = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);

  pinMode(9, INPUT);
  pinMode(2, INPUT);
}

void loop()
{
  angle = servo_9.read();
  pos = digitalRead(9);
  ButtonState = digitalRead(2);
  if (ButtonState == HIGH) {
    for (pos = 0; pos <= 180; pos += 1) {
      // tell servo to go to position in variable 'pos'
      servo_9.write(pos);
      delay(50); // Wait for 50 millisecond(s)
    }
    for (pos = 0; pos >= 180; pos -= 0.1) {
      // tell servo to go to position in variable 'pos'
      servo_9.write(pos);
      delay(50); // Wait for 50 millisecond(s)
    }
  } else {
    if (ButtonState == LOW) {
      angle = 0;
      servo_9.write(angle);
      delay(1); // Wait for 1 millisecond(s)
    }
  }
}