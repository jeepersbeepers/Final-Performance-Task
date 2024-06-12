#define RELAY_PIN 7
#define AIR_TEMP_HUMIDITY_SENSOR A0

#define MAX_TEMPERATURE 30       // max air temperature that plant reads to pump water
#define MAX_HUMIDITY 70          // max humidity level that plant reads to pump water
#define WATERING_INTERVAL 60000  // Water every 60 seconds (1 minute)

unsigned long lastWateringTime = 0;

#include <LiquidCrystal_I2C.h>
#include <Wire.h>  // Include the Wire library
#include <Time.h>  // Include the Time library

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change address and dimensions according to your LCD

int resval = 0;   // holds the value
int respin = A3;  // sensor pin used

// MAIN SETUP
void setup() {
  // put your setup code here, to run once:
  pinMode(AIR_TEMP_HUMIDITY_SENSOR, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);

  // initialize the LCD
  lcd.begin(16, 2);
  lcd.init();           // initialize the lcd
  lcd.backlight();      // Turn on the backlight
//  lcd.setCursor(0, 0);  // Set cursor to the top-left corner
 // lcd.setCursor(0, 1);  // Set cursor to the top-left corner
}

//MAIN LOOP
void loop() {
  // put your main code here, to run repeatedly:
  int temperature = analogRead(AIR_TEMP_HUMIDITY_SENSOR);  // Read temperature
  int humidity = analogRead(AIR_TEMP_HUMIDITY_SENSOR);     // Read humidity

  // Convert analog readings to actual values (assuming linear scaling)
  float temperatureValue = map(temperature, 0, 1023, 0, 50);  // Scale to 0-50°C
  float humidityValue = map(humidity, 0, 1023, 0, 100);       // Scale to 0-100%

  if (temperatureValue >= MAX_TEMPERATURE && humidityValue <= MAX_HUMIDITY && millis() - lastWateringTime >= WATERING_INTERVAL) {
    Serial.println("Temperature is high and air is dry. Starting watering...");
    digitalWrite(RELAY_PIN, HIGH);
    delay(5000);
    digitalWrite(RELAY_PIN, LOW);
    lastWateringTime = millis();
    Serial.println("Watering completed.");
  }

  timeWaterSensor();  // Read Water Sensor
  lcdScreen();    // Update LCD screen

  delay(1000);  // Adjust delay according to your needs
}
