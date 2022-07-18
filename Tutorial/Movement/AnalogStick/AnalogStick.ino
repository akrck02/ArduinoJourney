#define SW 2
#define X_AXIS A0
#define Y_AXIS A1

#define RED 3
#define GREEN 4
#define BLUE 5
#define YELLOW 6

#define X_ORIGIN 515
#define Y_ORIGIN 498
#define OFFSET 50

void setup() {
  pinMode(SW, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  
  digitalWrite(SW,HIGH);
  Serial.begin(9600);

  clear();
}

void loop() {

  int buttonPressed = digitalRead(SW);
  float x = analogRead(X_AXIS);
  float y = analogRead(Y_AXIS);
  clear();

  // All
  if(buttonPressed == 0){
    lightAll();
    return;
  }

  // Right
  if(x < X_ORIGIN - OFFSET){
    digitalWrite(YELLOW,HIGH);
  } 
  
  // Left
  if(x > X_ORIGIN + OFFSET){
    digitalWrite(GREEN,HIGH);
  } 

  // Up
  if(y< Y_ORIGIN - OFFSET){
    digitalWrite(BLUE,HIGH);
  } 
  
  // Down
  if(y > Y_ORIGIN + OFFSET){
    digitalWrite(RED,HIGH);
  }
  
  delay(10);
}

/**
 * Clear the LEDs
 */
void clear(){
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,LOW);
  digitalWrite(YELLOW,LOW);
}

/**
 * Light the LEDs
 */
void lightAll(){
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,HIGH);
    digitalWrite(YELLOW,HIGH);
}
