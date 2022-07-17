
// Define pins
#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {

  // Define time constants
  #define DELAY 5

  // Red color breath
  breath(RED);
  resetRGB();
  
  // Green color breath
  breath(GREEN);
  resetRGB();

  // Blue color breath
  breath(BLUE);  
  resetRGB();
}

/**
 * Reset the rgb values to 0
 */
void resetRGB(){
  analogWrite(RED,0);
  analogWrite(BLUE,0);
  analogWrite(GREEN,0);
}

/**
 * Breath effect by fading in and out
 * the RGB channel
 */
void breath(int channel){
  fadeIn(channel);
  fadeOut(channel);  
}

/**
 * Fade in a given color channel from 0 to 255
 */
void fadeIn(int channel) {
    for(int i = 0; i < 255; i++){
    analogWrite(channel, i);    
    delay(DELAY);
  }
  delay(DELAY);
}

/**
 * Fade in a out < color channel from 0 to 255
 */
void fadeOut(int channel) {
  for(int i = 0; i < 255; i++){
    analogWrite(channel, 255 - i);    
    delay(DELAY);
  }
  delay(DELAY);
}
