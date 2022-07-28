#include <Servo.h>

#define SERVO_DELAY 25
#define SERVO_MAX 180
#define SERVO_MIN 0
#define SERVO_PIN 9
#define SERVO_MOVE 1

#define X_AXIS A0
#define X_ORIGIN 495
#define X_MAX 1024
#define OFFSET 25

Servo servo;
float x;
float speed;
double relation;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  
  x = 0;
  speed = 0;
  relation = (double)(SERVO_MAX) / X_MAX;
  Serial.println(SERVO_MAX);
  Serial.println(X_MAX);
  Serial.println(relation);
}

void loop() {
  
  float dx = analogRead(X_AXIS);
  speed = dx * relation; 
  
  // Right
  if(dx < X_ORIGIN - OFFSET){
    x = SERVO_MOVE * speed;
  } 
  
  // Left
  if(dx > X_ORIGIN + OFFSET){
    x = SERVO_MOVE * speed;
  }   

  // X axis Control
  if(x > SERVO_MAX){
    x = SERVO_MAX;
  }

  if(x < SERVO_MIN){
    x = SERVO_MIN;
  }

  
  Serial.println();
  
  Serial.print("Speed : ");
  Serial.println(speed);
  
  Serial.print("Dx : ");
  Serial.println(dx);

  Serial.print("x : ");
  Serial.println(x);

  servo.write(x);
  delay(SERVO_DELAY);
  
}
