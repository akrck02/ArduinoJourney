#include <SR04.h>

#define LED 10
#define ECHO 11
#define MICROPHONE 12

#define DELAY_TIME 100
#define SERIAL_PORT 9600

SR04 sensor = SR04(ECHO, MICROPHONE);
long distance;

void setup() {
  
  Serial.begin(SERIAL_PORT);
  pinMode(LED, OUTPUT);
  
  distance = 0;
  delay(DELAY_TIME);

}

void loop() {
  distance = sensor.Distance();
  Serial.println(distance);  

  if(distance < 30){
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  
  delay(DELAY_TIME);
}
