#include <Wire.h>  // Include the Wire library
#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library

#include <Time.h>  // Include the Time library

// Define the address for the LCD
#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

// Initialize the LiquidCrystal_I2C library
LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

// Placeholder for checking water level
void water_sensor() {
    // Placeholder for checking water level
    lcd.setCursor(0, 0);
    lcd.print("Checking water level...");
}

void setup() {
    // initialize the LCD
    lcd.begin(16, 2);

    // Turn on the backlight
    lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
    lcd.setBacklight(HIGH);
}

void loop() {
    // time
    unsigned long start_time = millis();

    while (true) {
        water_sensor();
        
        // Wait for 10 seconds
        delay(10000);

        // Calculate how long it took to check the water level
        unsigned long end_time = millis();
        unsigned long elapsed_time = end_time - start_time;

        // Output the elapsed time
        lcd.setCursor(0, 1);
        lcd.print("Time elapsed: ");
        lcd.print(elapsed_time / 1000);
        lcd.print(" seconds");

        // Update the start time for the next iteration
        start_time = millis();
    }
}