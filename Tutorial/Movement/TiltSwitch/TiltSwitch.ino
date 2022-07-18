#define LED 8
#define BUZZER 9
#define TILT 10
#define DEFAULT_DELAY 500

bool detected;

void setup() {

  //Set pin modes
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(TILT,INPUT);

  // Reset LED and buzzer
  alarm(false);
  detected = false;

}

void loop() {

  // If movement is detected set the alarm
  if(detected ||  digitalRead(TILT) == HIGH){
    detected = true;
    alarm(true);
  }

  // Shut down the alarm
  alarm(false); 
  
}

/**
 * Set the alarm on/off
 */
void alarm(boolean on){
  
  int state = on ? HIGH : LOW;
 
  digitalWrite(LED,state);
  digitalWrite(BUZZER,state);
  delay(DEFAULT_DELAY);
  
}
