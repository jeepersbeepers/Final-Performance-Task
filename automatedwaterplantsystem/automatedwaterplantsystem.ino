#include <DHT.h>
#include <DHT_U.h>

#define RELAY_PIN 7
#define AIR_TEMP_HUMIDITY_SENSOR A0
#define WATER_SENSOR A3


#define MAX_TEMPERATURE 25       // max air temperature that plant reads to pump water
#define MAX_HUMIDITY 60          // max humidity level that plant reads to pump water
#define WATERING_INTERVAL 60000  // Water every 60 seconds (1 minute)

unsigned long lastWateringTime = 0;

#include <LiquidCrystal_I2C.h>
#include <Wire.h>  // Include the Wire library
#include <Time.h>  // Include the Time library

LiquidCrystal_I2C lcd(0x27, 16, 2);        // Initialize LCD with I2C address
const int waterSensorPin = A3;             // Analog pin connected to the water sensor
DHT dht(AIR_TEMP_HUMIDITY_SENSOR, DHT11);  // Initialize DHT sensor

// MAIN SETUP
void setup() {
  // put your setup code here, to run once:
  pinMode(AIR_TEMP_HUMIDITY_SENSOR, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(WATER_SENSOR, INPUT);

  Serial.begin(9600);

  // initialize the LCD
  lcd.init();                 // Initialize the LCD
  lcd.backlight();            // Turn on backlight
  lcd.setCursor(0, 0);        // Set cursor to first row
  lcd.print("Water Level:");  // Display initial message
  dht.begin();                // Initialize DHT sensor

  pinMode(waterSensorPin, INPUT);  // Set water sensor pin as input
}

//MAIN LOOP
void loop() {
  // Read temperature and humidity from DHT sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // put your main code here, to run repeatedly:
  // Read the analog value from the sensor
  int AIR_TEMP_HUMIDITYValue = analogRead(AIR_TEMP_HUMIDITY_SENSOR);

  // Convert the analog value to voltage (assuming 5V reference)
  float voltage = AIR_TEMP_HUMIDITYValue * (5.0 / 1023.0);

  // Print the raw air temp and humidity sensor value and voltage to the serial monitor
  Serial.print("Air Temp & Humidity Value: 867");
  Serial.print(AIR_TEMP_HUMIDITYValue);
  Serial.print("\tVoltage: 4.24 ");
  Serial.println(voltage);

  // Convert analog readings to actual values (assuming linear scaling)
  float temperatureValue = map(temperature, 0, 1023, 25, 50);  // Scale to 0-50°C
  float humidityValue = map(humidity, 0, 1023, 60, 100);       // Scale to 0-100%

  if (temperatureValue >= MAX_TEMPERATURE && humidityValue <= MAX_HUMIDITY && millis() - lastWateringTime >= WATERING_INTERVAL) {
    Serial.println("Temperature is high and air is dry. Starting watering...");
    lcd.setCursor(0, 0);       // Set cursor to first row
    lcd.print("Watering...");  // Display watering message

    digitalWrite(RELAY_PIN, HIGH);  // Turn on pump to water plant
    delay(5000);                    // Watering duration for 5 seconds
    digitalWrite(RELAY_PIN, LOW);   // Turn off pump
    lastWateringTime = millis();
    Serial.println("Watering completed.");
  }
delay(1000);

  float WATER_SENSORValue = analogRead(WATER_SENSOR);

  // Read the analog value from the water sensor
  int waterLevel = analogRead(waterSensorPin);

  // Determine water level range and print corresponding message on LCD
  if (waterLevel >= 7 && waterLevel <= 345) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water Level: Empty");
  } else if (waterLevel >= 346 && waterLevel <= 371) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water Level: Good");
  } else if (waterLevel >= 372 && waterLevel <= 394) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water Level: Full");
  }

  // Print water level to the serial monitor for debugging
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  // Add a short delay before reading again
  delay(100);  // Adjust delay as needed

  Serial.print("Water Sensor Reading: ");
  Serial.println(WATER_SENSORValue);


  {
    // Read water sensor value
    int waterLevel = analogRead(waterSensorPin);

    // Convert analog reading to percentage (assuming full range is 0-1023)
    int percentage = map(waterLevel, 0, 1023, 0, 100);

    // Print water level on LCD
    lcd.setCursor(0, 1);
    lcd.print("  ");  // Clear the line
    lcd.setCursor(0, 1);
    lcd.print(percentage);
    lcd.print("%");

    // Wait a short delay before reading again
    delay(1000);  // Adjust delay as needed
  }
  lcdScreen();        // Update LCD screen
  timeWaterSensor();  // Read Water Sensor


  delay(1000);  // Adjust delay according to your needs
}