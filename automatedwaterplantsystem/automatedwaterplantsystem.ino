#define RELAY_PIN 7
#define AIR_TEMP_HUMIDITY_SENSOR A0

#define MAX_TEMPERATURE 30 // max air temperature that plant reads to pump water
#define MAX_HUMIDITY 70    // max humidity level that plant reads to pump water
#define WATERING_INTERVAL 60000 // Water every 60 seconds (1 minute)

unsigned long lastWateringTime = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(AIR_TEMP_HUMIDITY_SENSOR, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
int temperature = analogRead(AIR_TEMP_HUMIDITY_SENSOR); // Read temperature
  int humidity = analogRead(AIR_TEMP_HUMIDITY_SENSOR);    // Read humidity

// Convert analog readings to actual values (assuming linear scaling)
  float temperatureValue = map(temperature, 0, 1023, 0, 50); // Scale to 0-50°C
  float humidityValue = map(humidity, 0, 1023, 0, 100);      // Scale to 0-100%

 if (temperatureValue >= MAX_TEMPERATURE && humidityValue <= MAX_HUMIDITY && millis() - lastWateringTime >= WATERING_INTERVAL) {
    Serial.println("Temperature is high and air is dry. Starting watering...");
    digitalWrite(RELAY_PIN, HIGH);    // Turn on pump to water plant
    delay(5000);    // Watering duration for 5 seconds
    digitalWrite(RELAY_PIN, LOW);     // Turn off pump
    lastWateringTime = millis();
    Serial.println("Watering completed.");
  }

  delay(1000); // Adjust delay according to your needs
}

