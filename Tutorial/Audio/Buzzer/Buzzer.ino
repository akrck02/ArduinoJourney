#define BUZZER_PASSIVE 3

#define SHORT_DELAY_MAX 2
#define SHORT_DELAY_DECREASE .05

#define LONG_DELAY_MAX 2
#define LONG_DELAY_DECREASE .01

#define DELAY_BETWEEN_BEEPS 1000


void setup() {
  pinMode(BUZZER_PASSIVE, OUTPUT);
}

void loop() {
   shortBeep();
   longBeep();
}

/**
 * Short beep sound on pasive buzzer 
 */
void shortBeep() {
  for( float delayTime = SHORT_DELAY_MAX; delayTime >= 0; delayTime -= SHORT_DELAY_DECREASE){
    digitalWrite(BUZZER_PASSIVE,HIGH);  
    delay(delayTime);
  
    digitalWrite(BUZZER_PASSIVE,LOW);  
    delay(delayTime);
  }
  delay(DELAY_BETWEEN_BEEPS);  
}

/**
 * Lonmg beep sound on pasive buzzer
 */
void longBeep(){
   for( float delayTime = LONG_DELAY_MAX; delayTime >= 0; delayTime -= LONG_DELAY_DECREASE){
    digitalWrite(BUZZER_PASSIVE,HIGH);  
    delay(delayTime);
  
    digitalWrite(BUZZER_PASSIVE,LOW);  
    delay(delayTime);
  }
  delay(DELAY_BETWEEN_BEEPS);  
}
