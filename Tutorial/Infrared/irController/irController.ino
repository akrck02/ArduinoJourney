#include <IRremote.h>
#include <IRremoteInt.h>

// Reciever data
#define RECIEVER 8
#define RECIEVE_DELAY 100

// LED PINS
#define YELLOW_PIN 12
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

// Controls
#define NONE -3
#define POWER_OFF -2
#define POWER -1
#define ZERO 0
#define ONE 1
#define TWO 2

// Mode parameters
#define LED_DELAY 100

IRrecv irrecv(RECIEVER);
decode_results results;

int state;

void setup() {

  // Start LED pins
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Start the receiver
  irrecv.enableIRIn();
  state = -1;
}

void loop() {

  // If IR Controller push change state
  if (irrecv.decode(&results)) {
    int newState = translateIR();

    // If power button if pressed twice, power off the LEDs
    if(newState == POWER && state == POWER){
      newState = POWER_OFF;
    }

    // If a new known state is selected change the current state
    if(newState != NONE) {
      state = newState;
    }
    
    irrecv.resume();
  }

  // Execute current state
  switch(state){
    case POWER: 
      RGBOn();
      break;
    case POWER_OFF: 
      RGBOff();
      break;
    case ZERO: 
      flowRGB();
      break;
    case ONE: 
      evenRGB();
      break;
    case TWO: 
      randomRGB();
      break;
    default: break;
  }

}

/**
 * Translate IR receiver value on 
 * a RGB mode
 */
int translateIR() {

  switch (results.value) {
    case 0xFFA25D: return POWER;
    case 0xFF6897: return ZERO;
    case 0xFF30CF: return ONE;
    case 0xFF18E7: return TWO;
    default: return NONE;
  }

  delay(RECIEVE_DELAY);
}

/**
 * RGB Wave effect
 */
void flowRGB() {
  RGBOff(); 

  // Prepare LED array and wave params
  int leds[] = {YELLOW_PIN, RED_PIN, GREEN_PIN, BLUE_PIN};
  int ledNumber = sizeof(leds) / sizeof(leds[0]);

  // Light all LEDs with a delay
  for (int i = 0; i < ledNumber; i++) {
    digitalWrite(leds[i], HIGH);
    delay(LED_DELAY);
  }

  // Power off all the LEDs with delay
  for (int i = 0; i < ledNumber; i++) {
    digitalWrite(leds[i], LOW);
    delay(LED_DELAY);
  }
}

/**
 * RGB even number switcher
 */
void evenRGB() {
  RGBOff();
  
  int leds[] = {YELLOW_PIN, RED_PIN, GREEN_PIN, BLUE_PIN};
  int ledNumber = sizeof(leds) / sizeof(leds[0]);

  for (int i = 0; i < 2; i++) {

    if (i % 2 == 0) {
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);

      digitalWrite(RED_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);

      delay(LED_DELAY);
    } else {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);

      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      delay(LED_DELAY);
    }
  }
}

/**
 * Random patter Lighting LEDs
 */
void randomRGB(){
  RGBOff();
  
  int leds[] = {YELLOW_PIN, RED_PIN, GREEN_PIN, BLUE_PIN};
  int ledNumber = sizeof(leds) / sizeof(leds[0]);
   
  for (int i = 0; i < ledNumber; i++) {
    int random = rand() % 10 + 1;
    digitalWrite(leds[i], random > 5 ? HIGH : LOW);
    delay(LED_DELAY);
  }
}

/**
 * Light all the LEDs 
 */
void RGBOn(){
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
}

/**
 * Power off the LEDs
 */
void RGBOff(){
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
}
