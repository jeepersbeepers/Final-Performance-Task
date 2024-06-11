int resval = 0;   // holds the value
int respin = A3;  // sensor pin used

void lcdScreen() {
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);

  resval = analogRead(respin);  //Read data from analog pin and store it to resval variable

  // Print a message to the LCD.
  lcd.print("WATER LEVEL: ");

  if (resval <= 100) {
    lcd.println("Empty!!!");
  } else if (resval > 100 && resval <= 300) {
    lcd.println("Low!!");
  } else if (resval > 300 && resval <= 330) {
    lcd.println("Medium");
  } else if (resval > 330) {
    lcd.println("High");
  }
  delay(1000);
}


