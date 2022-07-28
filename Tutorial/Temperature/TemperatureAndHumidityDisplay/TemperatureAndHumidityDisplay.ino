#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

#define DHT_PIN 13
#define DHT_TYPE DHT11
#define DELAY 100

#define DISPLAY_RS_PIN 7
#define DISPLAY_E_PIN 8
#define DISPLAY_D4_PIN 9
#define DISPLAY_D5_PIN 10
#define DISPLAY_D6_PIN 11
#define DISPLAY_D7_PIN 12

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal lcd(DISPLAY_RS_PIN,
                  DISPLAY_E_PIN, 
                  DISPLAY_D4_PIN, 
                  DISPLAY_D5_PIN, 
                  DISPLAY_D6_PIN, 
                  DISPLAY_D7_PIN
              );

void setup() {

  //Start LCD wit columns and rows
   lcd.begin(16, 2);

  // Start sensor
  dht.begin();

}

void loop() {
  delay(DELAY);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  lcd.setCursor(0, 0);
  lcd.print("Hum: ");
  lcd.print((int)humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print((int)temperature);
  lcd.print("C");
 
}
