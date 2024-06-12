void lcdScreen() {
  // Set the cursor to column 0, line 1
  lcd.setCursor(0, 1);

  resval = analogRead(respin);  // Read data from analog pin and store it in resval variable

  // Print a message to the LCD.
  lcd.print("WATER LEVEL: ");

  // if (resval <= 100) {
  //   lcd.print("Empty!!!");
  // } else if (resval > 100 && resval <= 300) {
  //   lcd.print("Low!!");
  // } else if (resval > 300 && resval <= 330) {
  //   lcd.print("Medium");
  // } else if (resval > 330) {
  //   lcd.print("High");
  // }
  // delay(1000);
}
