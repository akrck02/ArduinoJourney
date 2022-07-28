#include <Servo.h>

#define SERVO_DELAY 30
#define SERVO_MAX 180
#define SERVO_MIN 0
#define SERVO_PIN 9

#define X_AXIS A0
#define X_ORIGIN 515
#define OFFSET 50

Servo servo;
float x;

void setup() {
  servo.attach(SERVO_PIN);
  x = 0;
}

void loop() {
  
  float dx = analogRead(X_AXIS);
  
  // Right
  if(dx < X_ORIGIN - OFFSET){
    x -= 10;
  } 
  
  // Left
  if(dx > X_ORIGIN + OFFSET){
    x += 10;
  }   

  // X axis Control
  if(x > SERVO_MAX){
    x = SERVO_MAX;
  }

  if(x < SERVO_MIN){
    x = SERVO_MIN;
  }

  servo.write(x);
  delay(SERVO_DELAY);
}
