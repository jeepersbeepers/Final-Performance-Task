#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Define the pins for the water level sensor and LCD display
#define WATER_LEVEL_SENSOR_PIN A0


//initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Define a variable to store the water level sensor value
int waterLevel;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // put your setup code here, to run once:
  //Initialize the serial communication
  Serial.begin(115200);

  //Set the LCD display to 16x2 characters
  lcd.begin(16, 2);

  //Print a welcome message on the LCD display
  lcd.print("Water Level Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Running...");

  //Wait for 1 minute before running the water level sensor again
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Read the water level sensor value
  waterLevel = analogRead(WATER_LEVEL_SENSOR_PIN);

  //Print the water level sensor value on the serial monitor
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  //Check if the water level is below a certain threshold
  if (waterLevel < 500) {
    //Print a warning message on the LCD display
    lcd.clear();
    lcd.print("Water Level Low!!!");
    lcd.setCursor(0, 1);
    lcd.print("Refill Required");
  } else {
    //Print a normal message on the LCD display
    lcd.clear();
    lcd.print("Water Level OK!!!");
    lcd.setCursor(0, 1);
    lcd.print("No Refill Needed");
  }

  //Wait for 1 minute before running the water level sensor again
  delay(1000);
}