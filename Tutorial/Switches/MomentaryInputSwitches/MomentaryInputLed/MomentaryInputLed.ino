#define LED 5
#define BUTTON_ON 4
#define BUTTON_MEDIUM 3
#define BUTTON_OFF 2
#define MEDIUM 10

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_ON, INPUT_PULLUP);
  pinMode(BUTTON_MEDIUM, INPUT_PULLUP);
  pinMode(BUTTON_OFF, INPUT_PULLUP);

  // Make sure that the LED is OFF
   digitalWrite(LED, LOW);
}

void loop() {

  // If the ON button was pressed
  if(digitalRead(BUTTON_ON) == LOW){
    digitalWrite(LED, HIGH);
  }

  // If the MEDIUM BRIGHTNESS button was pressed
  if(digitalRead(BUTTON_MEDIUM) == LOW){
    analogWrite(LED, MEDIUM);
  }

  // If the OFF button was pressed
  if(digitalRead(BUTTON_OFF) == LOW){
    digitalWrite(LED, LOW);
  }
    
}
