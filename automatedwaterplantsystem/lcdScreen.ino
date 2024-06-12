// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(12, 11, 5, 4, 3, 2); // Change pins according to your setup
// int resval = 0;   // holds the value
// int respin = A3;  // sensor pin used

// void lcdScreen() {
//   // set the cursor to column 0, line 1
//   lcd.setCursor(0, 1);

//   resval = analogRead(respin);  //Read data from analog pin and store it to resval variable

//   // Print a message to the LCD.
//   lcd.print("WATER LEVEL: ");

//  // put your setup code here, to run once:
//   lcd.init();     //initialize the lcd
//   lcd.backlight();     //Turn on the backlight
//   lcd.setCursor(0, 0);     //set cursor to the top-left corner
//   lcd.setCursor(0, 1);     //set cursor to the top-left corner
 


//   if (resval <= 100) {
//     lcd.print("Empty!!!");
//   } else if (resval > 100 && resval <= 300) {
//     lcd.print("Low!!");
//   } else if (resval > 300 && resval <= 330) {
//     lcd.print("Medium");
//   } else if (resval > 330) {
//     lcd.print("High");
//   }
//   delay(1000);
// }

// void loop() {
//   lcdScreen();
// }


<<<<<<< HEAD
=======
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


>>>>>>> e4860a4083b36276e41ee1290b7f92c240679d0a
