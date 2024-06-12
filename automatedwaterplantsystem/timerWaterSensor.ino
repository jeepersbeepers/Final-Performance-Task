void timeWaterSensor() {
  unsigned long startTime = millis();  // Record start time

  while (true) {
    Serial.println("Checking water level...");

    // Wait for 10 seconds
    delay(10000);

    // Calculate how long it took to check the water level
    unsigned long endTime = millis();                 // Record end time
    unsigned long elapsedTime = endTime - startTime;  // Calculate elapsed time

    // Output the elapsed time
    Serial.print("Time elapsed since last check: ");
    Serial.print(elapsedTime / 1000);  // Convert milliseconds to seconds
    Serial.println(" seconds");

    // Update the start time for the next iteration
    startTime = millis();
  }
}